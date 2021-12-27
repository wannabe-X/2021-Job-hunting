#ifndef _CELL_SEMAPHORE_DPP_
#define _CELL_SEMAPHORE_DPP_

#include<chrono>
#include<thread>
// 条件变量
#include<condition_variable>
#include<mutex>

class CELLSemaphore
{
public:
	// 阻塞当前线程
	void wait()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		if (--_wait < 0)
		{
			// 阻塞等待
			_cv.wait(lock, [this]()->bool { return _wakeup > 0; });
			--_wakeup;
		}
	}

	// 唤醒当前线程
	void wakeup()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		if (++_wait <= 0)
		{
			++_wakeup;
			_cv.notify_one();
		}
	}

private:
	// 阻塞等待的条件变量
	std::condition_variable _cv;
	std::mutex _mutex;
	// 等待计数
	int _wait = 0;
	// 唤醒计数
	int _wakeup = 0;
};


#endif // !_CELL_SEMAPHORE_DPP_

// 虚假唤醒