#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createListNode(vector<int> &lst)
{
    ListNode *head = new ListNode(), *T = head;
    T->val = lst[0];
    T->next = NULL;

    for (int i = 1; i < lst.size(); i++)
    {
        ListNode *newNode = new ListNode(lst[i]);
        T->next = newNode;
        T = newNode;
    }

    return head;
}

void print(ListNode *T)
{
    for (; T != NULL; T = T->next)
        cout << T->val << endl;
}

// 利用栈先进后出的特点
// vector<int> reversePrint(ListNode *head)
// {
//     vector<int> nums;
//     stack<int> stk;
//     for (; head; head = head->next)
//         stk.push(head->val);

//     while (!stk.empty())
//     {
//         nums.push_back(stk.top());
//         stk.pop();
//     }
//     return nums;
// }

vector<int> reversePrint(ListNode *head)
{
    vector<int> nums;
    stack<ListNode *> stk;
    for (; head; head = head->next)
        stk.push(head);

    while (!stk.empty())
    {
        nums.push_back(stk.top()->val);
        stk.pop();
    }
    return nums;
}

int main(void)
{

    vector<int> a = {1, 3, 2};
    ListNode *head = createListNode(a);
    vector<int> ans = reversePrint(head);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}