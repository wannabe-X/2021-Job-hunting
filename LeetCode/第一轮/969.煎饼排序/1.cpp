#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;

vector<int> res;

void reverse(vector<int> &arr, int i, int j)
{
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void sort(vector<int> &cakes, int n)
{
    if (n == 1)
        return;
    int maxCake = 0, maxCakeIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (cakes[i] > maxCake)
        {
            maxCake = cakes[i];
            maxCakeIndex = i;
        }
    }

    reverse(cakes, 0, maxCakeIndex);
    res.push_back(maxCakeIndex + 1);
    reverse(cakes, 0, n - 1);
    res.push_back(n);

    sort(cakes, n - 1);
}

// void sort(vector<int> &cakes, int n)
// {
//     // base case
//     if (n == 1)
//         return;

//     // Ѱ������������
//     int maxCakeIndex = max_element(cakes.begin(), cakes.begin() + n) - cakes.begin();

//     // ������а����ı��ŵ��������η�ת
//     // ������һ������������, �Ͳ���Ҫ��ת, ֱ�ӽ����´εݹ�
//     if (maxCakeIndex == n - 1)
//     {
//         sort(cakes, n - 1);
//         return;
//     }

//     // ��һ�η�ת, ����������������
//     // �����һ����������������, �Ͳ���Ҫ��һ�η�ת.
//     if (maxCakeIndex != 0)
//     {
//         reverse(cakes.begin(), cakes.begin() + maxCakeIndex + 1);
//         res.push_back(maxCakeIndex + 1);
//     }

//     // �ڶ��η�ת������������������
//     reverse(cakes.begin(), cakes.begin() + n);
//     res.push_back(n);

//     // �ݹ����
//     sort(cakes, n - 1);
// }

vector<int> pancakeSort(vector<int> &arr)
{
    sort(arr, arr.size());
    return res;
}

int main(void)
{
    vector<int> pancake = {3, 2, 4, 1};
    vector<int> ans = pancakeSort(pancake);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}