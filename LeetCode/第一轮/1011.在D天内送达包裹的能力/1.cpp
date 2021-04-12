#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canFinish(vector<int> &w, int D, int cap)
{
    int i = 0;
    for (int t = 0; t < D; t++)
    {
        int maxCap = cap;
        
        while ((maxCap -= w[i]) >= 0)
        {
            i++;
            if (i == w.size())
                return true;
        }
    }
    return false;
}

int shipWithinDays(vector<int> &weights, int D)
{
    int left = 1, right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (canFinish(weights, D, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main(void)
{
    vector<int> piles = {1, 2, 3, 1, 1};
    int D = 4;
    int ans = shipWithinDays(piles, D);
    cout << ans << endl;
}