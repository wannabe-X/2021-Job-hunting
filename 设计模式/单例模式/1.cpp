/*
 * @Description: 单例模式
 * @Author: Mr. Lee
 * @Date: 2021-08-17 23:12:09
 * @LastEditTime: 2021-09-12 16:11:16
 * @LastEditors: Mr. Lee
 */
#include <iostream>

using namespace std;

/* 
单例模式构造步骤：
    1. 类的构造函数私有化
    2. 增加静态私有的当前类的指针变量
    3. 提供静态对外接口，可以让用户获得单例对象 
*/

// 懒汉式
class Singleton_lazy
{
private:
    Singleton_lazy() {}

public:
    static Singleton_lazy *getInstance()
    {
        if (pSingleton == nullptr)
            pSingleton = new Singleton_lazy;

        return pSingleton;
    }

private:
    static Singleton_lazy *pSingleton;
};

Singleton_lazy *Singleton_lazy::pSingleton = nullptr;

// 饿汉式
class Singleton_hungry
{
private:
    Singleton_hungry()
    {
        cout << "饿汉构造函数" << endl;
    }

public:
    static Singleton_hungry *getINstance()
    {
        return pSingleton;
    }

private:
    static Singleton_hungry *pSingleton;
};

// 在执行main()函数之前，饿汉式类的对象就已经被实例化
Singleton_hungry *Singleton_hungry::pSingleton = new Singleton_hungry;

int main()
{
    cout << "执行main函数" << endl;
    return 0;
}
