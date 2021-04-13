#include <iostream>
#include <vector>
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
    for (; T != NULL; T = T->next)
        cout << T->val << endl;
}

ListNode *traverse(ListNode *head)
{
    ListNode *pre = NULL, *cur = head;
    while (cur != NULL)
    {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

// Left Right相当于双指针，Left指向头结点，Right指向尾结点

bool isPalindrome(ListNode *head)
{
    // 第一步，先找到链表的中点位置
    // 如果链表的节点个数为偶数个，则slow最终指向中间节点的下一个元素
    // 如果链表的节点个数为奇数个，则slow最终指向中间节点元素
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 第二步
    // 若fast最终为NULL，则表示链表的节点个数为奇数个，则应将slow后移
    if (fast != NULL)
        slow = slow->next;

    // 将后半段元素反转
    // 原链表 1->2->3->4->5->4->3->2->1->NULL
    // 反转后 1->2->3->4->5->1<-2<-3<-4 , 5->1->NULL

    ListNode *Left = head;
    ListNode *Right = traverse(slow);

    // print(Left);

    // 第三步
    // 现在确保Left指向头节点元素，Right指向后半段反转之后的头结点元素
    // 开始比较
    while (Right != NULL)
    {
        if (Left->val != Right->val)
            return false;
        Left = Left->next;
        Right = Right->next;
    }
    return true;
}

int main(void)
{
    vector<int> a = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    ListNode *head = createListNode(a);
    cout << boolalpha << isPalindrome(head) << endl;
}