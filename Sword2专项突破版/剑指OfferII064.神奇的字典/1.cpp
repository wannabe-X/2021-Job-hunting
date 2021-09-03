/*
 * @Description: 剑指 Offer II 064. 神奇的字典
 * @Author: Mr. Lee
 * @Date: 2021-09-03 00:20:47
 * @LastEditTime: 2021-09-03 01:00:57
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

class MagicDictionary
{
private:
    Trie *root;
    bool dfs(Trie *root, string &word, int index, int edit)
    {
        if (root == nullptr)
            return false;

        if (root->isWord && index == word.size() && edit == 1)
            return true;

        if (index < word.size() && edit <= 1)
        {
            bool found = false;
            for (int i = 0; i < 26 && !found; i++)
            {
                int next = (i == word[index] - 'a') ? edit : edit + 1;
                found = dfs(root->child[i], word, index + 1, next);
            }
            return found;
        }

        return false;
    }

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary)
    {
        // 构建前缀树
        for (auto &str : dictionary)
            root->insert(str);
    }

    bool search(string searchWord)
    {
        return dfs(root, searchWord, 0, 0);
    }

private:
    Trie t;
};

int main(void)
{
    return 0;
}