#include <iostream>

using namespace std;

// 双指针法
void merge(int A[], int m, int B[], int n)
{
    int i = m - 1, j = n - 1;
    int idx = m + n - 1;
    while (i > -1 && j > -1)
    {
        A[idx--] = A[i] > B[j] ? A[i--] : B[j--];
    }
    for (; j > -1; A[idx--] = B[j--])
        ;
}

int main(void)
{
    int m = 1, n = 2;
    int A[m] = {1}, B[n] = {2, 5};
    merge(A, m, B, n);

    for (int i = 0; i < m + n; i++)
        cout << A[i] << endl;

    return 0;
}