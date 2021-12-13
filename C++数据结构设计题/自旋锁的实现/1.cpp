/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 18:13:40
 * @LastEditTime: 2021-12-13 18:17:25
 * @LastEditors: Mr. Lee
 */
#include <atomic>
using namespace std;

class spin_lock
{
private:
    atomic<bool> flag{false}; // false不加锁、true加锁
public:
    spin_lock() = default;                 // 使用默认的构造函数
    spin_lock(const spin_lock &) = delete; // 禁止使用拷贝构造函数
    spin_lock &operator=(const spin_lock &) = delete; // 禁止使用赋值构造
    void lock()
    {
        bool expected = false;
        while (!flag.compare_exchange_strong(expected, true))
            expected = false;
    }
    void unlock()
    {
        flag.store(false);
    }
};