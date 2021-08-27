#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void print(vector<int> &arr, bool isBefore = true)
{
    if (isBefore)
    {
        cout << "排序之前:" << endl;
        for (int num : arr)
        {
            cout << num << " ";
        }
    }
    else
    {
        cout << "排序之后:" << endl;
        for (int num : arr)
        {
            cout << num << " ";
        }
    }

    cout << endl;
}

void quickSort(vector<int> &nums)
{
    stack<int> s;
    s.push(nums.size() - 1);
    s.push(0);

    while (!s.empty())
    {
        int low = s.top();
        s.pop();
        int high = s.top();
        s.pop();

        int i = low, j = high;

        if (i >= j)
            continue;
        int pivot = nums[i];

        while (i < j)
        {
            while (i < j && pivot <= nums[j])
            {
                j--;
            }
            nums[i] = nums[j];

            while (i < j && pivot > nums[i])
            {
                i++;
            }
            nums[j] = nums[i];
        }

        nums[i] = pivot;

        s.push(high);
        s.push(i + 1);
        s.push(i - 1);
        s.push(low);
    }
}

int main(int argc, char *argv[])
{
    vector<int> arr = {1, 9, 66, 0, 33, 5, 2, 88, 666, 233};
    print(arr);

    // 快速排序 非递归
    cout << "Quick Sort";
    quickSort(arr);
    print(arr, false);

    return 0;
}