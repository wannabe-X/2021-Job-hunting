#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, int m, vector<int> &B, int n)
{
    A.resize(m + n, 0);
    int i = m - 1, j = n - 1, index = m + n - 1;
    while (i > -1 && j > -1)
        A[index--] = A[i] > B[j] ? A[i--] : B[j--];

    for (; j > -1; A[index--] = B[j--])
        ;
}

int main(void)
{
    int m = 5, n = 4;
    vector<int> A = {1, 2, 5, 6, 9}, B = {6, 7, 9, 20};
    merge(A, m, B, n);
    for (int num : A)
    {
        cout << num << endl;
    }

    return 0;
}