#include <stdio.h>

// 检索左边界 左闭右开
int search(int *nums, int numsSize, int target)
{
	if (numsSize == 0)
		return -1;
	int left = 0, right = numsSize, mid;
	while (left < right)
	{ // 注意是小于，不是小于等于
		mid = (right + left) / 2;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	if (left > numsSize || nums[left] != target)
		return -1;
	return left;
}

int main(void)
{
	int nums[10] = {1, 2, 2, 2, 3}, target = 2;
	printf("%d\n", search(nums, 5, target));
	return 0;
}
