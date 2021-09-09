/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-09 18:57:15
 * @LastEditTime: 2021-09-09 19:49:43
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string path = "";
    int pathlen = 0;
    stack<vector<string>> stk;

    for (int i = 0; i < n; i++)
    {
        vector<string> v;

        string str;
        while (cin >> str)
        {
            v.push_back(str);
            if (cin.get() == '\n')
                break;
        }

        if (v[0] == "cd" && v[1] != "..")
        {
            pathlen++;
            path += ('\\' + v[1]);
        }
        else if (v[0] == "pwd")
        {
            if (pathlen >= 1)
            {
                cout << path << endl;
            }
            else
            {
                cout << '\\' << endl;
            }
        }
        else if (v[0] == "cd" && v[1] == "..")
        {
            if (pathlen >= 1)
            {
                int pos = path.find_last_of('/\\');
                path = path.substr(0, pos);
                pathlen--;
            }
        }
    }

    return 0;
}
