/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-29 09:59:39
 * @LastEditTime: 2021-09-29 11:31:32
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, -1, 0, 1};
unordered_map<char, int> dirM = {{'E', 0}, {'S', 1}, {'W', 2}, {'N', 3}};


int func(int N, int X0, int Y0, int X1, int Y1, string dir)
{

    return -1;
}

int main(void)
{
    int N, X0, Y0, X1, Y1;
    cin >> N >> X0 >> Y0 >> X1 >> Y1;
    string dir;
    cin >> dir;
    int ans = func(N, X0, Y0, X1, Y1, dir);
    cout << ans;
    return 0;
}