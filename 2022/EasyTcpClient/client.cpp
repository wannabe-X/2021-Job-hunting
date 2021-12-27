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
			printf("�˳�cmdThread�߳�\n");
			break;
		}
		else 
		{
			printf("��֧�ֵ����\n");
		}
	}
}

// �����ͻ��˵�����
const int cCount = 1000;
// �����̵߳�����
const int tCount = 4;
// �����ͻ�������
EasyTcpClient* client[cCount];
std::atomic_int sendCount = 0;
std::atomic_int readyCount = 0;

void sendThread(int id)
{
	printf("thread<%d>, start\n", id);
	// 4���߳� ID 1~4 ÿ���̸߳���250���ͻ��˵���Ϣ����
	int c = (cCount / tCount);
	/*
		1. 0-249
		2.250-499
		3.500-749
		4.750-999
	*/
	int begin = (id - 1) * c, end = id * c;
	// ջ�ڴ�
	// �����ͻ��˶��� ��Ҫ�ǳ�ʼ�� ÿ���ͻ��˻��һ��socket
	for (int i = begin; i < end; i++)
	{
		if (!g_bRun)
		{
			return;
		}
		client[i] = new EasyTcpClient();

	}

	// ÿ���ͻ���ȥ���ӷ�����
	for (int i = begin; i < end; i++)
	{
		if (!g_bRun)
		{
			return;
		}
		// �ͻ���ȥ���ӷ������� ���connect����
		client[i]->Connect("127.0.0.1", 4567);
	}

	printf("thread<%d>,Conncet<begin = %d, end = %d> \n", id, begin, end);
	
	readyCount++;
	while (readyCount < tCount)
	{
		// �ȴ������߳�׼���÷�������
		std::chrono::milliseconds t(10);
		std::this_thread::sleep_for(t);
	}
	
	// ��װ�ͻ�����Ϣ ������Ϣ
	// ÿ���ͻ��˷���10����Ϣ
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
			// ÿ�η�����Ϣ��Ϊ1000�ֽ� 1Kb
			if (SOCKET_ERROR != client[i]->SendData(login, nLen))
			{
				sendCount++;
			}
			// ����������Ϣ �������Է������˵���Ϣ
			// OnRun������Ҫ����select���ͻ��˻������Ƿ�������д�룬Ȼ���ڶ�ȡ�����������ݣ�������ճ���������
			// ����������Ϣ����
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
	// ����UI�߳� ��Ҫ�������ǽ���exit����ͻ����˳�������Ϣ
	std::thread t1(cmdThread);
	t1.detach();

	//���������߳�
	for (int i = 0; i < tCount; i++)
	{
		std::thread t(sendThread, i + 1);
		t.detach(); // �̷߳���
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

	printf("���˳���\n");
	return 0;
}