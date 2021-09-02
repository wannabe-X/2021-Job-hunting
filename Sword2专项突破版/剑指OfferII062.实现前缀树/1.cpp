/*
 * @Description: 剑指 Offer II 062. 实现前缀树
 * @Author: Mr. Lee
 * @Date: 2021-09-02 16:20:43
 * @LastEditTime: 2021-09-02 16:48:55
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
public:
    // 构造函数
    // 初始化，root结点
    Trie() : isWord(false), children(26, nullptr)
    {
    }

    // 插入，如果没有该字符的路径，则新建一个结点记录该路径
    // 最后当一个单词插入结束，标记该结点位置的结束符，也就是node->isWord = true;
    void insert(string word)
    {
        Trie *node = this;
        for (const char &c : word)
        {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();

            node = node->children[c - 'a'];
        }

        node->isWord = true;
    }

    // 从树的根节点出发，开始寻找
    // 如果该结点的字符路径没有找到，返回的为nullptr，则说明没有找到
    // 如果返回不为nullptr，这说明找到了该字符串的路径，需要判断该结点是否为某个字符串的结尾
    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);

        return (node != nullptr) && (node->isWord == true);
    }

    // 判断前缀和search一样，只不过对返回结点是否为某个字符串的结尾不做要求
    // 只要该字符串路径存在即可
    bool startsWith(string prefix)
    {
        Trie *node = this->searchPrefix(prefix);

        return (node != nullptr);
    }

private:
    bool isWord;
    vector<Trie *> children;

    Trie *searchPrefix(string &prefix)
    {
        Trie *node = this;

        for (const char &c : prefix)
        {
            if (node->children[c - 'a'] == nullptr)
                return nullptr;

            node = node->children[c - 'a'];
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