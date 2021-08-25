/*
 * @Description: 依赖倒转原则
 * @Author: Mr. Lee
 * @Date: 2021-08-18 21:07:49
 * @LastEditTime: 2021-08-18 21:27:09
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// class BankWorker
// {
// public:
//     void saveService()
//     {
//         cout << "办理存款业务。" << endl;
//     }

//     void payService()
//     {
//         cout << "办理支付业务。" << endl;
//     }

//     void transferService()
//     {
//         cout << "办理转账业务。" << endl;
//     }
// };

// // 中层模块
// void doSaveBussiness(BankWorker *worker)
// {
//     worker->saveService();
// }

// void doPayBussiness(BankWorker *worker)
// {
//     worker->payService();
// }

// void doTransferBussiness(BankWorker *worker)
// {
//     worker->transferService();
// }

// // 业务逻辑
// void test01()
// {
//     BankWorker *worker = new BankWorker();
//     doSaveBussiness(worker); // 办理存款业务
//     doPayBussiness(worker);
//     doTransferBussiness(worker);

//     delete worker;
//     worker = nullptr;
// }

// 单一职责
class AbstractWorker
{
public:
    virtual void doBussiness() = 0;
};

// 拆分单一职责
// 专门负责办理存款业务的工作人员
class SaveBankWorker : public AbstractWorker
{
public:
    virtual void doBussiness()
    {
        cout << "办理存款业务。" << endl;
    }
};

// 专门负责办理支付业务的工作人员
class PayBankWorker : public AbstractWorker
{
public:
    virtual void doBussiness()
    {
        cout << "办理支付业务。" << endl;
    }
};

// 专门负责办理存款业务的工作人员
class TransferBankWorker : public AbstractWorker
{
public:
    virtual void doBussiness()
    {
        cout << "办理转账业务。" << endl;
    }
};

// 中层业务
// 依赖于抽象类，而不是依赖具体的实现，具有可扩展性
void doNewBussiness(AbstractWorker *worker)
{
    worker->doBussiness(); // 多态
    delete worker;
}

void test02()
{
    doNewBussiness(new TransferBankWorker());
    doNewBussiness(new SaveBankWorker());
    doNewBussiness(new PayBankWorker());
}

int main()
{
    test02();
    return 0;
}
