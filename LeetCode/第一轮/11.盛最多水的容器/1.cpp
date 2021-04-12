#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1, res = 0;
    while (i < j)
    {
        res = height[i] < height[j]
                  ? max(res, (j - i) * height[i++])
                  : max(res, (j - i) * height[j--]);
    }

    return res;
}

int main()
{
    vector<int> a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int max_ = maxArea(a);
    cout << max_ << endl;
    return 0;
}
