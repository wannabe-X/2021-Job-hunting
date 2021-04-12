#include <iostream>

using namespace std;

void Merge(int arr[], int l, int q, int r)
{
    int n = r - l + 1; //临时数组存合并后的有序序列
    int *tmp = new int[n];
    int i = 0;
    int left = l;
    int right = q + 1;
    while (left <= q && right <= r)
        tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
    while (left <= q)
        tmp[i++] = arr[left++];
    while (right <= r)
        tmp[i++] = arr[right++];
    for (int j = 0; j < n; ++j)
        arr[l + j] = tmp[j];
    delete[] tmp; //删掉堆区的内存
}

void MergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return; //递归基是让数组中的每个数单独成为长度为1的区间
    int q = (l + r) / 2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);

    // for (int i = 0; i < 8; ++i)
    //     cout << arr[i] << " ";


    Merge(arr, l, q, r);
}

int main()
{
    int a[8] = {3, 1, 2, 4, 5, 8, 7, 6};
    MergeSort(a, 0, 7);
    for (int i = 0; i < 8; ++i)
        cout << a[i] << " ";
}