#include <iostream>

using namespace std;

int translateNum(int num)
{
    // 初始化 dp[i]的含义是：截止到num的第i位，可以计算的方案数量
    // 无数字 dp_0 初始化为1
    // 因为，假设num的前两位数字组成的属于[10,25]的话
    // 那么应该有两种翻译方法 dp_2 = dp_0+dp_1 = 2，已知dp_1=1，所以dp_0=1
    int dp_0 = 1;
    int dp_1 = 1;
    string s = to_string(num);
    for (int i = 1; i < s.size(); i++)
    {
        // 动态规划 若x_(i-1) x_i整体可以被翻译，那么dp_i为dp_(i-2)+dp_(i-1)
        // 若只有dp_i可以被翻译，则dp_i = dp_(i-1)
        int val = 10 * (s[i - 1] - '0') + (s[i] - '0');
        int dp_2 = (val >= 10 && val <= 25) ? dp_0 + dp_1 : dp_1;
        dp_0 = dp_1;
        dp_1 = dp_2;
    }
    return dp_1;
}

int main(void)
{
    int num = 98;
    int ans = translateNum(num);
    cout << ans << endl;
    return 0;
}