#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string minNumber(vector<int> &nums)
{
    vector<string> temp;
    string res;
    for (int num : nums)
        temp.push_back(to_string(num));

    // c++中的[] 相当于lambda函数
    // 排序规则：拼接的字符串x+y<y+x，则x<y,那么x应该排在y之前
    sort(temp.begin(), temp.end(), [](string &x, string &y) { return x + y < y + x; });

    for (string s : temp)
        res += s;
    return res;
}

int main(void)
{
    vector<int> nums = {3, 30, 34, 5, 9};
    string ans = minNumber(nums);
    cout << ans << endl;
    return 0;
}