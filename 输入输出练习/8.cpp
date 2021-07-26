/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 23:08:06
 * @LastEditTime: 2021-07-26 23:23:28
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> v;

    string s;

    while (N--)
    {
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    for (auto &x : v)
    {
        cout << x << " ";
    }

    return 0;
}
