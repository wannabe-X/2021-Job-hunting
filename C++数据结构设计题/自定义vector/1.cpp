/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 17:03:33
 * @LastEditTime: 2021-12-13 17:19:42
 * @LastEditors: Mr. Lee
 */
#include <bits/stdc++.h>
using namespace std;

class Vector
{
private:
    int *head;
    int *tail;
    int *end;

public:

    // 构造函数 底层维护3个指针
    Vector() : head(nullptr), tail(nullptr), end(nullptr) {}

    // 析构函数
    ~Vector()
    {
        if (head != nullptr)
        {
            delete[] head;
            head = tail = end = nullptr;
        }
    }

    // 返回数组大小
    size_t size()
    {
        return tail - head;
    }
    
    // 返回容量
    size_t capacity()
    {
        return end - head;
    }

    // 数组扩容
    void expand(size_t new_cpt)
    {
        if (new_cpt <= capacity())
            return;
        cout << "expand" << endl;
        // 开辟更大的空间
        int *new_head = new int[new_cpt];
        int *new_tail = new_head;
        int *new_end = new_head + new_cpt;
        
        // 移动数据
        int *cur = head;
        while (cur < end)
        {
            *new_tail++ = *cur++;
        }

        // 释放原空间
        delete[] head;
        head = new_head;
        tail = new_tail;
        end = new_end;
    }

    // 
    void push_back(int value)
    {
        if (tail == end)
        {
            size_t new_capacity = (end == nullptr ? 3 : capacity() * 2);
            expand(new_capacity);
        }
        *tail++ = value;
    }
    
    void pop_back()
    {
        if (tail != head && tail != nullptr)
        {
            --tail;
        }
    }
    int &operator[](int index)
    {
        return *(head + index);
    }
};

int main()
{
    Vector v;
    for (int i = 0; i < 20; i++)
        v.push_back(i);
    for (int i = 0; i < 20; i++)
        cout << v[i] << endl;
}