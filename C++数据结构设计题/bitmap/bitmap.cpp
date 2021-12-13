/*
 * @Description: bitmap
 * @Author: Mr. Lee
 * @Date: 2021-12-13 09:46:24
 * @LastEditTime: 2021-12-13 10:10:53
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define N 20 // 考究0~19这20个数字
#define SHIFT 5
#define MASK 0x1f
unsigned int a[1 + N / 32] = {0};

// 设置第i位为1, 让它处于点亮状态
void setOne(int i)
{
    a[i >> SHIFT] |= (1 << (i & MASK));
}

// 设置第i位为0, 让它处于熄灭状态
void setZero(int i)
{
    a[i >> SHIFT] &= ~(1 << (i & MASK));
}

// 获取第i位的状态
int getState(int i)
{
    return (a[i >> SHIFT] & (1 << (i & MASK))) && 1;
}

int main(void)
{
    // 把1，3，1，4，9，9，9这几个值的状态点亮，即状态为1
    setOne(1);
    setOne(3);
    setOne(1);
    setOne(4);
    setOne(9);
    setOne(9);
    setOne(9);

    int i = 0;
    for (i = 0; i < N; i++)
    {
        cout << i << "对应的状态为:--->" << getState(i) << endl; // 获取状态
    }
    cout << endl;

    return 0;
}