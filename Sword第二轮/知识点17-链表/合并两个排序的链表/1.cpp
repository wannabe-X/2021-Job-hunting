/*
 * @Description: 合并两个排序的链表
 * @Author: Mr. Lee
 * @Date: 2021-07-03 22:51:18
 * @LastEditTime: 2021-07-03 23:07:05
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

ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    ListNode *H = new ListNode(0), *head = H;
    while (pHead1 && pHead2)
    {
        if (pHead1->val <= pHead2->val)
        {
            H->next = pHead1;
            H = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            H->next = pHead2;
            H = pHead2;
            pHead2 = pHead2->next;
        }
    }

    H->next = pHead1 ? pHead1 : pHead2;

    return head->next;
}

int main()
{
    vector<int> nums1 = {1, 3, 5};
    ListNode *pHead1 = createList(nums1);
    vector<int> nums2 = {2, 4, 6};
    ListNode *pHead2 = createList(nums2);
    ListNode *ans = Merge(pHead1, pHead2);
    for (; ans; ans = ans->next)
    {
        cout << ans->val << " ";
    }

    return 0;
}
