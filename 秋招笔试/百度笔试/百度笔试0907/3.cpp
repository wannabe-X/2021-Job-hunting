 /*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-07 18:47:56
 * @LastEditTime: 2021-09-07 21:30:40
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(string s)
{
    int res = 0;

    string tmp = s;
    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        for (int j = i + 1; j < s.size() - i; j++)
        {
            if (s[i] > c)
                c = s[i];
        }

        if (s[i] != tmp[i])
            res++;
    }

    return res;
}

int main(void)
{
    int N, Q;
    cin >> N >> Q;

    while (Q--)
    {
        string s;
        cin >> s;
        int ans = func(s);
        cout << ans << endl;
    }

    return 0;
}