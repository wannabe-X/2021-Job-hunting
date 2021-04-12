#include <iostream>

using namespace std;
// 暴力破解法
bool isSubsequence(string s, string t)
{
    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (s[j] == t[i])
            j++;
    }
    return j == s.size();
}

int main(void)
{
    string s = "abc", t = "ahbgdc";
    cout << boolalpha << isSubsequence(s, t) << endl;
    return 0;
}