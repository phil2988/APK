#include "Exercise1.cpp"
using namespace LectureOneToThree;

int main()
{
    size_t mySize = 5;
    MyArray<int> my(mySize);

    my[3] = 3; // Assuming that 'my' has been appropriately allocated based on MyArray.
    std::cout << "Looking for '3'? " << (myFind<int>(my.begin (), my.end(), 3) != my.end()? "found" : "sry no") << std::endl;
}
