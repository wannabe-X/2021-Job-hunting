/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-10 18:57:42
 * @LastEditTime: 2021-10-18 14:50:20
 * @LastEditors: Mr. Lee
 */
/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-10 18:57:42
 * @LastEditTime: 2021-10-10 19:39:03
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int func(vector<double> nums)
{
    sort(nums.begin(), nums.end());
    unordered_set<double> st;
    for (double num : nums)
        st.insert(num);

    return st.size();
}

int main(void)
{
    int N;
    cin >> N;
    vector<double> nums(N, 0);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    int ans = func(nums);
    cout << ans << endl;

    return 0;
}