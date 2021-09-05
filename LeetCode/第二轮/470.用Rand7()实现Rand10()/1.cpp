/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-06 01:12:17
 * @LastEditTime: 2021-09-06 01:35:50
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int rand7()
{
    return rand() % 7 + 1;
}

int rand10()
{
    int idx = 0;
    do
    {
        int col = rand7(), row = rand7();
        idx = col + (row - 1) * 7;
    } while (idx > 40);

    return 1 + (idx - 1) % 10;
}

int main(void)
{
    int ans = rand10();
    cout << ans << endl;
    
    return 0;
}