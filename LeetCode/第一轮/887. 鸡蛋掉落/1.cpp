#include <iostream>
#include <unordered_map>

using namespace std;

int superEggDrop(int k, int n)
{
    int k_n[k + 1][n + 1];

    for (int i = 0; i <= k; i++)
        k_n[i][0] = 0;
    for (int j = 0; j <= n; j++)
        k_n[0][j] = 0;

    int m = 0;
    while (k_n[k][m] < n)
    {
        m++;
        for (int i = 1; i <= k; i++)
            k_n[i][m] = 1 + k_n[i - 1][m - 1] + k_n[i][m - 1];
    }

    return m;
}

int main(void)
{

    int k = 2, n = 100;
    int max_val = superEggDrop(k, n);
    cout << max_val << endl;
}