/*
 * @Description:剑指 Offer 41. 数据流中的中位数
 * @Author: Mr. Lee
 * @Date: 2021-06-10 15:40:39
 * @LastEditTime: 2021-06-21 11:36:58
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
