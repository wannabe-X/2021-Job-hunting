#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n < 1)
        return {};

    vector<vector<int>> res;

    // ���ո�����[start,end]��start���򣬴�С����
    sort(intervals.begin(), intervals.end());
    // ��start��С��Ӧ������ŵ�res��
    res.push_back(intervals[0]);

    for (int i = 1; i < n; i++) // ע��i�Ǵ�1��ʼ��
    {
        vector<int> curvec = intervals[i];
        if (curvec[0] <= res.back()[1]) // ���Ժϲ������������Ƚ�ǰһ�������end����һ������start�Ĵ�С
        {
            // �ϲ���������endӦ����ǰһ�������end�ͺ�һ�������end�����ֵ
            int max_end = max(res.back()[1], curvec[1]);
            res.back()[1] = max_end;
        }
        else // �����Ժϲ���������
        {
            res.push_back(curvec);
        }
    }

    return res;
}

int main(void)
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}