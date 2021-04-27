#include <iostream>
#include <vector>

using namespace std;

vector<int> constructArr(vector<int> &a)
{
    // res初始化为1，便于之后作乘积
    vector<int> res(a.size(), 1);
    int p = 1, q = 1;

    // res[i]计算的是索引i之前数字的乘积
    for (int i = 0; i < a.size(); i++)
    {
        res[i] *= p;
        p *= a[i];
    }

    // res[i]计算的是索引i之后数字的乘积
    for (int i = a.size() - 1; i > -1; i--)
    {
        res[i] *= q;
        q *= a[i];
    }

    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = constructArr(nums);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}