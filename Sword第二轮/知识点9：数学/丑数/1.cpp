/*
 * @Description:  丑数
 * @Author: Mr. Lee
 * @Date: 2021-06-24 11:33:50
 * @LastEditTime: 2021-06-24 15:39:03
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
    丑数能够分解成2^x * 3^y * 5^z,
    所以只需要把得到的丑数不断地乘以2、3、5之后并放入他们应该放置的位置即可，
    而此题的难点就在于如何有序的放在合适的位置?

    而在2x，3y，5z中，如果x=y=z那么最小丑数一定是乘以2的，但关键是有可能存在x>y>z的情况，
    所以我们要维持三个指针来记录当前乘以2、乘以3、乘以5的最小值，然后当其被选为新的最小值后，要把相应的指针+1；
    因为这个指针会逐渐遍历整个数组，因此最终数组中的每一个值都会被乘以2、乘以3、乘以5，也就是实现了我们最开始的想法，
    只不过不是同时成乘以2、3、5，而是在需要的时候乘以2、3、5. 
*/

int Min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int GetUglyNumber_Solution(int index)
{
    if (index == 0)
        return 0;
    vector<int> uglynums(index);
    uglynums[0] = 1;

    auto uglynum2 = uglynums.begin();
    auto uglynum3 = uglynums.begin();
    auto uglynum5 = uglynums.begin();

    int nextnumidx = 1;

    while (index > nextnumidx)
    {
        uglynums[nextnumidx] = Min(*uglynum2 * 2, *uglynum3 * 3, *uglynum5 * 5);
        if (uglynums[nextnumidx] == *uglynum2 * 2)
            uglynum2++;
        if (uglynums[nextnumidx] == *uglynum3 * 3)
            uglynum3++;
        if (uglynums[nextnumidx] == *uglynum5 * 5)
            uglynum5++;

        nextnumidx++;
    }

    return uglynums[nextnumidx - 1];
}

int main()
{
    // 测试用例
    // int index = 0;

    int index;
    cin >> index;
    int ans = GetUglyNumber_Solution(index);
    cout << ans << endl;

    return 0;
}
