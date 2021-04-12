# -*- coding:utf-8 -*-
'''
方法一
class LRUCache:
    #@param capacity,an integer
    def __init__(self,capacity):
        self.cache ={}
        self.used_list=[]
        self.capacity = capacity
    #@return an integer
    def get(self,key):
        if key in self.cache:
            #使用一个list来记录访问的顺序，最先访问的放在list的前面，最后访问的放在list的后面，故cache已满时，则删除list[0]，然后插入新项；
            if key != self.used_list[-1]:
                self.used_list.remove(key)
                self.used_list.append(key)
            return self.cache[key]
        else:
            return -1
    def set(self,key,value):
        if key in self.cache:
            self.used_list.remove(key)
        elif len(self.cache) == self.capacity:
            self.cache.pop(self.used_list.pop(0))
        self.used_list.append(key)
        self.cache[key] = value
'''

# 方法二：

import collections


# 基于orderedDict实现
class LRUCache(collections.OrderedDict):
    '''
    function:利用collection.OrdereDict数据类型实现最近最少使用的算法
    OrdereDict有个特殊的方法popitem(Last=False)时则实现队列，弹出最先插入的元素
    而当Last=True则实现堆栈方法，弹出的是最近插入的那个元素。
    实现了两个方法：get(key)取出键中对应的值，若没有返回None
    set(key,value)更具LRU特性添加元素
    '''

    def __init__(self, capacity=5):
        self.capacity = capacity
        self.cache = collections.OrderedDict()  # 有序字典

    def get(self, key: int):
        value = None
        if key in self.cache.keys():
            # 因为在访问的同时还要记录访问的次数（顺序）
            value = self.cache.pop(key)
            # 保证最近访问的永远在list的最后面
            self.cache[key] = value
        return value

    def put(self, key: int, value: int):
        if key in self.cache.keys():
            self.cache.pop(key)
            self.cache[key] = value
        elif self.capacity == len(self.cache):
            self.cache.popitem(last=False)
            self.cache[key] = value
        else:
            self.cache[key] = value


if __name__ == '__main__':
    lru = LRUCache(2)
    lru.put(1, 1)  # 缓存是 {1=1}
    lru.put(2, 2)  # 缓存是 {1=1, 2=2}
    print(lru.get(1))  # 返回 1
    lru.put(3, 3)  # 该操作会使得关键字 2 作废，缓存是 {3=3,1=1}
    print(lru.get(2))  # 返回 -1 (未找到)
    lru.put(4, 4)  # 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    print(lru.get(1))  # 返回 -1 (未找到)
    print(lru.get(3))  # 返回 3
