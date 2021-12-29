#ifndef _CELL_THREAD_HPP
#define _CELL_THREAD_HPP

#include"CELLSemaphore.hpp"
#include<functional>
#include<mutex>

class CELLThread
{
private:
	typedef std::function<void(CELLThread*)> EventCall;

public:
	CELLThread()
	{

	}

	~CELLThread()
	{

	}
	 
	// 启动线程
	void Start(EventCall onCreate = nullptr, EventCall onRun = nullptr, EventCall onDestory = nullptr)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (!_isRun)
		{
			if (onCreate)
				_onCreate = onCreate;
			if (onRun)
				_onRun = onRun;
			if (onDestory)
				_onDestory = onDestory;

			_isRun = true;
			// 启动线程
			std::thread t(std::mem_fn(&CELLThread::OnWork), this);
			t.detach();
		}
	}

	// 关闭线程
	void Close()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_isRun)
		{
			_isRun = false; // 关闭OnRun
			_sem.wait();
		}
	}

	// 在工作函数中退出
	// 不需要使用信号量
	// 如果使用会阻塞
	void Exit()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_isRun)
		{
			_isRun = false; // 关闭OnRun
		}
	}

	bool isRun()
	{
		return _isRun;
	}

protected:
	// 线程运行的工作函数
	void OnWork()
	{
		if (_onCreate)
			_onCreate(this);
		if (_onRun)
			_onRun(this);
		if (_onDestory)
			_onDestory(this);

		_sem.wakeup();
	}

private:
	EventCall _onCreate;
	EventCall _onRun;
	EventCall _onDestory;
	std::mutex _mutex;
	// 控制线程的终止 退出
	CELLSemaphore _sem;
	// 线程是否启动运行中
	bool _isRun = false;

};


#endif // !_CELL_THREAD_HPP
