#include <iostream>
#include "timetest.h"

using namespace std;
Time::Time(int minute, int second)
{
    this->minute = minute;
    this->second = second;
}

const Time Time::add(const Time &t) const
{
    Time sum = *this;
    sum.minute += t.minute;
    sum.second += t.second;
    sum.minute += sum.second / 60;
    sum.second = sum.second % 60;
    return sum;
}

void Time::show()
{
    // cout << "minute:" << this->minute << endl;
    // cout << "second:" << this->second << endl;
    cout << "time:" << this->minute << ":" << this->second << endl;
}