/*
 * @Description: 1332. 删除回文子序列
 * @Author: Mr. Lee
 * @Date: 2022-01-22 14:09:17
 * @LastEditTime: 2022-01-22 14:12:10
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removePalindromeSub(string s)
{
    string tmp = s;
    reverse(s.begin(), s.end());

    return tmp == s ? 1 : 2;
}

int main(int argc, char *argv[])
{
    return 0;
}