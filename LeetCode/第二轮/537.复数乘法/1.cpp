/*
 * @Description: 537. 复数乘法
 * @Author: Mr. Lee
 * @Date: 2022-02-25 17:17:56
 * @LastEditTime: 2022-02-25 19:34:14
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string complexNumberMultiply(string num1, string num2)
{
    int idx_plus = 0, idx_i = 0;
    idx_plus = num1.find('+');
    idx_i = num1.find('i');
    int a = 0, b = 0, c = 0, d = 0;
    a = stoi(num1.substr(0, idx_plus)), b = stoi(num1.substr(idx_plus + 1, idx_i - idx_plus - 1));
    idx_plus = num2.find('+');
    idx_i = num2.find('i');
    c = stoi(num2.substr(0, idx_plus)), d = stoi(num2.substr(idx_plus + 1, idx_i - idx_plus - 1));
    return to_string(a * c - b * d) + '+' + to_string(a * d + b * c) + 'i';
}

int main(int argc, char *argv[])
{
    string num1 = "1+1i", num2 = "1+1i";
    string ans = complexNumberMultiply(num1, num2);
    cout << ans << endl;

    return 0;
}