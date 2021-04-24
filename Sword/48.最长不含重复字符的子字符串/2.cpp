#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int curLength = 0, maxLength = 0;
    vector<int> position(26, -1);

    for (int i = 0; i < s.size(); i++)
    {
        // prevIndex是当前元素在上一次出现位置的索引
        int prevIndex = position[s[i] - 'a'];
        // 首次出现不重复元素
        // 或者重复元素已经出现在当前重复元素之间
        // 类似于"abccdea" c出现在a...a中间
        if (prevIndex < 0 || i - prevIndex > curLength)
            curLength++;
        else
        {
            // 重复元素在上一轮元素中出现
            // 类似"abcdea" 或者 "abcded"这种情形
            // 那么早当前不重复元素长度为i - prevIndex
            if (maxLength < curLength)
                maxLength = curLength;
            curLength = i - prevIndex;
        }

        position[s[i] - 'a'] = i;
    }

    if (curLength > maxLength)
        maxLength = curLength;

    return maxLength;
}

int main(void)
{
    string s = "pwkwww";
    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}