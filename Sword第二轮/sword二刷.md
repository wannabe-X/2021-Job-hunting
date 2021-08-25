# 剑指offer

## 知识点1：排序

### **数据流中的中位数**

**涉及知识：**

```c++
/*
	大根堆、小根堆：
        #include <queue>
        #include <functional>
        //升序队列，小顶堆
        priority_queue <int,vector<int>,greater<int> > q;
        //降序队列，大顶堆
        priority_queue <int,vector<int>,less<int> >q;
        //greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）

        在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。优先队列具有最高级先出 （first in, largest out）的行为特征。
        优先队列具有队列的所有特性，包括队列的基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。
        
        和队列基本操作相同:
            top 访问队头元素
            empty 队列是否为空
            size 返回队列内元素个数
            push 插入元素到队尾 (并排序)
            emplace 原地构造一个元素并插入队列
            pop 弹出队头元素
            swap 交换内容

*/
```

**解题思路：**

* 使用优先队列中的大根堆、小根堆，将数据划分为两组。
* 大根堆里面装的是中位数左边的数据，按照从大到小排序；小根堆里面装的是中位数右边的队列，按照从小到大排序。第一个数字进来，先插入大根堆。
* 这样，可以保证小根堆的队头元素大于大根堆的队头元素；
* 如果插入的数字个数为偶数个，那么中位数就是大根堆、小根堆的队头元素相加除以2；如果插入得数据为奇数个，那么中位数就是大根堆的队头元素。

**实现代码：**

```c++
/*
 * @Description:剑指 Offer 41. 数据流中的中位数
 * @Author: Mr. Lee
 * @Date: 2021-06-10 15:40:39
 * @LastEditTime: 2021-06-10 17:02:48
 * @LastEditors: Mr. Lee
 */

/*
	大根堆、小根堆：
        #include <queue>
        #include <functional>
        //升序队列，小顶堆
        priority_queue <int,vector<int>,greater<int> > q;
        //降序队列，大顶堆
        priority_queue <int,vector<int>,less<int> >q;
        //greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）

        在优先队列中，元素被赋予优先级。当访问元素时，具有最高优先级的元素最先删除。优先队列具有最高级先出 （first in, largest out）的行为特征。
        优先队列具有队列的所有特性，包括队列的基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的。
        
        和队列基本操作相同:
            top 访问队头元素
            empty 队列是否为空
            size 返回队列内元素个数
            push 插入元素到队尾 (并排序)
            emplace 原地构造一个元素并插入队列
            pop 弹出队头元素
            swap 交换内容

*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> small_top;
    priority_queue<int, vector<int>, less<int>> big_top;

    void Insert(int num)
    {
        if (small_top.size() == big_top.size())
        {
            // 要把小根堆的最小元素移到大根堆里去，大根堆的最大元素移到小根堆
            // 也就是说，小根堆把小元素都移走，大根堆把大元素都移走
            // 最后，也就是说小根堆中存放的是中位数右边的数字，按照从小到大的顺序存入
            // 大根堆中存入的是中位数左边的数字，按照从大到小的顺序存放
            // 小根堆中最小的元素(队头元素) 大于等于 大根堆中最大的元素(队头元素)
            
            // 先存入到大根堆，那么当元素个数为奇数的时候，大根堆中的元素多一个，就是中位数
            small_top.push(num);
            big_top.push(small_top.top());
            small_top.pop();
        }
        else
        {
            big_top.push(num);
            small_top.push(big_top.top());
            big_top.pop();
        }
    }

    double GetMedian()
    {
        if (small_top.size() + big_top.size())
        {
            if ((small_top.size() + big_top.size()) % 2)
            {
                return (big_top.top() + 0.0);
            }

            return (small_top.top() + big_top.top() + 0.0) / 2;
        }

        return 0.0;
    }
};

// class Solution
// {
// public:
//     priority_queue<int, vector<int>, greater<int>> small_top;
//     priority_queue<int, vector<int>, less<int>> big_top;

//     void Insert(int num)
//     {
//         if (small_top.size() == big_top.size())
//         {
//             // 先存入到小根堆，那么当元素个数为奇数的时候，小根堆中的元素多一个，就是中位数
//             big_top.push(num);
//             small_top.push(big_top.top());
//             big_top.pop();
//         }
//         else
//         {
//             small_top.push(num);
//             big_top.push(small_top.top());
//             small_top.pop();
//         }
//     }

//     double GetMedian()
//     {
//         if (small_top.size() + big_top.size())
//         {
//             if ((small_top.size() + big_top.size()) % 2)
//             {
//                 return (small_top.top() + 0.0);
//             }

//             return (small_top.top() + big_top.top() + 0.0) / 2;
//         }

//         return 0.0;
//     }
// };

int main()
{
    // 写测试代码
    vector<double> ans;
    Solution slo;
    ans.push_back(slo.GetMedian());
    slo.Insert(1);
    slo.Insert(2);
    ans.push_back(slo.GetMedian());
    slo.Insert(3);
    ans.push_back(slo.GetMedian());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
```



### 最小的k个数

**解题方法1：**

* 先对给定的数组进行排序；
* 取前k个数字，存入结果数组中

**解题代码：**

```c++
/*
 * @Description: 剑指 Offer 40. 最小的k个数。直接排序，然后去前k小数据。
 * @Author: Mr. Lee
 * @Date: 2021-06-10 17:09:29
 * @LastEditTime: 2021-06-10 17:31:35
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> ret;
    if (k == 0 || k > input.size())
        return ret;
    sort(input.begin(), input.end());
    return vector<int>({input.begin(), input.begin() + k});
}

int main()
{
    // 测试用例
    // vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    // int k = 4;
    // vector<int> ans = GetLeastNumbers_Solution(nums, k);

    // 手动输入
    int k, num_len, idx = 0;
    cin >> k >> num_len;
    vector<int> nums(num_len);
    while (cin >> nums[idx++] && idx < num_len)
        ;

    // 获取结果
    vector<int> ans = GetLeastNumbers_Solution(nums, k);
    for (int num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
```



**解题方法2：**

* 如果数组为空或者数组的size小于k，那么就返回空数组即可；
* 建立一个大根堆，其队头元素是最大的，按照从大到小的顺序排列。首先，把队列中的前k个元素填入大根堆中，填入的元素已排好序；
* 其次，遇到原数组中下标大于等于k的元素，则跟大根堆的队头元素比较。如果是小于队头元素，那么则删除队头元素，然后将该元素插入到队列中。直到将原数组中的元素遍历完。
* 最后，将队列中的各个元素依次存入到答案数组中。

**解题代码：**

```c++
/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-06-10 17:34:47
 * @LastEditTime: 2021-06-10 17:44:08
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> ret;
    if (k == 0 || k > input.size())
        return ret;

    // 建立一个大根堆
    priority_queue<int, vector<int>, less<int>> big_top;
    for (const int num : input)
    {
        if (big_top.size() < k)
            big_top.push(num);
        else if (num < big_top.top())
        {
            big_top.pop();
            big_top.push(num);
        }
    }

    while (!big_top.empty())
    {
        ret.push_back(big_top.top());
        big_top.pop();
    }

    return ret;
}

int main()
{
    // 测试用例
    vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;
    vector<int> ans = GetLeastNumbers_Solution(nums, k);

    // 手动输入
    // int k, num_len, idx = 0;
    // cin >> k >> num_len;
    // vector<int> nums(num_len);
    // while (cin >> nums[idx++] && idx < num_len)
    //     ;
    // 获取结果
    // vector<int> ans = GetLeastNumbers_Solution(nums, k);

    for (int num : ans)
    {
        cout << num << " ";
    }
    return 0;
}
```



