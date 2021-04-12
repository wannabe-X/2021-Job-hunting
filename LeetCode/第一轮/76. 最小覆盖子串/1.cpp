#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t)
{
    int start = 0, minLen = INT_MAX;
    int left = 0, right = 0;

    unordered_map<char, int> windows;
    unordered_map<char, int> needs;

    for (char c : t)
        needs[c]++;

    int match = 0;

    while (right < s.size())
    {
        char c1 = s[right];
        if (needs.count(c1))
        {
            windows[c1]++;
            if (windows[c1] == needs[c1])
            {
                match++;
            }
        }
        right++;

        while (match == needs.size())
        {
            if (right - left < minLen)
            {
                start = left;
                minLen = right - left;
            }

            char c2 = s[left];
            if (needs.count(c2))
            {
                windows[c2]--;
                if (windows[c2] < needs[c2])
                    match--;
            }
            left++;
        }
    }

    return minLen == INT_MAX ? " " : s.substr(start, minLen);
}

int main(void)
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minWindow(s, t);
    cout << result;
}