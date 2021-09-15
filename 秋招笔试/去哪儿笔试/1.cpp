/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-14 12:38:37
 * @LastEditTime: 2021-09-14 13:33:44
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;
class Solution
{
public:
    /* Write Code Here */
    int solution(vector<int> arr)
    {
        int res = 0, tmp = 0, count = 1;
        sort(arr.begin(), arr.end());
        int loc = lower_bound(arr.begin(), arr.end(), -1) - arr.begin();
        for (int i = loc; i > -1; i--)
        {
            for (int j = i; j < arr.size(); j++)
            {
                tmp += arr[j] * count++;
            }

            res = max(res, tmp);
            tmp = 0;
            count = 1;
        }
        return res;
    }
};

int main()
{
    int res;

    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _arr;
    int _arr_item;
    for (int _arr_i = 0; _arr_i < _arr_size; _arr_i++)
    {
        cin >> _arr_item;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _arr.push_back(_arr_item);
    }

    Solution *s = new Solution();
    res = s->solution(_arr);
    cout << res << endl;

    return 0;
}
