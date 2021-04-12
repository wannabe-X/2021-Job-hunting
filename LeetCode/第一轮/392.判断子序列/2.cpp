#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 利用二分查找法进行求解
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

bool isSubsequence(string s, string t)
{
    unordered_map<char, vector<int>> myMap = t_pretreatment(t);

    int k = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (myMap[c].empty())
            return false;

        int pos = left_bound(myMap[c], k);
        if (pos == myMap[c].size())
            return false;
        k = myMap[c][pos] + 1;
    }

    return true;
}

int main(void)
{
    string s = "abc", t = "abcdefg";

    bool ans = isSubsequence(s, t);
    cout << boolalpha << ans << endl;

    return 0;
}