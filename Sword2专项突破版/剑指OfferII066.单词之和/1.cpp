/*
 * @Description: 剑指 Offer II 066. 单词之和
 * @Author: Mr. Lee
 * @Date: 2021-09-02 14:58:36
 * @LastEditTime: 2021-09-02 15:04:46
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class MapSum
{
public:
    /** Initialize your data structure here. */
    MapSum()
    {
        m.clear();
    }

    void insert(string key, int val)
    {
        m[key] = val;
    }

    int sum(string prefix)
    {
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if ((*it).first.substr(0, prefix.size()) == prefix)
                res += (*it).second;
        }

        return res;
    }

private:
    unordered_map<string, int> m;
};

int main(void)
{
    MapSum mapSum;
    mapSum.insert("apple", 3);
    cout << mapSum.sum("ap") << endl; // return 3 (apple = 3)
    mapSum.insert("app", 2);
    cout << mapSum.sum("ap") << endl; // return 5 (apple + app = 3 + 2 = 5)

    return 0;
}