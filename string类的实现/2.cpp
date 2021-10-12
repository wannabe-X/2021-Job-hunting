/*
 * @Description: string类的实现
 * @Author: Mr. Lee
 * @Date: 2021-10-11 14:42:25
 * @LastEditTime: 2021-10-11 15:01:29
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <cstring>

using namespace std;

/*
总体步骤:
    1.确定长度 m_size
    2.申请空间
    3.填充空间
*/

class String
{
public:
    String(const char *str = nullptr);    // 构造函数
    ~String();                            // 析构函数
    String(const String &str);            // 拷贝构造函数
    String &operator=(const String &str); // 赋值运算符重载
private:
    char *m_data;
    int m_size;
};

// 实现拷贝构造函数
String::String(const char *str)
{
    if (str == nullptr)
    {
        m_size = 0;
        m_data = new char[m_size + 1];
        m_data[0] = '\0';
    }
    else
    {
        m_size = strlen(str);
        m_data = new char[m_size + 1];
        strcpy(m_data, str);
    }
}

// 实现析构函数
String::~String()
{
    delete[] m_data;
}

// 实现拷贝构造函数
String::String(const String &str)
{
    m_size = str.m_size;
    m_data = new char[m_size + 1];
    strcpy(m_data, str.m_data);
}

// 实现=运算符重载
String &String::operator=(const String &str)
{
    if (&str == this)
        return *this;

    delete[] m_data;
    m_size = strlen(str.m_data);
    m_data = new char[m_size + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

int main(void)
{
    String str("hello");
    return 0;
}