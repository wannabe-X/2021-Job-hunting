#include <iostream>
#include <vector>

using namespace std;

// k>1的情况

vector<int> ReservoirSampling(vector<int> &nums, int k)
{
    vector<int> res(k);

    for (int i = 0; i < k; i++)
    {
        res[i] = nums[i];
    }

    for (int i = k; i < nums.size(); i++)
    {
        int random = rand() % (i + 1);
        if (random < k) // 对于每次新进来的元素，以k/i的概率保留
            res[random] = nums[i]; // 以1/k的概率替换任意一个元素
    }

    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 5;

    vector<int> ans = ReservoirSampling(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }

    // for (int i = 0; i < 100; i++)
    // {
    //     vector<int> ans = ReservoirSampling(nums, k);
    //     for (int i = 0; i < ans.size(); i++)
    //     {
    //         cout << ans[i] << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}