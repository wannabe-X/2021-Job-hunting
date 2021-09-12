/*
 * @Description: 手写String类
 * @Author: Mr. Lee
 * @Date: 2021-08-28 22:28:53
 * @LastEditTime: 2021-09-12 08:57:08
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <cstring>

using namespace std;
class String
{
private:
    char *m_data;

public:
    String(const char *cstr = 0);
    String(const String &str);
    String &operator=(const String &str);
    ~String();
    char *getInstance() const { return m_data; }
};

// 构造函数
String::String(const char *cstr = 0)
{
    if (!cstr)
    {
        m_data = new char[1];
        *m_data = '\n';
    }
    else
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
}

// 拷贝构造函数
String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 重载运算符
String &String::operator=(const String &str)
{
    if (this == &str)
        return *this;
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);

    return *this;
}

// 析构函数
String::~String()
{
    delete[] m_data;
}