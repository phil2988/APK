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
    /* future from a packaged_task */
    std::packaged_task<int()> task(
        [](){ 
            return 7; 
        }
    ); /* wrap the function */
    
    std::future<int> f2 = task.get_future(); /* get a future */
    std::thread(
        std::move(task)
    ).detach(); /* launch on a thread */
    
    std::cout << "Waiting..." << std::flush;
    f2.wait();
    
    std::cout << "Done!\nResult is: " << f2.get() << '\n';
    return 0;
}
