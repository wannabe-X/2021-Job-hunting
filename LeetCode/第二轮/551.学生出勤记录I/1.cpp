/*
 * @Description: 551.学生出勤记录I
 * @Author: Mr. Lee
 * @Date: 2021-08-17 23:45:10
 * @LastEditTime: 2021-08-17 23:55:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

bool checkRecord(string s)
{
    int countA = 0, countL = 0;
    for (auto &c : s)
    {
        if (c == 'A')
        {
            countA++;
            if (countA >= 2)
                return false;
        }
        else if (c == 'L')
        {
            countL++;
            if (countL == 3)
                return false;
        }

        if (c != 'L')
            countL = 0;
    }

    return true;
}

int main()
{
    string s = "PPALLP";
    bool ans = checkRecord(s);
    cout << boolalpha << ans << endl;

    return 0;
}