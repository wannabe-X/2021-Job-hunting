/*
 * @Description: 65. 有效数字。
 * @Author: Mr. Lee
 * @Date: 2021-06-17 09:41:00
 * @LastEditTime: 2021-06-17 15:16:36
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

bool isNumber(string s)
{
    // 当且仅当第一位为小数点 或第一位为符号第二位为小数点时小数点后一位必须是数字，
    // 且当第一位为符号，第二位必须为小数点或数字，预处理此情况
    switch (s[0])
    {
    case '+':
    case '-':
        if (s.size() == 1 || (s.size() == 2 && !isdigit(s[1])) || (s[1] == '.' && !isdigit(s[2])) || (s[1] != '.' && !isdigit(s[1])))
            return false;
        break;
    case '.':
        if (s.size() == 1 || !isdigit(s[1]))
            return false;
        break;
    }
    
    /*
        digit ：判断是否出现过数字
        eorE ：判断是否出现过e、E
        Dot ：判断是否出现过.
    */

    int digit = 0, eorE = 0, Dot = 0;

    for (auto i : s)
    {
        if (isdigit(i))
        {
            digit = 1;
        }
        else if (i == '.')
        {
            if (Dot || eorE)
            {
                return false;
            }
            else
            {
                Dot = 1;
            }
        }
        else if (i == 'e' || i == 'E')
        {
            if (eorE || !digit)
            {
                return false;
            }
            else
            {
                eorE = 1;
                digit = 0;
            }
        }
        else if (i == '+' || i == '-')
        {
            if (digit)
            {
                return false;
            }
            else
            {
                digit = 1;
            }
        }
        else
        {
            return false;
        }
    }

    return isdigit(s.back()) || s.back() == '.';
}

// bool isNumber(string s)
// {
//     // 当且仅当第一位为小数点或第一位为符号第二位为小数点时小数点后一位必须是数字，
//     // 且当第一位为符号，第二位必须为小数点或数字，预处理此情况
//     switch (s[0])
//     {
//     case '.':
//         if (s.size() == 1 || !isdigit(s[1]))
//             return false;
//         break;
//     case '+':
//     case '-':
//         if (s.size() == 1 || (s.size() == 2 && !isdigit(s[1])) || (s[1] == '.' && !isdigit(s[2])) || (s[1] != '.' && !isdigit(s[1])))
//             return false;
//         break;
//     }

//     bool isFirst{}; // 是否为数字首位
//     bool haveDot{};     // 是否出现过小数点.
//     bool haveE{};       // 是否出现过E

//     for (auto &i : s)
//     {
//         if (isdigit(i))
//         {
//             isFirst = true;
//         }
//         else if (i == '.')
//         {
//             if (haveDot || haveE)
//             {
//                 return false;
//             }
//             else
//             {
//                 haveDot = true;
//             }
//         }
//         else if (i == 'e' || i == 'E')
//         {
//             if (haveE || !isFirst)
//             {
//                 return false;
//             }
//             else
//             {
//                 haveE = true;
//                 isFirst = false;
//             }
//         }
//         else if (i == '+' || i == '-')
//         {
//             if (!isFirst)
//             {
//                 isFirst = true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             return false;
//         }
//     }

//     return isdigit(s.back()) || s.back() == '.';
// }

int main()
{
    string s;
    cin >> s;
    bool ans = isNumber(s);
    cout << boolalpha << ans << endl;

    return 0;
}
