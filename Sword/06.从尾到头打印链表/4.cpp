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

//逆序打印（非递归）
vector<int> reversePrint(ListNode *head)
{
    ListNode *pCur = head, *pEnd = NULL;
    vector<int> nums;
    while (pEnd != head)
    {
        pCur = head;
        for (; pCur->next != pEnd; pCur = pCur->next)
            ;
        nums.push_back(pCur->val);
        pEnd = pCur;
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