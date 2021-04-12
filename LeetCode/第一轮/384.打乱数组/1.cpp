#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution
{
private:
    vector<int> nums;

public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    // shuffle 1
    vector<int> shuffle()
    {
        int n = nums.size();
        auto data = nums;
        for (int i = 0; i < n; i++)
        {
            int rd = (rand() % ((n - 1) - i + 1)) + i;
            swap(data[i], data[rd]);
        }

        return data;
    }

    // shuffle 2
    vector<int> shuffle2()
    {
        int n = nums.size();
        auto data = nums;
        for (int i = 0; i < n - 1; i++)
        {
            int rd = (rand() % ((n - 1) - i + 1)) + i;
            swap(data[i], data[rd]);
        }

        return data;
    }

    // shuffle 3
    vector<int> shuffle3()
    {
        int n = nums.size();
        auto data = nums;
        for (int i = n - 1; i > -1; i--)
        {
            int rd = (rand() % (i - 0 + 1)) + 0;
            swap(data[i], data[rd]);
        }

        return data;
    }

    // shuffle 4
    vector<int> shuffle4()
    {
        int n = nums.size();
        auto data = nums;
        for (int i = n - 1; i > 0; i--)
        {
            int rd = (rand() % (i - 0 + 1)) + 0;
            swap(data[i], data[rd]);
        }

        return data;
    }
};

int main(void)
{
    vector<int> nums = {1, 2, 3};
    Solution solution(nums);
    vector<int> nums1 = solution.shuffle();
    // for (int i = 0; i < nums1.size(); i++)
    // {
    //     cout << nums1[i] << ' ';
    // }
    // cout << endl;
    vector<int> nums2 = solution.reset();
    // for (int i = 0; i < nums2.size(); i++)
    // {
    //     cout << nums2[i] << ' ';
    // }
    // cout << endl;
    vector<int> nums3 = solution.shuffle();
    // for (int i = 0; i < nums3.size(); i++)
    // {
    //     cout << nums3[i] << ' ';
    // }
    // cout << endl;
}