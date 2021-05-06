#include "People.h"

// 实现基类函数
People::People(const string &name, int age) : m_name(name), m_age(age)
{
}

const string People::getName() const{
    return m_name;
}

int People::getAge()
{
    return m_age;
}

void People::showInfo()
{
    cout << "using people method to show" << endl;
    cout << "name:" << m_name << endl;
    cout << "age:" << m_age << endl;
}

// 实现派生类函数
Student::Student(const string &name, int age,
                 const string &gender,
                 const string &major) : People(name, age), m_gender(gender), m_major(major)
{
}

Student::Student(const People &p,
                 const string &gender, const string &major) : People(p), m_gender(gender), m_major(major)
{
}

void Student::showInfo()
{
    cout << "using Student method to show" << endl;
    cout << "name:" << getName() << endl;
    cout << "age:" << getAge() << endl;
    cout << "gender:" << m_gender << endl;
    cout << "major:" << m_major << endl;
}