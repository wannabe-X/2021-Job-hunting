#include <iostream>
#include <vector>

using namespace std;

int lastRemaining(int n, int m)
{
    if (n < 1 || m < 1)
        return -1;

    vector<int> nums;

    for (int i = 0; i < n; i++)
        nums.push_back(i);

    auto current = nums.begin();

    while (nums.size() > 1)
    {
        for (int i = 0; i < m - 1; i++)
        {
            current++;
            // 如果走到头结点，那么应该回到起点
            // 这样就可以保证出循环后，当前元素不是最后一个位置的元素
            if (current == nums.end())
                current = nums.begin();
        }

        //当前元素使用erase方法后，执行删除元素操作，然后返回下一个元素的指针
        current = nums.erase(current);
        if (current == nums.end())
            current = nums.begin();
    }
    return *current;
}

int main(void)
{
    int n = 10, m = 17;
    int ans = lastRemaining(n, m);
    cout << ans << endl;
    return 0;
}