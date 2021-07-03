/*
 * @Description:  链表中倒数最后k个结点
 * @Author: Mr. Lee
 * @Date: 2021-07-03 21:19:41
 * @LastEditTime: 2021-07-03 21:31:26
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

ListNode *FindKthToTail(ListNode *pHead, int k)
{
    // 先获取链表的长度
    int listLen = 0;
    for (auto tmp = pHead; tmp; listLen++, tmp = tmp->next)
        ;
    if (listLen < k)
        return nullptr;

    for (int i = 0; i < listLen - k; i++)
    {
        pHead = pHead->next;
    }

    return pHead;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1;
    ListNode *pHead = createList(nums);
    // 打印链表
    cout << "打印链表: ";
    printList(pHead);

    ListNode *ans = FindKthToTail(pHead, k);
    cout << ans->val << endl;

    return 0;
}
