/*
 * @Description: 面向对象设计法则 - 开闭原则
 * @Author: Mr. Lee
 * @Date: 2021-08-18 20:01:40
 * @LastEditTime: 2021-08-18 20:18:05
 * @LastEditors: Mr. Lee
 */

// 开闭原则，对扩展开放，对修改关闭。增加功能是通过增加代码来实现的，而不是去修改源代码

#include <iostream>

using namespace std;

class AbstractCaculator
{
public:
    virtual int getResult() = 0; // 纯虚函数，相当于是接口
    virtual void setOperatorNumber(int a, int b) = 0;
};

// 加法计算器
class PlusCaculator : public AbstractCaculator
{
public:
    void setOperatorNumber(int a, int b)
    {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult()
    {
        return mA + mB;
    }

public:
    int mA;
    int mB;
};

// 减法计算器
class MinuteCaculator : public AbstractCaculator
{
public:
    void setOperatorNumber(int a, int b)
    {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult()
    {
        return mA - mB;
    }

public:
    int mA;
    int mB;
};

// 乘法计算器
class multiplyCaculator : public AbstractCaculator
{
public:
    void setOperatorNumber(int a, int b)
    {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult()
    {
        return mA * mB;
    }

public:
    int mA;
    int mB;
};

// 除法计算器
class DivideCaculator : public AbstractCaculator
{
public:
    void setOperatorNumber(int a, int b)
    {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult()
    {
        return mA / mB;
    }

public:
    int mA;
    int mB;
};

// 取模计算器
class ModCaculator : public AbstractCaculator
{
public:
    void setOperatorNumber(int a, int b)
    {
        this->mA = a;
        this->mB = b;
    }

    virtual int getResult()
    {
        return mA % mB;
    }

public:
    int mA;
    int mB;
};

void test01()
{
    AbstractCaculator *caculator = new PlusCaculator();
    caculator->setOperatorNumber(10, 20);
    cout << "加法:" << caculator->getResult() << endl;

    delete caculator;
    caculator = new MinuteCaculator();
    caculator->setOperatorNumber(10, 20);
    cout << "减法:" << caculator->getResult() << endl;

    delete caculator;
    caculator = new ModCaculator();
    caculator->setOperatorNumber(10, 20);
    cout << "取模运算:" << caculator->getResult() << endl;
}

int main(void)
{
    test01();
    return 0;
}
