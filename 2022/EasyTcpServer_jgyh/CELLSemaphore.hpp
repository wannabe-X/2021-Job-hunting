#ifndef _CELL_SEMAPHORE_DPP_
#define _CELL_SEMAPHORE_DPP_

#include<chrono>
#include<thread>
// ��������
#include<condition_variable>
#include<mutex>

class CELLSemaphore
{
public:
	// ������ǰ�߳�
	void wait()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		if (--_wait < 0)
		{
			// �����ȴ�
			_cv.wait(lock, [this]()->bool { return _wakeup > 0; });
			--_wakeup;
		}
	}

	// ���ѵ�ǰ�߳�
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
	// �����ȴ�����������
	std::condition_variable _cv;
	std::mutex _mutex;
	// �ȴ�����
	int _wait = 0;
	// ���Ѽ���
	int _wakeup = 0;
};


#endif // !_CELL_SEMAPHORE_DPP_

// ��ٻ���