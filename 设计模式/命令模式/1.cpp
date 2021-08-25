/*
 * @Description: 命令模式
 * @Author: Mr. Lee
 * @Date: 2021-08-22 10:02:15
 * @LastEditTime: 2021-08-22 11:59:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>

using namespace std;

class HandleClientProcotol
{
public:
    // 处理增加金币
    void AddMoney()
    {
        cout << "给玩家增加金币..." << endl;
    }

    // 处理增加钻石
    void AddDiamond()
    {
        cout << "给玩家增加钻石..." << endl;
    }

    // 处理玩家装备
    void AddEquipment()
    {
        cout << "给玩家增加装备..." << endl;
    }

    // 处理玩家装备
    void AddLevel()
    {
        cout << "给玩家升级等级..." << endl;
    }
};

// 把命令封装成请求
// 协议命令接口
class AbstractCommand
{
public:
    // 处理客户端请求的接口
    virtual void handle() = 0;
};

// 增加金币的请求
class AddMoenyCommand : public AbstractCommand
{
public:
    AddMoenyCommand(HandleClientProcotol *pProtocol)
    {
        this->pProtocol = pProtocol;
    }

    virtual void handle()
    {
        this->pProtocol->AddMoney();
    }

public:
    HandleClientProcotol *pProtocol;
};

// 增加钻石的请求
class AddDiamondCommand : public AbstractCommand
{
public:
    AddDiamondCommand(HandleClientProcotol *pProtocol)
    {
        this->pProtocol = pProtocol;
    }

    virtual void handle()
    {
        this->pProtocol->AddDiamond();
    }

public:
    HandleClientProcotol *pProtocol;
};

// 增加装备的请求
class AddEquipmentCommand : public AbstractCommand
{
public:
    AddEquipmentCommand(HandleClientProcotol *pProtocol)
    {
        this->pProtocol = pProtocol;
    }

    virtual void handle()
    {
        this->pProtocol->AddEquipment();
    }

public:
    HandleClientProcotol *pProtocol;
};

// 处理玩家升级的请求
class AddLevelCommand : public AbstractCommand
{
public:
    AddLevelCommand(HandleClientProcotol *pProtocol)
    {
        this->pProtocol = pProtocol;
    }

    virtual void handle()
    {
        this->pProtocol->AddLevel();
    }

public:
    HandleClientProcotol *pProtocol;
};

// 服务器程序
class Server
{
public:
    void Addrequest(AbstractCommand *command)
    {
        mCommands.push(command);
    }

    void startHandle()
    {
        while (!mCommands.empty())
        {
            Sleep(1000);
            AbstractCommand *commandTmp = mCommands.front();
            commandTmp->handle();
            mCommands.pop();
        }
    }

public:
    queue<AbstractCommand *> mCommands;
};

void test01()
{
    HandleClientProcotol *protocol = new HandleClientProcotol();
    // 增加金币的请求
    AbstractCommand *addmoney = new AddMoenyCommand(protocol);
    // 增加钻石的请求
    AbstractCommand *adddiamond = new AddDiamondCommand(protocol);
    // 增加装备的请求
    AbstractCommand *addequiment = new AddEquipmentCommand(protocol);
    // 提升等级的请求
    AbstractCommand *addlevel = new AddLevelCommand(protocol);

    Server *server = new Server();
    // 添加到请求队列中，先到先处理
    server->Addrequest(addmoney);
    server->Addrequest(adddiamond);
    server->Addrequest(addequiment);
    server->Addrequest(addlevel);

    // 服务器开始处理请求
    server->startHandle();

    delete addlevel;
    delete addequiment;
    delete adddiamond;
    delete addmoney;
    delete server;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
