#include "EasyTcpServer.hpp"
#include<thread>
#include "Alloctor.h"

#define _CRT_SECURE_NO_WARNINGS

bool g_bRun = true;

void cmdThread()
{

	while (true)
	{
		char cmdBuf[256] = {};
		scanf_s("%s", cmdBuf);
		if (0 == strcmp(cmdBuf, "exit"))
		{
			printf("退出cmdThread线程\n");
			break;
		}
		//else if (0 == strcmp(cmdBuf, "login"))
		//{
		//	Login login;
		//	strcpy(login.userName, "lyd");
		//	strcpy(login.PassWord, "lydmm");
		//	client->SendData(&login);

		//}
		//else if (0 == strcmp(cmdBuf, "logout"))
		//{
		//	Logout logout;
		//	strcpy(logout.userName, "lyd");
		//	client->SendData(&logout);
		//}
		else 
		{
			printf("不支持的命令。\n");
		}
	}
}

class MyServer: public EasyTcpServer
{
public:
	// 只会被一个线程调用
	virtual void OnNetJoin(ClientSocketPtr& pClient)
	{
		EasyTcpServer::OnNetJoin(pClient);
	}

	// cellSertver 4个线程 多个线程触发 不安全
	virtual void OnNetLeave(ClientSocketPtr& pClient)
	{
		EasyTcpServer::OnNetLeave(pClient);
	}

	// cellSertver 4个线程 多个线程触发 不安全
	virtual void OnNetMsg(CellServer *pCellServer, ClientSocketPtr& pClient, DataHeader* header)
	{
		// 计数器加加 _msgCount++;
		EasyTcpServer::OnNetMsg(pCellServer, pClient, header);
		// 处理消息
		switch (header->cmd)
		{
		case CMD_LOGIN:
		{
			Login* login = (Login*)header;
			//printf("收到客户端<Socket=%d>请求：CMD_LOGIN,数据长度：%d,userName=%s PassWord=%s\n", pClient->sockfd(), login->dataLength, login->userName, login->PassWord);
			//忽略判断用户密码是否正确的过程
			//LoginResult ret;
			//pClient->SendData(ret);
			LoginResult* ret = new LoginResult();
			pCellServer->addSendTask(pClient, ret);

		}// 接收 消息---处理 发送 生产者 数据缓冲区 消费者（生产者消费者模式）
		break;
		case CMD_LOGOUT:
		{
			Logout* logout = (Logout*)header;
			//printf("收到客户端<Socket=%d>请求：CMD_LOGOUT,数据长度：%d,userName=%s \n", cSock, logout->dataLength, logout->userName);
			//忽略判断用户密码是否正确的过程
			//LogoutResult ret;
			//SendData(cSock, &ret);
		}
		break;
		default:
		{
			printf("<socket=%d>收到未定义消息,数据长度：%d\n", pClient->sockfd(), header->dataLength);
			//DataHeader ret;
			//SendData(cSock, &ret);
		}
		break;
		}
	}

private:

};

int main()
{

	MyServer server;
	server.InitSocket(); // 初始化，为服务器端建立一个socket
	server.Bind(nullptr, 4567); // 完成绑定，将本机的ip和端口号绑定
	server.Listen(5); // 监听，主要是将服务器端的socket变为被动状态，可以使其他的客户端连接
	server.Start(4); // 消费者线程 完成对消息的处理
	//启动UI线程
	std::thread t1(cmdThread);
	t1.detach();

	while (g_bRun)
	{
		// 生产者线程
		server.OnRun();
		//printf("空闲时间处理其它业务..\n");
	}

	server.Close();
	printf("已退出。\n");
	getchar();
	return 0;
}