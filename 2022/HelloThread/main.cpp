#include<iostream>
#include<thread>
#include<mutex> // 锁
#include<atomic> // 原子
using namespace std;

// 原子操作 计算指令所不可分割的操作
mutex mtx;
const int tCount = 4;
//int sum = 0;
atomic_int sum = 0;
//atomic<int> sum = 0;

void workFun(int n)
{
	
	for (int i = 0; i < 20000000; i++)
	{
		// 自解锁 出括号，就会被unlock()
		//lock_guard<mutex> lg(mtx);
		// 临界区域 开始
		//mtx.lock();
		sum++;
		// 线程安全和线程不安全
		//cout << n << "hello, other thread." << i + 1 << endl;
		//// 临界区域 结束
		//mtx.unlock();

	}
} // 抢占式

int main()
{
	//thread t(workFun, 10);
	thread t[tCount];
	for (int i = 0; i < tCount; i++)
	{
		t[i] = thread(workFun, i);
	}
	for (int i = 0; i < tCount; i++)
	{
		t[i].join();
		//t[i].detach();
	}
		
	//t.detach(); // 启动线程
	//t.join();
	cout << "sum = " << sum << endl;
	cout << "hello, main thread." << endl;

	return 0;
}