## 知识点2：递归

### **跳台阶**

**解题思路1：动态规划**

```C++
/*
    动态规划法：
        考虑如果有n个台阶，如何计算dp[n];
        可以知道：青蛙一次可以跳一步或者两步。那么dp[n]可以由状态dp[n-1]和dp[n-2]得到
        因为，青蛙要跳到第n层，只有两种方法，要么从第n-1层一步就跳上去；要么从n-2层两步跳上去
    所以，状态转移方程为：dp[n] = d[n-1] + d[n-2]
    初始条件dp[1] = 1,dp[2] = 2
*/
```

**解题代码：**

```c++
/*
 * @Description: 剑指 Offer 10- II	青蛙跳台阶问题  
 * @Author: Mr. Lee
 * @Date: 2021-06-10 22:52:36
 * @LastEditTime: 2021-06-10 23:13:51
 * @LastEditors: Mr. Lee
 */

/*
    动态规划法：
        考虑如果有n个台阶，如何计算dp[n];
        可以知道：青蛙一次可以跳一步或者两步。那么dp[n]可以由状态dp[n-1]和dp[n-2]得到
        因为，青蛙要跳到第n层，只有两种方法，要么从第n-1层一步就跳上去；要么从n-2层两步跳上去
    所以，状态转移方程为：dp[n] = d[n-1] + d[n-2]
    初始条件dp[1] = 1,dp[2] = 2
*/
#include <iostream>
#include <vector>

using namespace std;

int jumpFloor(int number)
{
    // 定义dp[n] 表示青蛙跳到第n+1层的方案数
    // 最终返回结果为dp[number]
    vector<int> dp(number, 0);
    dp[0] = 1, dp[1] = 2;

    for (int i = 2; i < number; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[number - 1];
}

int main()
{
    // 测试用例
    // int number = 5;
    // int ans = jumpFloor(number);

    int number;
    cin >> number;
    int ans = jumpFloor(number);
    cout << ans << endl;
    return 0;
}
```



**解题思路2：状态压缩：**

```c++
// 状态压缩
// 其实由状态转移方程可以发现，青蛙跳台阶问题其实就是斐波拉契数列的问题，只不过初始值不同
// 斐波拉契数列的初始值为1,1 前两项
// 青蛙跳台阶问题的初始值为1,2 前两项
```

**解题代码：**

```c++
/*
 * @Description: 剑指 Offer 10- II	青蛙跳台阶问题 状态压缩
 * @Author: Mr. Lee
 * @Date: 2021-06-10 22:52:36
 * @LastEditTime: 2021-06-10 23:11:31
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int jumpFloor(int number)
{
    if (number < 3)
        return number;
    int a = 1, b = 2; // 前两项初始值
    for (int i = 3; i <= number; i++)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}

int main()
{
    // 测试用例
    // int number = 5;
    // int ans = jumpFloor(number);

    int number;
    cin >> number;
    int ans = jumpFloor(number);
    cout << ans << endl;
    return 0;
}
```



### **矩形覆盖**

**解题思路：**

* 根据前几项的值，进行猜测状态转移方程
* f(0)=0,f(1)=1,f(2)=2,f(3)=3,f(4)=5,f(5)=8,......
* 因此可以得出状态转移方程：f(n) = f(n-1) + f(n-2)
* 初始状态 if(n<=2) return n;

**解题代码1：**

```c++
// 递归 + 备忘录剪枝
/*
 * @Description: 矩形覆盖 递归法+备忘录
 * @Author: Mr. Lee
 * @Date: 2021-06-16 16:31:14
 * @LastEditTime: 2021-06-16 17:27:12
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

/*
    状态转移方程为：f(n) = f(n-1) + f(n-2)
*/

int helper(vector<int> &memo, int number)
{
    if (number <= 2)
        return number;
    if (memo[number] != 0)
        return memo[number];
    memo[number] = helper(memo, number - 1) + helper(memo, number - 2);

    return memo[number];
}

int rectCover(int number)
{
    if (number <= 3)
        return number;
    vector<int> memo(number + 1, 0);
    return helper(memo, number);
}

int main()
{
    // 测试用例
    // int number = 4;
    // int ans = rectCover(number);

    // 实际输入
    int number;
    cin >> number;
    int ans = rectCover(number);
    cout << ans << endl;

    return 0;
}
```

**解题代码2：**

```c++
/*
 * @Description: 矩形覆盖 动态规划法
 * @Author: Mr. Lee
 * @Date: 2021-06-16 16:31:14
 * @LastEditTime: 2021-06-16 17:34:02
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

/*
    状态转移方程为：f(n) = f(n-1) + f(n-2)
*/

int rectCover(int number)
{
    if (number < 3)
        return number;
    int a = 1, b = 2;
    for (int i = 3; i <= number; i++)
    {
        b = a + b;
        a = b - a;
    }

    return b;
}

int main()
{
    // 测试用例
    // int number = 4;
    // int ans = rectCover(number);

    // 实际输入
    int number;
    cin >> number;
    int ans = rectCover(number);
    cout << ans << endl;

    return 0;
}
```



## 知识点3：贪心

###  **跳台阶扩展问题**

**解题思路：**

*   关于本题，前提是n个台阶会有一次n阶的跳法。
* 状态转移方程为：f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) = f(0) + f(1) + f(2) + ... +f(n-1)

**解题代码：**

```C++
/*
 * @Description: 剑指offer-变态跳台阶II
 * @Author: Mr. Lee
 * @Date: 2021-06-11 09:38:39
 * @LastEditTime: 2021-06-11 10:09:35
 * @LastEditors: Mr. Lee
 */

/*
    关于本题，前提是n个台阶会有一次n阶的跳法。
        f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-(n-1)) + f(n-n) 
*/

#include <iostream>

using namespace std;

int jumpFloorII(int number)
{
    int f_0 = 1, f_1 = 0;
    for (int i = 1; i <= number; i++)
    {
        f_1 += f_0;
        f_0 = f_1;
    }

    return f_1;
}

int main()
{
    // 测试用例
    // int number = 5;
    // int ans = jumpFloorII(number);

    int number;
    cin >> number;
    int ans = jumpFloorII(number);
    cout << ans << endl;
    return 0;
}
```



## 知识点4：动态规划

### **连续子数组的最大和**

**解题思路：**

* 主要是考察当前连续序列求和的结果对下一轮求和的贡献，如果是大于0的，则在下一轮中把上一轮的求和加上；如果贡献小于0，那么就把该贡献置为0，下一次求和的时候直接从下一个元素开始。
* 每进来一个数字，都要保证当前求和结果是最大的。
* 注意初始值：int tmp = 0, res = INT_MIN;

**解题代码：**

