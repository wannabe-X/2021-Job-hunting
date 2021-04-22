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

ListNode *connectNode(ListNode *head, ListNode *common)
{
    ListNode *phead = head;
    for (; phead->next; phead = phead->next)
        ;

    phead->next = common;
    return head;
}

void print(ListNode *T)
{
    for (; T != NULL; T = T->next)
        cout << T->val << endl;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA==NULL || headB==NULL) return NULL;
    vector<ListNode *> A;
    int boundary = -1, i, j;

    for (; headA; A.push_back(headA), headA = headA->next, boundary += 1)
        ;
    for (; headB; A.push_back(headB), headB = headB->next)
        ;
    if (A[boundary] != A[A.size() - 1])
        return NULL;
    for (i = boundary, j = A.size() - 1; i > -1 && j > boundary; i--, j--)
    {
        if (A[i] != A[j])
            return A[i + 1];
    }
    return NULL;
}

int main(void)
{
    vector<int> common = {1}, listA = {1}, listB = {1};
    ListNode *c = createListNode(common);
    ListNode *phead = createListNode(listA);
    ListNode *qhead = createListNode(listB);

    ListNode *p = connectNode(phead, c);
    ListNode *q = connectNode(qhead, c);

    ListNode *ans = getIntersectionNode(p, q);
    print(ans);

    return 0;
}