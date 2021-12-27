#ifndef _CellClient_hpp_
#define _CellClient_hpp_

#include"CELL.hpp"

// 客户端心跳检测死亡计时时间
#define CLIENT_HEART_DEAD_TIME 60000
// 在间隔指定时间后将发送缓冲区缓存的数据发送给客户端
#define CLIENT_SEND_DEAD_BUFF_TIME 200

//客户端数据类型
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

	// 立即发送数据
	int SendDataReal(netmsg_DataHeader* header)
	{
		SendData(header);
		SendDataReal();
	}

	int SendDataReal()
	{
		int ret = SOCKET_ERROR;
		// 确保缓冲区里面有数据
		if (_lastSendPos > 0 && SOCKET_ERROR != _sockfd)
		{
			// 发送数据
			ret = send(_sockfd, _szSendBuf, _lastSendPos, 0);
			// 尾部数据清零
			_lastSendPos = 0;
			resetDTSend();
		}

		return ret;
	}

	//发送数据
	int SendData(netmsg_DataHeader* header)
	{
		int ret = SOCKET_ERROR;
		//要发送的数据长度
		int nSendLen = header->dataLength;
		//要发送的数据
		const char* pSendData = (const char*)header;

		while (true)
		{
			if (_lastSendPos + nSendLen >= SEND_BUFF_SZIE)
			{
				//计算可拷贝的数据长度
				int nCopyLen = SEND_BUFF_SZIE - _lastSendPos;
				//拷贝数据
				memcpy(_szSendBuf + _lastSendPos, pSendData, nCopyLen);
				//计算剩余数据位置
				pSendData += nCopyLen;
				//计算剩余数据长度
				nSendLen -= nCopyLen;
				//发送数据
				ret = send(_sockfd, _szSendBuf, SEND_BUFF_SZIE, 0);
				//数据尾部位置清零
				_lastSendPos = 0;
				// 重置计时
				resetDTSend();
				//发送错误
				if (SOCKET_ERROR == ret)
				{
					return ret;
				}
			}
			else {
				//将要发送的数据 拷贝到发送缓冲区尾部
				memcpy(_szSendBuf + _lastSendPos, pSendData, nSendLen);
				//计算数据尾部位置
				_lastSendPos += nSendLen;
				break;
			}
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

	// 心跳检测
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

	// 定时发送消息检测
	void checkSend(time_t dt)
	{
		_dtSend += dt;
		if (_dtSend >= CLIENT_SEND_DEAD_BUFF_TIME)
		{
			//printf("checkSend socket: %d, time = %d\n", _sockfd, _dtSend);
			// 时间到了立即发送数据
			SendDataReal();
			// 重置发送计时
			resetDTSend();
		}
	}

private:
	// socket fd_set  file desc set
	SOCKET _sockfd;
	//第二缓冲区 消息缓冲区
	char _szMsgBuf[RECV_BUFF_SZIE];
	//消息缓冲区的数据尾部位置
	int _lastPos;

	//第二缓冲区 发送缓冲区
	char _szSendBuf[SEND_BUFF_SZIE];
	//发送缓冲区的数据尾部位置
	int _lastSendPos;
	// 心跳检测 死亡计时
	time_t _dtHeart;
	// 上次发送消息的时间
	time_t _dtSend;
};

#endif // !_CellClient_hpp_



