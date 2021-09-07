/*
 * @Description: 剑指 Offer II 030. 插入、删除和随机访问都是 O(1) 的容器
 * @Author: Mr. Lee
 * @Date: 2021-09-07 15:35:22
 * @LastEditTime: 2021-09-07 16:40:50
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        m.clear();
        nums.clear();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m.count(val))
            return false;

        m[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (!m.count(val))
            return false;

        // 获取要删除的元素下标,然后更新哈希表;之后在哈希表中删除该元素,并将最后一个元素挪到已删除元素的位置上
        // 最后从数组尾部删除一个元素即可
        int loc = m[val];
        m[nums.back()] = loc;
        m.erase(val);
        nums[loc] = nums.back();
        nums.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }

private:
    unordered_map<int, int> m;
    vector<int> nums;
};

int main(void)
{
    RandomizedSet *randomSet = new RandomizedSet(); // 初始化一个空的集合

    cout << boolalpha << randomSet->insert(1) << endl; // 向集合中插入 1 ， 返回 true 表示 1 被成功地插入

    cout << boolalpha << randomSet->remove(2) << endl; // 返回 false，表示集合中不存在 2

    cout << boolalpha << randomSet->insert(2) << endl; // 向集合中插入 2 返回 true ，集合现在包含 [1,2]

    cout << randomSet->getRandom() << endl; // getRandom 应随机返回 1 或 2

    cout << boolalpha << randomSet->remove(1) << endl; // 从集合中移除 1 返回 true 。集合现在包含 [2]

    cout << boolalpha << randomSet->insert(2) << endl; // 2 已在集合中，所以返回 false

    cout << randomSet->getRandom() << endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2

    return 0;
}