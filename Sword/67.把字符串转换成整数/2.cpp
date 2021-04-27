#include <iostream>

using namespace std;

// 参考代码
int strToInt(string str)
{
    int res = 0, i = 0;
    bool flag = true;
    //检查空格
    while (str[i] == ' ')
        i++;
    //检查符号
    if (str[i] == '-')
        flag = false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    //检查数字
    for (; i < str.size(); i++)
    {
        int r = str[i] - '0';
        //判断是否是数字 也可以用isdigit(str[i])
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && r > 7)
            {
                return flag ? INT_MAX : INT_MIN;
            }
            res = 10 * res + r;
        }
        else
            break;
    }
    return flag ? res : -res;
}

int main(void)
{
    string s = "2147483646";
    int ans = strToInt(s);
    cout << ans << endl;
    return 0;
}
