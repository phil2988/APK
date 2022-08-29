#include <iostream>
#include <vector>

template<typename T>

class MyArray
{   
    T* array_;
public:
    MyArray(){
        array_ = new T[10];
    };
    MyArray(size_t size){
        array_ = new T[size];
    };
    ~MyArray(){ delete(array_); };

    void fill(const T&);

    T* begin(){
        return &array_[0];
    };

    T* end(){
        return &array_[sizeof(array_)];
    };

    T& operator[] (int i){
        return array_[i];
    };

    MyArray<double>& operator= (MyArray<int> intArray){
        for (size_t i = 0; i < sizeof(intArray); i++)
        {
            double* d = new double(intArray[i]);
            this->array_[i] = *d;
        }
        

        return *this;
    }

    size_t size(){
        return sizeof(array_);
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

