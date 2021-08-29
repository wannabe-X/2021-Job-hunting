/*
 * @Description: C++ string类的实现
 * @Author: Mr. Lee
 * @Date: 2021-08-28 22:28:53
 * @LastEditTime: 2021-08-28 22:32:58
 * @LastEditors: Mr. Lee
 */
#include <string.h> //C语言中的string
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//经典的面试题
class String
{
public:
    String() : _pstr(nullptr)
    {
        cout << "String()" << endl;
    }

    String(const char *pstr) : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    //将拷贝构造函数、赋值运算符函数称为具有复制控制的函数
    //const左值引用就是一个万能引用
    //const左值引用，不能区分出左值与右值
    String(const String &rhs) : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if (this != &rhs)
        {
            delete[] _pstr;
            _pstr = nullptr;

            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }

        return *this;
    }

    //移动语义的函数，编译器不会主动生成
    //将移动构造函数、移动赋值运算符函数称为具有移动语义的函数
    //String s2 = String("hello");
    //当传递的是右值的时候，移动构造函数优先于拷贝构造函数的执行
    //移动构造函数
    String(String &&rhs) : _pstr(rhs._pstr)
    {
        cout << "String(String &&)" << endl;
        rhs._pstr = nullptr;
    }

    //s3 = String("hello");
    //String("hello") = String("hello");
    //移动赋值运算符函数
    String &operator=(String &&rhs)
    {
        cout << "String &operator=(String &&)" << endl;
        if (this != &rhs) //1、自移动
        {
            delete[] _pstr; //2、释放左操作数
            _pstr = nullptr;

            _pstr = rhs._pstr; //3、浅拷贝
            rhs._pstr = nullptr;
        }

        return *this; //4、返回*this
    }

    ~String()
    {
        cout << "~String()" << endl;
        if (_pstr)
        {
            delete[] _pstr;
            _pstr = nullptr;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);

private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    os << rhs._pstr;

    return os;
}

void test()
{
    //Point(1, 2);
    String s1("hello");
    vector<String> vec;
    vec.push_back("hello,world"); //C风格字符串 String("hello,world")===>发生了隐式转换
                                  //右值
    cout << "vec[0] = " << vec[0] << endl;
    vec.push_back(s1); //拷贝构造函数的调用,左值
}

void test2()
{
    String s1("hello");
    cout << "s1 = " << s1 << endl;

    cout << endl;
    String s2(s1);
    cout << "s2 = " << s2 << endl;

    cout << endl;
    String s3 = String("world");
    cout << "s3 = " << s3 << endl;
}

void test3()
{
    String s1("hello");
    cout << "s1 = " << s1 << endl;

    cout << endl;
    String s2(s1);
    cout << "s2 = " << s2 << endl;

    cout << endl;
    s2 = String("world");
    cout << "s2 = " << s2 << endl;

    cout << endl
         << "对s2执行std::move(s2)之后: " << endl;
    s2 = std::move(s2);
    cout << "s2 = " << s2 << endl;

    //std::move可以吧一个左值转换为一个右值
    //表明不想使用左值,
    //std::move就是进行一个强制转换，将左值转为右值，static_cast<T &&>(lvaule)
    cout << endl;
    String s3 = std::move(s2);
    cout << "s3 = " << s3 << endl;

    //如果通过std::move调用，将一个左值转为右值之后，还想继续使用值，必须对其重新赋值
    s2 = s1;
    cout << "s2 = " << s2 << endl;
    cout << "111" << endl;
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}