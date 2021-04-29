#include <iostream>
#include "student.h"

using namespace std;

Student::Student()
{
    m_name = "NULL";
    m_age = 0;
    m_score = 0;
}

Student::Student(const string &name, int age, int score)
{
    m_name = name;
    m_age = age;
    m_score = score;
}

void Student::showInfo() const
{
    cout << "name:" << m_name << endl;
    cout << "age:" << m_age << endl;
    cout << "score:" << m_score << endl;
    cout << endl;
}

const Student &Student::compare(const Student &s) const
{
    if (s.m_score >= m_score)
        return s;
    else
        return *this;
}