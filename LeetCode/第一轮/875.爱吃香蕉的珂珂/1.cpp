#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timeOf(int n, int speed)
{
    return (n / speed) + ((n % speed > 0) ? 1 : 0);
}

bool canFinish(vector<int> &piles, int speed, int h)
{
    int time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        time += timeOf(piles[i], speed);
    }
    return time <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = *max_element(piles.begin(), piles.end()) + 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, h))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main(void)
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int ans = minEatingSpeed(piles, h);
    cout << ans << endl;
}