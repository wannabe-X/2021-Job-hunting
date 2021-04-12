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

// Left Right�൱��˫ָ�룬Leftָ��ͷ��㣬Rightָ��β���

bool isPalindrome(ListNode *head)
{
    // ��һ�������ҵ�������е�λ��
    // �������Ľڵ����Ϊż��������slow����ָ���м�ڵ����һ��Ԫ��
    // �������Ľڵ����Ϊ����������slow����ָ���м�ڵ�Ԫ��
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // �ڶ���
    // ��fast����ΪNULL�����ʾ����Ľڵ����Ϊ����������Ӧ��slow����
    if (fast != NULL)
        slow = slow->next;

    // ������Ԫ�ط�ת
    // ԭ���� 1->2->3->4->5->4->3->2->1->NULL
    // ��ת�� 1->2->3->4->5->1<-2<-3<-4 , 5->1->NULL

    ListNode *Left = head;
    ListNode *Right = traverse(slow);

    // print(Left);

    // ������
    // ����ȷ��Leftָ��ͷ�ڵ�Ԫ�أ�Rightָ����η�ת֮���ͷ���Ԫ��
    // ��ʼ�Ƚ�
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