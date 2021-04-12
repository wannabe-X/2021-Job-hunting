#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n)
{
    vector<bool> isPrime(n, true);

    for (int i = 2; i * i < n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }

    int res = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
            res++;
    }

    return res;
}

int main(void)
{
    int n = 1;
    cout << countPrimes(n) << endl;
}