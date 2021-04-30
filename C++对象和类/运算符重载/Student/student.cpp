#include <iostream>
#include "student.h"

using namespace std;

Student::Student()
{
    age = 18;
}

// 重载乘法运算符
Student operator*(int n, Student &t)
{
    Student s;
    s.age = n * t.age;
    return s;
}

// 重载<< 运算符，使之能够输出Student类的数据
ostream &operator<<(ostream &os, Student &t)
{
    // 把引用作为返回值
    // return os << t.age << endl;
    os << t.age << endl;
    return os;
}