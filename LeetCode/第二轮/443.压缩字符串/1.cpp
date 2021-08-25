/*
 * @Description: 443. 压缩字符串
 * @Author: Mr. Lee
 * @Date: 2021-08-21 00:41:15
 * @LastEditTime: 2021-08-21 10:09:38
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();
    int left = 0, right = 0;

    for (int r = 0; r < n; r++)
    {

        if (r == n - 1 || chars[r] != chars[r + 1])
        {
            chars[right++] = chars[r];
            int num = r - left + 1;

            if (num > 1)
            {
                int base = right;
                while (num > 0)
                {
                    chars[right++] = (num % 10) + '0';
                    num /= 10;
                }

                reverse(&chars[base], &chars[right]);
            }

            left = r + 1;
        }
    }

    return right;
}

int main()
{
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    int ans = compress(chars);
    cout << ans << endl;
    return 0;
}