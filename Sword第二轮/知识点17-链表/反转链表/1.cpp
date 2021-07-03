/*
 * @Description:  反转链表
 * @Author: Mr. Lee
 * @Date: 2021-07-03 21:19:41
 * @LastEditTime: 2021-07-03 21:53:12
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

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

ListNode *H = nullptr;

ListNode *ReverseList(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr)
    {
        H = pHead;
        return H;
    }

    ReverseList(pHead->next);
    pHead->next->next = pHead;
    pHead->next = nullptr;

    return H;
}

int main()
{
    vector<int> nums = {};
    ListNode *pHead = createList(nums);
    // 打印链表
    cout << "打印链表: ";
    printList(pHead);

    ListNode *ans = ReverseList(pHead);
    printList(ans);

    return 0;
}
