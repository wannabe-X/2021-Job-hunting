/*
 * @Description: 简单工厂模式
 * @Author: Mr. Lee
 * @Date: 2021-08-18 22:44:46
 * @LastEditTime: 2021-08-18 23:01:54
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

// 工厂；水果工厂
class FruitFactory
{
public:
    static AbstractFruit *CreateFruit(string flag)
    {
        if (flag == "Apple")
        {
            return new Apple();
        }
        else if (flag == "Orange")
        {
            return new Orange();
        }
        else if (flag == "Banana")
        {
            return new Banana();
        }
        else
        {
            return nullptr;
        }
    }
};

void test01()
{
    FruitFactory *factory = new FruitFactory();
    AbstractFruit *apple = factory->CreateFruit("Apple");
    apple->showName();
    delete apple;
    apple = nullptr;

    AbstractFruit *banana = factory->CreateFruit("Banana");
    banana->showName();
    delete banana;
    banana = nullptr;

    AbstractFruit *orange = factory->CreateFruit("Orange");
    orange->showName();
    delete orange;
    orange = nullptr;

    delete factory;
    factory = nullptr;
}

int main()
{
    test01();
    return 0;
}
