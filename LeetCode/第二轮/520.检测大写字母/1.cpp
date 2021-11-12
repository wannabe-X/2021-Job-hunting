/*
 * @Description: 520. 检测大写字母
 * @Author: Mr. Lee
 * @Date: 2021-11-13 00:17:31
 * @LastEditTime: 2021-11-13 00:42:25
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool detectCapitalUse(string word)
{
    if (word.size() > 1 && islower(word[0]) && isupper(word[1]))
        return false;

    for (int i = 2; i < word.size(); i++)
    {
        if (islower(word[i]) ^ islower(word[1]))
            return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    string word = "Google";
    bool ans = detectCapitalUse(word);
    cout << boolalpha << ans << endl;

    return 0;
}