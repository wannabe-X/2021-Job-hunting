/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-08-28 18:58:20
 * @LastEditTime: 2021-08-28 19:52:11
 * @LastEditors: Mr. Lee
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Valid(char *p)
{
    if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9'))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char str[250];
    char *p = str;
    char m[100], ma[100][20] = {'\0'};
    char(*pc)[20];

    pc = ma;
    gets(str);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (Valid(p))
        {
            m[i] = *p;
        }
        else if ((*p) == '-' && Valid(p - 1) && Valid(p + 1))
        {
            m[i] = *p;
        }
        else
        {
            m[i] = ' ';
        }
        p++;
    }

    m[len] = '\0';

    int i = 0, j = 0, k = 0;
    while (m[i] != '\0')
    {
        if (Valid(m + i) || m[i] == '-')
        {
            *(*(pc + j) + k) = m[i];
            k++;
        }
        else
        {
            j++;
            k = 0;
        }
        i++;
    }

    for (int i = j; i > -1; i--)
    {
        if (*(*(pc + i)) != '\0')
        {
            printf("%s ", *(pc + i));
        }
    }
    
    printf("\n");

    return 0;
}