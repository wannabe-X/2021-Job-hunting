/*
 * @Description: 删除链表中重复的结点
 * @Author: Mr. Lee
 * @Date: 2021-07-04 11:33:59
 * @LastEditTime: 2021-07-04 13:44:48
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

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

void delRepeat(ListNode *&pHead)
{
}

ListNode *deleteDuplication(ListNode *pHead)
{
    ListNode *p1 = pHead, *p2 = pHead->next;
    queue<int> repeat;
    map<int, int> m;
    // 找出重复的元素
    for (; p1; m[p1->val]++, p1 = p1->next)
        ;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second > 1)
            for (int i = 0; i < (*it).second; repeat.push((*it).first), i++)
                ;
    }

    // 去掉重复
    p1 = new ListNode(0), p2 = pHead;
    ListNode *p = p1;
    while (p2)
    {
        if (p2->val == repeat.front())
        {
            repeat.pop();
            auto tmp = p2->next;
            free(p2);
            p1->next = tmp;
            p2 = tmp;
        }
        else
        {
            p1->next = p2;
            p1 = p2;
            p2 = p2->next;
        }
    }
    
    auto res = p->next;
    free(p);

    return res;
}

int main()
{
    vector<int> nums = {1, 1,2};
    ListNode *pHead = createList(nums);
    ListNode *ans = deleteDuplication(pHead);
    printList(ans);

    return 0;
}
