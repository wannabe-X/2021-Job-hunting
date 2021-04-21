#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 参考解法 思路基本一致
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> stk;
    int i = 0;
    for (int num : pushed)
    {
        stk.push(num);
        while (!stk.empty() && stk.top() == popped[i])
        {
            stk.pop();
            i++;
        }
    }

    return stk.empty();
}

int main(void)
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 1, 2};
    bool ans = validateStackSequences(pushed, popped);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}