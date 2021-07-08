/*
 * @Description: 数组中的逆序对。归并排序，参考解法
 * @Author: Mr. Lee
 * @Date: 2021-07-07 23:58:20
 * @LastEditTime: 2021-07-09 00:01:18
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const long long mod = 1e9 + 7;

void add(int *tree, int k, int n)
{
    while (k <= n)
    {
        tree[k] += 1;
        k += k & (-k);
    }
}

long long sum_tree(int *tree, int k)
{
    long long ans = 0;
    while (k)
    {
        ans += tree[k];
        k -= k & (-k);
    }
    return ans;
}

int InversePairs(vector<int> data)
{
    int n = data.size();
    vector<int> a = data;
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 1; i < n; i++)
        if (a[i] != a[cnt])
            a[++cnt] = a[i];
    int tree[cnt + 7];
    memset(tree, 0, sizeof(tree));
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int id = lower_bound(a.begin(), a.end(), data[i]) - a.begin() + 1;
        ans = (ans + sum_tree(tree, cnt + 1) - sum_tree(tree, id)) % mod;
        add(tree, id, cnt + 1);
    }
    return ans;
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 0};
    int ans = InversePairs(data);
    cout << ans << endl;

    return 0;
}
