#ifndef _MEMORYMGR_HPP_
#define _MEMORYMGR_HPP_

#include"Alloctor.h"
#include<stdlib.h>
#include<assert.h>
#include<mutex>

#ifdef _DEBUG
	#include<stdio.h>
	#define xPrintf(...) printf(__VA_ARGS__)
#else
	#define xPrintf(...)
#endif // _DEBUG


// 最大内存单元 链表的结点
#define MAX_MEMORY_SIZE 128

class MemoryAlloc;

// 内存块 最小单元
class MemoryBlock
{
public:
	MemoryAlloc* pAlloc; // 所属大内存块
	MemoryBlock* pNext; // 下一块位置
	int nID; // 内存块编号
	int nRef; // 引用次数
	bool bPool; // 是否在内存池中

private:
	char c1; // 预留
	char c2;
	char c3;

};
//const int MemoryBlockSize = sizeof(MemoryBlock);


// 内存池
class MemoryAlloc
{
public:
	MemoryAlloc()
	{
		_pBuf = nullptr;
		_pHeader = nullptr;
		_nSize = 0;
		_nBlockSize = 0;
	}

	~MemoryAlloc()
	{
		if (_pBuf)
			free(_pBuf);
	}

	//申请内存
	void* allocMemory(size_t nSize)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (!_pBuf) // 如果申请的内存为空，则初始化内存
		{
			initMemory();
		}

		MemoryBlock* pReturn = nullptr;
		if (nullptr == _pHeader)
		{
			pReturn = (MemoryBlock*)malloc(nSize + sizeof(MemoryBlock)); // 从内存额外的地方申请空间
			if (nullptr == pReturn)
				return pReturn;

			pReturn->bPool = false;
			pReturn->nID = -1;
			pReturn->nRef = 1;
			pReturn->pAlloc = nullptr;
			pReturn->pNext = nullptr;
			xPrintf("allocMem: %llx, id = %d, size = %d\n", pReturn, pReturn->nID, nSize);
		}
		else {
			pReturn = _pHeader;
			_pHeader = _pHeader->pNext;
			assert(0 == pReturn->nRef);
			pReturn->nRef = 1;
		}

		//xPrintf("allocMem: %llx, id = %d, size = %d\n", pReturn, pReturn->nID, nSize);
		return ((char*)pReturn + sizeof(MemoryBlock));
	}

	// 释放内存
	void freeMemory(void* pMem)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		MemoryBlock* pBlock = (MemoryBlock*)(((char*)pMem) - sizeof(MemoryBlock));
		assert(1 == pBlock->nRef);
		if (0 != --pBlock->nRef)
		{
			return;
		}

		if (pBlock->bPool)
		{
			pBlock->pNext = _pHeader;
			_pHeader = pBlock;
		}
		else
		{
			free(pBlock);
		}
	}

	// 初始化
	void initMemory()
	{
		// 断言
		assert(nullptr == _pBuf);

		if (_pBuf) 
			return;
		// 向系统申请池内存
		size_t bufSize = (_nSize + sizeof(MemoryBlock)) * _nBlockSize; // 计算内存池的大小 每块大小*块的数量
		size_t realSize = (_nSize + sizeof(MemoryBlock)); // 96

		_pBuf = (char *)malloc(bufSize);
		// 初始化内存池
		_pHeader = (MemoryBlock*)_pBuf;
		if (_pHeader == nullptr) 
			return;
		_pHeader->bPool = true;
		_pHeader->nID = 0;
		_pHeader->nRef = 0;
		_pHeader->pAlloc = this;
		_pHeader->pNext = nullptr;

		// 遍历内存进行初始化
		MemoryBlock* pTemp1 = _pHeader;

		for (int i = 1; i < _nBlockSize; i++)
		{
			MemoryBlock* pTemp2 = (MemoryBlock*)(_pBuf + realSize * i);
			pTemp2->bPool = true;
			pTemp2->nID = i;
			pTemp2->nRef = 0;
			pTemp2->pAlloc = this;
			pTemp2->pNext = nullptr;
			pTemp1->pNext = pTemp2;
			pTemp1 = pTemp2;
		}

	}

protected:
	char* _pBuf; // 内存池地址
	MemoryBlock* _pHeader; // 头部内存单元
	size_t _nSize;  // 内存单元的大小
	size_t _nBlockSize; // 内存块的数量
	std::mutex _mutex;
};

//便于在声明类成员变量时初始化MemoryAlloc的成员数据
template<size_t nSize, size_t nBlockSize>
class MemoryAlloctor:public MemoryAlloc
{
public:
	MemoryAlloctor()
	{
		_nSize = nSize;
		_nBlockSize = nBlockSize;
	}
};

// 内存管理工具
class MemoryMgr
{
private:
	MemoryMgr()
	{
		init_szAlloc(0, 64, &_mem64);
		init_szAlloc(65, 128, &_mem128);
		//init_szAlloc(129, 256, &_mem256);
		//init_szAlloc(257, 512, &_mem512); 
		//init_szAlloc(513, 1024, &_mem1024);
	}

	~MemoryMgr()
	{

	}

public:
	static MemoryMgr& Instance()
	{
		// 单例模式 静态
		static MemoryMgr mgr;
		return mgr;
	}

	// 申请内存
	void* allocMem(size_t nSize)
	{
		if (nSize <= MAX_MEMORY_SIZE)
		{
			return _szAlloc[nSize]->allocMemory(nSize);
		}
		else
		{
			MemoryBlock* pReturn = (MemoryBlock*)malloc(nSize + sizeof(MemoryBlock));
			if (nullptr == pReturn) 
				return pReturn;
			pReturn->bPool = false;
			pReturn->nID = -1;
			pReturn->nRef = 1;
			pReturn->pAlloc = nullptr;
			pReturn->pNext = nullptr;

			//xPrintf("allocMem: %llx, id = %d, size = %d\n", pReturn, pReturn->nID, nSize);
			return ((char*)pReturn + sizeof(MemoryBlock));
		}	
	}

	// 释放内存
	void freeMem(void* pMem)
	{

		MemoryBlock* pBlock = (MemoryBlock*)(((char*)pMem) - sizeof(MemoryBlock));
		//xPrintf("freeMem: %llx, id = %d \n", pBlock, pBlock->nID);
		if (pBlock->bPool)
		{
			pBlock->pAlloc->freeMemory(pMem);
		}
		else
		{
			if(--pBlock->nRef == 0)
				free(pBlock);
		}
	}

	void addRef(void* pMem)
	{
		MemoryBlock* pBlock = (MemoryBlock*)(((char*)pMem) - sizeof(MemoryBlock));
		++pBlock->nRef;
	}

private:
	// 内存池映射数组
	void init_szAlloc(int nBegin,int nEnd, MemoryAlloc *pMemA)
	{
		for (int i = nBegin; i <= nEnd; i++)
		{
			_szAlloc[i] = pMemA;
		}
	}

private:
	MemoryAlloctor<64, 4000000> _mem64;
	MemoryAlloctor<128, 2000000> _mem128;
	//MemoryAlloctor<256, 100000> _mem256;
	//MemoryAlloctor<512, 100000> _mem512;
	//MemoryAlloctor<1024, 100000> _mem1024;
	MemoryAlloc* _szAlloc[MAX_MEMORY_SIZE + 1];
};


#endif // !_MEMORYMGR_HPP_
