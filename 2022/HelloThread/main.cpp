#include<iostream>
#include<thread>
#include<mutex> // ��
#include<atomic> // ԭ��
using namespace std;

// ԭ�Ӳ��� ����ָ�������ɷָ�Ĳ���
mutex mtx;
const int tCount = 4;
//int sum = 0;
atomic_int sum = 0;
//atomic<int> sum = 0;

void workFun(int n)
{
	
	for (int i = 0; i < 20000000; i++)
	{
		// �Խ��� �����ţ��ͻᱻunlock()
		//lock_guard<mutex> lg(mtx);
		// �ٽ����� ��ʼ
		//mtx.lock();
		sum++;
		// �̰߳�ȫ���̲߳���ȫ
		//cout << n << "hello, other thread." << i + 1 << endl;
		//// �ٽ����� ����
		//mtx.unlock();

	}
} // ��ռʽ

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
		
	//t.detach(); // �����߳�
	//t.join();
	cout << "sum = " << sum << endl;
	cout << "hello, main thread." << endl;

	return 0;
}