#include <iostream>
#include <future>
/*
    FUTURES
    Concept:
     - valid() - Future valid
     - get() - Retrieves the result (if not ready calls wait())
     - wait() - Waits until result is ready
     - wait_for() and wait_until() - Similar, but timed edition of wait()
*/

int main(int argc, char const *argv[])
{
    /* future from an async() */
    std::future<int> f3 = std::async(
        std::launch::async, 
        [](){ 
            return 8; 
        }
    );
    std::cout << "Waiting..." << std::flush;
    f3.wait();

    std::cout << "Done!\nResult is: " << f3.get() << '\n';
    return 0;
}
