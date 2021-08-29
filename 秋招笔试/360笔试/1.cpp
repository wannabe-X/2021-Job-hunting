/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-29 14:47:30
 * @LastEditTime: 2021-08-29 16:32:27
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> &v, int p, int q)
{
    sort(v.begin(), v.end(), [](int a, int b)
         { return a > b; });

    vector<int> v1;
    v1.push_back(100);
    
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            v1.push_back(v1.back());
        }
        else
        {
            v1.push_back(v1.back() - 1);
        }
    }

    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        float grade = (v[i] * q + v1[i] * p + 0.0) / 100.0;
        if (grade >= 60.0)
            count++;
    }

    return count;
}

int main(void)
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = func(v, p, q);
    cout << ans;

    return 0;
}