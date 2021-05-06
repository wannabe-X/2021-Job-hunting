#ifndef PEOPLE_H_
#define PEOPLE_H_

#include <string>
#include <iostream>

using namespace std;

class People
{
public:
    People(const string &name = "NULL", int age = 0);
    const string getName() const;
    int getAge();
    void showInfo();

private:
    string m_name;
    int m_age;
};

class Student : public People
{
public:
    Student(const string &name = "NULL", int age = 0,
            const string &gender = "MAN", const string &major = "NULL");
    Student(const People &p,
            const string &gender = "MAN", const string &major = "NULL");

    void showInfo();
    string &getMargor();

private:
    string m_gender;
    string m_major;
};
#endif