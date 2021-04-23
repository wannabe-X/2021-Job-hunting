#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//冒泡法
/*
相邻元素比较：选择小的元素放在前面
非相邻元素比较，则是插入法的思想
*/

void BubbleSort(vector<string> &str, int len)
{
    int i, j, tmp;
    int exchange = 1;
    //外层比较，确定n-1趟
    for (i = 0; (i < len - 1) && (exchange > 0); i++)
    {
        string tmp;
        exchange = 0;
        for (j = len - 1; j > 0; j--)
        { //从后往前冒泡
        // x+y < y+x ---> x<y 
        // 前面的元素是大于后面的 交换
            if (str[j] + str[j - 1] < str[j - 1] + str[j])
            { //相邻元素比较
                tmp = str[j];
                str[j] = str[j - 1];
                str[j - 1] = tmp;
                exchange = 1;
            }
        }
    }
}

string minNumber(vector<int> &nums)
{
    vector<string> temp;
    string res;
    for (int num : nums)
        temp.push_back(to_string(num));

    // 排序规则：拼接的字符串x+y<y+x，则x<y,那么x应该排在y之前
    BubbleSort(temp, temp.size());

    for (string s : temp)
        res += s;
    return res;
}

int main(void)
{
    vector<int> nums = {3, 30, 34, 5, 9};
    string ans = minNumber(nums);
    cout << ans << endl;
    return 0;
}