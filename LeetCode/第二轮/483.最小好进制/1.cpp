/*
 * @Description: 483. 最小好进制。使用二项式定理
 * @Author: Mr. Lee
 * @Date: 2021-06-18 09:41:13
 * @LastEditTime: 2021-06-18 11:09:34
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
    使用二项式定理，首先计算出最大的位数m
    然后根据当前的m计算出对应的进制数
    两次遍历即可
*/

string smallestGoodBase(string n)
{
    long long  nVal = stoll(n);
    int mVal = floor(log(nVal) / log(2));

    for (int m = mVal; m > 1; m--)
    {
        unsigned long long sum = 0, mul = 1;
        int k = pow(nVal, 1.0 / m);

        for (int j = 0; j <= m; j++)
        {
            sum += mul;
            mul *= k;

            if (sum == nVal)
            {
                return to_string(k);
            }
        }
    }

    return to_string(nVal - 1);
}

int main()
{
    // 测试用例
    string num = "1000000000000000000";
    string ans = smallestGoodBase(num);

    // string num;
    // cin >> num;
    // string ans = smallestGoodBase(num);
    cout << ans << endl;

    return 0;
}
