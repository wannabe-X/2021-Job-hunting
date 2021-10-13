/*
 * @Description: 412. Fizz Buzz
 * @Author: Mr. Lee
 * @Date: 2021-10-13 11:40:00
 * @LastEditTime: 2021-10-13 11:46:44
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> res;
    for (int i = 1; i <= n; i++)
    {

        if (i % 3 == 0 && i % 5 != 0)
            res.push_back("Fizz");
        else if (i % 3 != 0 && i % 5 == 0)
            res.push_back("Buzz");
        else if (i % 3 == 0 && i % 5 == 0)
            res.push_back("FizzBuzz");
        else
            res.push_back(to_string(i));
    }

    return res;
}

int main(void)
{
    int n = 15;
    vector<string> ans = fizzBuzz(n);
    for (string &str : ans)
        cout << str << endl;

    return 0;
}