/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 22:40:38
 * @LastEditTime: 2021-07-26 22:43:46
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int Add(vector<int> &a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int N, len;
    cin >> N;
    while (N--)
    {
        cin >> len;
        vector<int> v(len);
        for (int i = 0; i < len; i++)
            cin >> v[i];
        cout << Add(v) << endl;
    }
    
    return 0;
}