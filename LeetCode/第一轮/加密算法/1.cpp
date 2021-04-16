#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "time.h"

// 超级简单的对称加密算法
// 通信双方 获取加密密钥 
// 发方将数据与密钥异或运算发送加密数据
// 收方将加密数据与密钥做异或运算解密
// 存在的问题：密钥在传输过程中容易被Hack获取，造成数据安全问题
using namespace std;

void getKey(unsigned int a, unsigned int b, vector<int> &key)
{

    for (unsigned int t = b; t; key.push_back(!!(a & t)), t >>= 1)
        ;
}

void encryption(string &c, vector<int> &key)
{
    int len = c.size();
    for (int i = 0; i < len; i++)
    {
        c[i] = c[i] ^ key[i];
    }
}

void decode(string &c, vector<int> &key)
{
    int len = c.size();
    for (int i = 0; i < len; i++)
    {
        c[i] = c[i] ^ key[i];
    }
}

int main(void)
{
    string str;
    cout << "Please enter the password (no more than 16 digits):";
    cin >> str;

    vector<int> key;
    // 设置随机种子
    srand((unsigned)time(NULL));
    // 获取密钥
    int Pw = pow(2, str.size() - 1);
    getKey(rand() %  Pw, Pw, key);

    cout << "original:" << str << endl;

    // 加密
    encryption(str, key);
    cout << "encode" << str << endl;

    // 解密
    decode(str, key);
    cout << "decode:" << str << endl;
    return 0;
}