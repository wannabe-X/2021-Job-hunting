/*
 * @Description: WC140 三个数的最大乘积
 * @Author: Mr. Lee
 * @Date: 2021-09-24 22:55:32
 * @LastEditTime: 2021-09-24 23:46:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int *A, int ALen)
{
    // write code here
    sort(A, A + ALen);
    long long max1 = (long long)A[ALen - 1] * A[ALen - 2] * A[ALen - 3],
              max2 = (long long)A[0] * A[1] * A[ALen - 1];

    return max(max1, max2);
}

int main(void)
{
    int A[] = {-10000, -10000, -10000, -10000, -10000};
    long long ans = solve(A, 5);
    cout << ans << endl;
    return 0;
}