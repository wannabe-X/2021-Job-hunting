#include <iostream>
#include <vector>
#include <algorithm>
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
    for (; T->next != NULL; T = T->next)
        cout << T->val << "->";
    cout << T->val << endl;
}

// 参考代码
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dum = new ListNode(0), *cur = dum;
    while (l1 && l2)
    {
        l1->val > l2->val ? (cur->next = l2, l2 = l2->next) : (cur->next = l1, l1 = l1->next);
        cur = cur->next;
    }
    // while (l1 && l2)
    // {
    //     if (l1->val > l2->val)
    //     {
    //         cur->next = l2;
    //         // cur = l2;
    //         l2 = l2->next;
    //     }
    //     else
    //     {
    //         cur->next = l1;
    //         // cur = l1;
    //         l1 = l1->next;
    //     }
    //     cur = cur->next;
    // }

    cur->next = (l1 != NULL) ? l1 : l2;
    return dum->next;
}

int main(void)
{

    vector<int> a = {1, 2, 4}, b = {1, 3, 4};
    ListNode *l1 = createListNode(a), *l2 = createListNode(b);
    print(mergeTwoLists(l1, l2));
    return 0;
}