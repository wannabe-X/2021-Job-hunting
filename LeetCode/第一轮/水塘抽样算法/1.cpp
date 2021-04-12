#include <iostream>
#include <vector>

using namespace std;

// k=1�����

int ReservoirSampling(vector<int> &nums)
{
    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (rand() % (i + 1) == 0) // ����ÿ���½����Ķ�������1/i�ĸ��ʱ���
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