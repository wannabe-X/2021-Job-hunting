#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> printNumbers(int n)
{
    int maxVal = pow(10, n);
    vector<int> nums;
    for (int i = 1; i < maxVal; i++)
        nums.push_back(i);
    return nums;
}

int main(void)
{
    int n = 3;
    vector<int> ans = printNumbers(n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}