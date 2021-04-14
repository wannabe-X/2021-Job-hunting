#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string replaceSpace(string s)
{
    int count = 0, length = s.size();

    for (char c : s)
    {
        if (c == ' ')
            count++;
    }
    s.resize(length + 2 * count);

    for (int i = length - 1, j = s.size() - 1; i < j; i--, j--)
    {
        if (s[i] != ' ')
            s[j] = s[i];
        else
        {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 2;
        }
    }
    return s;
}

int main(void)
{
    string s = " We are happy. ";
    string ans = replaceSpace(s);
    cout << ans << endl;
    return 0;
}