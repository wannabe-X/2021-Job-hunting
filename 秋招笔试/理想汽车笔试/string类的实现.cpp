/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-29 21:38:43
 * @LastEditTime: 2021-08-29 23:06:34
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

char *strcpy1(char *strDest, char *strSrc)
{
    assert(strDest && strSrc);

    char *strDestCpy = strDest;
    while ((*strDest++ = *strSrc++) != '\0')
        ;
    return strDestCpy;
}

string strcpy1(string strDest, string strSrc)
{
    assert(strDest.size() && strSrc.size());

    strDest.resize(strSrc.size());
    for (int i = 0; i < strSrc.size(); i++)
    {
        strDest[i] = strSrc[i];
    }
    
    strDest = strDest + '\0';
    return strDest;
}

int main(void)
{
    string strdst = "abcd", strsrc = "efg";
    string ans = strcpy1(strdst, strsrc);
    cout << ans << endl;

    return 0;
}