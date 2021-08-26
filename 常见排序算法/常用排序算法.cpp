/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-26 15:11:39
 * @LastEditTime: 2021-08-26 15:44:12
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <time.h>

using namespace std;

struct myPrint
{
    void operator()(int val)
    {
        cout << val << " ";
    }
};

struct myCompare
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

// merge 算法
void test01()
{
    vector<int> v1, v2;
    list<int> l3;
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(rand() % 10);
    }

    for (int i = 0; i < 10; i++)
    {
        // v2.push_back(rand() % 10);
        l3.push_back(rand() % 10);
    }

    sort(v1.begin(), v1.end(), myCompare());
    // sort(v2.begin(), v2.end(), myCompare());
    l3.sort(myCompare());

    vector<int> v3;
    // 开辟空间
    // v3.resize(v1.size() + v2.size());
    v3.resize(v1.size() + l3.size());
    // merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), myCompare());
    // 合并链表和向量
    merge(v1.begin(), v1.end(), l3.begin(), l3.end(), v3.begin(), myCompare());

    for_each(v3.begin(), v3.end(), myPrint());
}

// random_shuffle
void test02()
{
    // vector<int> v;
    list<int> v;
    for (int i = 0; i < 9; i++)
    {
        v.push_back(i);
    }

    // STL语法丑陋不堪，但是效率高
    // 打印有序容器
    for_each(v.begin(), v.end(), myPrint());
    // 随机打乱 洗牌算法
    random_shuffle(v.begin(), v.end()); // 如果容器不支持随机访问，则不能使用random_shuffle
    // 打印打乱后的元素
    cout << endl;
    for_each(v.begin(), v.end(), myPrint());
}

// reverse 反转
void test03()
{
    // vector<int> v;
    list<int> v;
    for (int i = 0; i < 9; i++)
    {
        v.push_back(i);
    }

    // 打印有序容器
    for_each(v.begin(), v.end(), myPrint());
    // 随机打乱 洗牌算法
    reverse(v.begin(), v.end()); // 如果容器不支持随机访问，则不能使用reverse
    // 打印打乱后的元素
    cout << endl;
    for_each(v.begin(), v.end(), myPrint());
}

int main(int argc, char *argv[])
{
    test01();
    // test02();
    // test03();
    return 0;
}