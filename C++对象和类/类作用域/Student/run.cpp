#include <iostream>

using namespace std;

extern "C"{
    #include "student.h"
}

int main(void)
{
    Student s[4] = {
        Student("Tom", 20, 95),
        Student("Jack", 21, 94),
        Student("Jenny", 19, 99),
        Student("Richard", 20, 100)};

    s[2].showInfo();

    Student maxScore = s[0];
    for (int i = 1; i < 4; maxScore = maxScore.compare(s[i]), i++)
        ;
    cout << "the highest score:" << endl;
    maxScore.showInfo();
    return 0;
}