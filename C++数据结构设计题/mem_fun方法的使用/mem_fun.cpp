/*
 * @Description: mem_fun() 方法的使用
 * @Author: Mr. Lee
 * @Date: 2021-12-10 16:01:56
 * @LastEditTime: 2021-12-10 16:05:12
 * @LastEditors: Mr. Lee
 */
#include <vector>
#include <iostream>
#include <algorithm>

class Employee
{
public:
    int DoSomething()
    {
        std::cout << "do something" << std::endl;
        return 0;
    }
};

int GiveDoSomething(Employee &e)
{
    return e.DoSomething();
}

int main()
{
    Employee *employee = new Employee();

    std::vector<Employee *> emps;
    emps.push_back(employee);

    // std::for_each(emps.begin(), emps.end(), &GiveDoSomething);
    std::for_each(emps.begin(), emps.end(), std::mem_fun(&Employee::DoSomething));

    return 0;
}
