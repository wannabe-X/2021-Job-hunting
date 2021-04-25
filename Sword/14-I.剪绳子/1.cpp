#include <iostream>
#include <vector>

using namespace std;

int cuttingRope(int n)
{
    if (n <= 2)
        return 0;
    if (n == 3)
        return 2;

    vector<int> products(n + 1);
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;

    for (int i = 4; i <= n; i++)
    {
        max = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            int product = products[j] * products[i - j];
            if (max < product)
                max = product;
            products[i] = max;
        }
    }

    max = products[n];
    return max;
}

int main(void)
{
    int n = 18;
    int ans = cuttingRope(n);
    cout << ans << endl;
    return 0;
}