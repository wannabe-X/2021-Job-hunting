#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using namespace std;

class Student
{
public:
    Student();
    Student(const string &name, int age = 18, int score = 60);
    void showInfo() const; // const 该函数会承诺不会改变任何的值
    const Student &compare(const Student &s) const; // const 该函数会承诺不会改变任何参数的值

private:
    string m_name;
    int m_age;
    int m_score;
};

#endif