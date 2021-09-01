/*
 * @Description: 165. 比较版本号
 * @Author: Mr. Lee
 * @Date: 2021-09-01 17:00:29
 * @LastEditTime: 2021-09-01 17:55:35
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int compareVersion(string version1, string version2)
{
    stringstream s1(version1);
    stringstream s2(version2);

    string tmp;
    vector<int> v1, v2;

    while (getline(s1, tmp, '.'))
        v1.push_back(stoi(tmp));

    while (getline(s2, tmp, '.'))
        v2.push_back(stoi(tmp));

    for (int i = 0; i < max(v1.size(), v2.size()); i++)
    {
        int num1, num2;
        num1 = (i < v1.size() ? v1[i] : 0);
        num2 = (i < v2.size() ? v2[i] : 0);

        if (num1 > num2)
            return 1;
        else if (num1 < num2)
            return -1;
    }

    return 0;
}

int main(void)
{
    string version1 = "7.5.2.4", version2 = "7.5.3";
    int ans = compareVersion(version1, version2);
    cout << ans << endl;

    return 0;
}