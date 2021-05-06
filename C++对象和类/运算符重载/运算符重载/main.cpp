#include <iostream>
#include "timetest.h"

using namespace std;

int main()
{
    Time t1 = Time(1, 22);
    Time t2 = Time(3, 58);
    Time total;
    t1.show();
    total = t1 + t2;
    total.show();
    t1.show();
    return 0;
}