/*
 * @Description: 66. 加一
 * @Author: Mr. Lee
 * @Date: 2021-10-21 00:23:41
 * @LastEditTime: 2021-10-21 00:54:10
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    string str;
    for (int num : digits)
        str += to_string(num);
    int carry = 0, i = digits.size() - 1, j = 0;
    vector<int> res;

    while (i > -1 || j > -1)
    {
        int tmp1 = i > -1 ? str[i] - '0' : 0, tmp2 = j > -1 ? 1 : 0;
        res.push_back((carry + tmp1 + tmp2) % 10);
        carry = (carry + tmp1 + tmp2) / 10;
        i--;
        j--;
    }

    if (carry)
        res.push_back(1);

    reverse(res.begin(), res.end());

    return res;
}

int main(void)
{
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9, 9, 9, 9};
    vector<int> ans = plusOne(digits);
    for (int num : ans)
        cout << num << " ";

    return 0;
}