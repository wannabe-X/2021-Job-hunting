#include <iostream>

using namespace std;

int i = 0;

//扫描空格
void getSpace(string &s)
{
    while (i < s.size() && s[i] == ' ')
        i++;
}

//扫描无符号整数
bool getUint(string &s)
{
    int tmp = i;
    while (i < s.size() && isdigit(s[i]))
        i++;
    return i > tmp;
}

//扫描有符号整数
bool getInt(string &s)
{
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        i++;
    return getUint(s);
}

bool isNumber(string s)
{
    if (s == "")
        return false;

    getSpace(s);

    bool flag = getInt(s);

    if (i < s.size() && s[i] == '.')
    {
        i++;
        //当为.时,后面必须是无符号整数，并且.的前后只要有一个为true就行
        //而且必须把getUint(s)放在前面，不然由于||的短视特征，小数点后面可能不会被扫描到
        flag = getUint(s) || flag;
    }

    if (i < s.size() && (s[i] == 'e' || s[i] == 'E'))
    {
        i++;
        flag = flag && getInt(s); //e的前后都必须为true
    }

    getSpace(s);

    return i == s.size() && flag;
}

int main(void)
{
    string s = "    .1.2";
    bool ans = isNumber(s);
    cout << boolalpha << ans << endl;
    return 0;
}