#include <iostream>
using namespace std;

// int sumNums(int n)
// {
//     if (n == 1)
//         return 1;
//     n += sumNums(n - 1);
//     return n;
// }

// 利用逻辑符短路 终止递归
int sumNums(int n)
{
    // sumNums实际计算的是1...(n-1)的和，最后返回是需要加上当前n
    // 当计算到2+sumNums(2)时
    // 递归向下传递，此时n=1,1>1不成立，由于短路，1 += sumNums(1 - 1)不会执行
    // 直接返回1给sumNums(2)
    n > 1 && (n += sumNums(n - 1));
    return n;
}

int main(void)
{
    int n = 3;
    int ans = sumNums(n);
    cout << ans << endl;
    return 0;
}