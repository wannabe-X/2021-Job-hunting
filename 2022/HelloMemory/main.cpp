#include"Alloctor.h"
#include<stdlib.h>
#include<iostream>
#include<thread>
#include<mutex> // ��
#include<memory>
#include"CELLTimestamp.hpp"
#include"CELLObjectPoll.hpp"

using namespace std;

// ԭ�Ӳ��� ����ָ�������ɷָ�Ĳ���
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

} // ��ռʽ

void fun(shared_ptr<ClassA>& pA) // ���ڿ�������
{
	// ���ü���
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


	//// ����ָ�� c++��׼������ָ���һ��
	//std::shared_ptr<int> b = std::make_shared<int>();
	//*b = 100;
	//printf("b = %d\n", *b);

	//ClassA* a1 = new ClassA(); // ֻnew���ͷţ�������ڴ�й©���������ֻ�����˹��캯����û�е�����������
	//a1->num = 100;
	// delete a1;

	/*
	{
		shared_ptr<ClassA> a2 = make_shared<ClassA>(100); // ʹ������ָ�룬�ȵ����˹���Ҳ����������
		a2->num = 200;
		CELLTimestamp tTime;
		for (int i = 0; i < 10000000; i++)
		{
			fun(a2);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}

	{
		ClassA* a2 = new ClassA(100); // ʹ������ָ�룬�ȵ����˹���Ҳ����������
		a2->num = 200;
		CELLTimestamp tTime;
		for (int i = 0; i < 10000000; i++)
		{
			fun(a2);
		}
		cout << tTime.getElapsedTimeInMilliSec() << endl;
	}

	{
		ClassA a2(100); // ʹ������ָ�룬�ȵ����˹���Ҳ����������
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