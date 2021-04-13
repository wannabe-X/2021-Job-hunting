#include <iostream>
#include <vector>

using namespace std;

// k=1的情况

int ReservoirSampling(vector<int> &nums)
{
    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (rand() % (i + 1) == 0) // 对于每次新进来的额数，以1/i的概率保留
            res = nums[i];
    }

    return res;
}

int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ans = ReservoirSampling(nums);
    cout << ans << endl;
    
    // for (int i = 0; i < 100; i++)
    //     cout << ReservoirSampling(nums) << endl;
    return 0;
}