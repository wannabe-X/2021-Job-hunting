#include <iostream>
#include "People.h"

using namespace std;

int main()
{
    People p1;
    p1.showInfo();
    People p2("Jack", 20);
    p2.showInfo();

    Student s1;
    s1.showInfo();

    Student s2("Tom", 21, "Man", "Math");
    s2.showInfo();

    People *p_t = &s2;
    p_t->showInfo();
    People &r_t = s2;
    r_t.showInfo();

    Student s3 = Student(p2, "MAN", "CS");
    s3.showInfo();

    return 0;
}