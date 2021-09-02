/*
 * @Description: 剑指 Offer II 063. 替换单词
 * @Author: Mr. Lee
 * @Date: 2021-09-01 23:29:18
 * @LastEditTime: 2021-09-01 23:31:20
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string replaceWords(vector<string> &dictionary, string sentence)
{
}

int main(void)
{
    vector<string> dictionary = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    string ans = replaceWords(dictionary, sentence);
    cout << ans << endl;
    
    return 0;
}
