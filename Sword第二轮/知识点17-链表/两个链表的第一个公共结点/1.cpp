/*
 * @Description: 两个链表的第一个公共结点
 * @Author: Mr. Lee
 * @Date: 2021-07-03 23:12:15
 * @LastEditTime: 2021-07-03 23:59:31
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

// 创建一个链表
ListNode *createList(vector<int> &nums)
{
    ListNode *h = new ListNode(0), *head = h;
    h->next = nullptr;
    for (int num : nums)
    {
        auto tmp = new ListNode(num);
        tmp->next = nullptr;
        h->next = tmp;
        h = tmp;
    }

    return head->next;
}

// 打印链表
void printList(ListNode *H)
{
    for (; H; H = H->next)
    {
        cout << H->val << " ";
    }
    cout << endl;
}

// 创建有公共结点的链表
void CreateCommonNodesLists(ListNode *&pHead1, ListNode *&pHead2, ListNode *&cHead)
{
    auto tmp1 = pHead1, tmp2 = pHead2;
    for (; tmp1->next; tmp1 = tmp1->next)
        ;
    for (; tmp2->next; tmp2 = tmp2->next)
        ;
    tmp1->next = cHead;
    tmp2->next = cHead;
}

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    auto p1 = pHead1, p2 = pHead2;
    while (p1 != p2)
    {
        p1 = p1 ? p1->next : pHead2;
        p2 = p2 ? p2->next : pHead1;
    }

    return p1;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    ListNode *pHead1 = createList(nums1);
    vector<int> nums2 = {4, 5};
    ListNode *pHead2 = createList(nums2);
    vector<int> commonpart = {6, 7};
    ListNode *cHead = createList(commonpart);

    CreateCommonNodesLists(pHead1, pHead2, cHead);

    ListNode *ans = FindFirstCommonNode(pHead1, pHead2);
    for (; ans; ans = ans->next)
    {
        cout << ans->val << " ";
    }

    return 0;
}
