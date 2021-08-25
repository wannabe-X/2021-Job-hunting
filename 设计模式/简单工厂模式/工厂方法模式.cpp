/*
 * @Description: 工厂方法模式
 * @Author: Mr. Lee
 * @Date: 2021-08-18 23:16:59
 * @LastEditTime: 2021-08-18 23:29:54
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// 抽象水果类
class AbstractFruit
{
public:
    virtual void showName() = 0;
};

class Apple : public AbstractFruit
{
public:
    virtual void showName()
    {
        cout << "Apple." << endl;
    }
};

class Orange : public AbstractFruit
{
public:
    virtual void showName()
    {
        cout << "Orange." << endl;
    }
};

class Banana : public AbstractFruit
{
public:
    virtual void showName()
    {
        cout << "Banana." << endl;
    }
};

// 抽象工厂类
class AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit() = 0;
};

class AppleFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit()
    {
        return new Apple();
    }
};

class OrangeFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit()
    {
        return new Orange();
    }
};

class BananaFactory : public AbstractFactory
{
public:
    virtual AbstractFruit *CreateFruit()
    {
        return new Banana();
    }
};

void test01()
{
    AbstractFactory *factor = nullptr;
    AbstractFruit *fruit = nullptr;

    factor = new AppleFactory();
    fruit = factor->CreateFruit();
    fruit->showName();

    delete fruit;
    delete factor;

    factor = new BananaFactory();
    fruit = factor->CreateFruit();
    fruit->showName();

    delete fruit;
    delete factor;

    factor = new OrangeFactory();
    fruit = factor->CreateFruit();
    fruit->showName();

    delete fruit;
    delete factor;

    fruit = nullptr;
    factor = nullptr;
}

int main()
{
    test01();
    return 0;
}
