/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-26 22:27:18
 * @LastEditTime: 2021-07-26 22:29:57
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
    int A, B;
    cin >> A >> B;
    while (A != 0 || B != 0)
    {
        cout << Add(A, B) << endl;
        cin >> A >> B;
    }
    return 0;
}
