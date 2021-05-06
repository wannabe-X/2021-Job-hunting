#include "bank.h"
#include <iostream>
using namespace std;

int main()
{
    Brass br1;
    br1.viewAcct();

    Brass br2("Leo");
    br2.viewAcct();

    Brass br3("Jack", "123456789");
    br3.viewAcct();
    // 初始余额为0，现存入10000
    br3.deposit(10000);
    // 取款5000
    br3.withdraw(5000);
    br3.viewAcct();

    // 初始化账户余额为200.45
    Brass br4("Tom", "12345456", 200.45);
    br4.viewAcct();

    // 测试用例 贷款业务
    Brass br5("Richard", "430722199209280056", 100.0);
    BrassPlus bp1("Jenny", "88888888", 120.0, 500, 0.1);
    br5.viewAcct();
    bp1.viewAcct();
    br5.withdraw(500);
    bp1.withdraw(500);
    br5.viewAcct();
    bp1.viewAcct();

    // 使用虚函数以后，基类的指针也可以指向派生类的方法
    Brass *br6 = &bp1;
    br6->viewAcct();

    Brass &br7 = bp1;
    br7.viewAcct();

    return 0;
}