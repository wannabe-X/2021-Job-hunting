/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-12-13 11:36:07
 * @LastEditTime: 2021-12-13 11:36:07
 * @LastEditors: Mr. Lee
 */
#include <bits/stdc++.h>
using namespace std;

mutex mtx;
condition_variable can_produce, can_cunsume;
queue<int> resource;
const int max_size = 20;

void consumer() {
    while (true) {
        unique_lock<mutex> ul(mtx);
        while (resource.size() == 0) {
            can_cunsume.wait(ul);
        }
        int cur_resource = resource.front();
        cout << "consumer " << this_thread::get_id() << " consume resource: " << cur_resource << ",size: " << resource.size() << endl;
        resource.pop();
        can_produce.notify_all();
    }
}

void producer() {
    while (true) {
        unique_lock<mutex> ul(mtx);
        while (resource.size() == max_size)
            can_produce.wait(ul);
        int cur_resource = rand();
        cout << "producer " << this_thread::get_id() << " produce resource: " << cur_resource << ",size: " << resource.size() << endl;
        resource.push(cur_resource);
        can_cunsume.notify_all();
    }
}

int main() {
    vector<thread> consumers(5), producers(5);
    for (int i = 0; i < 5; i++) {
        consumers[i] = thread(consumer);
        producers[i] = thread(producer);
    }
    for (int i = 0; i < 5; i++) {
        consumers[i].join();
        producers[i].join();
    }
}