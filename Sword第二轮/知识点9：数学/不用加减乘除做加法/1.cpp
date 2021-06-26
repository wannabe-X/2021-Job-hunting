/*
 * @Description: 不用加减乘除做加法
 * @Author: Mr. Lee
 * @Date: 2021-06-27 00:02:01
 * @LastEditTime: 2021-06-27 00:27:19
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int Add(int num1, int num2)
{
    int sum = 0;
    
    // 一直循环，直到进位为0
    while (num2)
    {
        int c = ((unsigned int)(num1 & num2)) << 1; // 进位
        num1 ^= num2;                               // 异或是不进位加法
        num2 = c;
    }

    return num1;
}

int main()
{
    // 测试用例
    // int num1 = 1, num2 = 2;

    int num1, num2;
    cin >> num1 >> num2;
    int ans = Add(num1, num2);
    cout << ans << endl;

    return 0;
}
