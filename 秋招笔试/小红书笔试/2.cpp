/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-04 09:57:18
 * @LastEditTime: 2021-09-04 11:33:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hw(string str, int l, int r)
{
    while (l < r)
    {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }

    return true;
}

void dfs(string str, int begin, vector<string> &tmp, vector<vector<string>> &res)
{
    if (begin == str.size())
    {
        res.push_back(tmp);
        return;
    }

    for (int i = begin; i < str.size(); i++)
    {
        if (hw(str, begin, i))
        {
            tmp.push_back(str.substr(begin, i - begin + 1));
            dfs(str, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> func(string str)
{
    int n = str.size();
    vector<string> tmp;
    vector<vector<string>> res;
    dfs(str, 0, tmp, res);
    int t = 0;

    if (hw(str, 0, str.size() - 1))
        t++;

    return res;
}

int ld(string str)
{
    int res = 0, pre = 0;
    vector<vector<string>> ans = func(str);
    int n = str.size();
    vector<string> tmp;
    for (int i = 0; i < n / 2; i++)
    {
        if (str.substr(pre, i - pre + 1) == str.substr(n - i - 1, i - pre + 1))
        {
            int flag = 0;
            for (auto &x : ans)
            {
                if (str.substr(pre, i - pre + 1) == x[0])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                res += 2;

            pre = i + 1;
        }
    }

    if (n % 2 == 1 || pre < n / 2)
        res++;

    return res+ans.size();
}

int main(void)
{
    string str;
    cin >> str;
    int ans = ld(str);
    cout << ans-1 << endl;

    return 0;
}
