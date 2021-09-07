/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-30 17:34:53
 * @LastEditTime: 2021-09-06 00:51:42
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

double f(double x, double delta, double begin, double end)
{
    double mid = (begin + end) / 2;
    if (x < mid * mid)
    {
        return f(x, delta, begin, mid);
    }
    else if (x >= (mid + delta) * (mid + delta))
    {
        return f(x, delta, mid, end);
    }
    else
    {
        return mid;
    } //对比这个递归 和 斐波那契的 递归
      //不同之处在于  此处 是单分支 递归  --->好递归
      //而 斐波那契 是多分支 递归 指数级增长   --->坏递归
}

double sqrt(int x, double delta)
{
    if (x < 0)
    {
        return -1; //简单地异常处理
    }
    //x是被开方数字，delta是最大允许误差
    //为了方便处理，姑且认为0 =< x^0.5 - sqrt(x) < delta
    //这相当于是 将 范围 限制得更严格 了
    double begin = 0, end = double(x);
    //因为x is a int ,so x^0.5 < x
    //开始 递归
    return f(double(x), delta, begin, end);
}

int main(void)
{
    int x = 5;
    cin >> x;
    printf("%f\n", sqrt(x, 0.00000001));
    //printf和cout打印出来的位数并不同
    cout << sqrt(x, 0.00000001) << endl;
    //这里 值得讨论的地方就是 delta精度取到多少以后，就没有意义了？
    //double的 内部结构 构成 浮点数 的 机制
    return 0;
}
