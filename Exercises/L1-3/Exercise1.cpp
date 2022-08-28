#include <iostream>
#include <vector>
namespace LectureOneToThree{

    template<typename T>

    class MyArray
    {   
        T* array_;
    public:
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
        size_t size(){
            return sizeof(array_);
        };
    };

    template<typename T>
    T* myFind(T* first, T* last, const T& value){
        std::vector<int>* v = new std::vector<int>(first, last);
        
        for (size_t i = 0; i < v->size(); i++)
        {
            if((*v)[i] == value){
                last;
            }
        }
        return last;
    }
}
