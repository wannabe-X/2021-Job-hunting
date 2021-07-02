/*
 * @Description: 字符流中第一个不重复的字符
 * @Author: Mr. Lee
 * @Date: 2021-07-02 19:25:20
 * @LastEditTime: 2021-07-02 19:34:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char getFirstAppearingOnce(string str)
    {
        vector<int> dict(256, 0);
        for (auto &c : str)
        {
            dict[c] += 1;
        }

        for (auto &c : str)
        {
            if (dict[c] == 1)
                return c;
        }
        return '#';
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        return getFirstAppearingOnce(s);
    }

private:
    string s;
};

int main()
{
    Solution sol;
    sol.Insert('g');
    cout << sol.FirstAppearingOnce();
    sol.Insert('o');
    cout << sol.FirstAppearingOnce();
    sol.Insert('o');
    cout << sol.FirstAppearingOnce();
    sol.Insert('g');
    cout << sol.FirstAppearingOnce();
    sol.Insert('l');
    cout << sol.FirstAppearingOnce();
    sol.Insert('e');
    cout << sol.FirstAppearingOnce();

    return 0;
}
