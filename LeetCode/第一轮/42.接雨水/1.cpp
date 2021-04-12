#include <iostream>
#include <vector>

using namespace std;

// 解法1 根据核心思想 暴力破解
int trap(vector<int> &height)
{
    if (height.empty()) return 0;
    int n = height.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int l_max = 0, r_max = 0;
        for (int j = 0; j <= i; j++)
            l_max = max(l_max, height[j]);
        for (int k = i; k < n; k++)
            r_max = max(r_max, height[k]);
        int water_i = (min(l_max, r_max) - height[i]);

        res += water_i;
    }
    return res;
}

int main(void)
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trap(height);
    cout << ans << endl;
}