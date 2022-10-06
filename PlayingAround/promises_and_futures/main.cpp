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
    std::future<int> f1 = task.get_future(); /* get a future */
    std::thread(
        std::move(task)
    ).detach(); /* launch on a thread */
    
    /* future from an async() */
    std::future<int> f2 = std::async(std::launch::async, [](){ return 8; });
    
    /* future from a promise */
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread( 
        [](std::promise<int> p){ 
            p.set_value_at_thread_exit(9); 
        },
        std::move(p) 
    ).detach();
    
    std::cout << "Waiting..." << std::flush;
    
    f1.wait();
    f2.wait();
    f3.wait();
    
    std::cout << "Done!\nResults are: "
    << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
    return 0;
}
