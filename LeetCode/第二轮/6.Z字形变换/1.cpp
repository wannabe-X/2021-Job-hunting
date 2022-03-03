/*
 * @Description: 6.Z字形变换
 * @Author: Mr. Lee
 * @Date: 2022-03-01 22:11:14
 * @LastEditTime: 2022-03-01 22:37:37
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows < 2)
        return s;

    vector<string> v(numRows);
    int i = 0, flag = -1;
    for (char c : s)
    {
        v[i].push_back(c);
        if (i == 0 || i == numRows - 1)
            flag *= -1;
        i += flag;
    }

    for (int i = 1; i < numRows; v[0] += v[i], i++)
        ;

    return v[0];
}

int main(int argc, char *argv[])
{
    string s = "AB";
    int numRows = 1;
    string ans = convert(s, numRows);
    cout << ans << endl;

    return 0;
}