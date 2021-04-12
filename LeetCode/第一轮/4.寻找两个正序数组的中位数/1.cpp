#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged;
    merge(nums1.begin(), nums1.end(),
          nums2.begin(), nums2.end(),
          back_inserter(merged));

    auto middle = merged.size() / 2;
    if (merged.size() % 2 == 0)
    {
        auto a = merged[middle - 1];
        auto b = merged[middle];

        return (a + b) / 2.;
    }
    else
    {
        return merged[middle];
    }
}

int main()
{
    vector<int> num1 = {1, 2};
    vector<int> num2 = {3, 4};
    auto ans = findMedianSortedArrays(num1, num2);
    cout << ans << endl;
}