/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-16 17:13:26
 * @LastEditTime: 2021-12-18 11:46:45
 * @LastEditors: Mr. Lee
 */
#include <functional>
#include <future>
#include <vector>
#include <mutex>
#include <queue>
#include <thread>
#include <utility> //move forward pair等等
#include "thread_safe_queue.hpp"

using namespace std;

class threadpool
{
private:
    class thread_worker
    {
    private:
        int m_id;
        threadpool *m_pool;

    public:
        thread_worker(threadpool *pool, const int id)
            : m_pool(pool), m_id(id)
        {
        }

        void operator()()
        {
            function<void()> func;
            bool deququed;
            while (!m_pool->m_shutdown)
            {
                unique_lock<mutex> ul(m_pool->m_mtx);
                if (m_pool->m_queue.is_empty())
                {
                    m_pool->m_cv.wait(ul);
                }
                m_pool->m_queue.push(func);
                func();
            }
        }
    };

    bool m_shutdown;
    thread_safe_queue<function<void()>> m_queue;
    vector<thread> m_threads;
    mutex m_mtx;
    condition_variable m_cv;

public:
    threadpool(const int thread_num) : m_threads(vector<thread>(thread_num)), m_shutdown(false) {}
    threadpool(const threadpool &) = delete;
    threadpool(threadpool &&) = delete;
    threadpool &operator=(const threadpool &) = delete;
    threadpool &operator=(threadpool &&) = delete;

    // init
    void init()
    {
        for (int i = 0; i < m_threads.size(); i++)
            m_threads[i] = thread(&thread_worker(this, i));
    }

    void shutdown()
    {
        m_shutdown = true;
        m_cv.notify_all();
        for (int i = 0; i < m_threads.size(); i++)
        {
            if (m_threads[i].joinable())
                m_threads[i].join();
        }
    }

    template <typename T, typename... Args>
    auto submit(T &&t, Args &&...args) -> future<decltype(t(args...))>
    {
        function<decltype(t(args...))()> func = bind(forward<T>(t), forward<Args...>(args)...);
        auto task_ptr = make_shared<packaged_task<decltype(f(args...))()>>(func);
        function<void()> wrapper_func = [task_ptr]()
        {
            (*task_ptr);
        };

        m_queue.push(wrapper_func);
        m_cv.notify_one();
        return task_ptr->get_future();
    }
};
