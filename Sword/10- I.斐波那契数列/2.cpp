#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> myMap;

// 常规递归解法+带有备忘录的解法
int fib(int n)
{
    if (n <= 1)
        return n;
    if (myMap.count(n))
        return myMap[n];

    myMap[n] = (fib(n - 1) + fib(n - 2)) % 1000000007;
    return myMap[n];
}

int main(void)
{
    int n = 0;
    int ans = fib(45);
    cout << ans << endl;
    return 0;
}