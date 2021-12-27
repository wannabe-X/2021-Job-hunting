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
			printf("�˳�cmdThread�߳�\n");
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
			printf("��֧�ֵ����\n");
		}
	}
}

class MyServer: public EasyTcpServer
{
public:
	// ֻ�ᱻһ���̵߳���
	virtual void OnNetJoin(ClientSocketPtr& pClient)
	{
		EasyTcpServer::OnNetJoin(pClient);
	}

	// cellSertver 4���߳� ����̴߳��� ����ȫ
	virtual void OnNetLeave(ClientSocketPtr& pClient)
	{
		EasyTcpServer::OnNetLeave(pClient);
	}

	// cellSertver 4���߳� ����̴߳��� ����ȫ
	virtual void OnNetMsg(CellServer *pCellServer, ClientSocketPtr& pClient, DataHeader* header)
	{
		// �������Ӽ� _msgCount++;
		EasyTcpServer::OnNetMsg(pCellServer, pClient, header);
		// ������Ϣ
		switch (header->cmd)
		{
		case CMD_LOGIN:
		{
			Login* login = (Login*)header;
			//printf("�յ��ͻ���<Socket=%d>����CMD_LOGIN,���ݳ��ȣ�%d,userName=%s PassWord=%s\n", pClient->sockfd(), login->dataLength, login->userName, login->PassWord);
			//�����ж��û������Ƿ���ȷ�Ĺ���
			//LoginResult ret;
			//pClient->SendData(ret);
			LoginResult* ret = new LoginResult();
			pCellServer->addSendTask(pClient, ret);

		}// ���� ��Ϣ---���� ���� ������ ���ݻ����� �����ߣ�������������ģʽ��
		break;
		case CMD_LOGOUT:
		{
			Logout* logout = (Logout*)header;
			//printf("�յ��ͻ���<Socket=%d>����CMD_LOGOUT,���ݳ��ȣ�%d,userName=%s \n", cSock, logout->dataLength, logout->userName);
			//�����ж��û������Ƿ���ȷ�Ĺ���
			//LogoutResult ret;
			//SendData(cSock, &ret);
		}
		break;
		default:
		{
			printf("<socket=%d>�յ�δ������Ϣ,���ݳ��ȣ�%d\n", pClient->sockfd(), header->dataLength);
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
	server.InitSocket(); // ��ʼ����Ϊ�������˽���һ��socket
	server.Bind(nullptr, 4567); // ��ɰ󶨣���������ip�Ͷ˿ںŰ�
	server.Listen(5); // ��������Ҫ�ǽ��������˵�socket��Ϊ����״̬������ʹ�����Ŀͻ�������
	server.Start(4); // �������߳� ��ɶ���Ϣ�Ĵ���
	//����UI�߳�
	std::thread t1(cmdThread);
	t1.detach();

	while (g_bRun)
	{
		// �������߳�
		server.OnRun();
		//printf("����ʱ�䴦������ҵ��..\n");
	}

	server.Close();
	printf("���˳���\n");
	getchar();
	return 0;
}