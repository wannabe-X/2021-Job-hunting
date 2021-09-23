/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-01 18:40:39
 * @LastEditTime: 2021-09-23 21:58:05
 * @LastEditors: Mr. Lee
 */

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> func(vector<int> &nums)
// {
//     int n =n;
//     vector<int> res(n);
//     res[0] = nums[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (i % 2 == 1)
//             res[i] = nums[i - 1] - nums[i];
//         else
//             res[i] = -nums[i - 1] + nums[i];
//     }

//     return res;
// }

// int main(void)
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n, 0);
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];

//     vector<int> ans = func(nums);
//     for (auto num : ans)
//         cout << num << " ";

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int n, int m, int x, int y, string str, vector<vector<int>> &nums)
{
    int i = 1, j = 1;
    int res = 0;

    if (str[0] == 'k')
    {
        res += y;
        i--;
    }
    else if (str[0] == 'j' && nums[1][0] == -1)
    {
        res += y;
        i++;
    }
    else if (str[0] == 'l' && nums[0][1] == -1)
    {
        res += y;
        j++;
    }

    for (int b = 1; b < str.size(); b++)
    {
        if (str[b] != str[b - 1])
        {
            res += x;
        }

        if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
        {
            res += y;

            if (i == 0)
                i++;
            else if (i == n + 1)
                i--;
            else if (j == 0)
                j++;
            else if (j == m + 1)
                j--;

            continue;
        }

        if (str[b] == 'k')
        {
            res += max(nums[i][j], nums[i - 1][j]);
            i--;
            if (i > -1 && nums[i][j] == -1)
            {
                i++;
                res += y;
            }
        }
        else if (str[b] == 'j')
        {
            res += max(nums[i][j], nums[i + 1][j]);
            i++;
            if (i < n + 1 && nums[i][j] == -1)
            {
                i--;
                res += y;
            }
        }
        else if (str[b] == 'l')
        {
            res += max(nums[i][j], nums[i][j + 1]);
            j++;
            if (j < m + 1 && nums[i][j] == -1)
            {
                j--;
                res += y;
            }
        }
        else if (str[b] == 'h')
        {
            res += max(nums[i][j], nums[i][j - 1]);
            j--;
            if (j > -1 && nums[i][j] == -1)
            {
                j++;
                res += y;
            }
        }
    }

    return res;
}

int main(void)
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> nums(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> nums[i + 1][j + 1];
    }
    string str;
    cin >> str;
    int ans = func(n, m, x, y, str, nums);
    cout << ans;

    return 0;
}