/*
 * @Description: 从尾到头打印链表
 * @Author: Mr. Lee
 * @Date: 2021-07-03 20:57:41
 * @LastEditTime: 2021-07-03 21:18:50
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

// 从尾到头打印链表
vector<int> printListFromTailToHead(ListNode *head)
{
    vector<int> res;
    for (; head; head = head->next)
    {
        res.push_back(head->val);
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> nums = {8, 6, 10, 5, 7, 9, 11};
    ListNode *pHead = createList(nums);
    // 打印链表
    cout<<"打印链表: ";
    printList(pHead);
    // 从尾到头打印链表
    cout<<"从尾到头打印链表: ";
    vector<int> ans = printListFromTailToHead(pHead);
    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}