```c++
/*
 * @Description: 连续子数组的最大和
 * @Author: Mr. Lee
 * @Date: 2021-06-17 15:15:06
 * @LastEditTime: 2021-06-17 15:44:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    int tmp = 0, res = INT_MIN;
    for (auto num : array)
    {
        tmp += num;
        // 每一步都更新求最大连续子序列的和
        res = max(res, tmp);
		
        // 考察当前求和结果对下一轮的贡献
        // (tmp = max(0, tmp)) 相当于 tmp = tmp > 0 ? tmp : 0;
        // 如果当前数字对求和的贡献小于0，那么就按照0来计算贡献
        tmp = max(0, tmp);
    }

    return res;
}

int main()
{
    // 测试用例
    // vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};

    int numofarray, idx = 0;
    cin >> numofarray;
    vector<int> nums(numofarray);
    while(idx<numofarray && cin>>nums[idx++]);
    int ans = FindGreatestSumOfSubArray(nums);

    cout << ans << endl;

    return 0;
}
```



### **字符串的排列**

**解题思路：**

* 首先建立一个全局变量用于存放结果，然后创建一个临时字符串变量，用于存放中间结果。另外，还需要建立一个字符串长度的向量，用于记录走过的字符，或者说是已经使用过的字符；
* 使用回溯算法，遍历字符串的每个字符，判断是否被使用，然后将未使用的字符添加到中间结果中；
* 返回条件：用于存放中间结果的字符串的长度和给定的字符串的长度相等，保存中间变量，然后返回；
* 回溯，将走过的位置抹除掉。然后中去掉中间结果中的最后一个元素

**解题代码：**

```C++
/*
 * @Description: 字符串的排列。回溯算法
 * @Author: Mr. Lee
 * @Date: 2021-06-17 16:01:50
 * @LastEditTime: 2021-06-17 16:55:13
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;

// 回溯算法
void boardtrack(string str, vector<int> &track, string &tmp)
{
    if (tmp.size() == str.size())
    {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (!track[i])
        {
            // 先做选择，并做好标记，记录走过的位置
            tmp += str[i];
            track[i] = 1;

            // 递归调用
            boardtrack(str, track, tmp);

            // 回溯，将走过的位置抹除掉。然后tmp中去掉最后一个元素
            track[i] = 0;
            tmp = tmp.substr(0, tmp.length() - 1);
        }
    }
}

vector<string> Permutation(string str)
{
    string tmp;
    vector<int> track(str.size(), 0);
    boardtrack(str, track, tmp);

    // 对于"aa"这样的字符串做排列，会出现重复结果。所以要去掉
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    return res;
}

int main()
{
    // 测试用例
    // string s = "aaa";
    // vector<string> ans = Permutation(s);

    // 实际输入
    string s;
    cout << "input:"<<endl;
    cin >> s;
    
    vector<string> ans = Permutation(s);
    cout << "output:" << endl;
    for (string str : ans)
        cout << str << endl;
        
    return 0;
}
```



## 知识点5：分治

### **二叉搜索树与双向链表**

**解题思路：**

* 首先使用递归方法建立一棵二叉搜索树，然后采用中序遍历，因为中序遍历的结果就是从小到大的顺序；
* 建立两个指向树节点的指针，然后让两个指针指向中序遍历的第一个访问的结点；
* 之后，按照访问顺序，依次改变结点左右指针的指向即可。并移动last指针的位置。

**解题代码：**

```C++
/*
 * @Description: 二叉搜索树与双向链表。分治算法
 * @Author: Mr. Lee
 * @Date: 2021-06-17 17:10:57
 * @LastEditTime: 2021-06-18 17:48:15
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

// 手动建立二叉搜索树
TreeNode *insertion(TreeNode *root, int x)
{
    TreeNode *p = new TreeNode(x);

    if (root == nullptr)
    {
        root = p;
    }
    else if (x > root->val)
    {
        root->right = insertion(root->right, x);
    }
    else if (x < root->val)
    {
        root->left = insertion(root->left, x);
    }

    return root;
}

TreeNode *creatBinarySearchTree(vector<int> &ptr)
{
    // 此处的p是个根节点
    TreeNode *p = new TreeNode(ptr[0]);

    for (int i = 1; i < ptr.size(); i++)
    {
        // 每次插入都从根节点出发
        insertion(p, ptr[i]);
    }

    return p;
}

// 前序遍历打印二叉搜索树
void print(TreeNode *root)
{
    if (root != nullptr)
    {
        // 前序遍历
        cout << root->val << endl;

        if (root->left)
            print(root->left);
        if (root->right)
            print(root->right);
    }
    else if (root == nullptr)
    {
        return;
    }
}

// 改变二叉搜索树各节点的指向，使其成为一个双向链表
TreeNode *head = NULL;
TreeNode *last = NULL;

void BuildDequeue(TreeNode *node)
{
    if (node == NULL)
        return;

    // 中序遍历，访左->访中(处理)->访右
    BuildDequeue(node->left);
    if (head == nullptr)
    {
        head = node;
        last = node;
    }
    else
    {
        last->right = node;
        node->left = last;
        last = node;
    }
    BuildDequeue(node->right);
}

TreeNode *Convert(TreeNode *pRootOfTree)
{
    BuildDequeue(pRootOfTree);
    return head;
}

int main()
{
    // 测试用例
    // int arr[7] = {10, 6, 14, 4, 8, 12, 16};
    // TreeNode *p = creatBinarySearchTree( arr);
    // print(p);
    // TreeNode *h = Convert(p);

    int size, idx = 0;
    cin >> size;
    vector<int> nums(size);
    while (cin >> nums[idx++] && idx < size)
        ;
    TreeNode *p = creatBinarySearchTree(nums);
    print(p);
    TreeNode *h = Convert(p);

    for (auto tmp = h; tmp; tmp = tmp->right)
        cout << tmp->val << " ";

    return 0;
}
```



## 知识点6：模拟

### **扑克牌顺子**

**解题思路：**

* 先将五张牌排序，按照从小到大的顺序排列好
* 然后，计算不连续的牌之间的间隔，以及统计"0"牌的个数
* 比较"0"牌的个数和间隔的大小，判断"0"牌是否可以填充进去，以使得顺子连续
* 另外，如果发现有牌重复，那么一定无法构成顺子，直接返回false

**解题代码：**

```C++
/*
 * @Description: 扑克牌顺子。排序+判断
 * @Author: Mr. Lee
 * @Date: 2021-06-18 22:59:05
 * @LastEditTime: 2021-06-20 10:27:16
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous(vector<int> numbers)
{
    // 统计"0"牌的个数，以及记录不连续的牌之间的间隔
    int zeroofnum = 0, gap = 0;
    // 排序
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        if (!numbers[i])
        {
            // 统计"0"牌的个数
            zeroofnum++;
        }
        else
        {
            if (numbers[i] != numbers[i + 1])
            {
                // 统计牌与牌之间的间隔
                gap += (numbers[i + 1] - numbers[i] - 1);
            }
            else
            {
                // 如果有牌出现重复，那么一定无法构成顺子，直接返回false
                return false;
            }
        }
    }

    // 如果"0"牌的个数大于等于间隔，那么可以构成顺子
    return zeroofnum >= gap;
}

int main()
{
    // 测试用例
    // vector<int> numbers = {13, 12, 11, 0, 1};
    // bool ans = IsContinuous(numbers);
    // cout << boolalpha << ans << endl;

    // 手动输入
    vector<int> numbers(5);
    int idx = 0;
    while (cin >> numbers[idx++] && idx < 5)
        ;
    bool ans = IsContinuous(numbers);
    cout << boolalpha << ans << endl;

    return 0;
}
```



