#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
    wait() - unique lock and an optional predicate
    wait_for() and wait_until() are similar - unique lock, timeout and an optional predicate
    notify_one() - Wakes one
    notify_all() - Guess
*/

void threadFunc(std::mutex& m, std::condition_variable& cond, bool& flag)
{
    std::cout << "Waiting on signal..." << std::endl;
    std::unique_lock<std::mutex> ul(m);
    cond.wait(ul, [&]{return flag;});
    std::cout << "Signal received..." << std::endl;
}

void conditionalTest()
{
    std::mutex m;
    std::condition_variable cond;

    bool flag = false;
    
    std::thread t(threadFunc, std::ref(m),
    std::ref(cond), std::ref(flag));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Sending signal (flag == false)" << std::endl;
    
    cond.notify_all();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    flag = true;
    
    std::cout << "Sending signal (flag == true)" << std::endl;
    cond.notify_all();
    
    t.join();
}

int main(int argc, char const *argv[])
{
    conditionalTest();
    conditionalTest();
    conditionalTest();
    conditionalTest();
    
    return 0;
}
