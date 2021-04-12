#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    struct node
    {
        int key, val;
        node *next, *pre;
        node() {}
        node(int key, int val) : key(key), val(val), next(NULL), pre(NULL) {}
    };

    // ��ɳ�ʼ��
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->pre = head;
    }

    void movetohead(node *cur)
    {
        node *next = head->next;
        cur->pre = head;
        head->next = cur;
        next->pre = cur;
        cur->next = next;
    }

    node *delele(node *cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        return cur;
    }

    void makerecent(node *cur)
    {
        node *temp = delele(cur);
        movetohead(temp);
    }

    int get(int key)
    {
        int ret = -1;
        if (map.count(key))
        {
            node *temp = map[key];
            makerecent(temp);
            ret = temp->val;
        }
        return ret;
    }

    void put(int key, int val)
    {
        if (map.count(key))
        {
            node *temp = map[key];
            makerecent(temp);
            temp->val = val;
        }
        else
        {
            node *cur = new node(key, val);
            if (capacity == map.size())
            {
                node *temp = delele(tail->pre);
                map.erase(temp->key);
            }
            movetohead(cur);
            map[key] = cur;
        }
    }

    unordered_map<int, node *> map;
    int capacity;
    node *head, *tail;
};

int main(void)
{
    LRUCache lru(2);
    lru.put(1, 1);              // ������ {1=1}
    lru.put(2, 2);              // ������ {1=1, 2=2}
    cout << lru.get(1) << endl; // ���� 1
    lru.put(3, 3);              // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {3=3, 1=1}
    cout << lru.get(2) << endl; // ���� -1 (δ�ҵ�)
    lru.put(4, 4);              // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
    cout << lru.get(1) << endl; // ���� -1 (δ�ҵ�)
    cout << lru.get(3) << endl; // ���� 3
    cout << lru.get(4) << endl; // ���� 4
    return 0;
}