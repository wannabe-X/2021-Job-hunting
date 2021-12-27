#include"Alloctor.h"
#include<stdlib.h>
#include"MemoryMgr.hpp"

void* operator new(size_t nSize)
{

	return MemoryMgr::Instance().allocMem(nSize);
}

void operator delete(void* p)
{
	MemoryMgr::Instance().freeMem(p);
}

void* operator new [](size_t nSize)
{
	return MemoryMgr::Instance().allocMem(nSize);
}

void operator delete [](void* p)
{
	MemoryMgr::Instance().freeMem(p);
}

void* mem_alloc(size_t nSize)
{
	return MemoryMgr::Instance().allocMem(nSize);
}

void mem_free(void* p)
{
	MemoryMgr::Instance().freeMem(p);
}