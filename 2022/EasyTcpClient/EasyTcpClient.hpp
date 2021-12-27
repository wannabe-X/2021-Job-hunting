#ifndef _EasyTcpClient_hpp_
#define _EasyTcpClient_hpp_

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
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
#include <stdio.h>
#include "MessageHeader.hpp"

class EasyTcpClient
{
	// ��Ա����
	// �ͻ��˵�socket
	SOCKET _sock;
	// �Ƿ�������״̬
	bool _isConnect;
public:
	// ���캯��
	EasyTcpClient()
	{
		_sock = INVALID_SOCKET;
		_isConnect = false;
	}

	// �������� ������
	virtual ~EasyTcpClient()
	{
		Close();
	}

	//��ʼ��socket Ϊÿ���ͻ��˽���һ��socket
	void InitSocket()
	{
#ifdef _WIN32
		//����Windows socket 2.x����
		WORD ver = MAKEWORD(2, 2);
		WSADATA dat;
		WSAStartup(ver, &dat);
#endif
		if (INVALID_SOCKET != _sock)
		{
			printf("<socket=%d>�رվ�����...\n", _sock);
			Close();
		}

		// ����һ���׽��� ʹ��ipv4���䣬������ģʽ��ʹ��TCP����
		_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == _sock)
		{
			printf("���󣬽���Socketʧ��...\n");
		}
		else {
			//printf("����Socket�ɹ�...\n");
		}
	}

	//���ӷ�����
	int Connect(const char* ip, unsigned short port)
	{
		if (INVALID_SOCKET == _sock)
		{
			InitSocket(); // ����һ���׽���
		}
		// 2 ���ӷ����� connect
		// ָ����������ip�Ͷ˿ںţ��󶨵��ṹ��_sin�У�Ȼ��ʹ��connect���������������
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port);
#ifdef _WIN32
		_sin.sin_addr.S_un.S_addr = inet_addr(ip);
#else
		_sin.sin_addr.s_addr = inet_addr(ip);
#endif
		/*
		* connect ����
			��һ�������ǿͻ��˵��׽��֣���������������������
			�ڶ��������Ƿ���˵��׽������ڵġ��ط��������ط��������Զ����ר�����ʣ�
			�����������Ǹá��ط����Ĵ�С��

			����������ӳɹ����򷵻�0�����򷵻ش����롣
		*/
		int ret = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
		if (SOCKET_ERROR == ret)
		{
			printf("�������ӷ�����ʧ��...\n");
		}
		else {
			// ���ӽ����ɹ�
			_isConnect = true;
			//printf("���ӷ������ɹ�...\n");
		}
		return ret;
	}

	//�ر��׽���closesocket
	void Close()
	{
		if (_sock != INVALID_SOCKET)
		{
#ifdef _WIN32
			closesocket(_sock);
			//���Windows socket����
			WSACleanup();
#else
			close(_sock);
#endif
			_sock = INVALID_SOCKET;
		}

		_isConnect = false;
	}

	int _nCount = 0;
	// ����������Ϣ ʹ��select�����жϵ�ǰ�ͻ��˵Ļ��������Ƿ����˱仯
	// �������˱仯������ȡ�������ڵ����� recv
	bool OnRun()
	{
		if (isRun()) // ֻҪ�׽��ֵ�״̬����INVALID_SOCKET �ͱ�ʾ���׽��ֹ�������
		{
			fd_set fdReads;
			FD_ZERO(&fdReads); // ���׽��ּ������
			FD_SET(_sock, &fdReads); // ���׽��ּ��뵽������
			timeval t = { 0,0 }; // ���÷�����
			int ret = select(_sock + 1, &fdReads, 0, 0, &t); // selectģ��
			_nCount++;
			//printf("select ret = %d, count = %d\n", ret, _nCount);
			if (ret < 0)
			{
				printf("<socket=%d>select�������1\n", _sock);
				return false;
			}
			if (FD_ISSET(_sock, &fdReads)) // �ж��׽����Ƿ��ڼ�����
			{
				FD_CLR(_sock, &fdReads); // �������ļ�������������ɾ��һ���ļ�������

				if (-1 == RecvData(_sock))
				{
					printf("<socket=%d>select�������2\n", _sock);
					return false;
				}
			}
			return true;
		}
		return false;
	}

	// �Ƿ�����
	bool isRun()
	{
		// socket��Ч������
		return _sock != INVALID_SOCKET && _isConnect;
	}

	// ��������С��Ԫ��С
