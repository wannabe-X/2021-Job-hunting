/*
 * @Description: 剑指 Offer II 063. 替换单词
 * @Author: Mr. Lee
 * @Date: 2021-09-01 23:29:18
 * @LastEditTime: 2021-09-02 22:59:48
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie
{
public:
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

    string searchStr(const string str)
    {
        string tmp = "";
        Trie *node = this;
        for (auto &c : str)
        {
            if (node->child[c - 'a'] == nullptr)
            {
                return "";
            }
            tmp += c;

            node = node->child[c - 'a'];

            if (node->isWord == true)
                return tmp;
        }

        return tmp;
    }

private:
    bool isWord;
    vector<Trie *> child;
};

string replaceWords(vector<string> &dictionary, string sentence)
{
    //构建前缀树
    Trie t;
    for (int i = 0; i < dictionary.size(); i++)
        t.insert(dictionary[i]);

    string tmp = "", res = "";
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] != ' ')
            tmp += sentence[i];
        else
        {
            if (!t.searchStr(tmp).empty())
                res += t.searchStr(tmp) + ' ';
            else
                res += tmp + ' ';

            tmp = "";
        }
    }

    res += t.searchStr(tmp);

    return res;
}

int main(void)
{
    vector<string> dictionary = {"ac", "ab"};
    string sentence = "it is abnormal that this solution is accepted";
    string ans = replaceWords(dictionary, sentence);
    cout << ans << endl;

    return 0;
}
