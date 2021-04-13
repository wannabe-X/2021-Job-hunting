#include <stdio.h>
#include <stdlib.h>

// 数组无序 暴力破解
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 2);
    int flag = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                arr[0] = i;
                arr[1] = j;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    *returnSize = 2;
    return arr;
}

int main(void)
{
    int numsSize = 3;
    int nums[3] = {3, 2, 4}, target = 6, returnSize = 2;
    int *val = twoSum(nums, numsSize, target, &returnSize);
    printf("%d,%d\n", val[0], val[1]);
    return 0;
}