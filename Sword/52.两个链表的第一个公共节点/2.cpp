#include <iostream>
#include <vector>
using namespace std;

// 参考解法
// 两个链表长度分别为L1+C、L2+C， C为公共部分的长度
// 第一个人走了L1+C步后，回到第二个人起点走L2步；
// 第2个人走了L2+C步后，回到第一个人起点走L1步。
// 当两个人走的步数都为L1+L2+C时就相遇了
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

// 你变成我，走过我走过的路。
// 我变成你，走过你走过的路。
// 然后我们便相遇了..
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *node1 = headA,*node2 = headB;
    while(node1!=node2){
        node1 = (node1!=nullptr)?node1 = node1->next:headB;
        node2 = (node2!=nullptr)?node2 = node2->next:headA;
    }

    return node1;
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