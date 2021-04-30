#include "mystring.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//首先初始化静态的变量
int MyString::num_of_strings = 0;

int MyString::howMany()
{
    return num_of_strings;
}

//realize the constructor
MyString::MyString()
{
    len = 0;
    str = new char[len + 1];
    str[0] = '\0';
    ++num_of_strings;
    cout << "using default constructor to init!: " << str << endl;
    cout << "we have " << num_of_strings << " objects now!" << endl
         << endl;
}

MyString::MyString(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    ++num_of_strings;
    cout << "using artificial constructor to init!: " << str << endl;
    cout << "we have " << num_of_strings << " objects now!" << endl
         << endl;
}

MyString::~MyString()
{
    --num_of_strings;
    cout << "\"" << str << "\""
         << " deleted\n"
         << endl;
    cout << "we have " << num_of_strings << " objects now!" << endl
         << endl;
    delete[] str;
}

//realize the copy constructor
//本质就是进行深度复制，目的是保持每个对象的独立性
//不会是因为删除其中一个或是怎么的而影响到另外一个
MyString::MyString(const MyString &ms)
{
    ++num_of_strings;
    len = ms.len;
    //重新分配空间
    str = new char[len + 1];
    strcpy(str, ms.str);
    cout << "using the copy constructor to init!: " << str << endl;
    cout << "we have " << num_of_strings << " objects now!" << endl
         << endl;
}

// 输出流
ostream &operator<<(ostream &os, const MyString &ms)
{
    os << "Infomation:\n";
    os << "content of the string: " << ms.str << endl;
    os << "lenth of the string: " << ms.len << endl
       << endl;
    return os;
}

// 输入流
istream &operator>>(istream &is, MyString &ms)
{
    char buffer[MyString::CINLIM];
    is.get(buffer, MyString::CINLIM);
    if (is)
        ms = buffer;
    while (is && is.get() != '\n')
        continue;
    return is;
}
//重载赋值运算符需要注意的！
//函数应该避免将对象赋给自己，所以前面应当进行比较。
//函数会有一个清除当前内存的动作，因为以前可能会有数据在其中
//这就是为什么要比较两个对象的原因，因为相同的对象，删除其中任何的元素都会破坏另外的元素
//按照自己的需要进行深度复制
MyString &MyString::operator=(const MyString &ms)
{
    if (this == &ms)
    {
        return *this;
    }
    delete[] str;
    len = ms.len;
    str = new char[len + 1];
    strcpy(str, ms.str);
    return *this;
}

MyString &MyString::operator=(const char *s)
{
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char &MyString::operator[](int i)
{
    return str[i];
}

const char &MyString::operator[](int i) const
{
    return str[i];
}

bool operator<(MyString &ms1, MyString &ms2)
{
    return (strcmp(ms1.str, ms2.str) < 0);
}

bool operator>(MyString &ms1, MyString &ms2)
{
    return (strcmp(ms1.str, ms2.str) > 0);
}

bool operator==(MyString &ms1, MyString &ms2)
{
    return (strcmp(ms1.str, ms2.str) == 0);
}