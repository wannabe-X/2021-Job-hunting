#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
        v.push_back(6); // 迭代器失效
    }
    return 0;
}