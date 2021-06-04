#include <iostream>
#include <string.h>

using namespace std;



int lengthOfLastWord(string s)
{

    // 去掉字符首尾空格
    s.erase(0,s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ')+1);

    char *next = &s[0];

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            next = &s[i];
        }
    }

    return next[0] == ' ' ? strlen(next + 1) : strlen(next);
}

int main()
{
    string s = " hello worlds ";
    int ans = lengthOfLastWord(s);
    cout << ans << endl;

    return 0;
}