#include <iostream>
#include <cmath>

using namespace std;

int countOfIntegers(int digit)
{
    if (digit == 1)
        return 10;
    return 9 * pow(10, digit - 1) * digit;
}

// 计算digit位数的起始位置
int beginNumber(int digit)
{
    if (digit == 1)
        return 0;
    return pow(10, digit - 1);
}

int digitAtIndex(int idx, int digitCapacity)
{
    // 先找到以digit位数开始的头号数字
    // 计算偏移量idx / digit
    // 注意从0开始计算的，所以偏移量不需要减1
    int number = beginNumber(digitCapacity) + idx / digitCapacity;

    // 从后往前退indexFromRight-1步的元素
    int indexFromRight = digitCapacity - idx % digitCapacity - 1;
    // int indexFromRight = (idx / digitCapacity + 1) * digitCapacity - (idx + 1);
    for (int i = 0; i < indexFromRight; i++)
    {
        number /= 10;
    }
    return number % 10;
}

int findNthDigit(int n)
{
    int digitCapacity = 1;

    // while (true)
    // {
    //     int numbers = countOfIntegers(digitCapacity);
    //     if (n < numbers)
    //         return digitAtIndex(n, digitCapacity);
    //     n -= numbers;
    //     digitCapacity++;
    // }

    for (; n >= countOfIntegers(digitCapacity); n -= countOfIntegers(digitCapacity), digitCapacity++)
        ;
    //含义 在digitCapacity位数字中，寻找索引以n为索引的元素
    // 例如digitAtIndex(0, 2) 表示在两位数中寻找索引为0的元素。也就是1
    return digitAtIndex(n, digitCapacity);
}

int main(void)
{
    int n = 5;
    int ans = findNthDigit(n);
    cout << ans << endl;
    return 0;
}