## **知识点7：穷举**

### **和为S的连续正数序列**

**解题思路：**

* 一次遍历所有数字，注意数字的范围是要小于等于【sum / 2 + 1】
* 每次均求和，并将求和结果和sum比较
* 如果求和结果大于sum，那么就从最小的数字开始剔除，直到求和结果小于等于sum
* 如果求和结果等于sum，则将连续的数字添加到临时结果数组中

**解题代码：**

```C++
/*
 * @Description: 和为S的连续正数序列
 * @Author: Mr. Lee
 * @Date: 2021-06-21 10:55:53
 * @LastEditTime: 2021-06-21 11:23:34
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> FindContinuousSequence(int sum)
{
    vector<vector<int>> res;
    vector<int> tmp;
    int tmpsum = 0;

    for (int i = 1; i <= sum / 2 + 1; i++)
    {
        tmpsum += i;
        tmp.push_back(i);

        while (tmpsum > sum)
        {
            auto it = tmp.begin();
            tmpsum -= *it;
            tmp.erase(it);
        }

        if (tmpsum == sum && tmp.size() > 1)
            res.push_back(tmp);
    }

    return res;
}

int main()
{
    // 测试用例
    // int sum = 10;

    int sum;
    cin >> sum;
    vector<vector<int>> ans = FindContinuousSequence(sum);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int num : ans[i])
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
```



## 知识点8：回溯

### 机器人的运动范围

**解题思路：**

* 经过分析，答案的可行解出现在 满足数位和的解构成的几何形状形如多个等腰直角三角形 ，每个三角形的直角顶点位于 0, 10, 20, ...0,10,20,... 等数位和突变的矩阵索引处 。[参考解答](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/solution/mian-shi-ti-13-ji-qi-ren-de-yun-dong-fan-wei-dfs-b/)
* 因此，机器人每次只可以向右或者向下走。可以使用递归遍历可行解的范围
* 递归的返回条件为：1.横坐标越界 2.纵坐标越界 3.横纵坐标的数位和大于阈值 4.该坐标位置已经走过
* 每次递归，是以当前[x,y]坐标出发的寻找可行解。所以需要+1

**解题代码：**

```C++
/*
 * @Description: 机器人的运动范围。
 * @Author: Mr. Lee
 * @Date: 2021-06-23 14:16:20
 * @LastEditTime: 2021-06-23 16:57:07
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int check(int x, int y)
{
    int sum = 0;
    while (x || y)
    {
        sum += (x % 10 + y % 10);
        x = (x / 10) ? x / 10 : 0;
        y = (y / 10) ? y / 10 : 0;
    }
    return sum;
}

int dfs(int x, int y, vector<vector<int>> &visited, int threshold, int rows, int cols)
{
    if (x >= rows || y >= cols || visited[x][y] || check(x, y) > threshold)
        return 0;

    visited[x][y] = 1;

    return 1 + dfs(x + 1, y, visited, threshold, rows, cols) // 向右走，递归
           + dfs(x, y + 1, visited, threshold, rows, cols);  // 向下走，递归
}

int movingCount(int threshold, int rows, int cols)
{
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    return dfs(0, 0, visited, threshold, rows, cols);
}

int main()
{
    int threshold = 17, rows = 2, cols = 3;
    int ans = movingCount(threshold, rows, cols);
    cout << ans << endl;

    return 0;
}
```



## 知识点9：数学

### 二进制中1的个数

**解题思路：**

* 一个数和1取与运算，可以判断该数的二进制位的最后一位是否为1，然后依次将数字右移一位，判断末位数
* 注意：如果n为负数，经过右移以后，最高位会补1
* 所以需要限制右移的次数，最高为32次

**解题代码：**

```C++
/*
 * @Description: 二进制中1的个数
 * @Author: Mr. Lee
 * @Date: 2021-06-23 17:22:39
 * @LastEditTime: 2021-06-23 17:44:30
 * @LastEditors: Mr. Lee
 */
#include <iostream>

using namespace std;

int NumberOf1(int n)
{
    int count = 0;

    // while (n)
    // {
    //     n = (n & (n - 1));
    //     count++;
    // }
    
    /*
        n >>= 1表示，如果n的二进制是110，则操作之后会变成011,也就是舍去最低位，然后最高位补0.
        但是如果n为负数，最高位会补1，所以对于负数还是有点问题。 
        需要加循环，限制一下位移的次数
    */
    for (int i = 0; i < 32; i++)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }

    return count;
}

int main()
{
    // 测试用例
    // int n = 10;

    int n;
    cin >> n;
    int ans = NumberOf1(n);
    cout << ans << endl;

    return 0;
}
```



### 数值的整数次方

**解题思路：**

* 常规思路，如果次幂为负数，则将幂底取倒数，次幂变为正数。
* 然后，循环将幂底乘次幂次。

**解题代码：**

```C++
/*
 * @Description: 数值的整数次方
 * @Author: Mr. Lee
 * @Date: 2021-06-23 17:48:45
 * @LastEditTime: 2021-06-23 17:56:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>

using namespace std;

double Power(double base, int exponent)
{
    if (exponent < 0)
        base = 1 / base;
    double res = 1.0;
    exponent = exponent > 0 ? exponent : -exponent;

    while (exponent--)
    {
        res *= base;
    }

    return res;
}

int main()
{
    // 测试用例
    // double base = 2;
    // int exponent = -2;
    // double ans = Power(base, exponent);
    // cout << ans << endl;

    double base;
    int exponent;
    cin >> base >> exponent;
    double ans = Power(base, exponent);
    cout << ans << endl;

    return 0;
}
```



### 丑数

**解题思路：**

* 丑数能够分解成2^x * 3^y * 5^z，所以只需要把得到的丑数不断地乘以2、3、5之后并放入他们应该放置的位置即可，而此题的难点就在于如何有序的放在合适的位置？
* 在2x，3y，5z中，如果x=y=z那么最小丑数一定是乘以2的；
* 但关键是有可能存在x>y>z的情况， 所以我们要维持三个指针来记录当前乘以2、乘以3、乘以5的最小值，然后当其被选为新的最小值后，要把相应的指针+1； 因为这个指针会逐渐遍历整个数组，因此最终数组中的每一个值都会被乘以2、乘以3、乘以5，也就是实现了最开始的想法， 只不过不是同时成乘以2、3、5，而是在需要的时候乘以2、3、5。

**解题代码：**

