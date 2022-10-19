/*
    Conceptual implementation of
    • Move Constructor
    • Move Assignment
    Remember to denote them noexcept
    • Reason: move will sometimes only be used if noexcept gauranteed!
*/

#include <iostream>
#include <vector>

class Movable
{
public:
    Movable() : data_{new int{10}}{}
    Movable(Movable&& other) noexcept;
    Movable& operator = (Movable&& other) noexcept;
    ~Movable() { delete data_;}
private:
    int* data_;
};

Movable::Movable(Movable&& other) noexcept
: data_{std::move(other.data_)}
{
    other.data_ = nullptr;
}

Movable& Movable::operator=(Movable&& other) noexcept
{
    if (this != &other) {
        delete data_;
        data_ = nullptr;
        std::swap(other.data_, data_);
    }
    return *this;
}

int main(int argc, char const *argv[])
{
    // Move Construction
    Movable ctorSrc;
    Movable ctorDst{std::move(ctorSrc)};
    // Move Assignment
    Movable assignSrc;
    Movable assignDst;
    assignDst = std::move(assignSrc);

    Movable m;
    std::vector<Movable> v;
    // forced move, m converted to an xvalue 
    v.push_back(std::move(m));
    // prvalue implicit move
    v.push_back(Movable());


    return 0;
}

// Moving instead of copying
// !!Move if you can, otherwise copy!!

// Copy
template<typename T>
void swap(T& t1, T& t2){
    T tmp(t1);
    t1 = t2;
    t2 = tmp;
}

// Moving
template<typename T>
void swap(T& t1, T& t2){
    T tmp(std::move(t1));
    t1 = std::move(t2);
    t2 = std::move(tmp);
}