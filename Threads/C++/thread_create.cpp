#include <thread>
#include <iostream>

void thread_func(int id) {
    std::cout << "Thread " << id << " running" << std::endl;
}

int main() {
    std::thread t(thread_func, 1);
    t.join();
    std::cout << "Thread joined" << std::endl;
    return 0;
}