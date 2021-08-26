/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-07-31 10:09:18
 * @LastEditTime: 2021-07-31 10:09:39
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <tr1/memory>
#include <typeinfo>
#include <vector>
using namespace std;

template <typename T>
struct smart_ptr_checker
{
    enum
    {
        value = false
    };
    typedef long type;
};

template <template <typename> class P, typename T>
struct smart_ptr_checker<P<T>>
{
    enum
    {
        value = true
    };
    template <typename C>
    static bool test(typeof(&C::operator->));
    template <typename C>
    static long test(...);
    typedef typeof(test<P<T>>(0)) type;
};

int main()
{
    cout << typeid(smart_ptr_checker<int>::type).name() << endl;                  // long
    cout << typeid(smart_ptr_checker<tr1::shared_ptr<int>>::type).name() << endl; // bool
    cout << typeid(smart_ptr_checker<vector<int>>::type).name() << endl;          // long
    return 0;
}
