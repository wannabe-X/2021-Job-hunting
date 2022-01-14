/*
 * @Description: 1629. 按键持续时间最长的键
 * @Author: Mr. Lee
 * @Date: 2022-01-09 22:21:30
 * @LastEditTime: 2022-01-09 22:46:57
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    vector<int> v(26, 0);
    v[keysPressed[0] - 'a'] += releaseTimes[0];
    for (int i = 1; i < releaseTimes.size(); i++)
    {
        v[keysPressed[i] - 'a'] = max(releaseTimes[i] - releaseTimes[i - 1], v[keysPressed[i] - 'a']);
    }

    int idx = 0;
    for (int i = 1; i < 26; i++)
    {
        idx = v[i] >= v[idx] ? i : idx;
    }

    return 'a' + idx;
}

int main(int argc, char *argv[])
{
    vector<int> releaseTimes = {12, 23, 36, 46, 62};
    string keysPressed = "spuda";
    char ans = slowestKey(releaseTimes, keysPressed);
    cout << ans << endl;

    return 0;
}
