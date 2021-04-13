#include <iostream>
#include <cstdlib>
#include <memory.h>

class Ciclequeue
{
public:
    //队列最大容量
    int m_maxSize;
    //队列头指针
    int m_frontIdx;
    //队列尾指针
    int m_rearIdx;
    //队列数组
    int *m_queueArr;

public:
    //构造函数
    Ciclequeue(int tmpSize)
    {
        m_maxSize = tmpSize;
        m_frontIdx = 0;
        m_rearIdx = 0;
        m_queueArr = new int[m_maxSize];
        memset(m_queueArr, 0, sizeof(int) * m_maxSize);
    }

    //析构函数
    ~Ciclequeue()
    {
        delete m_queueArr;
        m_queueArr = NULL;
    }

    //入队
    void enqueue(int datavalue)
    {
        if (isfull())
        {
            std::cout << "Queue is full!" << std::endl;
            return;
        }

        m_queueArr[m_rearIdx] = datavalue;
        m_rearIdx = (m_rearIdx + 1) % m_maxSize;
    }

    //出队
    void dequeue()
    {
        if (isempty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        m_queueArr[m_frontIdx] = -1; //模拟出队列动作
        m_frontIdx = (m_frontIdx + 1) % m_maxSize;
    }

    //检查队列是否已满
    bool isfull()
    {
        if (m_maxSize == -1)
        {
            std::cout << "Create queue error!" << std::endl;
            return false;
        }
        return (m_rearIdx + 1) % m_maxSize == m_frontIdx;
    }

    //检查队列是否为空
    bool isempty()
    {
        if (m_maxSize == -1)
        {
            std::cout << "Create queue error!" << std::endl;
            return false;
        }
        return m_rearIdx == m_frontIdx;
    }

    //当前队列元素各个数
    int size()
    {
        return (m_rearIdx - m_frontIdx + m_maxSize) % m_maxSize;
    }

    //显示队列
    void showqueue()
    {
        if (isempty())
        {
            return;
        }

        for (int i = m_frontIdx; i < m_frontIdx + size(); i++)
        {
            std::cout << m_queueArr[i] << " " << std::endl;
        }
    }

    //显示队列头
    void showqueuefront()
    {
        std::cout << m_queueArr[m_frontIdx] << std::endl;
    }
};

int main(int argc, char **argv)
{
    int tmpSize = std::atoi(argv[1]);
    if (tmpSize <= 0)
    {
        std::cout << "Set MaxSize Error!" << std::endl;
        return 0;
    }

    Ciclequeue *testqueue = new Ciclequeue(tmpSize);
    testqueue->enqueue(3);
    testqueue->enqueue(2);
    testqueue->dequeue();
    testqueue->enqueue(4);
    testqueue->dequeue();
    testqueue->enqueue(5);
    testqueue->enqueue(66);
    testqueue->enqueue(88);
    testqueue->enqueue(1204);

    testqueue->showqueue();

    delete testqueue;
    testqueue = NULL;

    return 0;
}