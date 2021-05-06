#ifndef BANK_H_
#define BANK_H_

// 多态：方法的功能取决于调用该方法的对象。
// 有两种方法可以实现多态共有继承：
// 1.在派生类之中重新定义基类的方法
// 2. 使用虚方法

#include <string>
using namespace std;

class Brass
{
private:
private:
    string m_name;          // 用户名
    string m_accountNumber; // 账号
    double m_balance;       // 银行余额

public:
    // 构造函数用来创建账户 使用默认参数减少重载函数声明
    Brass(const string &name = "NULL", const string &accnum = "-1", double banlance = 0.0);
    // 存款
    void deposit(double money);
    // 取款
    virtual void withdraw(double money);
    // 得到余额
    double getBalance() const;
    // 查看账户信息
    virtual void viewAcct() const;
    // 析构函数，用来销毁对象
    virtual ~Brass(){};
};

class BrassPlus : public Brass
{
private:
    double maxLoan;  // 透支上限
    double rate;     // 透支利率
    double owesBank; // 当前透支总额
public:
    // 初始化赋值
    BrassPlus(const string &name = "NULL", const string &accnum = "-1", double balance = 0.0, double ml = 500, double r = 0.111125);
    BrassPlus(Brass &br, double ml = 500, double r = 0.111125);

    // 需要重写的函数都使用虚函数
    virtual void withdraw(double money);
    virtual void viewAcct() const;

    void resetMax(double m)
    {
        maxLoan = m;
    }

    void resetRate(double r)
    {
        rate = r;
    }

    void resetowes()
    {
        owesBank = 0.0;
    }
};

#endif