/*
 * @Description: 在O(1)时间删除链表结点
 * @Author: Mr. Lee
 * @Date: 2021-07-30 09:54:04
 * @LastEditTime: 2021-07-30 11:02:16
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 尾插法建立链表
ListNode *CreateListNode()
{
    ListNode *head = new ListNode(-1), *pHead = head;

    int n;
    cout << "请输入链表的结点个数:";
    cin >> n;

    int tmp;

    for (int i = 0; i < n; i++)
    {
        cout << "请输入第" << i + 1 << "个结点:";
        cin >> tmp;
        ListNode *p = new ListNode(tmp);
        pHead->next = p;
        pHead = p;
    }

    ListNode *p = head->next;
    free(head);
    head = nullptr;

    return p;
}

void PrintListNode(ListNode *head)
{
    cout << "链表的结点:";
    for (auto tmp = head; tmp; tmp = tmp->next)
    {
        cout << tmp->val << " ";
    }
    cout << endl;
}

ListNode *WillDeleteNode(ListNode *head, int n)
{
    ListNode *target = head;
    for (int i = 1; i < n; i++)
    {
        target = target->next;
    }

    return target;
}

void DeleteNode(ListNode *&head, ListNode *&target)
{
    if (head == nullptr || target == nullptr)
    {
        return;
    }
    
    // 待删除的结点是中间结点
    if (target->next != nullptr)
    {
        auto tmp = target->next;
        target->val = tmp->val;
        target->next = tmp->next;
        free(tmp);
        tmp = nullptr;
    }
    // 待删除的结点是头结点
    else if (head == target)
    {
        free(target);
        target = nullptr;
        head = nullptr;
    }
    // 待删除的结点是尾结点
    else
    {
        auto tmp = head;
        for (; tmp->next != target; tmp = tmp->next)
            ;
        tmp->next = tmp->next->next;
        free(target);
        target = nullptr;
    }
}

int main()
{
    ListNode *head = CreateListNode();
    cout << endl;
    cout << "删除之前";
    PrintListNode(head);
    cout << endl;

    int n;
    cout << "请输入待删除的结点位置:";
    cin >> n;
    ListNode *target = WillDeleteNode(head, n);
    DeleteNode(head, target);
    cout << endl;

    cout << "删除之后";
    PrintListNode(head);
    cout << endl;

    return 0;
}
