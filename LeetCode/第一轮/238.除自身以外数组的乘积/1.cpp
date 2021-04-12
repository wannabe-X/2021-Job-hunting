#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> product(nums.size(), 1);
    int q = 1, p = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        product[i] = p;
        p *= nums[i];
    }

    for (int i = nums.size() - 1; i > 0; i--)
    {
        q *= nums[i];
        product[i - 1] *= q;
    }

    return product;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(a);
    for (int i = 0; i < a.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
