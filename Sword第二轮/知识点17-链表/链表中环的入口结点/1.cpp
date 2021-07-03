/*
 * @Description: 链表中环的入口结点
 * @Author: Mr. Lee
 * @Date: 2021-07-03 23:51:21
 * @LastEditTime: 2021-07-04 00:26:24
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

// 创建有环的链表
void CreateCircularLists(ListNode *&cHead, ListNode *&pHead)
{
    auto tmp = cHead;
    for (; tmp->next; tmp = tmp->next)
        ;
    tmp->next = cHead; // 拼接，形成一个环形链表

    tmp = pHead;
    for (; tmp->next; tmp = tmp->next)
        ;
    tmp->next = cHead; // 拼接到环形链表的头结点
}

// 创建无环的链表
void CreateNoCircularLists(ListNode *&cHead, ListNode *&pHead)
{
    auto tmp = pHead;
    for (; tmp->next; tmp = tmp->next)
        ;
    tmp->next = cHead;
}

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    auto slow = pHead, fast = pHead;
    if ((!fast) || (!fast->next))
        return nullptr;
    while (slow && fast)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    
    // 没有环
    if ((!slow) || (!fast))
        return nullptr;

    // 存在环，找环
    slow = pHead;
    for (; slow - fast; slow = slow->next, fast = fast->next)
        ;

    return slow;
}

int main()
{
    vector<int> nums = {1, 2};
    ListNode *pHead = createList(nums);
    vector<int> Circular = {3, 4, 5};
    ListNode *cHead = createList(Circular);
    CreateCircularLists(cHead, pHead);
    // CreateNoCircularLists(cHead,pHead);
    // printList(pHead);

    ListNode *ans = EntryNodeOfLoop(pHead);
    if (ans)
        cout << ans->val << endl;

    return 0;
}
