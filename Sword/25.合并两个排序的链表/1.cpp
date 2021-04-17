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

// 不忍直视的垃圾代码
// 把链表的元素存入数组，在将数组排序
// 之后将数组的各元素依次存入链表中
// 返回链表的头结点
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    vector<int> nums;

    for (; l1; nums.push_back(l1->val), l1 = l1->next)
        ;
    for (; l2; nums.push_back(l2->val), l2 = l2->next)
        ;
    sort(nums.begin(), nums.end());

    ListNode *t = new ListNode;
    t->next = NULL;
    t->val = nums[0];
    ListNode *head = t;

    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode;
        temp->next = NULL;
        temp->val = nums[i];
        t->next = temp;
        t = temp;
    }

    return head;
}

int main(void)
{

    vector<int> a = {1, 2, 4}, b = {1, 3, 4};
    ListNode *l1 = createListNode(a), *l2 = createListNode(b);
    print(mergeTwoLists(l1, l2));
    return 0;
}