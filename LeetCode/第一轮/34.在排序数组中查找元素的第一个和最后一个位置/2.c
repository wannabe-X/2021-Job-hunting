#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 2);
    // memset(arr, -1, sizeof(arr));
    arr[0] = arr[1] = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            arr[0] = i;
            break;
        }
    }

    for (int i = numsSize - 1; i > -1; i--)
    {
        if (nums[i] == target)
        {
            arr[1] = i;
            break;
        }
    }

    *returnSize = 2;
    return arr;
}

int main(void)
{
    int nums[] = {}, numsSize = 0, target = 5;
    int returnSize = 2;
    int *b = searchRange(nums, numsSize, target, &returnSize);
    printf("%d,%d", b[0], b[1]);
    return 0;
}