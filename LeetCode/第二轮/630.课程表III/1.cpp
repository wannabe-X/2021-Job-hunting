/*
 * @Description: 630.课程表III
 * @Author: Mr. Lee
 * @Date: 2021-12-14 00:15:08
 * @LastEditTime: 2021-12-14 00:52:53
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int scheduleCourse(vector<vector<int>> &courses)
{
    sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int total = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    for (vector<int> course : courses)
    {
        if (total + course[0] <= course[1])
        {
            total += course[0];
            pq.push(course[0]);
        }
        else if (!pq.empty() && pq.top() > course[0])
        {
            total += -pq.top() + course[0];
            pq.pop();
            pq.push(course[0]);
        }
    }

    return pq.size();
}

int main(int argc, char *argv[])
{
    return 0;
}