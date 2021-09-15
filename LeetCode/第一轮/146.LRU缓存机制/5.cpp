/*
 * @Description: LRU
 * @Author: Mr. Lee
 * @Date: 2021-09-15 10:40:20
 * @LastEditTime: 2021-09-15 11:00:58
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache
{
public:
    struct Node
    {
        int key, val;
        Node *left, *right;
        Node() {}
        Node(int x, int y) : key(x), val(y), left(nullptr), right(nullptr) {}
    };

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->right = tail;
        tail->left = head;
    }

    void moveToHead(Node *cur)
    {
        Node *tmp = head->right;
        head->right = cur;
        cur->left = head;
        tmp->left = cur;
        cur->right = tmp;
    }

    Node *deleteNode(Node *cur)
    {
        cur->right->left = cur->left;
        cur->left->right = cur->right;

        return cur;
    }

    void makeCurrently(Node *cur)
    {
        moveToHead(deleteNode(cur));
    }

    int get(int key)
    {
        int tmp = -1;
        if (m.count(key))
        {
            Node *t = m[key];
            tmp = t->val;
            makeCurrently(t);
        }

        return tmp;
    }

    void insert(int key, int val)
    {
        if (m.count(key))
        {
            Node *tmp = m[key];
            tmp->val = val;
            makeCurrently(tmp);
        }
        else
        {
            if (m.size() == capacity)
            {
                Node *tmp = deleteNode(tail->left);
                m.erase(tmp->key);
                delete tmp;
            }

            Node *cur = new Node(key, val);
            moveToHead(cur);
            m[key] = cur;
        }
    }

private:
    Node *head, *tail;
    int capacity;
    unordered_map<int, Node *> m;
};

int main(void)
{
    LRUCache *lru = new LRUCache(2);
    lru->insert(1, 1);
    lru->insert(2, 2);
    lru->insert(3, 3);
    cout << lru->get(2) << endl;
    return 0;
}