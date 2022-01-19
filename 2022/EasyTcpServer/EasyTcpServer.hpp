#ifndef _EasyTcpServer_hpp_
#define _EasyTcpServer_hpp_

#ifdef _WIN32
	#define FD_SETSIZE      2506
	#define WIN32_LEAN_AND_MEAN
	#define _WINSOCK_DEPRECATED_NO_WARNINGS // ���ξ���
	#include<windows.h>
	#include<WinSock2.h>
	#pragma comment(lib,"ws2_32.lib")
#else
	#include<unistd.h> //uni std
	#include<arpa/inet.h>
	#include<string.h>

	#define SOCKET int
	#define INVALID_SOCKET  (SOCKET)(~0)
	#define SOCKET_ERROR            (-1)
#endif

#include<stdio.h>
#include<vector>
#include<thread>
#include<mutex>
#include<atomic>
#include<functional>
#include<memory>
#include "MessageHeader.hpp"
#include "CELLTimestamp.hpp"
#include "CELLTask.hpp"
#include "CELLObjectPool.hpp"

//��������С��Ԫ��С
#ifndef RECV_BUFF_SIZE
#define RECV_BUFF_SIZE 10240 * 5
#define SEND_BUFF_SIZE RECV_BUFF_SIZE
#endif // !RECV_BUFF_SIZE

typedef std::shared_ptr<DataHeader> DataHeaderPtr;
typedef std::shared_ptr<LoginResult> LoginResultPtr;

//#define _CellServer_THREAD_COUNT 4

// ��װ�ͻ��˶���
class ClientSocket: public ObjectPoolBase<ClientSocket, 1000>
{
public:
	ClientSocket(SOCKET sockfd = INVALID_SOCKET)
	{
		_sockfd = sockfd;
		memset(_szMsgBuf, 0, RECV_BUFF_SIZE);
		_lastPos = 0;

		memset(_szSendBuf, 0, SEND_BUFF_SIZE);
		_lastSendPos = 0;
	}

	SOCKET sockfd()
	{
		return _sockfd;
	}

	char* msgBuf()
	{
		return _szMsgBuf;
	}

	int getLastPos()
	{
		return _lastPos;
	}

	void setLastPos(int pos)
	{
		_lastPos = pos;
	}

	//����ָ����
	int SendData( DataHeader* header)
	{
		int ret = SOCKET_ERROR;
		// Ҫ���͵����ݳ���
		int nSendLen = header->dataLength;
		// Ҫ���͵�����
		const char* pSendData = (const char*)header;
		while (true)
		{
			// ��������
			if (_lastSendPos + nSendLen >= SEND_BUFF_SIZE)
			{
				// ����ɿ��������ݳ���
				int nCopyLen = SEND_BUFF_SIZE - _lastSendPos;
				// ��������
				memcpy(_szSendBuf + _lastSendPos, pSendData, nCopyLen);
				// ʣ�����ݵ�λ��ƫ��
				pSendData += nCopyLen;
				// ʣ�����ݳ���
				nSendLen -= nCopyLen;
				// ��������
				ret = send(_sockfd, _szSendBuf, SEND_BUFF_SIZE, 0);
				// ����β������
				_lastSendPos = 0;
				if (SOCKET_ERROR == ret)
				{
					return ret;
				}
			}
			else
			{
				// ��Ҫ���͵����ݿ��������ͻ�����β��
				memcpy(_szSendBuf + _lastSendPos, pSendData, nSendLen);
				// β��ָ��ƫ��
				_lastSendPos += nSendLen;
				break;
			}
		}

		return ret;
	}

private:
	// socket fd_set  file desc set
	SOCKET _sockfd;
	//�ڶ������� ��Ϣ������
	char _szMsgBuf[RECV_BUFF_SIZE];
	//�ڶ������� ���ͻ�����
	char _szSendBuf[SEND_BUFF_SIZE];
	//��Ϣ������������β��λ��
	int _lastPos;
	int _lastSendPos;
};

typedef std::shared_ptr<ClientSocket> ClientSocketPtr;

class CellServer;

