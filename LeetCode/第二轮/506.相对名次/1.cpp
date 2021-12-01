/*
 * @Description: 506. 相对名次
 * @Author: Mr. Lee
 * @Date: 2021-12-02 00:03:35
 * @LastEditTime: 2021-12-02 00:30:29
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
    map<int, int, greater<int>> m;
    for (int i = 0; i < score.size(); i++)
        m[score[i]] = i;

    vector<string> res(score.size());
    auto it = m.begin();
    
    for (int i = 0; i < score.size(); i++)
    {
        if (i == 0)
            res[(*it).second] = "Gold Medal";
        else if (i == 1)
            res[(*it).second] = "Silver Medal";
        else if (i == 2)
            res[(*it).second] = "Bronze Medal";
        else
            res[(*it).second] = to_string(i + 1);
        it++;
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> score = {10, 3, 8, 9, 4};
    vector<string> ans = findRelativeRanks(score);
    for (string str : ans)
        cout << str << " ";
    cout << endl;

    return 0;
}