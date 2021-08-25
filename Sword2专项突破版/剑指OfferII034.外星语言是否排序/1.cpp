/*
 * @Description: 剑指 Offer II 034. 外星语言是否排序
 * @Author: Mr. Lee
 * @Date: 2021-08-21 21:15:40
 * @LastEditTime: 2021-08-21 21:18:38
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>

using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    
}

int main()
{
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    bool ans = isAlienSorted(words, order);
    cout << boolalpha << ans << endl;

    return 0;
}