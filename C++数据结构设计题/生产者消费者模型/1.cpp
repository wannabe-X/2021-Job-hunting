/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 11:36:07
 * @LastEditTime: 2021-12-13 15:20:31
 * @LastEditors: Mr. Lee
 */
#include <bits/stdc++.h>
#include <windows.h>
#include <iostream>

using namespace std;

mutex mtx;
condition_variable cv_producer, cv_consumer;
queue<int> resource;
const int max_size = 20;

// 消费者
void constuomer()
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        while (resource.size() == 0)
        {
            cv_consumer.wait(lock);
        }

        int cur_resource = resource.front();
        cout << "consumer:" << this_thread::get_id() << " consume resource:" << cur_resource << endl;
        resource.pop();
        cv_producer.notify_all();
        Sleep(1000);
    }
}

// 生产者
void producer()
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        while (resource.size() == max_size)
        {
            cv_producer.wait(lock);
        }

        int cur_resource = rand() % 100;
        resource.push(cur_resource);
        cout << "producer:" << this_thread::get_id() << " produce resource:" << cur_resource << endl;
        cv_consumer.notify_all();
        Sleep(100);
    }
}

int main()
{
    vector<thread> consumers(5), producers(5);
    for (int i = 0; i < 5; i++)
    {
        consumers[i] = thread(constuomer);
        producers[i] = thread(producer);
    }

    for (int i = 0; i < 5; i++)
    {
        consumers[i].join();
        producers[i].join();
    }

    return 0;
}