// �����¼��ӿ� 
// ���麯�� ����ӿ�
class INetEvent
{
public:
	//���麯��
	//�ͻ��˼����¼�
	virtual void OnNetJoin(ClientSocketPtr& pClient) = 0;
	//�ͻ����뿪�¼�
	virtual void OnNetLeave(ClientSocketPtr& pClient) = 0;
	// �ͻ�����Ϣ�¼�
	virtual void OnNetMsg(CellServer* pcellServer, ClientSocketPtr& pClient, DataHeader* header) = 0;
	// recv�¼�
	virtual void OnNetRecv(ClientSocketPtr& pClient) = 0;

};

// ������Ϣ����������
class CellS2CTask: public CellTask
{
private:
	ClientSocketPtr _pClient;
	DataHeader* _pHeader;

public:
	CellS2CTask(ClientSocketPtr pClient, DataHeader *header)
	{
		_pClient = pClient;
		_pHeader = header;
	}

	void doTask()
	{
		_pClient->SendData(_pHeader);
		delete _pHeader;
	}


};

typedef std::shared_ptr<CellS2CTask> CellS2CTaskPtr;


// ������Ϣ���մ���������
class CellServer
{
public:
	CellServer(SOCKET sock = INVALID_SOCKET)
	{
		_sock = sock;
		_pNetEvent = nullptr;
	}

	~CellServer()
	{
		Close();
		_sock = INVALID_SOCKET;
	}

	void setEventObj(INetEvent* event)
	{
		_pNetEvent = event;
	}

	//�ر�Socket
	void Close()
	{
		if (_sock != INVALID_SOCKET)
		{
#ifdef _WIN32
			for (int n = (int)_clients.size() - 1; n >= 0; n--)
			{
				closesocket(_clients[n]->sockfd());
			}
			// 8 �ر��׽���closesocket
			closesocket(_sock);
#else
			for (int n = (int)_clients.size() - 1; n >= 0; n--)
			{
				close(_clients[n]->sockfd());
			}
			// 8 �ر��׽���closesocket
			close(_sock);
#endif
			_clients.clear();
		}
	}

	//�Ƿ�����
	bool isRun()
	{
		return _sock != INVALID_SOCKET;
	}

	// ���ݿͻ�socket
	fd_set _fdRead_back;
	// �ͻ��б��Ƿ��иı�
	bool _clients_change;
	SOCKET _maxSock;

	//����������Ϣ
	bool OnRun()
	{
		while (isRun())
		{
			_clients_change = true;
			if (!_clientsBuff.empty())
			{
				//�ӻ��������ȡ���ͻ�����
				std::lock_guard<std::mutex> lock(_mutex);
				// ����ʱ�����еĿͻ���ȡ�������뵽��ʽ�Ŀͻ���������
				for (auto pClient : _clientsBuff)
				{
					_clients.push_back(pClient);
				}
				_clientsBuff.clear();
				_clients_change = true;
			}

			// ���û����Ҫ�����Ŀͻ��ˣ�������
			if (_clients.empty())
			{
				std::chrono::milliseconds t(1);
				std::this_thread::sleep_for(t);
				continue;
			}

			// ����ʽ�Ŀͻ��������еĿͻ���fd���뵽����⼯����
			//�������׽��� BSD socket
			fd_set fdRead;//��������socket�� ����
			//��������
			FD_ZERO(&fdRead);
			//����������socket�����뼯��
			if (_clients_change)
			{
				_clients_change = false;
				_maxSock = _clients[0]->sockfd();

				for (int n = (int)_clients.size() - 1; n >= 0; n--)
				{
					// ����ʽ�Ŀͻ��������еĿͻ���fd���뵽����⼯����
					FD_SET(_clients[n]->sockfd(), &fdRead);
					// ����socketfd���ֵ���Ա��ڴ��ݸ�select
					if (_maxSock < _clients[n]->sockfd())
					{
						_maxSock = _clients[n]->sockfd();
					}
				}
			}
			else 
			{
				memcpy(&fdRead, &_fdRead_back, sizeof(_fdRead_back));
			}
			
			// ����ʽ����ʹ��select�����¼�
			///nfds ��һ������ֵ ��ָfd_set����������������(socket)�ķ�Χ������������
			///���������ļ����������ֵ+1 ��Windows�������������д0
			int ret = select(_maxSock + 1, &fdRead, nullptr, nullptr, nullptr);
			if (ret < 0)
			{
				printf("select���������\n");
				Close();
				return false;
			}

			// ���ȥ�����ͻ��� ÿ���ͻ������л��������������ȡ������ɷ���
			std::vector<ClientSocketPtr > temp;
			for (int n = (int)_clients.size() - 1; n >= 0; n--)
			{
				if (FD_ISSET(_clients[n]->sockfd(), &fdRead))
				{
					// �ͻ���recv��������-1����˵���ÿͻ����Ѿ��˳�
					if (-1 == RecvData(_clients[n]))
					{
						auto iter = _clients.begin() + n; //std::vector<SOCKET>::iterator
						if (iter != _clients.end())
						{
							_clients_change = false;
							temp.push_back(_clients[n]);
							if (_pNetEvent)
								_pNetEvent->OnNetLeave(_clients[n]);
							_clients.erase(iter);
						}
					}
				}
			}
		}
	}

