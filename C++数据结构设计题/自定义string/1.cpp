/*
 * @Description: 自定义String类
 * @Author: Mr. Lee
 * @Date: 2021-12-14 16:55:46
 * @LastEditTime: 2021-12-16 16:26:59
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <assert.h>
using namespace std;

int my_strlen(const char *p)
{
    int count = 0;
    assert(p);
    while (*p != '\0')
    {
        p++;
        count++;
    }
    return count;
}

char *my_strcopy(char *dest, char *source)
{
    assert(!dest);
    assert(!source);
    char *res = dest;
    while ((*dest++ = *source++) != '\0')
        ;
    return res;
}

// 目的地址介于原地址之间,则先从高地址开始拷贝
char *my_memcopy(char *dest, const char *source, int count)
{
    assert(!dest);
    assert(!source);
    char *res = dest;
    if (dest >= source && dest <= source + count - 1) //高地址开始复制
    {
        dest += count - 1;
        source += count - 1;
        while (count--)
            *dest-- = *source--;
    }
    else
    {
        while (count--)
            *dest++ = *source++;
    }
    return res;
}

char *my_strcopy_mem(char *dest, const char *source)
{
    assert(!dest);
    assert(!source);
    char *res = dest;
    my_memcopy(dest, source, my_strlen(source) + 1);
    return res;
}

class myString
{
private:
    char *p;
    int *count;

public:
    
    // 构造函数
    myString(const char *str = nullptr)
    {
        if (str == nullptr)
        {
            p = new char[1];
            *p = '\0';
        }
        else
        {
            p = new char[my_strlen(p) + 1];
            my_strcopy_mem(p, str);
        }
        *count = 1;
    }

    // 析构函数
    ~myString()
    {
        if (p != nullptr && --(*count) == 0)
        {
            delete[] p;
            p = nullptr;
            delete[] count;
            count = nullptr;
        }
    }
    
    // 拷贝构造函数
    myString(const myString &str) : p(str.p), count(str.count)
    {
        (*count)++;
    }

    // 赋值运算符重载
    myString &operator=(const myString &str)
    {
        if (this != &str)
        {
            if (p != nullptr && --(*count) == 0)
            {
                delete[] p;
                delete[] count;
            }
            p = str.p;
            count = str.count;
            *(count)++;
        }
        
        return *this;
    }
};

int main()
{
    auto a = new int[5];
    cout << sizeof *((int *)a - 2) << endl;
}