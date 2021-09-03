/*
 * @Description: 剑指 Offer II 065. 最短的单词编码
 * @Author: Mr. Lee
 * @Date: 2021-09-03 10:42:42
 * @LastEditTime: 2021-09-03 10:55:23
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
public:
    bool isWord;
    vector<Trie *> child;
    Trie() : isWord(false), child(26, nullptr) {}

    void insert(string str)
    {
        Trie *node = this;
        for (auto &c : str)
        {
            if (node->child[c - 'a'] == nullptr)
                node->child[c - 'a'] = new Trie();
            node = node->child[c - 'a'];
        }
        node->isWord = true;
    }
};

int minimumLengthEncoding(vector<string> &words)
{
}

int main(void)
{
    vector<string> words = {"time", "me", "bell"};
    int ans = minimumLengthEncoding(words);
    cout << ans << endl;

    return 0;
}