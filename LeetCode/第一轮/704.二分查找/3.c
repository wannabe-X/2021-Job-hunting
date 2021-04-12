#include <stdio.h>

// �����ұ߽� ����ҿ�
int search(int *nums, int numsSize, int target)
{
	if (numsSize == 0)
		return -1;
	int left = 0, right = numsSize, mid;
	while (left < right)
	{ // ע����С�ڣ�����С�ڵ��ڣ��˳�������left==right
		mid = (right + left) / 2;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	if (left > numsSize || nums[left - 1] != target)
		return -1;
	return left - 1;
}

int main(void)
{
	int nums[10] = {1, 2, 3, 4, 5}, target = 5;
	printf("%d\n", search(nums, 5, target));
	return 0;
}