```C++
/*
 * @Description:  丑数
 * @Author: Mr. Lee
 * @Date: 2021-06-24 11:33:50
 * @LastEditTime: 2021-06-24 15:24:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 

*/

int Min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int GetUglyNumber_Solution(int index)
{
    if (index == 0)
        return 0;
    vector<int> uglynums(index);
    uglynums[0] = 1;

    auto uglynum2 = uglynums.begin();
    auto uglynum3 = uglynums.begin();
    auto uglynum5 = uglynums.begin();

    int nextnumidx = 1;

    while (index > nextnumidx)
    {
        uglynums[nextnumidx] = Min(*uglynum2 * 2, *uglynum3 * 3, *uglynum5 * 5);
        if (uglynums[nextnumidx] == *uglynum2 * 2)
            uglynum2++;
        if (uglynums[nextnumidx] == *uglynum3 * 3)
            uglynum3++;
        if (uglynums[nextnumidx] == *uglynum5 * 5)
            uglynum5++;

        nextnumidx++;
    }

    return uglynums[nextnumidx - 1];
}

int main()
{
    int index = 0;
    int ans = GetUglyNumber_Solution(index);
    cout << ans << endl;

    return 0;
}
```



### **孩子们的游戏(圆圈中最后剩下的数)**

**解题思路1：**

* 使用向量模拟运算；
* 每次删除第 m 个,从当前 idx 的基础上，加上m-1。注意，每次向量中有数据被剔除，向量的长度应该减1，这样才能正确找到下一个应该剔除的数字；
* 一直循环，直到向量的长度为1；
* 最后，返回向量中的那个元素，即为正确答案。

**解题代码1：**

```C++
/*
 * @Description: 剑指 Offer 62. 圆圈中最后剩下的数字。模拟法
 * @Author: Mr. Lee
 * @Date: 2021-06-24 15:35:32
 * @LastEditTime: 2021-06-26 15:46:54
 * @LastEditors: Mr. Lee
 */

/*
    按照题目要求，使用数组进行模拟
*/

#include <iostream>
#include <vector>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if (n <= 0)
        return -1;

    vector<int> num(n);
    int idx = 0;
    for (int i = 0; i < n; num[i] = i, i++)
        ;

    while (num.size() > 1)
    {
        //每次删除第 m 个,从当前 idx 的基础上，加上m-1
        idx = (idx + m - 1) % n;
        num.erase(num.begin() + idx);
        n--;
    }

    return num.front();
}

int main()
{
    // 测试用例
    // int n = 5;
    // int m = 3;

    int n;
    int m;
    cin >> n >> m;
    int ans = LastRemaining_Solution(n, m);
    cout << ans << endl;

    return 0;
}
```



**解题思路2：**

* 采用数学归纳法进行推导递推表达式；
* 当我们知道了 f(n - 1, m) 对应的答案 x 之后，我们也就可以知道，长度为 n 的序列最后一个删除的元素，应当是从 m % n 开始数的第 x 个元素。因此有 f(n, m) = (m % n + x) % n = (m + x) % n。所以，递推表达式为： f(n, m) = (f(n - 1, m)  + x) % n；
* 初始值：当n等于1时，f(1,m) = 0；
* 循环求解。

**解题代码2：**

```C++
/*
 * @Description: 剑指 Offer 62. 圆圈中最后剩下的数字。动态规划法
 * @Author: Mr. Lee
 * @Date: 2021-06-24 15:35:32
 * @LastEditTime: 2021-06-26 15:06:21
 * @LastEditors: Mr. Lee
 */

/*
    数学推导递推公式，然后使用动态规划的思路求解
*/

#include <iostream>
#include <vector>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if (n <= 0)
        return -1;

    int f = 0;
    // 知道了f(n-1)最后要删除的数字，那么就可以通过递推表达式计算f(n)的结果
    for (int i = 2; i != n + 1; ++i)
    {
        f = (m + f) % i;
    }
    return f;
}

int main()
{
    // 测试用例
    // int n = 5;
    // int m = 3;

    int n;
    int m;
    cin >> n >> m;
    int ans = LastRemaining_Solution(n, m);
    cout << ans << endl;

    return 0;
}
```



### **求1+2+3+...+n**

**描述：**

* 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

**解题思路：**

* 利用逻辑与&&符号替代if终止递归，达到目的

**解题代码1：**

```C++
/*
 * @Description: 求1+2+3+...+n。先使用递归，改进递归机制
 * @Author: Mr. Lee
 * @Date: 2021-06-26 10:19:24
 * @LastEditTime: 2021-06-26 10:40:58
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

// 利用短路运算符终止递归，以替代递归中的if条件判断
using namespace std;

int res = 0;

int Sum_Solution(int n)
{
    bool x = n > 1 && Sum_Solution(n - 1);
    res += n;
    return res;
}

int main()
{
    // 测试用例
    // int n = 10;

    //
    int n;
    cin >> n;
    int ans = Sum_Solution(n);
    cout << ans << endl;

    return 0;
}
```



**解题代码2：**

```C++
/*
 * @Description: 求1+2+3+...+n。先使用递归，改进递归机制
 * @Author: Mr. Lee
 * @Date: 2021-06-26 10:19:24
 * @LastEditTime: 2021-06-26 10:41:07
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

// 利用短路运算符终止递归，以替代递归中的if条件判断
using namespace std;

int Sum_Solution(int n)
{
    bool x = n > 1 && (n += Sum_Solution(n - 1));
    return n;
}

int main()
{
    // 测试用例
    // int n = 10;

    //
    int n;
    cin >> n;
    int ans = Sum_Solution(n);
    cout << ans << endl;

    return 0;
}
```



### **不用加减乘除做加法**

**解题思路：**

* 不能使用加减乘除，就要考虑使用位运算；
* 异或运算【^】，表示不进位加法，比如 0101 ^ 0001 = 0100；与运算【&】，结合左移运算符可以获取进位，例如0101 & 0001 = 0001，0001 << 1 = 0010，其中，经过左移运算符之后，第三位的1正是所需要的进位；
* 循环运算，知道没有产生进位，结束循环；
* 返回运算结果。

**解题代码：**

```C++
/*
 * @Description: 不用加减乘除做加法
 * @Author: Mr. Lee
 * @Date: 2021-06-27 00:02:01
 * @LastEditTime: 2021-06-27 00:27:19
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int Add(int num1, int num2)
{
    int sum = 0;
    
    // 一直循环，直到进位为0
    while (num2)
    {
        int c = ((unsigned int)(num1 & num2)) << 1; // 进位
        num1 ^= num2;                               // 异或是不进位加法
        num2 = c;
    }

    return num1;
}

int main()
{
    // 测试用例
    // int num1 = 1, num2 = 2;

    int num1, num2;
    cin >> num1 >> num2;
    int ans = Add(num1, num2);
    cout << ans << endl;

    return 0;
}
```



###

**解题思路：**

* 首先，考虑字符串的长度小于2的情况，排除一位符号或者空字符串的形式。例如，将""、"+"、"-"、"#"、"a"等形式的字符串排除；
* 第二步，考虑字符串的长度小于2的情况。如果字符串首位是"0"，直接返回0；如果字符串首位是"+"或"-"，那么必须保证第二位是1-9的数字，其他情况直接返回0；这样，将"0123..."、"+0"、"-0"、"+#"、"+a"等形式的字符串排除
* 第三步，对字符串进行求和。如果字符串中出现非数字的符号，直接返回0；
* 最后，返回正确的求和结果。

**解题代码：**

