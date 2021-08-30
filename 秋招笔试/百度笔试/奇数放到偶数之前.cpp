/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-27 17:46:43
 * @LastEditTime: 2021-08-30 20:21:48
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// void func(vector<int> &nums)
// {
//     if (nums.size() <= 1)
//         return;

//     int start = 0, end = nums.size() - 1;

//     while (start < end)
//     {
//         // 从左向右找到一个偶数
//         while (start < end && ((nums[start] & 1) == 1))
//         {
//             start++;
//         }

//         // 从右向左找到一个奇数
//         while (start < end && ((nums[end] & 1) == 0))
//         {
//             end--;
//         }

//         // 交换
//         int tmp = nums[start];
//         nums[start] = nums[end];
//         nums[end] = tmp;
//     }
// }

// vector<int> func(vector<int> &arr)
// {
//     int low = 0;
//     int size = arr.size();
//     // int size = sizeof(arr)/sizeof(arr[0]);
//     int high = size - 1;
//     while (low < high)
//     {
//         while (low < high && arr[low] % 2 == 0)
//         {
//             low++;
//         }
//         while (low < high && arr[high] % 2 == 1)
//         {
//             high--;
//         }
//         swap(arr[low], arr[high]);
//     }
//     return arr;
// }

void func(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = nums.size() - 1; j > i; j--)
        {
            if ((nums[j] % 2 == 0) && (nums[j - 1] % 2 == 1))
            {
                swap(nums[j - 1], nums[j]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    string raw_data, tmp;
    vector<int> nums;
    cin >> raw_data;
    vector<string> data;
    stringstream input(raw_data);

    while (getline(input, tmp, ','))
        data.push_back(tmp);
    for (auto &x : data)
        nums.push_back(stoi(x));
    func(nums);

    int i = 0;
    for (; i < nums.size() - 1; i++)
    {
        cout << nums[i] << ',';
    }
    cout << nums[i];

    return 0;
}