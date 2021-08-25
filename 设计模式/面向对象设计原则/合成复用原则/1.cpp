/*
 * @Description: 面向对象设计法则 - 合成复用原则
 * @Author: Mr. Lee
 * @Date: 2021-08-18 20:01:40
 * @LastEditTime: 2021-08-18 21:02:12
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

class AbstractCar
{
public:
    virtual void run() = 0;
};

class Dazhong : public AbstractCar
{
public:
    virtual void run()
    {
        cout << "大众汽车启动..." << endl;
    }
};

class Tuolaji : public AbstractCar
{
public:
    virtual void run()
    {
        cout << "拖拉机启动..." << endl;
    }
};

// 针对具体的类
// class Person : public Tuolaji
// {
// public:
//     void Drive()
//     {
//         run();
//     }
// };

// class PersonB : public Dazhong
// {
// public:
//     void Drive()
//     {
//         run();
//     }
// };

// 可以使用组合
class Person
{
public:
    void setCar(AbstractCar *car)
    {
        this->car = car;
    }

    void Drive()
    {
        car->run();
        if (this->car)
        {
            delete this->car;
            this->car = nullptr;
        }
    }

public:
    AbstractCar *car;
};

void test01()
{
    Person *p = new Person();
    p->setCar(new Dazhong());
    p->Drive();

    p->setCar(new Tuolaji());
    p->Drive();

    delete p;
}

int main(void)
{
    test01();
    return 0;
}
