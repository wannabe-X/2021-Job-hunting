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

ListNode *Left;
// Left Right相当于双指针，Left指向头结点，Right指向尾结点
bool traverse(ListNode *Right)
{
    if (Right == NULL)
        return true;
    bool res = traverse(Right->next);
    // 后序遍历
    res = res && (Right->val == Left->val);
    Left = Left->next;
    return res;
}

bool isPalindrome(ListNode *head)
{
    Left = head;
    return traverse(head);
}

int main(void)
{
    vector<int> a = {1, 2, 1};
    ListNode *head = createListNode(a);
    cout << boolalpha << isPalindrome(head) << endl;
}