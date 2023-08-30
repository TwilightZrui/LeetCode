#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;  // 创建互斥锁对象

void shared_print(int id, int value) {
    std::lock_guard<std::mutex> lock(mtx);  // 获取互斥锁对象
    std::cout << "Thread " << id << ": " << value << std::endl;
}

void func(int id) {
    for(int i = 0; i < 10; ++i) {
        shared_print(id, i);
    }
}

int main() {
    std::thread t1(func, 1);
    std::thread t2(func, 2);

    t1.join();
    t2.join(); 

    return 0;
}