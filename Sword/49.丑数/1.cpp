#include <iostream>
#include <vector>

using namespace std;

int Min(int x, int y, int z)
{
    int temp = x < y ? x : y;
    return temp < z ? temp : z;
}

int nthUglyNumber(int n)
{
    vector<int> pUglyNumbers(n);
    pUglyNumbers[0] = 1;

    int nextUglyIndex = 1;
    auto pUglyNumber2 = pUglyNumbers.begin();
    auto pUglyNumber3 = pUglyNumbers.begin();
    auto pUglyNumber5 = pUglyNumbers.begin();

    while (nextUglyIndex < n)
    {
        pUglyNumbers[nextUglyIndex] = Min((*pUglyNumber2) * 2, (*pUglyNumber3) * 3, (*pUglyNumber5) * 5);
        while ((*pUglyNumber2) * 2 <= pUglyNumbers[nextUglyIndex])
            pUglyNumber2++;
        while ((*pUglyNumber3) * 3 <= pUglyNumbers[nextUglyIndex])
            pUglyNumber3++;
        while ((*pUglyNumber5) * 5 <= pUglyNumbers[nextUglyIndex])
            pUglyNumber5++;

        nextUglyIndex++;
    }

    return pUglyNumbers[nextUglyIndex - 1];
}

int main(void)
{
    int n = 1690;
    int ans = nthUglyNumber(n);
    cout << ans << endl;
    return 0;
}