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

ListNode *deleteNode(ListNode *head, int val)
{
    if (head == NULL)
        return head;
    if (head->val == val)
        return head->next;

    ListNode *p;
    for (p = head; p->next && p->next->val != val; p = p->next)
        ;
    p->next = p->next->next;

    return head;
}

int main(void)
{

    vector<int> a = {1, 2, 3,4,5,6};
    int val = 4;
    ListNode *l1 = createListNode(a);
    print(deleteNode(l1,val));
    return 0;
}