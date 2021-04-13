#include <stdio.h>
#include <stdlib.h>

// 数组是升序的
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int left = 0, right = numsSize - 1;
    int *arr = (int *)malloc(sizeof(int) * 2);
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            arr[0] = left;
            arr[1] = right;
			break;
        }
        else if (sum > target)
            right--;
        else
            left++;
    }

    return arr;
}

int main(void)
{
	int numsSize = 3;
    int nums[3] = {3,2,4}, target = 6, returnSize = 2;
    int *val = twoSum(nums, numsSize, target, &returnSize);
    printf("%d,%d\n",val[0],val[1]);
    return 0;
}