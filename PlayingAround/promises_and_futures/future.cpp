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
    /* future from a promise */
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::thread( 
        [](std::promise<int> p){ 
            p.set_value_at_thread_exit(9); 
        },
        std::move(p)
    ).detach();

    std::cout << "Waiting..." << std::flush;
    f.wait();
    
    std::cout << "Done!\nResult is: " << f.get() << '\n';

    return 0;
}
