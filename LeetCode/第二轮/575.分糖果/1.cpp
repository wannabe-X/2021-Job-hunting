/*
 * @Description: 575. 分糖果
 * @Author: Mr. Lee
 * @Date: 2021-11-01 09:42:54
 * @LastEditTime: 2021-11-01 09:55:45
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// int distributeCandies(vector<int> &candyType)
// {
//     unordered_set<int> st;
//     for (int num : candyType)
//         st.insert(num);

//     return candyType.size() / 2 > st.size() ? st.size() : candyType.size() / 2;
// }

int distributeCandies(vector<int> &candyType)
{
    return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
}

int main(int argc, char **argv)
{
    vector<int> candyType = {1, 2, 3, 1, 2, 3};
    int ans = distributeCandies(candyType);
    cout << ans << endl;

    return 0;
}