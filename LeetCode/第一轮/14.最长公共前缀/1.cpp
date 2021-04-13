#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
        return "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            // 不具有公共前缀的情况
            if (i == strs[j].size() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }

    return strs[0];
}

int main(void)
{
    vector<string> s = {"ff","ff","ff"};
    string ans = longestCommonPrefix(s);
    cout << ans << endl;
    return 0;
}