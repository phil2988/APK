#include "Exercise1.cpp";

int main()
{
    size_t mySize = 5;
    MyArray<int> my(mySize);
    MyArray<double> myDouble(mySize);

    my[3] = 3; // Assuming that 'my' has been appropriately allocated based on MyArray.
    std::cout << "Looking for '3'? " << (myFind<int>(my.begin (), my.end(), 3) != my.end()? "found" : "sry no") << std::endl;

    myDouble[2] = 2.53;
    std::cout << "Looking for '2.53'? " << (myFind<double>(myDouble.begin (), myDouble.end(), 2.53) != myDouble.end()? "found" : "sry no") << std::endl;

    MyArray<int> intArray;
    MyArray<double> doubleArray;

    intArray[5] = 10;
    intArray[2] = 22;

    doubleArray = intArray;
    
    std::cout << "doubleArray: ";
    
    for (size_t i = 0; i < sizeof(intArray); i++)
    {
        std::cout << intArray[i] << ", ";
    }
    std::cout << std::endl;
}
