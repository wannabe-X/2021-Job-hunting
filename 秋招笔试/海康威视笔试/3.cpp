/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-14 16:01:04
 * @LastEditTime: 2021-09-14 16:53:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    vector<int> res;
    while (num)
    {
        res.push_back(num % 7);
        num /= 7;
    }
    for (int i = res.size() - 1; i > -1; i--)
    {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
