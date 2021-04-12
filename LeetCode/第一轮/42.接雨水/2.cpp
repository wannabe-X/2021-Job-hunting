#include <iostream>
#include <vector>

using namespace std;

// 解法2 根据核心思想 使用备忘录进行优化
int trap(vector<int> &height)
{
    if (height.empty()) return 0;
    int n = height.size();

    vector<int> l_max(n), r_max(n);
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
        l_max[i] = max(l_max[i - 1], height[i]);
    for (int i = n - 2; i > -1; i--)
        r_max[i] = max(r_max[i + 1], height[i]);

    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        // int water_i = min(l_max[i - 1], r_max[i + 1]) - height[i];
        // res += (water_i >= 0 ? water_i : 0);

        res += min(l_max[i], r_max[i]) - height[i];
    }

    return res;
}

int main(void)
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trap(height);
    cout << ans << endl;
}