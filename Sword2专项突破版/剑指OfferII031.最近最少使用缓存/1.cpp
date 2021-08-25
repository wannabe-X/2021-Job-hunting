/*
 * @Description: 剑指 Offer II 031. 最近最少使用缓存
 * @Author: Mr. Lee
 * @Date: 2021-08-20 09:48:44
 * @LastEditTime: 2021-08-20 10:51:43
 * @LastEditors: Mr. Lee
 */

// LRU技术

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache
{
public:
    struct ListNode
    {
        int key, value;
        ListNode *pre, *next;
        ListNode() {}                                                                     // 默认构造函数
        ListNode(int key, int val) : key(key), value(val), pre(nullptr), next(nullptr) {} // 列表初始化
    };

    LRUCache(int capacity)
    {
        // 初始化容量
        this->capacity = capacity;
        head = new ListNode();
        tail = new ListNode();
        // 构建一个循环双向链表
        head->next = tail;
        tail->pre = head;
    }

    // 将当前结点插入到头结点
    void moveToHead(ListNode *cur)
    {
        ListNode *tmp = head->next;
        cur->next = tmp;
        tmp->pre = cur;
        head->next = cur;
        cur->pre = head;
    }

    // 删除当前结点
    ListNode *deleteCurrentNode(ListNode *cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;

        return cur;
    }

    // 将当前结点变成最近使用的，分为两步
    // 1.将当前结点删除
    // 2.将当前结点移至头结点
    void makeRecently(ListNode *cur)
    {
        ListNode *tmp = deleteCurrentNode(cur);
        moveToHead(tmp);
    }

    // get方法
    // 查找是否已经在map中，如果在，则直接返回对应的value
    int get(int key)
    {
        int ret = -1;
        if (m.count(key))
        {
            ListNode *tmp = m[key];
            makeRecently(tmp);
            ret = tmp->value;
        }

        return ret;
    }

    // 首先在缓存中查找是否包含该进程，若包含，则更新value值
    // 若不包含，则判断是否到达最大容量，若到达最大容量，则删除尾结点，然后将该结点移至头结点，并添加到map中
    // 若没有到达最大容量，则将该结点直接移至头部，然后添加到map中
    void put(int key, int value)
    {
        if (m.count(key))
        {
            // 更新key所对应的value
            ListNode *tmp = m[key];
            tmp->value = value;
            makeRecently(tmp);
        }
        else
        {
            ListNode *node = new ListNode(key, value);
            // 判断是否达到最大容量
            if (m.size() == capacity)
            {
                ListNode *tmp = deleteCurrentNode(tail->pre);
                m.erase(tmp->key); // 注意此处移除的是tmp->key
            }

            // 插入到头结点去
            moveToHead(node);
            m[key] = node;
        }
    }

private:
    int capacity;                     // 最大容量
    unordered_map<int, ListNode *> m; // 判断key是否在缓存中
    ListNode *head, *tail;            // 构建双向链表的首尾结点，实际缓存进程在其中包含
};

int main(void)
{
    LRUCache lru(2);
    lru.put(1, 1);              // 缓存是 {1=1}
    lru.put(2, 2);              // 缓存是 {1=1, 2=2}
    cout << lru.get(1) << endl; // 返回 1
    lru.put(3, 3);              // 该操作会使得关键字 2 作废，缓存是 {3=3, 1=1}
    cout << lru.get(2) << endl; // 返回 -1 (未找到)
    lru.put(4, 4);              // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lru.get(1) << endl; // 返回 -1 (未找到)
    cout << lru.get(3) << endl; // 返回 3
    cout << lru.get(4) << endl; // 返回 4
    return 0;
}