#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> myMap;
    int left = 0, right = 0, res = 0;
    while (right < s.size())
    {
        char c1 = s[right];
        myMap[c1]++;
        right++;

        // 保证(left,right]左开右闭区间内无重复
        while (myMap[c1] > 1) 
        {
            char c2 = s[left];
            myMap[c2]--;
            left++;
        }
        
        // 每次在确保没有重复的情况下计算最大不重复的长度
        res = max(res, right - left);
    }

    return res;
}

int main(void)
{
    string s = "pwkwww";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}