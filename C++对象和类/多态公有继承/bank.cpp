#include "bank.h"
#include <iostream>

using namespace std;

// 实现基类
// 构造函数
Brass::Brass(const string &name, const string &accnum, double balance)
{
    m_name = name;
    m_accountNumber = accnum;
    m_balance = balance;
}

// 存款
// 存款金额money大于0，则累加到余额m_banlance
void Brass::deposit(double money)
{
    if (money < 0)
    {
        cout << "the number should be positive!" << endl;
        cout << "the deposit has been canceled!" << endl;
    }
    else
    {
        m_balance += money;
        cout << "deposit successful!" << endl;
    }
}

// 取款
// 存款金额money大于等于0且小于余额m_balance，则从余额m_banlance中扣除
void Brass::withdraw(double money)
{
    // 取款金额小于0 输入有误
    if (money < 0)
    {
        cout << "the number should be positive!" << endl;
        cout << "the withdraw has been canceled!" << endl;
    }
    // 存款金额money大于等于0且小于余额m_balance，则从余额m_banlance中扣除
    else if (money <= m_balance)
    {
        m_balance -= money;
        cout << "withdraw successful!" << endl;
    }
    // 余额不足
    else
    {
        cout << "money you want to withdraw is exceed the balance!" << endl;
        cout << "the withdraw has been canceled!" << endl;
    }
}

// 获取余额
double Brass::getBalance() const
{
    return m_balance;
}

// 查看当前账户信息
void Brass::viewAcct() const
{
    cout << "Information:" << endl;
    cout << "Client:" << m_name << endl;
    cout << "Account Number:" << m_accountNumber << endl;
    cout << "Balance:" << m_balance << endl
         << endl;
}

// 实现派生类函数
BrassPlus::BrassPlus(const string &name, const string &accnum, double balance, double ml, double r) : Brass(name, accnum, balance)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(Brass &br, double ml, double r) : Brass(br)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// 重写函数
void BrassPlus::withdraw(double money)
{
    double ba = getBalance();
    if (money <= ba)
        Brass::withdraw(money);
    else if (money <= ba + maxLoan - owesBank)
    {
        double advance = money - ba;
        // 透支的钱是会产生利息的
        owesBank += advance * (1.0 + rate);
        cout << "advance:" << advance << endl;
        deposit(advance);
        Brass::withdraw(money);
    }
    else
    {
        cout << "Too big and canceled!" << endl;
    }
}

void BrassPlus::viewAcct() const
{
    Brass::viewAcct();
    cout << "new info:" << endl;
    cout << "maxLoan:" << maxLoan << endl;
    cout << "Reimbursement amount:" << owesBank << endl
         << endl;
}
