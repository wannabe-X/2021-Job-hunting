#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> addToArrayForm(vector<int> &num, int k)
{
    int n = num.size() - 1, carry = 0;
    vector<int> res;

    while (n > -1)
    {
        int tmp = (n > -1) ? num[n] : 0;
        int sum = tmp + k % 10 + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        k /= 10;
        n--;
    }

    if (carry)
    {
        res.push_back(carry);
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> A = {2,7,4};
    int K = 181;
    vector<int> ans = addToArrayForm(A, K);
    for (int c : ans)
    {
        cout << c << " ";
    }
    return 0;
}