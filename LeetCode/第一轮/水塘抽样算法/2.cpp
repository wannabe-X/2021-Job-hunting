#include <iostream>
#include <vector>

using namespace std;

// k>1�����

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
        if (random < k) // ����ÿ���½�����Ԫ�أ���k/i�ĸ��ʱ���
            res[random] = nums[i]; // ��1/k�ĸ����滻����һ��Ԫ��
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