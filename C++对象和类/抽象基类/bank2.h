#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <string>
using namespace std;

//含有纯虚函数，是一个抽象基类
class AcctABC
{
private:
    string m_name;
    string m_ID;
    double m_balance;

protected:
    const string &getName() const
    {
        return m_name;
    }
    const string &getID() const
    {
        return m_ID;
    }
    double getBalance() const
    {
        return m_balance;
    }

public:
    //构造函数
    AcctABC(const string &name = "No Name",
            const string &ID = "-1", double balance = 0.0);

    //存款
    void deposit(double money);

    //取款(纯虚函数)
    virtual void withdraw(double money) = 0;
    //显示信息（纯虚函数）
    virtual void showIofo() const = 0;

    //内联析构函数,别忘记了带上实现。。。。
    virtual ~AcctABC()
    {
    }
};

class Brass : public AcctABC
{
public:
    Brass(const string &name = "NoName", const string &ID = "-1", double balance = 0.0);

    //取款(重写纯虚函数),这里就不要加=0了
    virtual void withdraw(double money);
    //显示信息（重写纯虚函数）
    virtual void showIofo() const;

    virtual ~Brass()
    {
    }
};

class BrassPlus : public AcctABC
{
private:
    double m_maxLoan;
    double m_rate;
    double m_owesBank;

public:
    BrassPlus(const string &name = "NoName", const string &ID = "-1", double balance = 0.0, double maxLoan = 500, double rate = 0.1);
    BrassPlus(const Brass &br, double maxLoan = 500, double rate = 0.1);
    //取款(纯虚函数)
    virtual void withdraw(double money);
    //显示信息（纯虚函数）
    virtual void showIofo() const;
    void resetMax(double max)
    {
        m_maxLoan = max;
    }
    void resetRate(double rate)
    {
        m_rate = rate;
    }
    void resetOwes()
    {
        m_owesBank = 0.0;
    }
};
#endif