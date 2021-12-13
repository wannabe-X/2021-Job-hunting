/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 15:45:27
 * @LastEditTime: 2021-12-13 16:25:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BFPRT
{
public:
    // 时间复杂度 T(N) = T(N/2) + O(N) = O(N)
    int getMinKthByBFPRT(vector<int> &arr, int k, int left, int right)
    {
        if (arr.empty() || k >= arr.size() || left > right || k < left || k > right)
        {
            return -1;
        }
        if (left == right)
        {
            return arr.at(left);
        }
        // 获取每组的中位数组成的数组的中位数(这是BFPTR算法与荷兰国旗问题最大的不同点)
        // 时间复杂度 O(N)
        int pivot = medianOfMedians(arr, left, right);
        // partition过程 <在左，=在中，>在右
        // 时间复杂度 O(N)
        vector<int> range = partition(arr, left, right, pivot);
        // k恰好在 相等的区域内，直接返回
        if (k > range.at(0) && k < range.at(1))
        {
            return arr.at(k);
        }
        // 根据k所在的范围继续递归
        return k <= range.at(0) ? getMinKthByBFPRT(arr, k, left, range.at(0)) : getMinKthByBFPRT(arr, k, range.at(1), right);
    }

    // partition过程 <在左，=在中，>在右，时间复杂度 O(N)
    // 大数往前放,小数往后放
    vector<int> partition(vector<int> &arr, int left, int right, int pivot)
    {
        int tmpL = left - 1;
        int tmpR = right + 1;
        int index = left;
        while (index < tmpR)
        {
            if (arr.at(index) < pivot)
            {
                swap(arr, index++, ++tmpL);
            }
            else if (arr.at(index) > pivot)
            {
                swap(arr, index, --tmpR);
            }
            else
            {
                index++;
            }
        }
        vector<int> res{tmpL, tmpR};
        return res;
    }

    // 获取每组的中位数组成的数组的中位数，时间复杂度 O(N)
    int medianOfMedians(vector<int> &arr, int left, int right)
    {
        vector<int> medians;
        int offset = ((right - left + 1) % 5 == 0) ? 0 : 1;
        int groupNums = (right - left + 1) / 5 + offset;
        // 此过程 (N/5) * O(1) = O(N)，(N/5)次5个数(或少于5个)排序O(1)
        for (int i = 0; i < groupNums; i++)
        {
            int tmpL = left + i * 5;
            int tmpR = tmpL + 5;
            sort(arr.begin() + tmpL, arr.begin() + min(tmpR, right));
            medians.push_back(arr.at(tmpL + ((min(tmpR, right) - tmpL) >> 1)));
        }
        return getMinKthByBFPRT(medians, medians.size() / 2, 0, medians.size() - 1);
    }

    void swap(vector<int> &arr, int n1, int n2)
    {
        int tmp = arr.at(n1);
        arr.at(n1) = arr.at(n2);
        arr.at(n2) = tmp;
    }
};

int main()
{
    vector<int> arr{0, 10, 4, 2, 9, 12, 10, 22};
    cout << BFPRT().getMinKthByBFPRT(arr, 6, 0, arr.size() - 1) << endl;

    // system("pause");
    return 0;
}