#include <iostream>
#include <vector>
# include<algorithm>

using namespace std;
// 把问题转化为求最小值的问题 简单粗暴
// 但该种方法使用了排序，增大了时间复杂度
int minArray(vector<int> &numbers)
{
    sort(numbers.begin(),numbers.end());
    return numbers[0];
}

int main(void)
{
    vector<int> nums = {3, 4, 5, 1, 2};
    int ans = minArray(nums);
    cout << ans << endl;
    return 0;
}
