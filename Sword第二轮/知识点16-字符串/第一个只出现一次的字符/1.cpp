/*
 * @Description: 第一个只出现一次的字符
 * @Author: Mr. Lee
 * @Date: 2021-07-02 16:06:13
 * @LastEditTime: 2021-07-02 19:21:38
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int FirstNotRepeatingChar(string str)
{
    int idx = 0;
    vector<int> dict(128, 0);
    for (char c : str)
    {
        dict[c] += 1;
    }

    for (char c : str)
    {
        if (dict[c] == 1)
            return idx;
        idx++;
    }
    
    return -1;
}

int main()
{
    string str = "google";
    int ans = FirstNotRepeatingChar(str);
    cout << ans << endl;

    return 0;
}
