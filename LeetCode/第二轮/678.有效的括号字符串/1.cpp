/*
 * @Description: 678. 有效的括号字符串
 * @Author: Mr. Lee
 * @Date: 2021-09-12 00:11:32
 * @LastEditTime: 2021-09-12 00:35:10
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// bool checkValidString(string s)
// {
//     int numOfStar = 0;
//     stack<char> stk;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (!stk.empty() && stk.top() == '(' && s[i] == ')')
//             stk.pop();
//         else if (s[i] == '*')
//             numOfStar++;
//         else
//             stk.push(s[i]);
//     }

//     return (stk.empty() || stk.size() == numOfStar);
// }

bool checkValidString(string s)
{
    int minCount = 0, maxCount = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            minCount++;
            maxCount++;
        }
        else if (s[i] == ')')
        {
            minCount = max(minCount - 1, 0);
            maxCount--;
            if (maxCount < 0)
                return false;
        }
        else
        {
            minCount = max(minCount - 1, 0);
            maxCount++;
        }
    }

    return minCount == 0;
}

int main(void)
{
    string str = "(((((*)(*)*))))))))))";
    bool ans = checkValidString(str);
    cout << boolalpha << ans;

    return 0;
}