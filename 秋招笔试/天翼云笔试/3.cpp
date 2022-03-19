/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2022-03-19 18:58:24
 * @LastEditTime: 2022-03-19 20:10:16
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int func(vector<int> weights, vector<int> values)
// {

// }

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; cin >> weights[i], i++)
        ;
    for (int i = 0; i < n; cin >> values[i], i++)
        ;

    int res = func(weights, values);
    cout << res << endl;

    return 0;
}