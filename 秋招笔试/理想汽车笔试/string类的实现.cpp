/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-29 21:38:43
 * @LastEditTime: 2021-08-29 22:46:29
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char *strcpy1(char *strDest, char *strSrc)
{
    if (strDest == NULL || strSrc == NULL)
        throw "Invalid arguments";

    char *strDestCpy = strDest;
    while ((*strDest++ = *strSrc++) != '\0')
        ;
    return strDestCpy;
}

string strcpy1(string strDest, string strSrc)
{
    if (strSrc.empty() || strDest.empty())
    {
        return strSrc;
    }

    strDest.resize(strSrc.size());
    for (int i = 0; i < strSrc.size(); i++)
    {
        strDest[i] = strSrc[i];
    }

    return strDest;
}

int main(void)
{
    string strdst = "abcd", strsrc = "efg";
    string ans = strcpy1(strdst, strsrc);
    cout << ans << endl;

    return 0;
}