/*
 * @Description: 345. 反转字符串中的元音字母
 * @Author: Mr. Lee
 * @Date: 2021-08-19 09:44:32
 * @LastEditTime: 2021-08-19 09:59:27
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// bool isVowel(char c)
// {
//     if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
//     {
//         return true;
//     }

//     return false;
// }

string reverseVowels(string s)
{
    // 匿名函数
    auto isVowel = [](char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return true;
        }

        return false;
    };

    // 双指针
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        while (left < s.size() && !isVowel(s[left]))
        {
            left++;
        }

        while (right > 0 && !isVowel(s[right]))
        {
            right--;
        }

        if (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }

    return s;
}

int main()
{
    string s = "hello";
    string ans = reverseVowels(s);
    cout << ans << endl;

    return 0;
}