	// �����Ϣ�Ķ�ȡ��Ȼ��OnNetMsg������Ϣ
	// �������� ����ճ�� ��ְ�
	int RecvData(ClientSocketPtr pClient)
	{
		// 5 ���տͻ�������
		char* szRecv = pClient->msgBuf() + pClient->getLastPos();
		int nLen = (int)recv(pClient->sockfd(), szRecv, RECV_BUFF_SIZE - pClient->getLastPos(), 0);
		_pNetEvent->OnNetRecv(pClient);
		//printf("nLen=%d\n", nLen);
		if (nLen <= 0)
		{
			//printf("�ͻ���<Socket=%d>���˳������������\n", pClient->sockfd());
			return -1;
		}
		//����ȡ�������ݿ�������Ϣ������
		memcpy(pClient->msgBuf() + pClient->getLastPos(), szRecv, nLen);
		//��Ϣ������������β��λ�ú���
		pClient->setLastPos(pClient->getLastPos() + nLen);

		//�ж���Ϣ�����������ݳ��ȴ�����ϢͷDataHeader����
		while (pClient->getLastPos() >= sizeof(DataHeader))
		{
			//��ʱ�Ϳ���֪����ǰ��Ϣ�ĳ���
			DataHeader* header = (DataHeader*)pClient->msgBuf();
			//�ж���Ϣ�����������ݳ��ȴ�����Ϣ����
			if (pClient->getLastPos() >= header->dataLength)
			{
				//��Ϣ������ʣ��δ�������ݵĳ��� 
				int nSize = pClient->getLastPos() - header->dataLength;
				//����������Ϣ ������һ����Ϣ��
				OnNetMsg(pClient, header);
				//����Ϣ������ʣ��δ��������ǰ��
				memcpy(pClient->msgBuf(), pClient->msgBuf() + header->dataLength, nSize);
				//��Ϣ������������β��λ��ǰ��
				pClient->setLastPos(nSize);
			}
			else {
				//��Ϣ������ʣ�����ݲ���һ��������Ϣ
				break;
			}
		}
		return 0;
	}

	//��Ӧ������Ϣ
	virtual void OnNetMsg(ClientSocketPtr pClient, DataHeader* header)
	{
		_pNetEvent->OnNetMsg(this, pClient, header);
	}

	//����ָ��Socket����
	int SendData(SOCKET cSock, DataHeader* header)
	{
		if (isRun() && header)
		{
			return send(cSock, (const char*)header, header->dataLength, 0);
		}
		return SOCKET_ERROR;
	}

	void addClient(ClientSocketPtr pClient)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		//_mutex.lock();
		_clientsBuff.push_back(pClient);
		//_mutex.unlock();
	}

	void Start()
	{
		_thread = std::thread(std::mem_fn(&CellServer::OnRun), this);
		_taskServer.Start();
	}

	size_t getClientCount()
	{
		return _clients.size() + _clientsBuff.size();
	}

	void addSendTask(ClientSocketPtr pClient, DataHeader * header)
	{
		// auto CellS2CTaskPtr
		auto task = std::make_shared<CellS2CTask>(pClient, header);
		_taskServer.addTask((CellTaskPtr &)task);
	}

private:
	SOCKET _sock;
	//��ʽ�ͻ�����
	std::vector<ClientSocketPtr> _clients;
	//����ͻ�����
	std::vector<ClientSocketPtr> _clientsBuff;
	// ������е���
	std::mutex _mutex;
	std::thread _thread;
	// �����¼�����
	INetEvent* _pNetEvent;
	//
	CellTaskServer _taskServer;
};

