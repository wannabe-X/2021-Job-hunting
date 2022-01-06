#ifndef _CELLCELLObjectPool_HPP_
#define _CELLCELLObjectPool_HPP_

#include<stdlib.h>
#include<mutex>
#include<assert.h>

#ifdef _DEBUG
	#ifndef xPrintf
	#include<stdio.h>
	#define xPrintf(...) printf(__VA_ARGS__)
	#endif // !xPrintf
#else
	#ifndef xPrintf
	#define xPrintf(...)
	#endif // !xPrintf
#endif // _DEBUG

template<class Type, size_t nPollSize>
class CELLObjectPool
{
private:
	// 对象的结点
	class NodeHeader
	{
	public:
		// 下一块位置
		NodeHeader* pNext;
		// 其他属性
		int nID;
		char nRef;
		bool bPool;
	private:
		char c1;
		char c2;
	};

private:
	// 
	NodeHeader* _pHeader;
	// 对象池内存缓冲区地址
	char* _pBuf;
	std::mutex _mutex;

public:
	// 释放对
	void freeObjMemory(void* pMem)
	{
		NodeHeader* pBlock = (NodeHeader*)(((char*)pMem) - sizeof(NodeHeader));
		xPrintf("freeObjMemory: %llx, id = %d\n", pBlock, pBlock->nID);
		assert(1 == pBlock->nRef);
		pBlock->nRef = 0;

		if (pBlock->bPool)
		{
			std::lock_guard<std::mutex> lock(_mutex);
			if (--pBlock->nRef != 0)
			{
				return;
			}
			pBlock->pNext = _pHeader;
			_pHeader = pBlock;
		}
		else
		{
			if (--pBlock->nRef != 0)
			{
				return;
			}
			delete[] pBlock;
		}
	}

	// 申请对象内存
	void* allocObjMemory(size_t nSize)
	{
		std::lock_guard<std::mutex> lock(_mutex);

		NodeHeader* pReturn = nullptr;
		if (nullptr == _pHeader)
		{
			pReturn = (NodeHeader*)new char[nSize + sizeof(NodeHeader)]; // 从内存额外的地方申请空间
			if (nullptr == pReturn)
				return pReturn;

			pReturn->bPool = false;
			pReturn->nID = -1;
			pReturn->nRef = 1;
			pReturn->pNext = nullptr;
		}
		else {
			pReturn = _pHeader;
			_pHeader = _pHeader->pNext;
			assert(0 == pReturn->nRef);
			pReturn->nRef = 1;
		}

		xPrintf("allocObjMem: %llx, id = %d, size = %d\n", pReturn, pReturn->nID, nSize);
		return ((char*)pReturn + sizeof(NodeHeader));
	}

	// 初始化对象池
	CELLObjectPool()
	{
		initPool();
	}

	~CELLObjectPool()
	{
		if(_pBuf)
			delete _pBuf;
	}
private:
	void initPool()
	{
		assert(nullptr == _pBuf);
		if (_pBuf)
			return;

		// 计算对象池大小
		size_t n = nPollSize * (sizeof(Type) + sizeof(NodeHeader));
		// 申请池的内存
		_pBuf = new char[n];
		// 初始化对象池
		_pHeader = (NodeHeader*)_pBuf;
		_pHeader->bPool = true;
		_pHeader->nID = 0;
		_pHeader->nRef = 0;
		_pHeader->pNext = nullptr;

		NodeHeader* pTemp1 = _pHeader;
		size_t realSize = sizeof(Type) + sizeof(NodeHeader);

		for (int i = 1; i < nPollSize; i++)
		{
			NodeHeader* pTemp2 = (NodeHeader*)(_pBuf + i * realSize);
			pTemp2->bPool = true;
			pTemp2->nID = i;
			pTemp2->nRef = 0;
			pTemp1->pNext = pTemp2;
			pTemp1 = pTemp2;
		}
	}
};

template<class Type, size_t nPoolSize>
class ObjcetPollBase
{
public:
	void* operator new(size_t nSize)
	{
		printf("CELLObjectPoll size:%d\n", nSize);
		return ObjectPoll().allocObjMemory(nSize);
	}

	void operator delete(void* p)
	{
		ObjectPoll().freeObjMemory(p);
	}

	// 不定参数 可变参数
	template<typename ...Args>
	static Type* createObject(Args ... args)
	{
		Type* obj = new Type(args...);
		return obj;
	}

	static void destroyObject(Type* obj)
	{
		delete obj;
	}

private:
	typedef CELLObjectPool<Type, nPoolSize> ClassTypePool;
	// 懒汉式单例对象池
	static ClassTypePool& ObjectPoll()
	{
		static ClassTypePool sPool;
		return sPool;
	}

};


#endif // !_CELLCELLObjectPool_HPP_
