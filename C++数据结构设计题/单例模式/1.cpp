/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 18:05:00
 * @LastEditTime: 2021-12-13 18:10:50
 * @LastEditors: Mr. Lee
 */
#include <iostream>
using namespace std;

// 饿汉式 单例模式
class singleton
{
private:
    // =delete 禁止编译器使用默认生成的函数
    singleton(){};
    singleton(const singleton &temp) = delete;
    singleton &operator=(const singleton &temp) = delete;

public:
    ~singleton(){};
    static singleton *getInstance()
    {
        static singleton instance;
        return &instance;
    }
    /*
    static singleton& getInstance()
    {
        static singleton instance;
        return instance;
    }
    */
};

#include <mutex>
class singleton1
{
private:
    singleton1(){};
    singleton1(const singleton1 &temp) = delete;
    singleton1 &operator=(const singleton1 &temp) = delete;

public:
    ~singleton1(){};
    static singleton1 *m_Instance;
    static mutex mtx;
    static singleton1 *getInstance()
    {
        if (m_Instance == nullptr)
        {
            unique_lock<mutex> ul(mtx);
            if (m_Instance == nullptr)
                m_Instance = new singleton1();
        }
        return m_Instance;
    }
};

singleton1 *singleton1::m_Instance = new singleton1();
mutex singleton1::mtx;