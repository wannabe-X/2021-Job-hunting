#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
	int left = 0, right = numsSize - 1, mid;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main(void)
{
	int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100}, target = 6;
	printf("%d\n", search(nums, 10, target));
	return 0;
}
