#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

string replaceSpace(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]== ' ')
            s = s.substr(0,i) + "%20" + s.substr(i+1);
    }
    return s;
}

int main(void)
{
    string s = "We are happy. ";
    string ans = replaceSpace(s);
    cout << ans << endl;
    return 0;
}