```C++
/*
 * @Description: 把字符串转换成整数
 * @Author: Mr. Lee
 * @Date: 2021-06-27 20:09:32
 * @LastEditTime: 2021-06-27 21:58:17
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int StrToInt(string str)
{
    // 考虑字符串的长度小于2的情况，排除一位符号或者空字符串的形式
    if (str.size() < 2)
    {
        if (str.size() == 0)
            return 0;
        else
        {
            int num = (str[0] - '0');
            return (num < 10 && num > -1) ? num : 0;
        }
    }

    // 考虑字符串的长度大于等于2的情况
    int sym = 1, start = 0;
    long digit = 1, res = 0;
    if (str[0] == '0')
    {
        return 0;
    }
    else if (str[0] == '-')
    {
        sym = -1;
        start++;
    }
    else if (str[0] == '+')
    {
        start++;
    }

    // 排除+a/+0等非法数字
    if (start == 1)
    {
        int num = (str[1] - '0');
        if (num >= 10 || num == 0)
        {
            return 0;
        }
    }

    for (int i = start; i < str.size(); i++)
    {
        int num = (str[i] - '0');
        if (num >= 10)
        {
            return 0;
        }
        res = res * 10 + num;
    }

    res *= sym;

    return res;
}

int main()
{
    // 测试用例
    // string str = "+2147483647";

    string str;
    cin >> str;
    int ans = StrToInt(str);
    cout << ans << endl;

    return 0;
}
```



### 剪绳子

**解题思路：**

* 由均值不等式可以知道，和为定值，积有最大值；
* 也就是说，想要把剪成m段，那么这m段中的绳子越接平均值，乘积就越大；
* 对m遍历，求出最大结果即可。

**解题代码：**

```C++
/*
 * @Description: 剪绳子
 * @Author: Mr. Lee
 * @Date: 2021-06-27 21:55:23
 * @LastEditTime: 2021-06-27 22:17:33
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

int getMaxVal(int number, int m)
{
    int maxVal = 1;
    for (int i = m; i > 0; i--)
    {
        int avg = number / i;
        maxVal *= avg;
        number -= avg;
    }

    return maxVal;
}

int cutRope(int number)
{
    int res = -1;
    for (int m = 2; m <= number; m++)
    {
        res = max(res, getMaxVal(number, m));
    }

    return res;
}

int main()
{
    // 测试用例
    // int number = 8;

    int number;
    cin >> number;
    int ans = cutRope(number);
    cout << ans << endl;

    return 0;
}
```



## 知识点10：dfs

## 知识点11：双指针

### 和为S的两个数字

**解题思路：**

* 使用两个指针i,j，分别指向数组的第一个元素和最后一个元素；
* 每次循环，循环的条件是i<j，都计算两个指针指向的元素值相加和；
* 由于数组是从小到大排序的。如果两个指针指向的元素值相加和大于目标值，则j--；如果两个指针指向的元素值相加和小于目标值，则i++；如果是等于，则直接返回两个指针指向的元素；
* 如果没有找到，那么返回空数组。

**解题代码：**

```C++
/*
 * @Description: 和为S的两个数字。双指针法
 * @Author: Mr. Lee
 * @Date: 2021-06-28 22:52:49
 * @LastEditTime: 2021-06-28 23:06:37
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    int i = 0, j = array.size() - 1;
    while (i < j)
    {
        int tmp = array[i] + array[j];
        if (tmp > sum)
            j--;
        else if (tmp < sum)
            i++;
        else
            return {array[i], array[j]};
    }

    return {};
}

int main()
{
    // 测试代码
    // vector<int> array = {1, 2, 4, 7, 11, 15};
    // int num = 15;

    //
    int n, num;
    cin >> n >> num;
    vector<int> array(n);
    int idx = 0;
    while (idx < n && cin >> array[idx++])
        ;

    vector<int> ans = FindNumbersWithSum(array, num);
    if (ans.size() > 0)
        cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
```



### 滑动窗口的最大值

**解题思路：**

* 使用单调栈；
* 对于数组中的每一个元素，如果元素的下标小于窗口宽度-1，那么就将其加入到栈中，同时维护好栈。有一个元素想要入栈，那么必须要大于等于栈顶元素，如果栈顶元素小于该元素，就让栈顶元素出栈，直到遇到栈中的一个元素大于该元素；
* 如果栈空或者该元素大于等于栈顶元素，那么就让该元素入栈，这样保证栈顶的元素是最大的；
* 另外，如果栈顶元素等于滑动窗口最左边的元素值，那么在下一个元素值进栈之前应将其删除掉。同时，要维护好栈；
* 每经过一个滑动，栈顶元素就是此窗口中的最大值，将栈顶元素加入到结果数组中；
* 直至遍历完数组中所有的元素。返回结果数组。

**解题代码：**

```C++
/*
 * @Description: 滑动窗口的最大值。采用单调栈
 * @Author: Mr. Lee
 * @Date: 2021-06-28 23:07:35
 * @LastEditTime: 2021-06-29 14:55:14
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void pushstack(stack<int> &win, int num)
{
    while ((!win.empty()) && (num > win.top()))
    {
        win.pop();
    }

    if (win.empty() || num >= win.top())
        win.push(num);
}

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (size > num.size())
        return {};

    stack<int> win;
    vector<int> res;
    int i = 0;

    while (i < num.size())
    {
        if (i < size - 1)
        {
            pushstack(win, num[i]);
        }
        else
        {
            pushstack(win, num[i]);
            res.push_back(win.top());
            int winleft = i - size + 1;
            if (num[winleft] == win.top())
            {
                win.pop();
                for (int m = winleft + 1; m <= i; pushstack(win, num[m]), m++)
                    ;
            }
        }

        i++;
    }

    return res;
}

int main()
{
    // 测试用例
    // vector<int> num = {2,3,4,2,6,2,5,1};
    // unsigned int size = 3;

    //
    int n, idx = 0;
    unsigned int size;
    cin >> n >> size;
    vector<int> num(n);
    while (idx < n && cin >> num[idx++])
        ;
    vector<int> ans = maxInWindows(num, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
```



## 知识点12：二分

### 数字在升序数组中出现的次数

**解题思路：**

* 常规思路，遍历完整个数组，如果数组中的数字等于目标值，计数器加一；
* 返回计数器的结果即可。

**解题代码：**

```C++
/*
 * @Description: 数字在升序数组中出现的次数。常规思路，遍历
 * @Author: Mr. Lee
 * @Date: 2021-06-29 22:10:56
 * @LastEditTime: 2021-06-29 22:25:51
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int GetNumberOfK(vector<int> data, int k)
{
    int count = 0;
    for (int num : data)
    {
        if (num == k)
            count++;
    }

    return count;
}

int main()
{
    // 测试用例
    // vector<int> data = {1, 2, 3, 3, 3, 3, 4, 5};
    // int k = 3;

    int idx = 0, n, k;
    cin >> n >> k;
    vector<int> data(n);
    while (idx < n && cin >> data[idx++])
        ;
    int ans = GetNumberOfK(data, k);
    cout << ans << endl;

    return 0;
}
```



**解题思路2：**

* 由于数组是单调增加的，所以利用二分法，分别找到目标值的在数组中的左右边界；
* 利用左右二分之差，计算目标值出现的次数。

**解题代码2：**

