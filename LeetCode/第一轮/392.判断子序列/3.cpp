#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 对多个字符串进行判断，利用二分查找法进行求解
unordered_map<char, vector<int>> t_pretreatment(string t)
{
    unordered_map<char, vector<int>> myMap;
    for (int i = 0; i < t.size(); i++)
    {
        if (myMap.count(t[i]))
        {
            myMap[t[i]].push_back(i);
            continue;
        }
        myMap[t[i]].push_back(i);
    }
    return myMap;
}

int left_bound(vector<int> arr, int tar)
{
    int lo = 0, hi = arr.size();
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (tar > arr[mid])
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

vector<bool> isSubsequence(vector<string> &s, string t)
{
    unordered_map<char, vector<int>> myMap = t_pretreatment(t);

    vector<bool> contain(s.size(), true);
    int k;

    for (int j = 0; j < s.size(); j++)
    {
        k = 0;
        string s_sub = s[j];

        for (int i = 0; i < s_sub.size(); i++)
        {
            char c = s_sub[i];
            if (myMap[c].empty())
            {
                contain[j] = false;
                break;
            }
            int pos = left_bound(myMap[c], k);
            if (pos == myMap[c].size())
            {
                contain[j] = false;
                break;
            }
            k = myMap[c][pos] + 1;
        }
    }

    return contain;
}

int main(void)
{
    vector<string> s = {"abc", "abcd", "aad", "xyz"};
    string t = "abcdefg";

    vector<bool> ans = isSubsequence(s, t);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << boolalpha << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}