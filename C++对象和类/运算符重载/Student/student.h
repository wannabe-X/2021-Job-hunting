#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
using namespace std;

class Student
{
public:
    Student();
    void show();
    friend Student operator*(int n, Student &t);
    friend ostream &operator<<(ostream &os, Student &t);

private:
    int age;
};

#endif