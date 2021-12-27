#ifndef _CELL_TASK_H_
#include<thread>
#include<mutex>
#include<list>
#include<functional>

// 任务类型-基类
// 执行任务的服务类型
class CellTask
{
public:
	CellTask()
	{

	}

	virtual ~CellTask()
	{

	}

	virtual void doTask()
	{

	}

private:

};

typedef std::shared_ptr<CellTask> CellTaskPtr;
// 执行任务的服务类型
class CellTaskServer
{
private:
	// 任务数据
	std::list<CellTaskPtr > _tasks;
	// 任务数据缓冲区
	std::list<CellTaskPtr > _tasksBuf;
	// 改变数据缓冲区需要加锁
	std::mutex _mutex;
	// 

public:
	CellTaskServer() 
	{

	}

	~CellTaskServer()
	{

	}

	// 添加任务
	void addTask(CellTaskPtr& task)
	{
		std::lock_guard<std::mutex> lock(_mutex);
		_tasksBuf.push_back(task);
	}

	// 启动工作线程
	void Start()
	{
		// 线程
		std::thread t(std::mem_fn(&CellTaskServer::OnRun), this);
		t.detach();
	}

protected:
	// 执行任务 工作内容
	void OnRun()
	{
		while (true)
		{
			// 从缓冲区里面取出数据
			if (!_tasksBuf.empty())
			{
				std::lock_guard<std::mutex> lock(_mutex);
				for (auto pTask : _tasksBuf)
				{
					_tasks.push_back(pTask);
				}
				_tasksBuf.clear();
			}

			// 如果没有任务
			if (_tasks.empty())
			{
				std::chrono::milliseconds t(1);
				std::this_thread::sleep_for(t);
				continue;
			}

			// 处理任务
			for (auto pTask : _tasks)
			{
				pTask->doTask();
			}

			// 清空任务
			_tasks.clear();
		}
	}

private:

};

#endif // _CELL_TASK_H_
