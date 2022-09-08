#include <iostream>
#include <vector>
using namespace std;

template<typename T, size_t capacity = 5>
class MyArray
{   
    T array_[capacity];
public:
    MyArray(){
        for (size_t i = 0; i < capacity; i++)
        {
            array_[i] = 0;
        }
        
        cout << "Array initialized with values: ";
        for (size_t i = 0; i < capacity; i++)
        {
            cout << array_[i] << ", ";
        };
        cout << std::endl;
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
            cout <<"int value is: " << intArray[i] << ", new double value is: " << d << endl;
            this->array_[i] = d;
        }
        return *this;
    }

    size_t size(){
        return capacity;
    };
};

template<typename T, size_t capacity>
class MyArray<T*, capacity>{
    T array_[capacity];
public:
    MyArray(){
        for (size_t i = 0; i < capacity; i++)
        {
            array_[i] = 0;
        }
        
        cout << "Array initialized with values: ";
        for (size_t i = 0; i < capacity; i++)
        {
            cout << array_[i] << ", ";
        };
        cout << endl;
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

    size_t size(){
        return capacity;
    };

    MyArray<double>& operator= (MyArray<int> intArray){
        for (size_t i = 0; i < capacity - 1; i++)
        {
            double d = intArray[i];
            cout <<"int value is: " << intArray[i] << ", new double value is: " << d << endl;
            this->array_[i] = d;
        }
        return *this;
    }

    ~MyArray(){
        for (auto i : array_){
            delete(array_[i])
        }
    }
};

template<typename T>
T* myFind(T* first, T* last, const T& value){
    vector<T>* _value = new vector<T>(first, last);
    
    cout << endl;
    
    for (size_t i = 0; i < _value->size(); i++)
    {
        cout << "comparing values: " << (*_value)[i] << " to: " << value << endl;
        if((*_value)[i] == value)
        {
            T* returnVal =  &(*_value)[i];
            return returnVal;
        }
    }
    return last;
}

