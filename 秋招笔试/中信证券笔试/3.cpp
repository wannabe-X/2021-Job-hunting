/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-09-12 18:55:06
 * @LastEditTime: 2021-09-13 10:32:01
 * @LastEditors: Mr. Lee
 */

#include <iostream>
using namespace std;

class Point
{
public:
    int x, y;
    explicit Point(int x = 0, int y = 0)
        : x(x), y(y) {}
};

void displayPoint(const Point &p)
{
    cout << "(" << p.x << ","
         << p.y << ")" << endl;
}

int main()
{
    displayPoint(Point(1));
    Point p(1);
}