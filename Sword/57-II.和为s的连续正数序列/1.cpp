#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    int small = 1, big = 2;
    int mid = (target + 1) / 2;
    vector<vector<int>> res;
    while (small < mid)
    {
        int sum = 0;
        vector<int> temp;
        for (int i = small; i < big + 1; i++)
        {
            sum += i;
            temp.push_back(i);
        }

        if (sum == target)
        {
            res.push_back(temp);
            big++;
        }
        else if (sum < target)
            big++;
        else
            small++;
    }

    return res;
}

int main(void)
{
    int target = 3;
    vector<vector<int>> ans = findContinuousSequence(target);
    for (vector<int> tem : ans)
    {
        for (int num : tem)
            cout << num << ' ';
        cout << endl;
    }

    cout << endl;
    return 0;
}