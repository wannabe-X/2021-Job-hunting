#include <iostream>
#include <vector>

using namespace std;

// �ⷨ3 ���ݺ���˼�� ʹ��˫ָ�뷨�����Ż�
int trap(vector<int> &height)
{
    if (height.empty())
        return 0;

    int n = height.size(), res = 0;

    int left = 0, right = n - 1, l_max = 0, r_max = 0;
    while (left <= right)
    {
        l_max = max(l_max, height[left]);
        r_max = max(r_max, height[right]);

        if (l_max < r_max)
            // water_i��װ����ˮ��ȡ��������������С��һ��
            res += l_max - height[left++];
        else
            res += r_max - height[right--];
    }

    return res;
}

int main(void)
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = trap(height);
    cout << ans << endl;
}