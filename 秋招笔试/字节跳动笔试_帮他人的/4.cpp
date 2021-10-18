/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-10-17 20:21:14
 * @LastEditTime: 2021-10-17 20:35:37
 * @LastEditors: Mr. Lee
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define MAXN 100000 + 10
using namespace std;
int A[MAXN];
int Amax[MAXN][20];
int Amin[MAXN][20];
int N, Q;

void RMQ_init()
{
    for (int i = 1; i <= N; i++)
        Amax[i][0] = Amin[i][0] = A[i];
    for (int j = 1; (1 << j) <= N; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
        {
            Amax[i][j] = max(Amax[i][j - 1], Amax[i + (1 << (j - 1))][j - 1]);
            Amin[i][j] = min(Amin[i][j - 1], Amin[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R)
{
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1)
        k++;
    return max(Amax[L][k], Amax[R - (1 << k) + 1][k]) - min(Amin[L][k], Amin[R - (1 << k) + 1][k]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &N, &Q);
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        RMQ_init();
        int s = 1;
        LL ans = 0;
        for (int i = 1; i <= N; i++) //枚举结尾
        {
            while (query(s, i) >= Q && s < i)
                s++;
            ans += i - s + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
