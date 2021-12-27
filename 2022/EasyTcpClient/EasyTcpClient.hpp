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
	// 成员变量
	// 客户端的socket
	SOCKET _sock;
	// 是否处于连接状态
	bool _isConnect;
public:
	// 构造函数
	EasyTcpClient()
	{
		_sock = INVALID_SOCKET;
		_isConnect = false;
	}

	// 析构函数 虚析构
	virtual ~EasyTcpClient()
	{
		Close();
	}

	//初始化socket 为每个客户端建立一个socket
	void InitSocket()
	{
#ifdef _WIN32
		//启动Windows socket 2.x环境
		WORD ver = MAKEWORD(2, 2);
		WSADATA dat;
		WSAStartup(ver, &dat);
#endif
		if (INVALID_SOCKET != _sock)
		{
			printf("<socket=%d>关闭旧连接...\n", _sock);
			Close();
		}

		// 建立一个套接字 使用ipv4传输，基于流模式，使用TCP传输
		_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (INVALID_SOCKET == _sock)
		{
			printf("错误，建立Socket失败...\n");
		}
		else {
			//printf("建立Socket成功...\n");
		}
	}

	//连接服务器
	int Connect(const char* ip, unsigned short port)
	{
		if (INVALID_SOCKET == _sock)
		{
			InitSocket(); // 创建一个套接字
		}
		// 2 连接服务器 connect
		// 指定服务器的ip和端口号，绑定到结构体_sin中，然后使用connect与服务器建立连接
		sockaddr_in _sin = {};
		_sin.sin_family = AF_INET;
		_sin.sin_port = htons(port);
#ifdef _WIN32
		_sin.sin_addr.S_un.S_addr = inet_addr(ip);
#else
		_sin.sin_addr.s_addr = inet_addr(ip);
#endif
		/*
		* connect 函数
			第一个参数是客户端的套接字（表明即将发起连接请求）
			第二个参数是服务端的套接字所在的“地方”（“地方”是我自定义的专有名词）
			第三个参数是该“地方”的大小。

			如果请求连接成功，则返回0，否则返回错误码。
		*/
		int ret = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
		if (SOCKET_ERROR == ret)
		{
			printf("错误，连接服务器失败...\n");
		}
		else {
			// 连接建立成功
			_isConnect = true;
			//printf("连接服务器成功...\n");
		}
		return ret;
	}

	//关闭套节字closesocket
	void Close()
	{
		if (_sock != INVALID_SOCKET)
		{
#ifdef _WIN32
			closesocket(_sock);
			//清除Windows socket环境
			WSACleanup();
#else
			close(_sock);
#endif
			_sock = INVALID_SOCKET;
		}

		_isConnect = false;
	}

	int _nCount = 0;
	// 处理网络消息 使用select方法判断当前客户端的缓冲区内是否发生了变化
	// 若发生了变化，则提取缓冲区内的内容 recv
	bool OnRun()
	{
		if (isRun()) // 只要套接字的状态不是INVALID_SOCKET 就表示该套接字工作正常
		{
			fd_set fdReads;
			FD_ZERO(&fdReads); // 将套接字集合清空
			FD_SET(_sock, &fdReads); // 将套接字加入到集合中
			timeval t = { 0,0 }; // 设置非阻塞
			int ret = select(_sock + 1, &fdReads, 0, 0, &t); // select模型
			_nCount++;
			//printf("select ret = %d, count = %d\n", ret, _nCount);
			if (ret < 0)
			{
				printf("<socket=%d>select任务结束1\n", _sock);
				return false;
			}
			if (FD_ISSET(_sock, &fdReads)) // 判断套接字是否在集合中
			{
				FD_CLR(_sock, &fdReads); // 用于在文件描述符集合中删除一个文件描述符

				if (-1 == RecvData(_sock))
				{
					printf("<socket=%d>select任务结束2\n", _sock);
					return false;
				}
			}
			return true;
		}
		return false;
	}

	// 是否工作中
	bool isRun()
	{
		// socket有效的连接
		return _sock != INVALID_SOCKET && _isConnect;
	}

	// 缓冲区最小单元大小
