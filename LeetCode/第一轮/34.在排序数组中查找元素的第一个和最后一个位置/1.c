#include <stdio.h>

int left_bound(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        {
            // �𷵻أ��������߽�
            right = mid - 1;
        }
    }
    // ���Ҫ��� left Խ������
    if (left >= numsSize || nums[left] != target)
        return -1;
    return left;
}

int right_bound(int *nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        {
            // �𷵻أ������Ҳ�߽�
            left = mid + 1;
        }
    }
    // ���Ҫ��� right Խ������
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int left = left_bound(nums, numsSize, target);
    int right = right_bound(nums, numsSize, target);
    if (left < right)
    {
        returnSize[0] = left;
        returnSize[1] = right;
    }
    return returnSize;
}

int main(void)
{
    int nums[] = {}, numsSize = 0, target = 5;
    int returnSize[2] = {-1, -1};
    int *b = searchRange(nums, numsSize, target, returnSize);
    printf("%d,%d", b[0], b[1]);
    return 0;
}
