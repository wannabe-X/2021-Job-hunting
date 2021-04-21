#include <iostream>
#include <stack>
#include <vector>

using namespace std;
// 利用栈的先进后出的性质
// 先将pushed的元素依次压入栈中
// 如果遇到栈顶元素与弹出元素相等，则弹出栈顶元素
// 如果pushed已经全部压入栈，弹出的过程中如果遇到栈顶元素不等于弹出元素，则直接break
// 最后如果全部弹出，返回true；否则，返回false
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    bool bPossible = false;
    stack<int> stk;
    int j = 0;
    int i = 0;
    while (j < popped.size())
    {
        while (i < pushed.size() && (stk.empty() || stk.top() != popped[j]))
        {
            stk.push(pushed[i]);
            i++;
        }

        if (stk.top() != popped[j])
            break;

        stk.pop();
        j++;
    }

    if (stk.empty())
        bPossible = true;

    return bPossible;
}

int main(void)
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    bool ans = validateStackSequences(pushed, popped);
    cout << boolalpha;
    cout << ans << endl;
    return 0;
}