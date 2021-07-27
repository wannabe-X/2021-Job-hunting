/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 23:28:12
 * @LastEditTime: 2021-07-27 17:45:20
 * @LastEditors: Mr. Lee
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;

    while (cin >> line)
    {
        istringstream s(line);
        vector<string> vec;
        string tmp;
        while (getline(s, tmp, ','))
            vec.push_back(tmp);

        sort(vec.begin(), vec.end());

        for (int i = 0; i < vec.size() - 1; i++)
        {
            cout << vec[i] << ",";
        }
        cout << vec[vec.size() - 1] << endl;
    }
    return 0;
}
