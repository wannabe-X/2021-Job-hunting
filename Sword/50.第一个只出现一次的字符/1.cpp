#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

char firstUniqChar(string s)
{
    unordered_map<char, int> myMap;

    for (char c : s)
    {
        if (myMap.count(c))
            myMap[c] += 1;
        else
            myMap[c] = 1;
    }

    for (char c : s)
    {
        if (myMap[c] == 1)
            return c;
    }

    return ' ';
}

int main(void)
{
    string s = "leetcode";
    char ans = firstUniqChar(s);
    cout << ans << endl;
    return 0;
}