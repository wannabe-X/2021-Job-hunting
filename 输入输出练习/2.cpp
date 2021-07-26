/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 22:24:55
 * @LastEditTime: 2021-07-26 22:26:38
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

int Add(int a, int b)
{
    return a + b;
}

int main()
{
    int N;
    cin >> N;
    int A, B;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B;
        cout << Add(A, B) << endl;
    }
    return 0;
}