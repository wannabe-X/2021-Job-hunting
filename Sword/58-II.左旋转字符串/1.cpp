#include <iostream>

using namespace std;

string reverseLeftWords(string s, int n)
{
    s += s.substr(0, n);
    s.erase(0, n);
    return s;
}

int main(void)
{
    string s = "lrloseumgh";
    int k = 6;
    string ans = reverseLeftWords(s, k);
    cout << ans << endl;
    return 0;
}