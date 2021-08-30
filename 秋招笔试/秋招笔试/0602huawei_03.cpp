#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    // 处理特殊情况
    if (M < 1 || N < 1)
    {
        return 0;
    }

    // 测试数据
    // vector<vector<int>> vec = {
    //     {910281, 204893, 736213},
    //     {924362, 937935, 524007},
    //     {652577, 199113, 582984}};

    // vec存放原始数据
    vector<vector<int>> vec(M, vector<int>(N, 0));
    // res用来记录走到每个计算单元的最大值
    vector<vector<int>> res(M, vector<int>(N, 0));
    // track用来记录行走的过程轨迹
    vector<vector<int>> track(M, vector<int>(N, 1));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> vec[i][j];
        }
    }

    // 处理特殊情况
    if (M < 2)
    {
        int res1 = 0;
        for (int i = 0; i < N; i++)
        {
            res1 += vec[0][i];
        }

        cout << (int)res1 / N << endl;
        return 0;
    }
    if (N < 2)
    {
        int res2 = 0;
        for (int i = 0; i < M; i++)
        {
            res2 += vec[i][0];
        }

        cout << (int)res2 / M << endl;
        return 0;
    }
    
    // 处理M N都大于等于2的情况
    int tmp = 0;
    for (int j = 0; j < N; j++)
    {
        tmp += vec[0][j];
        res[0][j] = tmp;
    }

    tmp = 0;
    for (int i = 1; i < M; i++)
    {
        tmp += vec[i][0];
        res[i][0] = tmp;
    }

    // count用来计数，计算单元的个数
    int left = 0, up = 0, count = 0;

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            left = res[i][j - 1];
            up = res[i - 1][j];

            if (max(left, up) == left)
            {
                // 来自于左边的话，将其上方置0
                track[i - 1][j] = 0;
            }
            else
            {
                // 来自于上方的话，将其左边置0
                track[i][j - 1] = 0;
            }
            res[i][j] = max(left, up) + vec[i][j];
        }
    }

    // 描述跟踪轨迹
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (track[i][j] == 1)
                count++;
        }
    }

    cout << (int)res[M - 1][N - 1] / count << endl;

    return 0;
}