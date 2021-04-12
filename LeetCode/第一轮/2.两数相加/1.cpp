#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(const int &v = 0) : val(v), next(nullptr) {}
};

ListNode *CreateList(ListNode *T, int *a, int len)
{
    ListNode *pHead = T;

    for (int i = 0; i < len; i++)
    {
        T->val = a[i];
        T->next = NULL;
        ListNode *pNewNode = new ListNode();
        T->next = pNewNode;
        T = pNewNode;
    }
    T->next = NULL;

    return pHead;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *p = new ListNode(-1);
    ListNode *pHead = p;
    bool flag = false;
    int sum = 0;
    while (l1 || l2)
    {
        sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        if (flag)
            sum++;
		
        p->next = new ListNode(sum % 10);
        p = p->next;
        flag = (sum >= 10) ? true : false;
    }
    if (flag)
        p->next = new ListNode(1);

    return pHead->next;
}

// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {
//     ListNode *addP = new ListNode();
//     if (l1->val == 0 && l2->val == 0)
//     {
//         addP->val = 0;
//         addP->next = NULL;
//         return addP;
//     }

//     ListNode *pHead = addP;

//     int num = 0;
//     for (int i = 0; l1 != NULL; l1 = l1->next, i++)
//         num += l1->val * pow(10.0, i);

//     for (int i = 0; l2 != NULL; l2 = l2->next, i++)
//         num += l2->val * pow(10.0, i);
//     // cout << num << endl;

//     while (num)
//     {
//         ListNode *P = new ListNode();
//         addP->next = P;
//         P->val = num % 10;
//         P->next = NULL;
//         addP = P;
//         num /= 10;
//     }

//     return pHead->next;
// }

void print(ListNode *T)
{
    for (; T != NULL; T = T->next)
        cout << T->val << endl;
    return;
}

int main()
{
    int a[] = {9};
    ListNode *l1 = (ListNode *)malloc(sizeof(ListNode));
    CreateList(l1, a, sizeof(a) / sizeof(a[0]));

    int b[] = {8};
    ListNode *l2 = (ListNode *)malloc(sizeof(ListNode));
    CreateList(l2, b, sizeof(b) / sizeof(b[0]));

    ListNode *add = addTwoNumbers(l1, l2);
    print(add);

    return 0;
}
