#include <iostream>

using namespace std;

int translateNum(int num)
{
    // 从右往左计算 利用对称性
    int a = 1;               // 末尾只有一位数字的时候，方案数为1
    int b = 1;               // 末尾空的时候，方案数为1
    int x = 0, y = num % 10; // 初始化,x为倒数第二位数字，y为倒数第一位数字
    while (num)
    {
        num /= 10;
        x = num % 10;
        int temp = 10 * x + y;
        int c = (temp >= 10 && temp <= 25) ? a + b : a;
        b = a;
        a = c;
        y = x;
    }
    return a;
}

int main(void)
{
    int num = 98;
    int ans = translateNum(num);
    cout << ans << endl;
    return 0;
}