#define RECV_BUFF_SIZE 10240
	//接收缓冲区
	//char szRecv[RECV_BUFF_SIZE] = {}; // 双缓冲
	// 第二缓冲区
	char _szMsgBuf[RECV_BUFF_SIZE * 5] = {};
	// 消息缓冲区数据尾部位置
	int _lastPos = 0;
	//接收数据 处理粘包 拆分包
	int RecvData(SOCKET _cSock)
	{
		// 5 接收客户端数据
		char* szRecv = _szMsgBuf + _lastPos;
		/*
			* 功能：在已建立连接的套接字上接收数据。
			格式：int recv(SOCKET s, char *buf, int len, int flags)。
			参数：s-已建立连接的套接字；buf-存放接收到的数据的缓冲区指针；len-buf的长度；flags-调用方式：
			（1）0：接收的是正常数据，无特殊行为。
			（2）MSG_PEEK：系统缓冲区数据复制到提供的接收缓冲区，但是系统缓冲区内容并没有删除。
			（3）MSG_OOB：表示处理带外数据。
			返回值：接收成功时返回接收到的数据长度，连接结束时返回0，连接失败时返回SOCKET_ERROR。
		*/
		int nLen = (int)recv(_cSock, szRecv, RECV_BUFF_SIZE * 5 - _lastPos, 0);
		if (nLen <= 0)
		{
			printf("与服务器断开连接，任务结束。\n");
			return -1;
		}

		// 将收取的数据拷贝到消息缓冲区
		memcpy(_szMsgBuf + _lastPos, szRecv, nLen);
		// 消息缓冲区的数据尾部位置后移
		_lastPos += nLen;
		// 判断消息缓冲区的数据是否长度大于消息头的长度
		// 此时就可以知道当前消息体的长度
		// 消息一条一条的去处理
		while (_lastPos >= sizeof(DataHeader))
		{
			// 取出消息头
			DataHeader* header = (DataHeader*)_szMsgBuf;
			// 判断缓冲区的数据长度是否大于一条消息长度
			if (_lastPos >= header->dataLength)
			{
				// 剩余未处理消息缓冲区数据的长度
				int nSize = _lastPos - header->dataLength;
				// 处理网络消息
				OnNetMsg(header);
				// 将消息缓冲区的数据尾部未处理数据前移
				memcpy(_szMsgBuf, _szMsgBuf + header->dataLength, nSize);
				// 消息缓冲区的数据尾部前移
				_lastPos = nSize;
			}
			else
			{
				// 剩余消息不足 剩余数据不够一条完整消息
				break;
			}
		}

		// printf("nLen = %d\n", nLen);
		/*
		DataHeader* header = (DataHeader*)szRecv;
		if (nLen <= 0)
		{
			printf("与服务器断开连接，任务结束。\n");
			return -1;
		}
		recv(_cSock, szRecv + sizeof(DataHeader), header->dataLength - sizeof(DataHeader), 0);

		OnNetMsg(header);
		*/

		return 0;
	}

	//响应网络消息
	void OnNetMsg(DataHeader* header)
	{
		switch (header->cmd)
		{
		case CMD_LOGIN_RESULT:
		{
			//  指针强制转换仅仅是将地址后的内容按照不同的类型进行变量解释和读取。
			LoginResult* login = (LoginResult*)header;
			// printf("<socket = %d>收到服务端消息：CMD_LOGIN_RESULT,数据长度：%d\n", _sock,login->dataLength);
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
			printf("<socket = %d>收到服务端消息：CMD_ERROR,数据长度：%d\n", _sock, userJoin->dataLength);
		}
		break;
		default:
		{
			printf("<socket = %d>收到服务端未知消息\n", _sock);
		}

		}
	}

	//发送数据
	// 多态 DataHeader* header 父类指针指向派生类的对象
	int SendData(DataHeader* header, int nLen)
	{
		int ret = SOCKET_ERROR;
		if (isRun() && header)
		{
			/*
			* send()用来将数据由指定的socket 传给对方主机. 参数s 为已建立好连接的socket.
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