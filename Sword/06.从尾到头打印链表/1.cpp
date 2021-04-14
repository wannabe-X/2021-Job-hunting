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

// 正向遍历链表，存入数组，并将其数组反向
vector<int> reversePrint(ListNode *head)
{
    vector<int> nums;
    for (; head != NULL; head = head->next)
        nums.push_back(head->val);

    return {nums.rbegin(), nums.rend()};
}

int main(void)
{

    vector<int> a = {1,3,2};
    ListNode *head = createListNode(a);
    vector<int> ans = reversePrint(head);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}