/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 16:27:14
 * @LastEditTime: 2021-12-13 16:33:11
 * @LastEditors: Mr. Lee
 */
#include <iostream>
using namespace std;

class A
{
};

class B // 16字节
{
    int a; // int类型 4字节
    char *p; // 指针大小: 32位系统下是4个字节,64位系统下是8个字节
};

class C // 24字节
{
public:
    C() {}
    virtual ~C() {} // 虚函数会产生一虚指针,大小为8字节

private:
    int a; // 4字节
    char *p; // 8字节
};

class CChild : C // 24 + 4 考虑内存对齐 32个字节
{
public:
    CChild() {}
    virtual ~CChild() {} // 多个虚指针,只计算1个

private:
    int c;
};

class D // 8字节
{
    virtual void funA() {}
    virtual void funB() {} // 多个虚指针只计算1个,所以说是8字节
};

int main()
{
    A *a1 = new A();
    A *a2 = new A();
    cout << sizeof A() << endl;        // 1  大小为1方便地址分配 栈向下增长，堆向上
    cout << &a1 << "," << &a2 << endl; // 0x7ffef12ba0b8,0x7ffef12ba0b0
    cout << a1 << "," << a2 << endl;   // 0x2170c20,0x2170c40
    cout << sizeof B() << endl;        // 16 字节对齐
    cout << sizeof C() << endl;        // 24 字节对齐 + 虚指针
    cout << sizeof CChild() << endl;   // 24 父类 + 子类成员（字节对齐）
    cout << sizeof D() << endl;        // 8 多个虚函数等于一个虚函数
}