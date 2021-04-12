#include <iostream>
#include <vector>
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

ListNode *reverse(ListNode *head)
{
    if (head->next == NULL)
        return head;
    ListNode *last = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

int main(void)
{
    vector<int> a = {1, 2, 3, 4, 5};
    ListNode *head = createListNode(a);
    print(reverse(head));
}

