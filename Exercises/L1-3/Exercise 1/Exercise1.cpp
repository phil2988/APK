#include <iostream>
#include <vector>

template<typename T, std::size_t capacity = 5>

class MyArray
{   
    T array_[capacity];
public:
    MyArray(){
        for (size_t i = 0; i < capacity; i++)
        {
            array_[i] = 0;
        }
        
        std::cout << "Array initialized with values: ";
        for (size_t i = 0; i < capacity; i++)
        {
            std::cout << array_[i] << ", ";
        };
        std::cout << std::endl;
    };

    ~MyArray(){ };

    void fill(const T&);

    T* begin(){
        return &array_[0];
    };

    T* end(){
        return &array_[capacity - 1];
    };

    T& operator[] (int i){
        return array_[i];
    };

    MyArray<double>& operator= (MyArray<int> intArray){
        for (size_t i = 0; i < capacity - 1; i++)
        {
            double d = intArray[i];
            std::cout <<"int value is: " << intArray[i] << ", new double value is: " << d << std::endl;
            this->array_[i] = d;
        }
        
        return *this;
    }

    size_t size(){
        return capacity;
    };
};

template<typename T>
T* myFind(T* first, T* last, const T& value){
    std::vector<T>* _value = new std::vector<T>(first, last);
    
    std::cout << std::endl;
    
    for (size_t i = 0; i < _value->size(); i++)
    {
        std::cout << "comparing values: " << (*_value)[i] << " to: " << value << std::endl;
        if((*_value)[i] == value)
        {
            T* returnVal =  &(*_value)[i];
            return returnVal;
        }
    }
    return last;
}

