/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 23:28:12
 * @LastEditTime: 2021-07-26 23:40:48
 * @LastEditors: Mr. Lee
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    vector<string> vec;
    while (getline(cin, str))
    {
        stringstream ss;
        ss << str;
        while (getline(ss, str, ','))
            vec.push_back(str);
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size() - 1; i++)
            cout << vec[i] << ",";
        cout << vec[vec.size() - 1] << endl;
        vec.clear();
    }
    return 0;
}
