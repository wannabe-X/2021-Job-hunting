#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SSTF(vector<int> t, vector<int> &list, vector<int> &d, int begin)
{
    int length = t.size();
    int cur = begin; // 当前磁道数
    while (list.size() != length)
    {
        list.push_back(t[0]);
        int min = abs(cur - list.back()), temp = 0;
        for (int i = 0; i < t.size(); i++)
            if (abs(cur - t[i]) < min)
            {
                temp = i;
                min = abs(cur - t[i]); //利用绝对值找到最短距离
            }
        if (t[temp] != list.back())
        {
            list.pop_back();
            list.push_back(t[temp]);
        }
        d.push_back(min);
        t.erase(t.begin() + temp);
        cur = list.back();
    }
}

int diskRead(vector<int> &a, int pos)
{
    vector<int> list, d;
    SSTF(a, list, d, pos);
    int time = 0;
    for (auto &num : d)
        time += num;

    return time;
}

int main(void)
{
    vector<int> a = {1, 5};
    int begin = 3;

    int time = diskRead(a, begin);

    cout << time;
    return 0;
}
