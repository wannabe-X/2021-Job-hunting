/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-02 17:34:26
 * @LastEditTime: 2021-09-02 17:48:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie() : isWord(false), child(26, nullptr)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (auto &c : word)
        {
            if (node->child[c - 'a'] == nullptr)
                node->child[c - 'a'] = new Trie();
            node = node->child[c - 'a'];
        }

        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *node = this->searchPrefix(prefix);
        return node != nullptr;
    }

private:
    bool isWord;
    vector<Trie *> child;

    Trie *searchPrefix(const string prefix)
    {
        Trie *node = this;
        for (const auto &c : prefix)
        {
            if (node->child[c - 'a'] == nullptr)
                return nullptr;

            node = node->child[c - 'a'];
        }

        return node;
    }
};

int main(void)
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 返回 True
    cout << trie.search("app") << endl;     // 返回 False
    cout << trie.startsWith("app") << endl; // 返回 True
    trie.insert("app");
    cout << trie.search("app") << endl; // 返回 True

    return 0;
}