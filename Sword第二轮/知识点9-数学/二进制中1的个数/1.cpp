/*
 * @Description: 二进制中1的个数
 * @Author: Mr. Lee
 * @Date: 2021-06-23 17:22:39
 * @LastEditTime: 2021-06-23 17:46:06
 * @LastEditors: Mr. Lee
 */
#include <iostream>

using namespace std;

int NumberOf1(int n)
{
    int count = 0;

    // while (n)
    // {
    //     n = (n & (n - 1));
    //     count++;
    // }
    
    /*
        n >>= 1表示，如果n的二进制是110，则操作之后会变成011,也就是舍去最低位，然后最高位补0.
        但是如果n为负数，最高位会补1，所以对于负数还是有点问题。 
        需要加循环，限制一下位移的次数
    */
    for (int i = 0; i < 32; i++)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }

    return count;
}

int main()
{
    // 测试用例
    // int n = 10;

    int n;
    cin >> n;
    int ans = NumberOf1(n);
    cout << ans << endl;

    return 0;
}