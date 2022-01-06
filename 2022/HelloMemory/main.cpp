#include"Alloctor.h"
#include<stdlib.h>
#include<iostream>
#include<thread>
#include<mutex> // 锁
#include<memory>
#include"CELLTimestamp.hpp"
#include"CELLObjectPoll.hpp"

using namespace std;

// 原子操作 计算指令所不可分割的操作
mutex mtx;
const int tCount = 4;
const int mCount = 16;
const int nCount = mCount / tCount;

class ClassA : public ObjcetPollBase<ClassA, 100000>
{
public:
	ClassA(int n)
	{
		num = n;
		printf("ClassA\n");
	}

	~ClassA()
	{
		printf("~ClassA\n");
	}

public:
	int num = 0;
	char data[1000];
};

class ClassB : public ObjcetPollBase<ClassB, 100000>
{
public:
	ClassB(int n, int m)
	{
		num = n * m;
		printf("ClassB\n");
	}

	~ClassB()
	{
		printf("~ClassB\n");
	}

public:
	int num = 0;
};

void workFun(int n)
{
	ClassA* data[nCount];

	for (size_t i = 0; i < nCount; i++)
	{
		data[i] = ClassA::createObject(6);
	}

	for (size_t i = 0; i < nCount; i++)
	{
		ClassA::destroyObject(data[i]);
	}

} // 抢占式

void fun(shared_ptr<ClassA>& pA) // 存在拷贝过程
{
	// 引用计数
	//printf("2use_count = %d\n", pA.use_count());
	pA->num++;
}

void fun(ClassA* pA)
{
	pA->num++;
}

void fun(ClassA& pA)
{
	pA.num++;
}

int main()
{
	/*
	thread t[tCount];
	for (int i = 0; i < tCount; i++)
	{
		t[i] = thread(workFun, i);
	}

	CELLTimestamp tTime;
	for (int i = 0; i < tCount; i++)
	{
		t[i].join();
	}
	cout << tTime.getElapsedTimeInMilliSec() << endl;
	tTime.update();

	cout << "hello, main thread." << endl;
	*/

	//int* a = new int;
	//*a = 100;
	//printf("a = %d\n", *a);
	//delete a;


	//// 智能指针 c++标准库智能指针的一种
	//std::shared_ptr<int> b = std::make_shared<int>();
	//*b = 100;
	//printf("b = %d\n", *b);

	//ClassA* a1 = new ClassA(); // 只new不释放，会造成内存泄漏的情况。即只调用了构造函数，没有调用析构函数
	//a1->num = 100;
	// delete a1;

	/*
	{
		shared_ptr<ClassA> a2 = make_shared<ClassA>(100); // 使用智能指针，既调用了构造也调用了析构
		a2->num = 200;
		CELLTimestamp tTime;
		for (int i = 0; i < 10000000; i++)
		{
			fun(a2);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}

	{
		ClassA* a2 = new ClassA(100); // 使用智能指针，既调用了构造也调用了析构
		a2->num = 200;
		CELLTimestamp tTime;
		for (int i = 0; i < 10000000; i++)
		{
			fun(a2);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}

	{
		ClassA a2(100); // 使用智能指针，既调用了构造也调用了析构
		a2.num = 200;
		CELLTimestamp tTime;
		for (int i = 0; i < 10000000; i++)
		{
			fun(a2);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}
	*/

	/*
	ClassA* a1 = new ClassA(5);
	delete a1;

	ClassA* a2 = ClassA::createObject(6);
	ClassA::destroyObject(a2);

	ClassB* b1 = new ClassB(5, 6);
	delete b1;

	ClassB* b2 = ClassB::createObject(5, 6);
	ClassB::destroyObject(b2);
	*/


	printf("------------------------1--------------------------\n");
	{
		std::shared_ptr<ClassA> a2 = std::make_shared<ClassA>(5);
	}

	printf("------------------------2--------------------------\n");
	{
		std::shared_ptr<ClassA> a2(new ClassA(5));
	}

	printf("------------------------3--------------------------\n");
	printf("ClassA size:%d\n", sizeof(ClassA));
	ClassA* a1 = new ClassA(5);
	delete a1;

	printf("------------------------4--------------------------\n");

	return 0;
}