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