#define RECV_BUFF_SIZE 10240
	//���ջ�����
	//char szRecv[RECV_BUFF_SIZE] = {}; // ˫����
	// �ڶ�������
	char _szMsgBuf[RECV_BUFF_SIZE * 5] = {};
	// ��Ϣ����������β��λ��
	int _lastPos = 0;
	//�������� ����ճ�� ��ְ�
	int RecvData(SOCKET _cSock)
	{
		// 5 ���տͻ�������
		char* szRecv = _szMsgBuf + _lastPos;
		/*
			* ���ܣ����ѽ������ӵ��׽����Ͻ������ݡ�
			��ʽ��int recv(SOCKET s, char *buf, int len, int flags)��
			������s-�ѽ������ӵ��׽��֣�buf-��Ž��յ������ݵĻ�����ָ�룻len-buf�ĳ��ȣ�flags-���÷�ʽ��
			��1��0�����յ����������ݣ���������Ϊ��
			��2��MSG_PEEK��ϵͳ���������ݸ��Ƶ��ṩ�Ľ��ջ�����������ϵͳ���������ݲ�û��ɾ����
			��3��MSG_OOB����ʾ����������ݡ�
			����ֵ�����ճɹ�ʱ���ؽ��յ������ݳ��ȣ����ӽ���ʱ����0������ʧ��ʱ����SOCKET_ERROR��
		*/
		int nLen = (int)recv(_cSock, szRecv, RECV_BUFF_SIZE * 5 - _lastPos, 0);
		if (nLen <= 0)
		{
			printf("��������Ͽ����ӣ����������\n");
			return -1;
		}

		// ����ȡ�����ݿ�������Ϣ������
		memcpy(_szMsgBuf + _lastPos, szRecv, nLen);
		// ��Ϣ������������β��λ�ú���
		_lastPos += nLen;
		// �ж���Ϣ�������������Ƿ񳤶ȴ�����Ϣͷ�ĳ���
		// ��ʱ�Ϳ���֪����ǰ��Ϣ��ĳ���
		// ��Ϣһ��һ����ȥ����
		while (_lastPos >= sizeof(DataHeader))
		{
			// ȡ����Ϣͷ
			DataHeader* header = (DataHeader*)_szMsgBuf;
			// �жϻ����������ݳ����Ƿ����һ����Ϣ����
			if (_lastPos >= header->dataLength)
			{
				// ʣ��δ������Ϣ���������ݵĳ���
				int nSize = _lastPos - header->dataLength;
				// ����������Ϣ
				OnNetMsg(header);
				// ����Ϣ������������β��δ��������ǰ��
				memcpy(_szMsgBuf, _szMsgBuf + header->dataLength, nSize);
				// ��Ϣ������������β��ǰ��
				_lastPos = nSize;
			}
			else
			{
				// ʣ����Ϣ���� ʣ�����ݲ���һ��������Ϣ
				break;
			}
		}

		// printf("nLen = %d\n", nLen);
		/*
		DataHeader* header = (DataHeader*)szRecv;
		if (nLen <= 0)
		{
			printf("��������Ͽ����ӣ����������\n");
			return -1;
		}
		recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);

		OnNetMsg(header);
		*/

		return 0;
	}

	//��Ӧ������Ϣ
	void OnNetMsg(DataHeader* header)
	{
		switch (header->cmd)
		{
		case CMD_LOGIN_RESULT:
		{
			//  ָ��ǿ��ת�������ǽ���ַ������ݰ��ղ�ͬ�����ͽ��б������ͺͶ�ȡ��
			LoginResult* login = (LoginResult*)header;
			// printf("<socket = %d>�յ��������Ϣ��CMD_LOGIN_RESULT,���ݳ��ȣ�%d\n", _sock,login->dataLength);
		}
		break;
		case CMD_LOGOUT_RESULT:
		{
			LogoutResult* logout = (LogoutResult*)header;
		}
		break;
		case CMD_NEW_USER_JOIN:
		{
			NewUserJoin* userJoin = (NewUserJoin*)header;
		}
		break;
		case CMD_ERROR:
		{
			NewUserJoin* userJoin = (NewUserJoin*)header;
			printf("<socket = %d>�յ��������Ϣ��CMD_ERROR,���ݳ��ȣ�%d\n", _sock, userJoin->dataLength);
		}
		break;
		default:
		{
			printf("<socket = %d>�յ������δ֪��Ϣ\n", _sock);
		}

		}
	}

	//��������
	// ��̬ DataHeader* header ����ָ��ָ��������Ķ���
	int SendData(DataHeader* header, int nLen)
	{
		int ret = SOCKET_ERROR;
		if (isRun() && header)
		{
			/*
			* send()������������ָ����socket �����Է�����. ����s Ϊ�ѽ��������ӵ�socket.
			*/
			ret = send(_sock, (const char*)header, nLen, 0);
			if (ret == SOCKET_ERROR)
				Close();
		}
		return ret;
	}
private:

};

#endif