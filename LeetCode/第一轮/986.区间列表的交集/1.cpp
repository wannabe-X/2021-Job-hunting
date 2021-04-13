#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    vector<vector<int>> res;
    int i = 0, j = 0;
    while (i < firstList.size() && j < secondList.size())
    {
        int a1 = firstList[i][0], a2 = firstList[i][1];
        int b1 = secondList[j][0], b2 = secondList[j][1];
        // if(a2<b1 || b2<a1) 不存在交集的情况
        if (a2 >= b1 && b2 >= a1)
        {
            int c1 = max(a1, b1), c2 = min(a2, b2);
            res.push_back({c1,c2});
        }

        if(b2>a2) i++;
        else j++;
    }
    return res;
}

int main(void)
{
    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}},
                        secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    vector<vector<int>> ans = intervalIntersection(firstList, secondList);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}