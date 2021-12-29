#ifndef _CellClient_hpp_
#define _CellClient_hpp_

#include"CELL.hpp"

// �ͻ����������������ʱʱ��
#define CLIENT_HEART_DEAD_TIME 60000
// �ڼ��ָ��ʱ��󽫷��ͻ�������������ݷ��͸��ͻ���
#define CLIENT_SEND_DEAD_BUFF_TIME 200

//�ͻ�����������
class CellClient
{
public:
	int id = -1;
	int serverId = -1;
public:
	CellClient(SOCKET sockfd = INVALID_SOCKET)
	{
		static int n = 1;
		id = n++;
		_sockfd = sockfd;
		memset(_szMsgBuf, 0, RECV_BUFF_SZIE);
		_lastPos = 0;

		memset(_szSendBuf, 0, SEND_BUFF_SZIE);
		_lastSendPos = 0;

		resetDTHeart();
		resetDTSend();
	}

	~CellClient()
	{
		printf("s=%d, CellClient<%d>.~CellClient 1\n", serverId, id);
		if (_sockfd != INVALID_SOCKET)
		{
#ifdef _WIN32
			closesocket(_sockfd);
#else
			close(_sockfd);
#endif // _WIN32
			_sockfd = INVALID_SOCKET;
		}
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

	int SendDataReal()
	{
		int ret = -1;
		// ȷ������������������
		if (_lastSendPos > 0 && INVALID_SOCKET != _sockfd)
		{
			// ��������
			ret = send(_sockfd, _szSendBuf, _lastSendPos, 0);
			// β����������
			_lastSendPos = 0;
			_sentBuffFullCount = 0;
			resetDTSend();
		}

		return ret;
	}

	// �������Ŀ��Ƹ���ҵ������Ĳ�����仯����
	
	//��������
	int SendData(netmsg_DataHeader* header)
	{
		int ret = SOCKET_ERROR;
		//Ҫ���͵����ݳ���
		int nSendLen = header->dataLength;
		//Ҫ���͵�����
		const char* pSendData = (const char*)header;

		if (_lastSendPos + nSendLen <= SEND_BUFF_SZIE)
		{
			//��Ҫ���͵����� ���������ͻ�����β��
			memcpy(_szSendBuf + _lastSendPos, pSendData, nSendLen);
			//��������β��λ��
			_lastSendPos += nSendLen;
			if (_lastSendPos >= SEND_BUFF_SZIE)
			{
				_sentBuffFullCount++;
			}

			return nSendLen;
		}
		else
		{
			_sentBuffFullCount++;
		}

		return ret;
	}

	void resetDTHeart()
	{
		_dtHeart = 0;
	}

	void resetDTSend()
	{
		_dtSend = 0;
	}

	// �������
	bool checkHeart(time_t dt)
	{
		_dtHeart += dt;
		if (_dtHeart >= CLIENT_HEART_DEAD_TIME)
		{
			printf("checkHeart dead: %d, time = %d\n", _sockfd, _dtHeart);
			return true;
		}

		return false;
	}

	// ��ʱ������Ϣ���
	void checkSend(time_t dt)
	{
		_dtSend += dt;
		if (_dtSend >= CLIENT_SEND_DEAD_BUFF_TIME)
		{
			//printf("checkSend socket: %d, time = %d\n", _sockfd, _dtSend);
			// ʱ�䵽��������������
			SendDataReal();
			// ���÷��ͼ�ʱ
			resetDTSend();
		}
	}

private:
	// socket fd_set  file desc set
	SOCKET _sockfd;
	//�ڶ������� ��Ϣ������
	char _szMsgBuf[RECV_BUFF_SZIE];
	//��Ϣ������������β��λ��
	int _lastPos;

	//�ڶ������� ���ͻ�����
	char _szSendBuf[SEND_BUFF_SZIE];
	//���ͻ�����������β��λ��
	int _lastSendPos;
	// ������� ������ʱ
	time_t _dtHeart;
	// �ϴη�����Ϣ��ʱ��
	time_t _dtSend;
	// ���ͻ�����д���Ĵ���
	int _sentBuffFullCount = 0;
};

#endif // !_CellClient_hpp_



