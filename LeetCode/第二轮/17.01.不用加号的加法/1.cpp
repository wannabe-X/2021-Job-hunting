#include <iostream>

using namespace std;

int add(int a, int b)
{
    int sum = 0, carry = 0;
    while (b != 0)
    {
        sum = a ^ b; // 不进位加法
        // 不用的话unsigned int 类型会溢出，无法得出正确结果。int范围-2^31~ 2^31-1,unsigned int范围0~2^32-1。
        carry = (unsigned int)(a & b) << 1; // 考虑进位,都是操作的补码
        a = sum;
        b = carry;
    }
    return a; // 最后无进位，异或的结果即加法结果
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int res = add(a, b);
        cout << res << endl;
    }

    return 0;
}