#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//去掉收尾空格
string &ClearHeadTailSpace(string &str)
{
    if (str.empty())
    {
        return str;
    }

    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}

// 左闭右闭 翻转字符串
void Reverse(string &s, int left, int right)
{
    while (left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

string reverseWords(string s)
{
    if (s.empty())
    {
        return s;
    }

    Reverse(s, 0, s.size() - 1);

    string res;

    int left = 0, right = 0;

    // 结束的条件是s[left]等于结束符
    while (s[left] != '\0')
    {
        // 如果s[left]不等于空格，则两个指针同时前进
        if (s[left] == ' ')
        {
            left++;
            right++;
        }
        // s[left]不等于空格，s[right]等于空格或结束符
        // 说明[left,right-1]就是应该要反转的字符串
        else if (s[right] == ' ' || s[right] == '\0')
        {
            // right进循环，是空格或者结束符
            // 那么真正包含单词的区间为[left,right-1] 闭区间
            Reverse(s, left, right - 1);                 // 注意Resverse是左闭右闭的，所以right要减1
            res += (s.substr(left, right - left) + ' '); // 将反转的字符串加到res中，并且在末尾加上一个空格
            left = right;                                // left走到right的位置，要么是空格，要么是结束符
        }
        // s[left]、s[right]均不为空格
        // 此时应该left停住,right继续走
        else
        {
            right++;
        }
    }

    // 字符串最后一个位置放的是空格，要去掉
    // return res.erase(res.size() - 1);
    
    return res.substr(0, res.size() - 1);
}

int main(void)
{
    string s = "the sky is      blue.    ";
    string ans = reverseWords(s);
    cout << ans << endl;
    return 0;
}