typedef std::shared_ptr<CellServer> CellServerPtr;

class EasyTcpServer : public INetEvent
{
private:
	SOCKET _sock;
	// ��Ϣ���������ڲ� �ᴴ���߳�
	std::vector<CellServerPtr> _cellServers;
	// ÿ����Ϣ��ʱ
	CELLTimestamp _tTime;
protected:
	// �յ���Ϣ���� Socket recv����
	std::atomic_int _recvCount;
	// �ͻ��˼���ĸ���
	std::atomic_int _clientCount;
	// �յ���Ϣ����
	std::atomic_int _msgCount;

public:
	EasyTcpServer()
	{
		_sock = INVALID_SOCKET;
		_recvCount = 0;
		_clientCount = 0;
		_msgCount = 0;
	}

	virtual ~EasyTcpServer()
	{
		Close();
	}

	//��ʼ��Socket
	SOCKET InitSocket()
	{
#ifdef _WIN32
		//����Windows socket 2.x����
		WORD ver = MAKEWORD(2, 2);
		WSADATA dat;
		WSAStartup(ver, &dat);
#endif
		if (INVALID_SOCKET != _sock)
		{
			printf("<socket=%d>�رվ�����...\n", (int)_sock);
			Close();
		}
		// Ϊ�������˽���һ��socket
		_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == _sock)
		{
			printf("���󣬽���socketʧ��...\n");
		}
		else {
			printf("����socket=<%d>�ɹ�...\n", (int)_sock);
		}
		return _sock;
	}

	//��IP�Ͷ˿ں�
	int Bind(const char* ip, unsigned short port)
	{
		//if (INVALID_SOCKET == _sock)
		//{
		//	InitSocket();
		//}
		// 2 bind �����ڽ��ܿͻ������ӵ�����˿�
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port);//host to net unsigned short ʹ�ô��ݽ����Ķ˿ں�

#ifdef _WIN32
		if (ip) 
		{
			_sin.sin_addr.S_un.S_addr = inet_addr(ip);
		}
		else 
		{
			/*
			* INADDR_ANY INADDR_ANY
			ת����������0.0.0.0����ָ��������˼��Ҳ���Ǳ�ʾ����������IP;
			��Ϊ��Щ���Ӳ�ֹһ��������������������£�����ͱ�ʾ��������ip��ַ����˼��
			*/
			_sin.sin_addr.S_un.S_addr = INADDR_ANY; // ������ip
		}
#else
		if (ip) {
			_sin.sin_addr.s_addr = inet_addr(ip);
		}
		else {
			_sin.sin_addr.s_addr = INADDR_ANY;
		}
