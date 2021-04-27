#include <iostream>

using namespace std;

int i = 0;
//扫描空格
void getSpace(string &s)
{
    while (i < s.size() && s[i] == ' ')
        i++;
}

int strToInt(string str)
{
    getSpace(str);

    char sign = '+';
    string res;
    
    if (i < str.size() && (str[i] == '+' || str[i] == '-'))
    {
        sign = str[i];
        i++;
    }

    while (i < str.size() && isdigit(str[i]))
    {
        res += str[i];
        i++;
    }

    int res2Int = 0, boundary = INT_MAX / 10;

    for (int i = 0; i < res.size(); i++)
    {
        // 越界处理
        if (res2Int > boundary || res2Int == boundary && res[i] > '7')
            return sign == '+' ? INT_MAX : INT_MIN;

        res2Int = res2Int * 10 + (res[i] - '0');
    }

    long ans = sign == '+' ? res2Int : -res2Int;

    return ans;
}

int main(void)
{
    string s = "2147483646";
    int ans = strToInt(s);
    cout << ans << endl;
    return 0;
}