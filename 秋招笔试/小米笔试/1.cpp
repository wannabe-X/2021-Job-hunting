/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-09-01 18:40:30
 * @LastEditTime: 2021-09-01 19:59:51
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
void merge(vector<int> &A, vector<int> &B, int m, int n)
{
    int i = A.size() - 1;
    m--;
    n--;
    while (n > -1)
    {
        while (m > -1 && A[m] > B[n])
        {
            swap(A[i--], A[m--]);
        }
        swap(A[i--], B[n--]);
    }
}

int main(void)
{
    string str, tmp;
    cin >> str;
    stringstream input(str);
    vector<string> v;
    while (getline(input, tmp, ','))
    {
        v.push_back(tmp);
    }

    int m = stoi(v[0].substr(2, v[0].size() - 2));
    int n = stoi(v[1].substr(2, v[1].size() - 2));

    string A, B;
    cin >> A;
    vector<int> numA, numB;

    stringstream n1(A);
    while (getline(n1, tmp, ','))
    {
        numA.push_back(stoi(tmp));
    }

    cin >> B;
    stringstream n2(B);
    while (getline(n2, tmp, ','))
    {
        numB.push_back(stoi(tmp));
    }

    numA.resize(m + n);

    merge(numA, numB, m, n);

    for (auto &num : numA)
    {
        cout << num << " ";
    }

    return 0;
}