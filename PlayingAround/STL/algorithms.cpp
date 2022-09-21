#include <iostream>
#include <list>
#include <numeric> // accumulate
#include <functional> // array

void printArray(int a[], size_t arrSize){

    for (int i = 0; i < arrSize; ++i)
    {
        if(a[i] != 0)
            std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

bool isOdd(int number)
{
    return number % 2;
};

int square(int number)
{
    return number*number;
}

int main(int argc, char const *argv[])
{
    std::array<int, 6> a = { 1, 50, 10, 11, 42, 19 };
    std::list<int> l = {5, 16, 9, 2, 88, 21};

    std::cout << std::max(50, 10) << "\n";
    std::cout << std::accumulate(a.begin(), a.end(), 0) << "\n";

    std::sort(a.begin(), a.end());

    // sort doesnt work on list. Use list.sort()
    l.sort();

    int result[ 6 ] = { 0, 0, 0, 0, 0, 0 };
    std::remove_copy_if(a.begin(), a.end(), result, isOdd );
    printArray(&*result, sizeof(result)/sizeof(int));

    std::transform(a.begin(), a.end(), result, square );
    printArray(&*result, sizeof(result)/sizeof(int));

    return 0;
}


