#include <thread>
#include <iostream>
/*
    Can
     - Classic ability to create threads that may do some form of work
     - Arguments are passed onward to thread function
    Can NOT
     - Set priority on a thread
        - Need to retrieve native handle and perform native operations on that
*/

void printText(const std::string&& s)
{
    std::cout << s << std::endl;
}

void threadTest()
{   
    std::thread t1(printText, "Hello from thread");
    t1.join();
}

int main(int argc, char const *argv[])
{
    threadTest();
    return 0;
}
