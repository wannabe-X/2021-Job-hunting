/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-14 12:38:41
 * @LastEditTime: 2021-09-14 14:46:14
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
    string solution(vector<int> d)
    {
        sort(d.begin(), d.end());
        int count = 0;
        int ac = 0, bc = 0;
        vector<pair<int, int>> a(1), b(1);
        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] % 3 && ac <= 1)
                a[ac++] = i;

            if (d[i] % 3 && bc <= 2)
                a[bc++] = i;
        }

        count += d[i];

        int x = -1, y = -1;
        if (count % 3 == 0)
        {
        }
        else if (count % 3 == 1)
        {
            if (a[0] != -1)
            {
                x = a[0];
            }
            else
            {
                x = a[0];
                y = b[1];
            }
        }
        else if (count % 3 == 2)
        {
            if (b[0] != -1)
            {
                x = b[0];
            }
            else
            {
                x = a[0];
                y = b[1];
            }
        }
    }

    string res = "";
    for (int i = d.size() - 1; i > -1; i--)
    {
        if (i == x || i == y)
            continue;
        res += to_string(d[i]);
    }

    return res;
};
int main()
{
    string res;

    int _d_size = 0;
    cin >> _d_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _d;
    int _d_item;
    for (int _d_i = 0; _d_i < _d_size; _d_i++)
    {
        cin >> _d_item;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _d.push_back(_d_item);
    }

    Solution *s = new Solution();
    res = s->solution(_d);
    cout << res << endl;

    return 0;
}
