/*
 * @Description: 剑指 Offer II 067. 最大的异或
 * @Author: Mr. Lee
 * @Date: 2021-09-02 15:14:42
 * @LastEditTime: 2021-09-04 00:37:00
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 前缀树
class Trie
{
public:
    vector<Trie *> child;
    Trie() : child(2, nullptr) {}

    void insert(int val)
    {
        Trie *node = this;
        for (int i = 31; i > -1; i--)
        {
            int bit = (val >> i) & 1;
            if (node->child[bit] == nullptr)
                node->child[bit] = new Trie();
            node = node->child[bit];
        }
    }

    int MAXXOR(int n)
    {
        Trie *node = this;
        int res = 0;

        for (int i = 31; i > -1; i--)
        {
            int bit = (n >> i) & 1;
            if (node->child[!bit] != nullptr)
            {
                res |= (1 << i);
                node = node->child[!bit];
            }
            else
                node = node->child[bit];
        }

        return res;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie *root = new Trie();

    for (const auto &num : nums)
        root->insert(num);

    int maxXOR = INT_MIN;
    for (const auto &num : nums)
        maxXOR = max(maxXOR, root->MAXXOR(num));

    return maxXOR;
}

int main(void)
{
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    int ans = findMaximumXOR(nums);
    cout << ans << endl;

    return 0;
}