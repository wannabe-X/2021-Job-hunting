#include <iostream>
#include <cmath>

using namespace std;

int findNthDigit(int n)
{
    // cnt是计算bit为数字的总长度的因子

    // 例如 bit为1时，长度为1的数字占据长度为9（1-9）；
    // bit为2时，长度为2的数字占据长度为180（10-99）
    // bit指的是要寻找的是个长度为bit的数字中的某一位
    int cnt = 0, bit = 1;
    while (n > pow(10, cnt) * 9 * bit)
    {
        n -= pow(10, cnt) * 9 * bit;
        bit++;
        cnt++;
    }

    // 因为要从0开始计数，所以出循环后相当于在数字长度为bit的数字中找到第n-1个数
    // 可以发现pow(10, cnt) + (n - 1) / bit转成字符串
    // 字符串第0位刚好是int((n-1)/bit)*bit的位置
    // 余数(n - 1) % bit作索引，自然就是要寻找的元素位置
    
    // 例如要寻找的数字为第1001位
    // 1001-9-180 = 812
    // 从0开始计数，实际找第812-1位数字
    // cnt=2,100+811/3=370
    // to_string(370)的第0位'3'是第810位数字
    // 811-810 = (811-810)%3 = 811%3 的索引就是要找的元素的位置
    // 所以可以得到结果就是7
    return to_string(pow(10, cnt) + (n - 1) / bit)[(n - 1) % bit] - '0';
}

int main(void)
{
    int n = 1001;
    int ans = findNthDigit(n);
    cout << ans << endl;
    return 0;
}