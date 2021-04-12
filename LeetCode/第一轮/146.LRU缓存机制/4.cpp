#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    struct node
    {
        int key, val;
        node *pre, *next;
        node() {}
        node(int key, int val) : key(key), val(val), pre(NULL), next(NULL) {}
    };

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
        head->next = cur;
        cur->pre = head;
        cur->next = next;
        next->pre = cur;
    }

    node *deletecurrentlynode(node *cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        return cur;
    }

    void makecurrently(node *cur)
    {
        node *temp = deletecurrentlynode(cur);
        movetohead(temp);
    }

    int get(int key)
    {
        int ans = -1;
        if (map.count(key))
        {
            node *temp = map[key];
            makecurrently(temp);
            ans = temp->val;
        }
        return ans;
    }

    void put(int key, int value)
    {
        if (map.count(key))
        {
            node *temp = map[key];
            makecurrently(temp);
            temp->val = value;
        }
        else
        {
            node *cur = new node(key, value);
            if (capacity == map.size())
            {
                node *temp = deletecurrentlynode(tail->pre);
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
    lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    cout << lru.get(3) << endl;
    return 0;
}
