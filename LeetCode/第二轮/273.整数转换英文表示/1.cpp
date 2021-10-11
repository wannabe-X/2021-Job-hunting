/*
 * @Description: 273. 整数转换英文表示
 * @Author: Mr. Lee
 * @Date: 2021-10-11 09:37:31
 * @LastEditTime: 2021-10-11 11:11:22
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string numberToWords(int num)
{
    unordered_map<int, string> m1, m2, m3, m4;
    m1 = {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
    m2 = {{1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};
    m3 = {{1, "Hundred"}, {2, "Thousand"}, {3, "Million"}, {4, "Billion"}, {5, "Trillion"}};
    m4 = {{11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};

    string res;

    string n = to_string(num);
    if (n.size() == 1)
    {
        return m1[n[0] - '0'];
    }

    reverse(n.begin(), n.end());

    vector<string> v;
    for (int i = 0; i < n.size(); i += 3)
    {
        string tmp = n.substr(i, 3);
        reverse(tmp.begin(), tmp.end());
        v.push_back(tmp);
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        string tmp;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] != '0')
            {
                if (v[i].size() - j == 3)
                    tmp += m1[v[i][j] - '0'] + " " + "Hundred ";
                else if (v[i].size() - j == 2)
                {
                    if (m4.count(stoi(v[i].substr(j, 2))))
                    {
                        tmp += m4[stoi(v[i].substr(j, 2))] + " ";
                        j += 2;
                    }
                    else
                    {
                        tmp += m2[v[i][j] - '0'] + " ";
                    }
                }
                else if (v[i].size() - j == 1)
                {
                    tmp += m1[v[i][j] - '0'] + " ";
                }
            }
        }

        res += tmp;

        if (v.size() - i > 1 && !tmp.empty())
        {
            res += m3[v.size() - i] + " ";
        }
    }

    res = res.erase(res.find_last_not_of(" ") + 1);

    return res;
}

int main(void)
{
    int num = 1000000;
    string ans = numberToWords(num);
    cout << ans << endl;

    return 0;
}