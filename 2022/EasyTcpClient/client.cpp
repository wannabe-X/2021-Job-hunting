#include "EasyTcpClient.hpp"
#include "CELLTimestamp.hpp"
#include<thread>
#include<atomic>

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
			g_bRun = false;
			printf("退出cmdThread线程\n");
			break;
		}
		else 
		{
			printf("不支持的命令。\n");
		}
	}
}

// 创建客户端的数量
const int cCount = 1000;
// 创建线程的数量
const int tCount = 4;
// 创建客户端数组
EasyTcpClient* client[cCount];
std::atomic_int sendCount = 0;
std::atomic_int readyCount = 0;

void sendThread(int id)
{
	printf("thread<%d>, start\n", id);
	// 4个线程 ID 1~4 每个线程负责250个客户端的消息发送
	int c = (cCount / tCount);
	/*
		1. 0-249
		2.250-499
		3.500-749
		4.750-999
	*/
	int begin = (id - 1) * c, end = id * c;
	// 栈内存
	// 创建客户端对象 主要是初始化 每个客户端获得一个socket
	for (int i = begin; i < end; i++)
	{
		if (!g_bRun)
		{
			return;
		}
		client[i] = new EasyTcpClient();

	}

	// 每个客户端去连接服务器
	for (int i = begin; i < end; i++)
	{
		if (!g_bRun)
		{
			return;
		}
		// 客户端去连接服务器端 完成connect操作
		client[i]->Connect("127.0.0.1", 4567);
	}

	printf("thread<%d>,Conncet<begin = %d, end = %d> \n", id, begin, end);
	
	readyCount++;
	while (readyCount < tCount)
	{
		// 等待其他线程准备好发送数据
		std::chrono::milliseconds t(10);
		std::this_thread::sleep_for(t);
	}
	
	// 封装客户端消息 发送消息
	// 每个客户端发送10条消息
	const int n = 10;
	Login login[n];
	for (int i = 0; i < n; i++)
	{
		strcpy(login[i].userName, "lyd");
		strcpy(login[i].PassWord, "lydmm");
	}

	const int nLen = sizeof(login);

	//bool isSend = false;
	while (g_bRun)
	{
		for (int i = begin; i < end; i++)
		{
			// 每次发送消息的为1000字节 1Kb
			if (SOCKET_ERROR != client[i]->SendData(login, nLen))
			{
				sendCount++;
			}
			// 处理网络消息 接收来自服务器端的消息
			// OnRun里面主要利用select检测客户端缓冲区是否有内容写入，然后在读取缓冲区的数据，并进行粘包拆包处理
			// 进行网络消息处理
			client[i]->OnRun();
		}
	}

	for (int i = begin; i < end; i++)
	{
		client[i]->Close();
		delete client[i];
	}

	printf("thread<%d>, exit \n", id);
}

int main()
{
	// 启动UI线程 主要的作用是接收exit命令，客户端退出发送消息
	std::thread t1(cmdThread);
	t1.detach();

	//启动发送线程
	for (int i = 0; i < tCount; i++)
	{
		std::thread t(sendThread, i + 1);
		t.detach(); // 线程分离
	}

	CELLTimestamp tTime;
	while (g_bRun)
	{
		auto t = tTime.getElapsedSecond();
		if (t >= 1.0)
		{
			printf("thread<%d>,clients<%d>,time<%lf>,send<%d>\n", tCount, cCount, t, (int)sendCount);
			sendCount = 0;
			tTime.update();
		}
		Sleep(1);
	}

	printf("已退出。\n");
	return 0;
}