#endif
		// ��ɰ�
		int ret = bind(_sock, (sockaddr*)&_sin, sizeof(_sin));
		if (SOCKET_ERROR == ret)
		{
			printf("����,������˿�<%d>ʧ��...\n", port);
		}
		else {
			printf("������˿�<%d>�ɹ�...\n", port);
		}
		return ret;
	}

	//�����˿ں�
	int Listen(int n)
	{
		// 3 listen ��������˿�
		/*
		* listen����������������ֻ���൱�ڰѷ�������socket�����Ը���Ϊ�������ӣ����Խ����������̵����ӡ�
		*/
		int ret = listen(_sock, n);
		if (SOCKET_ERROR == ret)
		{
			printf("socket=<%d>����,��������˿�ʧ��...\n", _sock);
		}
		else {
			printf("socket=<%d>��������˿ڳɹ�...\n", _sock);
		}
		return ret;
	}

	//���ܿͻ�������
	SOCKET Accept()
	{
		// 4 accept �ȴ����ܿͻ�������
		sockaddr_in clientAddr = {};
		int nAddrLen = sizeof(sockaddr_in);
		SOCKET cSock = INVALID_SOCKET;
#ifdef _WIN32
		cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
#else
		cSock = accept(_sock, (sockaddr*)&clientAddr, (socklen_t*)&nAddrLen);
#endif
		if (INVALID_SOCKET == cSock)
		{
			printf("socket=<%d>����,���ܵ���Ч�ͻ���SOCKET...\n", (int)_sock);
		}
		else
		{
			// ��װ�ͻ��˶���
			// ���µĿͻ��˷�����ͻ��������ٵ�cellServer
			addClientToCellServer(std::make_shared<ClientSocket>(cSock));
			//ClientSocketPtr c(new ClientSocket(cSock));
			//addClientToCellServer(c);
			// ��ȡIP��ַ inet_ntoa(clientAddr.sin_addr)
		}

		return cSock;
	}

	// ���µĿͻ��˷�����ͻ��������ٵ�cellServer
	void addClientToCellServer(ClientSocketPtr pClient)
	{
		//���ҿͻ��������ٵ�CellServer��Ϣ��������
		auto pMinServer = _cellServers[0];
		for (auto pCellServer : _cellServers)
		{
			if (pMinServer->getClientCount() > pCellServer->getClientCount())
			{
				pMinServer = pCellServer;
			}
		}
		pMinServer->addClient(pClient);
		OnNetJoin(pClient);
	}

	void Start(int nCellServer)
	{
		for (int n = 0; n < nCellServer; n++)
		{
			//CellServer* ser = new CellServer();
			// ��������Ԫ�Ķ���
			auto ser = std::make_shared<CellServer>(_sock);
			_cellServers.push_back(ser);
			// ע�������¼����ܶ���
			ser->setEventObj(this);
			// ������Ϣ�����߳�
			ser->Start();
		}
	}

	//�ر�Socket
	void Close()
	{
		if (_sock != INVALID_SOCKET)
		{
#ifdef _WIN32
			// 8 �ر��׽���closesocket
			closesocket(_sock);
			//------------
			//���Windows socket����
			WSACleanup();
#else
			// 8 �ر��׽���closesocket
			close(_sock);
#endif
		}
	}

	//����������Ϣ
	bool OnRun()
	{
		if (isRun())
		{
			time4msg();
			//�������׽��� BSD socket
			fd_set fdRead;//��������socket�� ����
			//��������
			FD_ZERO(&fdRead);
			//����������socket�����뼯��
			FD_SET(_sock, &fdRead);
			///nfds ��һ������ֵ ��ָfd_set����������������(socket)�ķ�Χ������������
			///���������ļ����������ֵ+1 ��Windows�������������д0
			timeval t = { 0,10 };
			int ret = select(_sock + 1, &fdRead, 0, 0, &t); //
			//printf("select ret=%d count=%d\n", ret, _nCount++);
			if (ret < 0)
			{
				printf("Accept Select���������\n");
				Close();
				return false;
			}
			// �ж���������socket���Ƿ��ڼ�����
			if (FD_ISSET(_sock, &fdRead))
			{
				FD_CLR(_sock, &fdRead);
				Accept(); // ���տͻ���fd���ŵ�����������
				return true;
			}
			return true;
		}
		return false;
	}
	//�Ƿ�����
	bool isRun()
	{
		return _sock != INVALID_SOCKET;
	}

	//���������ÿ���յ���������Ϣ ����
	void time4msg()
	{
		auto t1 = _tTime.getElapsedSecond();
		if (t1 >= 1.0)
		{
			printf("thread<%d>,time<%lf>,socket<%d>,clients<%d>,recvCount<%d>,msgCount<%d>\n", _cellServers.size(), t1, _sock, (int)_clientCount, (int)(_recvCount / t1), int(_msgCount / t1));
			
			// ����������
			_recvCount = 0; 
			_msgCount = 0;
			_tTime.update();
			
		}
	}

	// ֻ�ᱻһ���̵߳���
	virtual void OnNetJoin(ClientSocketPtr& pClient)
	{
		_clientCount++;
	}

	// cellSertver 4���߳� ����̴߳��� ����ȫ
	virtual void OnNetLeave(ClientSocketPtr& pClient)
	{
		_clientCount--;
	}

	// cellSertver 4���߳� ����̴߳��� ����ȫ
	virtual void OnNetMsg(CellServer *pCellServer, ClientSocketPtr& pClient, DataHeader* header)
	{
		_msgCount++;
	}

	virtual void OnNetRecv(ClientSocketPtr& pClient)
	{
		_recvCount++;
		//printf("client<%d> leave\n", pClient->sockfd());
	}
};

#endif // !_EasyTcpServer_hpp_
