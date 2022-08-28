#include <iostream>
#include <vector>

template<typename T>
class RAII
{
private:
    T* pointer_;
public:
    explicit RAII(T* pointer = 0) : pointer_(pointer){};

    ~RAII(){delete(pointer_);}; /* Deallocate resource at scope exit */

    T& operator*() const { return *pointer_; } /* *raii retrieves data T& */
    T* operator->() const { return pointer_; } /* raii> accesses data T* */
};


int main()
{
    RAII<std::vector<int>> raiiVector(new std::vector<int>());

    std::cout << raiiVector->size() << std::endl;
 
}   /* The std::vector is automatically deallocated */
