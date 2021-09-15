/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-14 12:38:45
 * @LastEditTime: 2021-09-14 14:55:42
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;
class Solution
{
public:
    /* Write Code Here */

    bool isBanHuiWen(string str, int n)
    {
        int t1 = 1;
        int t2 = 2 * n - 1;
        int t3 = 2 * n + 1 - 2;

        if (str[t1 - 1] == str[t2 - 1] && str[t1 - 1] == str[t3 - 1])
            return true;

        return false;
    }

    int solution(string str)
    {
        int res = 0;
        for (int i = 2; 3 * i - 2 <= str.size(); i++)
        {
            int len = 3 * i - 2;

            for (int j = 0; j + len <= str.size(); j++)
            {
                string tmp = str.substr(j, len);
                if (isBanHuiWen(tmp, i))
                {
                    res++;
                }
            }
        }

        return res;
    }
};
int main()
{
    int res;

    string _str;
    getline(cin, _str);
    Solution *s = new Solution();
    res = s->solution(_str);
    cout << res << endl;

    return 0;
}
