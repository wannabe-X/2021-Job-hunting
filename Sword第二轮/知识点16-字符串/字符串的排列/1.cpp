/*
 * @Description: 字符串的排列
 * @Author: Mr. Lee
 * @Date: 2021-07-02 19:36:53
 * @LastEditTime: 2021-07-02 19:42:55
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;

// 回溯算法
void boardtrack(string str, vector<int> &track, string &tmp)
{
    if (tmp.size() == str.size())
    {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (!track[i])
        {
            // 先做选择，并做好标记，记录走过的位置
            tmp += str[i];
            track[i] = 1;

            // 递归调用
            boardtrack(str, track, tmp);

            // 回溯，将走过的位置抹除掉。然后tmp中去掉最后一个元素
            track[i] = 0;
            tmp = tmp.substr(0, tmp.length() - 1);
        }
    }
}

vector<string> Permutation(string str)
{
    string tmp;
    vector<int> track(str.size(), 0);
    boardtrack(str, track, tmp);

    // 对于"aa"这样的字符串做排列，会出现重复结果。所以要去掉
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main()
{
    string str = "abc";
    vector<string> ans = Permutation(str);
    for (string s : ans)
    {
        cout << s << endl;
    }
    
    return 0;
}