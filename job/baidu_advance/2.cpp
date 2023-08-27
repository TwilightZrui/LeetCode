生产者消费者模式

#include<stdio.h>
#include<thread>
#include<mutex>
#include<vector>
#include<condition_variable>
#include<queue>
#include<list>

using namespace std;

list<double> m_queue; //举例存放数据是double
int m_maxSize;

mutex m_mutex; //gloal mutex

condition_variable_any m_notEmpty; // 条件变量，不为空
condition_variable_any m_notFull;//条件变量，不为满

// 队列为空
bool isEmpty()
{
    return m_queue.empty();
}

//队列满
bool isFull()
{
    return m_queue.size() == m_maxSize;
}

void product(double& p)
{
    unique_lock(mutex) locker(m_mutex);
    while(isFull())
    {
        // 队列满，生产者需要等待，直到队列缓冲区不为满
        m_notFull.wait(m_mutex);
    }

    //如果不满，往队列里生产一个
    m_queue.push_back(p);
    m_notEmpty.notify_one(); // 通知队列不为空这个信号量
}

void consumer(double& c)
{
    unique_lock(mutex) locker(m_mutex);
    while(isEmpty())
    {
        // 队列空，消费者需要等待，直到队列缓冲区不为空
        m_notEmpty.wait(m_mutex);
    }

    //往队列里消费一个
    c = m_queue.front();
    m_queue.pop_front();
    m_notFull.notify_one();  // 通知队列不为满这个信号量
}