```C++
/*
 * @Description: 数字在升序数组中出现的次数。使用二分查找左右边界
 * @Author: Mr. Lee
 * @Date: 2021-06-29 22:10:56
 * @LastEditTime: 2021-06-29 22:25:22
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int leftbound(vector<int> data, int target)
{
    int i = 0, j = data.size();
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (data[mid] < target)
            i = mid + 1;
        else
            j = mid;
    }
    return i;
}

int rightbound(vector<int> data, int target)
{
    int i = 0, j = data.size();
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (data[mid] > target)
            j = mid;
        else
            i = mid + 1;
    }
    return i - 1;
}

int GetNumberOfK(vector<int> data, int k)
{
    return rightbound(data, k) - leftbound(data, k) + 1;
}

int main()
{
    // 测试用例
    // vector<int> data = {1, 2, 3, 3, 3, 3, 4, 5};
    // int k = 3;

    int idx = 0, n, k;
    cin >> n >> k;
    vector<int> data(n);
    while (idx < n && cin >> data[idx++])
        ;
    int ans = GetNumberOfK(data, k);
    cout << ans << endl;

    return 0;
}
```



### 旋转数组的最小数字

**解题思路1：**

* 遍历完整个数据，将数组中的最小值找出来即可

**解题代码1：**

```C++
/*
 * @Description: 旋转数组的最小数字。直接查找最小的值即可
 * @Author: Mr. Lee
 * @Date: 2021-06-29 21:53:20
 * @LastEditTime: 2021-06-29 22:09:13
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
    if (rotateArray.size() == 0)
    {
        return 0;
    }

    int res = INT_MAX;
    for (int i = 0; i < rotateArray.size(); i++)
    {
        res = min(res, rotateArray[i]);
    }

    return res;
}

int main()
{
    vector<int> rotateArray = {3, 4, 5, 1, 2};
    int ans = minNumberInRotateArray(rotateArray);
    cout << ans << endl;

    return 0;
}
```



**解题思路2：**

**解题代码2：**



## 知识点13：位运算

### 数组中只出现一次的两个数字

**解题思路1：**

* 常规思路，使用一个hashmap来保存数组中每个数字出现的次数；
* 然后，将出现次数为一的数字放到结果数组中；
* 返回结果数组。

**解题代码1：**

```c++
/*
 * @Description: 数组中只出现一次的两个数字。使用哈希表
 * @Author: Mr. Lee
 * @Date: 2021-06-29 23:06:37
 * @LastEditTime: 2021-06-29 23:17:44
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int> &array)
{
    vector<int> res;
    map<int, int> m;
    for (int i = 0; i < array.size(); i++)
    {
        m[array[i]] += 1;
    }

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second == 1)
            res.push_back((*it).first);
    }
    return res;
}

int main()
{
    // 测试用例
    // vector<int> array = {1, 4, 1, 6};
    
    int n, idx = 0;
    cin >> n;
    vector<int> array(n);
    while (idx < n && cin >> array[idx++])
        ;
    vector<int> ans = FindNumsAppearOnce(array);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
```



**解题思路2：**

* 利用位运算，首先遍历一次数组，将所有数字进行异或操作。那么执行该操作的结果就是不重复元素异或的结果。比如，数组中的数字为 1 1 2 2  4 6 ，那么数组中所有数字异或的结果就是1^1^2^2^4^6 = 4^6 = 2(二进制为010)；
* 然后，根据异或结果二进制中第一个1来划分数组中的数字。也就是说，1^1^2^2^4^6 = 4^6 = 2(二进制为010)，从右往左数第二位是1，依据第二位1来将数据划分成两派，【1，1，4】是一派，【2，2，6】是一派。将这两派中的数字分别异或运算，就可以得到最终的结果，【4，6】。
* 原理：为什么要利用异或结果中第一个不为0的位数作为划分依据呢？因为，所有重复的数字，无论在该为是0还是1，只要是成双成对的，经过异或运算以后，在该位的数字都会变成0。唯独不重复的两个数字，异或以后，结果二进制中该位的数字会是1。所以使用原数组所有数字异或的结果二进制中从右往左第一个不为0的位数作为划分依据。

**解题代码2：**

```C++
/*
 * @Description: 数组中只出现一次的两个数字。使用位运算
 * @Author: Mr. Lee
 * @Date: 2021-06-29 23:06:37
 * @LastEditTime: 2021-06-29 23:56:54
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> FindNumsAppearOnce(vector<int> &array)
{
    int res = 0, m = 1;
    int res1 = 0, res2 = 0;
    for (int num : array)
    {
        res ^= num;
    }

    while ((m & res) == 0)
        m <<= 1;

    for (int num : array)
    {
        cout << num << endl;
        if (num & m)
            res1 ^= num;
        else
            res2 ^= num;
    }

    if (res1 > res2)
    {
        swap(res1, res2);
    }

    return {res1, res2};
}

int main()
{
    // 测试用例
    vector<int> array = {1, 4, 1, 6};

    // int n, idx = 0;
    // cin >> n;
    // vector<int> array(n);
    // while (idx < n && cin >> array[idx++])
    //     ;
    vector<int> ans = FindNumsAppearOnce(array);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
```



## 知识点14：bfs

## 知识点15：数组

### 调整数组顺序使奇数位于偶数前面

**解题思路：**

* 常规思路，建立两个数组，一个用来存放奇数，一个用来存放偶数；
* 遍历整个数组，把所有的奇数按顺序存入到奇数数组中，把所有的偶数按顺序存入到偶数数组中；
* 然后，拼接两个数组。奇数数组在前，偶数数组在后；
* 返回拼接后的数组。

**解题代码：**

```C++
/*
 * @Description: 调整数组顺序使奇数位于偶数前面
 * @Author: Mr. Lee
 * @Date: 2021-06-30 16:23:52
 * @LastEditTime: 2021-06-30 16:36:23
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> reOrderArray(vector<int> &array)
{
    vector<int> odd, even;
    for (int num : array)
    {
        if (num & 1)
            odd.push_back(num);
        else
            even.push_back(num);
    }

    odd.insert(odd.end(), even.begin(), even.end());
    
    return odd;
}

int main()
{
    vector<int> array = {1, 2, 3, 4};
    vector<int> ans = reOrderArray(array);
    for (int num : ans)
    {
        cout << num << " " << endl;
    }

    return 0;
}
```



### 二维数组中的查找

**解题思路：**

* 常规思路，在数组中每一行都进行查找；
* 因为每一行的数字都是排好序的，所以如果在第一行没有查到，自某个元素大于目标值以后，就不再往后查找，则跳到第二行进行查找；
* 直到找到了与目标值相等的元素，返回true；
* 没找到就返回false。

**解题代码：**

```C++
/*
 * @Description: 二维数组中的查找
 * @Author: Mr. Lee
 * @Date: 2021-06-30 00:02:06
 * @LastEditTime: 2021-06-30 00:07:23
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int>> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[0].size(); j++)
        {
            if (array[i][j] > target)
                continue;
            else if (array[i][j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> array = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}};
    int target = 7;
    bool ans = Find(target, array);
    cout << boolalpha << ans << endl;

    return 0;
}
```



## 知识点16：字符串

### 替换空格

**解题思路：**

* 遍历一次字符串，遇到空格就用"%20"代替。

**解题代码：**

