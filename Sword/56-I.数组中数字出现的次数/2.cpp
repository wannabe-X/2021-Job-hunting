#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 从异或的结果来查找二进制位中第一个为1的索引
// 便于将数据分成两部分
// 两部分数据各自包含一个不重复的数字
// idx从0开始计数
int findIdx(int temp)
{
    int idx = 0;
    while ((temp & 1) == 0)
    {
        idx++;
        temp >>= 1;
    }
    return idx;
}

// 将数据分类
// 根据上一步的索引idx
// 数组中数字的二进制中倒数第idx位为1的数据分为一类
// 数组中数字的二进制中倒数第idx位位0的数据分为另外一类
// 数字和1作与运算，可判断最后一位是1还是0，可以用于判断数字的奇偶性
// 例如 101&1=1,110&1=0.（1相当于001）
bool classification(int val, int idx)
{
    return ((val >>= idx) & 1) ? true : false;
}

vector<int> singleNumbers(vector<int> &nums)
{
    int ans1 = 0, ans2 = 0;
    int temp = 0;
    for (int num : nums)
        temp ^= num;

    int idx = findIdx(temp);
    // cout << idx << endl;

    for (int num : nums)
    {
        if (classification(num, idx))
            ans1 ^= num;
        else
            ans2 ^= num;
    }

    return {ans1, ans2};
}

int main(void)
{
    vector<int> nums = {4, 1, 4, 6};
    vector<int> ans = singleNumbers(nums);
    for (int num : ans)
        cout << num << ' ';
    cout << endl;
    return 0;
}