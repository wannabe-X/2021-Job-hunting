#ifndef _EasyTc_pClient_hpp_
#define _EasyTc_pClient_hpp_

#include"CELL.hpp"
#include"CELLNetWork.hpp"
#include"MessageHeader.hpp"
#include"CELLClient.hpp"

class EasyTcpClient
{
public:
	EasyTcpClient()
	{
		_isConnect = false;
	}

	virtual ~EasyTcpClient()
	{
		Close();
	}
	//��ʼ��socket
	void InitSocket()
	{
		CELLNetWork::Init();

		if (_pClient != nullptr)
		{
			CELLLog::Info("warning, initSocket close old socket<%d>...\n", (int)_pClient->sockfd());
			Close();
		}
		SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == sock)
		{
			CELLLog::Info("error, create socket failed...\n");
		}
		else {
			CELLLog::Info("bind port<%d> success...\n", (int)_pClient->sockfd());
			_pClient = new CELLClient(sock);
		}
	}

	//���ӷ�����
	int Connect(const char* ip, unsigned short port)
	{
		if (_pClient == nullptr)
		{
			InitSocket();
		}
		// 2 ���ӷ����� connect
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port);
#ifdef _WIN32
		_sin.sin_addr.S_un.S_addr = inet_addr(ip);
#else
		_sin.sin_addr.s_addr = inet_addr(ip);
#endif
		// CELLLog::Info("<socket=%d>connecting <%s:%d>...\n", (int)_pClient->sockfd(), ip, port);
		int ret = connect(_pClient->sockfd(), (sockaddr*)&_sin, sizeof(sockaddr_in));
		if (SOCKET_ERROR == ret)
		{
			CELLLog::Info("<socket=%d>connect <%s:%d>failed...\n", (int)_pClient->sockfd(), ip, port);
		}
		else {
			_isConnect = true;
			// CELLLog::Info("<socket=%d>connect <%s:%d>success...\n", (int)_pClient->sockfd(), ip, port);
		}
		return ret;
	}

	//�ر��׽���closesocket
	void Close()
	{
		if (_pClient)
		{
			delete _pClient;
			_pClient = nullptr;
		}
		_isConnect = false;
	}

	//����������Ϣ
	bool OnRun()
	{
		if (isRun())
		{
			SOCKET _sock = _pClient->sockfd();

			fd_set fdReads;
			FD_ZERO(&fdReads);
			FD_SET(_sock, &fdReads);
			fd_set fdWrite;
			FD_ZERO(&fdWrite);

			timeval t = { 0,1 };
			int ret = 0;
			if (_pClient->needWrite())
			{
				FD_SET(_sock, &fdWrite);
				ret = select(_sock + 1, &fdReads, &fdWrite, nullptr, &t);
			}
			else
			{
				ret = select(_sock + 1, &fdReads, nullptr, nullptr, &t);
			}

			
			if (ret < 0)
			{
				CELLLog::Info("<socket=%d>OnRun.select exit\n", _sock);
				Close();
				return false;
			}

			if (FD_ISSET(_sock, &fdReads))
			{
				if (-1 == RecvData())
				{
					CELLLog::Info("<socket=%d>OnRun.select RecvData exit\n", _sock);
					Close();
					return false;
				}
			}

			if (FD_ISSET(_sock, &fdWrite))
			{
				if (-1 == _pClient->SendDataReal())
				{
					CELLLog::Info("<socket=%d>OnRun.select SendDataReal exit\n", _sock);
					Close();
					return false;
				}
			}

			return true;
		}
		return false;
	}

	//�Ƿ�����
	bool isRun()
	{
		return _pClient && _isConnect;
	}


	//�������� ����ճ�� ��ְ�
	int RecvData()
	{
		//���տͻ�������
		int nLen = _pClient->RecvData();
		if (nLen > 0)
		{
			//ѭ�� �ж��Ƿ�����Ϣ��Ҫ����
			while (_pClient->hasMsg())
			{
				//����������Ϣ
				OnNetMsg(_pClient->front_msg());
				//�Ƴ���Ϣ���У�����������ǰ��һ������
				_pClient->pop_front_msg();
			}
		}

		return 0;
	}

	//��Ӧ������Ϣ
	virtual void OnNetMsg(netmsg_DataHeader* header) = 0;

	//��������
	int SendData(netmsg_DataHeader* header)
	{
		return _pClient->SendData(header);
	}
private:
	CELLClient* _pClient = nullptr;
	bool _isConnect = false;
};

#endif