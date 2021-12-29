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
	 
	// �����߳�
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
			// �����߳�
			std::thread t(std::mem_fn(&CELLThread::OnWork), this);
			t.detach();
		}
	}

	// �ر��߳�
	void Close()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_isRun)
		{
			_isRun = false; // �ر�OnRun
			_sem.wait();
		}
	}

	// �ڹ����������˳�
	// ����Ҫʹ���ź���
	// ���ʹ�û�����
	void Exit()
	{
		std::lock_guard<std::mutex> lock(_mutex);
		if (_isRun)
		{
			_isRun = false; // �ر�OnRun
		}
	}

	bool isRun()
	{
		return _isRun;
	}

protected:
	// �߳����еĹ�������
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
	// �����̵߳���ֹ �˳�
	CELLSemaphore _sem;
	// �߳��Ƿ�����������
	bool _isRun = false;

};


#endif // !_CELL_THREAD_HPP
