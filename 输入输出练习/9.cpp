/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 23:24:08
 * @LastEditTime: 2021-07-27 17:29:22
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> v;
    string s;

    while (cin >> s)
    {
        v.push_back(s);

        if (cin.get() == '\n')
        {
            sort(v.begin(), v.end());
            for (auto &x : v)
            {
                cout << x << " ";
            }
            
            cout << endl;
            v.clear();
        }
    }
    return 0;
}