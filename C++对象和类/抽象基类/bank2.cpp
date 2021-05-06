#include "bank2.h"
#include <string>
#include <iostream>
using namespace std;

//实现抽象基类中可以实现的构造函数和其他函数
AcctABC::AcctABC(const string &name, const string &ID, double balance)
{
    m_name = name;
    m_ID = ID;
    m_balance = balance;
}

void AcctABC::deposit(double money)
{
    if (money < 0)
        cout << "money can't be a negetive number!!!" << endl;
    else
    {
        m_balance += money;
        cout << "deposit DONE !!!!!!" << endl;
    }
}

void AcctABC::withdraw(double money)
{
    m_balance -= money;
}

//实现Brass类以及其中的虚函数
Brass::Brass(const string &name, const string &ID, double balance) : AcctABC(name, ID, balance)
{
}

void Brass::withdraw(double money)
{
    if (money < 0)
        cout << "money can't be a negetive number!!!" << endl;
    else if (money <= getBalance())
    {
        AcctABC::withdraw(money);
        cout << "withsraw DONE!!!!!" << endl;
    }
    else
        cout << "no enough money to withdraw" << endl;
}

void Brass::showIofo() const
{
    cout << "Infomation:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID" << getID() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "----------end---------" << endl
         << endl;
}

//实现Brassplus类 以及其中的虚函数。
BrassPlus::BrassPlus(const string &name, const string &ID, double balance, double maxLoan, double rate) : AcctABC(name, ID, balance)
{
    m_maxLoan = maxLoan;
    m_rate = rate;
    m_owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &br, double maxLoan, double rate) : AcctABC(br)
{
    m_maxLoan = maxLoan;
    m_rate = rate;
    m_owesBank = 0.0;
}

void BrassPlus::withdraw(double money)
{
    if (money < 0)
        cout << "money can't be a negetive number!!!" << endl;
    else if (money <= getBalance())
    {
        AcctABC::withdraw(money);
        cout << "withsraw DONE!!!!!" << endl;
    }
    else
    {
        cout << "other method to shutdown!!!" << endl;
    }
}

void BrassPlus::showIofo() const
{
    cout << "Infomation:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "ID" << getID() << endl;
    cout << "Balance: " << getBalance() << endl;
    cout << "MaxLoan: " << m_maxLoan << endl;
    cout << "Rate: " << m_rate << endl;
    cout << "OwesBank: " << m_owesBank << endl;
    cout << "----------end---------" << endl
         << endl;
}