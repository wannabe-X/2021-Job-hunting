/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-25 16:20:35
 * @LastEditTime: 2021-07-25 17:16:41
 * @LastEditors: Mr. Lee
 */
// /*
//  * @Description: 多多的求和计算
//  * @Author: Mr. Lee
//  * @Date: 2021-07-25 16:20:35
//  * @LastEditTime: 2021-07-25 16:53:57
//  * @LastEditors: Mr. Lee
//  */

// #include <vector>
// #include <iostream>

// using namespace std;

// long long res = 0;

// void func(vector<int> &v, int &M, int &k)
// {
//     for (int i = 0; i < v.size() + 1 - k; i++)
//     {
//         long long sum = 0;
//         for (int j = i; j < i + k; j++)
//         {
//             sum += v[j];
//         }

//         if (sum % M == 0)
//         {
//             res++;
//         }
//     }
// }

// long long function(vector<int> &v, int &M)
// {

//     for (int i = 1; i <= v.size(); i++)
//     {
//         func(v, M, i);
//     }

//     return res;
// }

// int main()
// {
//     // int N = 5, M = 2;
//     // vector<int> v = {1, 2, 3, 4, 5};

//     int N, M;
//     cin >> N >> M;
//     vector<int> v(N);
//     for (int i = 0; i < N; cin >> v[i], i++)
//         ;
//     int ans = function(v, M);
//     cout << ans << endl;

//     return 0;
// }

// 参考代码

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    // int n, m;
    // cin >> n >> m;
    // int arr[n];
    // for (int i = 0; i < n; ++i)
    // {
    //     cin >> arr[i];
    // }

    int n = 5, m = 2;
    vector<int> arr = {1, 2, 3, 4, 5};
    int map[m]; //下标表示前缀和 % m后的值，map[i]表示取余后值为i的个数；
    memset(map, 0, sizeof(map));
    map[0] = 1; //需要设置这个初始值，看下面代码就懂了
    long sum = 0;
    long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        int index = sum % m;
        cout<<map[index]<<" ";
        ans += map[index]++;
        
    }

    cout << ans << endl;

    return 0;
}