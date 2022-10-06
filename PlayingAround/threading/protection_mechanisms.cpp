#include <iostream>
#include <thread>
#include <mutex>

/*
    Mutexes and only mutexes - No semaphores

    features
     - mutex 
     - timed_mutex
     - recursive_mutex
     - recursive_timed_mutex
     - shared_timed_mutex (C++14)
    
    Acquisition via
     - lock_guard
     - unique_lock
     - shared_lock (C++14)

    RAII style locking
     - Simplified - AKA Scoped Lock
        - lock_guard
     - Deferability
        - unique_lock
     - Deferability & R/W locks
        - shared_lock
*/

void threadNoDeadlock(std::mutex& m1, std::mutex& m2)
{
    std::cout << "Started\n";

    // unique lock ~= locked in scope
    std::unique_lock<std::mutex> ul1(m1, std::defer_lock);
    std::unique_lock<std::mutex> ul2(m2, std::defer_lock);
    
    std::lock(ul1, ul2);
    std::cout << "Completed\n";
}

int main(int argc, char const *argv[])
{
    std::mutex m1, m2;

    std::thread t1(threadNoDeadlock, std::ref(m1), std::ref(m2));
    std::thread t2(threadNoDeadlock, std::ref(m2), std::ref(m1));

    t1.join();
    t2.join();

    return 0;
}
