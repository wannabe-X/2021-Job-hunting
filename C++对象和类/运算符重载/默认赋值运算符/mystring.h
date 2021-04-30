#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
using namespace std;
class MyString
{
private:
    char *str;
    int len;
    static int num_of_strings;
    //cin limits,只有const整形才能够在这里直接赋值！！！
    static const int CINLIM = 80;

public:
    //constructors and other methods
    MyString();
    MyString(const char *s);
    ~MyString(); //destructor

    MyString(const MyString &ms); //copy constructor

    int lenth() const
    {
        return len;
    }

    //overload operator methods
    MyString &operator=(const MyString &ms);
    MyString &operator=(const char *s);

    char &operator[](int i);             //can access and modified
    const char &operator[](int i) const; //can access but can't modified

    //overload operator friends
    //输入输出
    friend ostream &operator<<(ostream &os, const MyString &ms);
    friend istream &operator>>(istream &is, MyString &ms);

    //字符串比较
    friend bool operator<(MyString &ms1, MyString &ms2);
    friend bool operator>(MyString &ms1, MyString &ms2);
    friend bool operator==(MyString &ms1, MyString &ms2);

    //静态方法
    static int howMany();
};
#endif