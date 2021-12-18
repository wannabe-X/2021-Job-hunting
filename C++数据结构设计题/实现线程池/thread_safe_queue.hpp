/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-16 17:14:19
 * @LastEditTime: 2021-12-18 11:15:02
 * @LastEditors: Mr. Lee
 */
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

template <typename T>
class thread_safe_queue
{
public:
    thread_safe_queue(){};
    ~thread_safe_queue(){};

    void push(T temp)
    {
        unique_lock<mutex> ul(m_mtx);
        m_queue.push(move(temp));
        cout << "push!" << endl;
        m_not_empty_cv.notify_one();
    }

    void wait_and_pop()
    {
        unique_lock<mutex> ul(m_mtx);
        m_not_empty_cv.wait(ul, [this](){ cout << "waiting until not empty" << endl; return !this->m_queue.empty(); });
        m_queue.pop();
        cout << "pop!" << endl;
    }

    bool try_pop()
    {
        unique_lock<mutex> ul(m_mtx);
        if (m_queue.empty())
            return false;
        m_queue.pop();
        return true;
    }

    bool is_empty()
    {
        unique_lock<mutex> ul(m_mtx);
        return m_queue.empty();
    }

private:
    queue<T> m_queue;
    mutex m_mtx;
    condition_variable m_not_empty_cv;
};