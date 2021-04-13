#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int left = 0, right = 0, res = 0;
    unordered_map<char, int> window;
    while (right < s.size())
    {
        char c1 = s[right];
        window[c1]++;
        right++;

        while (window[c1] > 1) //出现重复
        {
            char c2 = s[left];
            window[c2]--;
            left++;
        }
        res = max(res, right - left);
    }

    return res;
}

int main(void)
{
    string s = "abcdb";
    int x = lengthOfLongestSubstring(s);
    cout << x << endl;
}