```C++
/*
 * @Description: 替换空格
 * @Author: Mr. Lee
 * @Date: 2021-06-30 11:14:26
 * @LastEditTime: 2021-06-30 11:44:57
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string replaceSpace(string s)
{
    string res;
    for (int k = 0; k < s.size(); k++)
    {
        if (s[k] == ' ')
            res += "%20";
        else
            res += s[k];
    }

    return res;
}

int main()
{
    // 测试用例
    // string str = "  hello   world    ";

    //
    string str;
    getline(cin, str);
    string res = replaceSpace(str);
    cout << res << endl;

    return 0;
}





/*
 * @Description: 替换空格。包含去掉首尾空格
 * @Author: Mr. Lee
 * @Date: 2021-06-30 11:14:26
 * @LastEditTime: 2021-06-30 11:44:05
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string replaceSpace(string s)
{
    // 去掉首尾空格

    int i, j;

    // 去掉首空格
    for (i = 0; (i < s.size()) && (s[i] == ' '); i++)
        ;
    // 去掉尾空格
    for (j = s.size() - 1; (j >= 0) && (s[j] == ' '); j--)
        ;

    string res;
    for (int k = i; k < j + 1; k++)
    {
        if (s[k] == ' ')
            res += "%20";
        else
            res += s[k];
    }

    return res;
}

int main()
{
    // 测试用例
    // string str = "  hello   world    ";

    // 
    string str;
    getline(cin,str);
    string res = replaceSpace(str);
    cout << res << endl;

    return 0;
}
```



### **字符串的排列**

**解题思路：**

**解题代码：**

```C++
/*
 * @Description: 字符串的排列
 * @Author: Mr. Lee
 * @Date: 2021-07-02 19:36:53
 * @LastEditTime: 2021-07-02 19:42:55
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> res;

// 回溯算法
void boardtrack(string str, vector<int> &track, string &tmp)
{
    if (tmp.size() == str.size())
    {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (!track[i])
        {
            // 先做选择，并做好标记，记录走过的位置
            tmp += str[i];
            track[i] = 1;

            // 递归调用
            boardtrack(str, track, tmp);

            // 回溯，将走过的位置抹除掉。然后tmp中去掉最后一个元素
            track[i] = 0;
            tmp = tmp.substr(0, tmp.length() - 1);
        }
    }
}

vector<string> Permutation(string str)
{
    string tmp;
    vector<int> track(str.size(), 0);
    boardtrack(str, track, tmp);

    // 对于"aa"这样的字符串做排列，会出现重复结果。所以要去掉
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main()
{
    string str = "abc";
    vector<string> ans = Permutation(str);
    for (string s : ans)
    {
        cout << s << endl;
    }
    
    return 0;
}
```



### **第一个只出现一次的字符**

**解题思路：**

**解题代码：**

```C++
/*
 * @Description: 第一个只出现一次的字符
 * @Author: Mr. Lee
 * @Date: 2021-07-02 16:06:13
 * @LastEditTime: 2021-07-02 19:21:38
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int FirstNotRepeatingChar(string str)
{
    int idx = 0;
    vector<int> dict(128, 0);
    for (char c : str)
    {
        dict[c] += 1;
    }

    for (char c : str)
    {
        if (dict[c] == 1)
            return idx;
        idx++;
    }
    
    return -1;
}

int main()
{
    string str = "google";
    int ans = FirstNotRepeatingChar(str);
    cout << ans << endl;

    return 0;
}
```



### **左旋转字符串**

**解题思路：**

**解题代码：**

```C++
/*
 * @Description: 左旋转字符串
 * @Author: Mr. Lee
 * @Date: 2021-07-02 16:47:14
 * @LastEditTime: 2021-07-02 16:54:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

string LeftRotateString(string str, int n)
{
    string a, b;
    for (int i = 0; i < str.size(); i++)
    {
        if (i < n)
            a += str[i];
        else
            b += str[i];
    }

    return (b + a);
}

int main()
{
    string str = "abcXYZdef";
    int n = 3;
    string ans = LeftRotateString(str, n);
    cout << ans << endl;

    return 0;
}
```



### **翻转单词序列**

**解题思路：**

**解题代码：**

```C++
/*
 * @Description: 翻转单词序列
 * @Author: Mr. Lee
 * @Date: 2021-07-02 16:56:44
 * @LastEditTime: 2021-07-02 17:29:34
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

string ReverseSentence(string str)
{
    str += " ";
    string res, tmp;
    for (int i = 0; i < str.size(); i++)
    {
        tmp += str[i];

        if (str[i] == ' ')
        {
            res = tmp + res;
            tmp.clear();
        }
    }

    res = res.substr(0, res.size() - 1);

    return res;
}

int main()
{
    string str = "nowcoder. a am I";
    string ans = ReverseSentence(str);
    cout << ans << endl;

    return 0;
}
```



### **把字符串转换成整数**

**解题思路：**

**解题代码：**

```C++
/*
 * @Description: 把字符串转换成整数
 * @Author: Mr. Lee
 * @Date: 2021-06-27 20:09:32
 * @LastEditTime: 2021-06-27 21:58:17
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

int StrToInt(string str)
{
    // 考虑字符串的长度小于2的情况，排除一位符号或者空字符串的形式
    if (str.size() < 2)
    {
        if (str.size() == 0)
            return 0;
        else
        {
            int num = (str[0] - '0');
            return (num < 10 && num > -1) ? num : 0;
        }
    }

    // 考虑字符串的长度大于等于2的情况
    int sym = 1, start = 0;
    long digit = 1, res = 0;
    if (str[0] == '0')
    {
        return 0;
    }
    else if (str[0] == '-')
    {
        sym = -1;
        start++;
    }
    else if (str[0] == '+')
    {
        start++;
    }

    // 排除+a/+0等非法数字
    if (start == 1)
    {
        int num = (str[1] - '0');
        if (num >= 10 || num == 0)
        {
            return 0;
        }
    }

    for (int i = start; i < str.size(); i++)
    {
        int num = (str[i] - '0');
        if (num >= 10)
        {
            return 0;
        }
        res = res * 10 + num;
    }

    res *= sym;

    return res;
}

int main()
{
    // 测试用例
    // string str = "+2147483647";

    string str;
    cin >> str;
    int ans = StrToInt(str);
    cout << ans << endl;

    return 0;
}
```



### **字符流中第一个不重复的字符**

**解题思路：**

**解题代码：**

```C++
/*
 * @Description: 字符流中第一个不重复的字符
 * @Author: Mr. Lee
 * @Date: 2021-07-02 19:25:20
 * @LastEditTime: 2021-07-02 19:34:00
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char getFirstAppearingOnce(string str)
    {
        vector<int> dict(256, 0);
        for (auto &c : str)
        {
            dict[c] += 1;
        }

        for (auto &c : str)
        {
            if (dict[c] == 1)
                return c;
        }
        return '#';
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        return getFirstAppearingOnce(s);
    }

private:
    string s;
};

int main()
{
    Solution sol;
    sol.Insert('g');
    cout << sol.FirstAppearingOnce();
    sol.Insert('o');
    cout << sol.FirstAppearingOnce();
    sol.Insert('o');
    cout << sol.FirstAppearingOnce();
    sol.Insert('g');
    cout << sol.FirstAppearingOnce();
    sol.Insert('l');
    cout << sol.FirstAppearingOnce();
    sol.Insert('e');
    cout << sol.FirstAppearingOnce();

    return 0;
}
```

