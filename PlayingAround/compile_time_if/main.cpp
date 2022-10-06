#include <iostream>
// < C++17
template<typename T>
T& get_ref_old(T* t)
{
    return *t;
}
template<typename T>
T& get_ref_old(T& t)
{
    return t;
}

// C++17
// Condition must be a constant expression, otherwise compiler error
template<typename T>
auto& get_ref_new(T&&t){
    if constexpr(std::is_pointer_v<T>){
        return *t;
    }
    else 
    {
        return t;
    }
}

 /*
    Must be compile-time evaluable
    Can be used in both template and non-template code
    Discards code for not taken path
    May change return type if need be
 */

int main(int argc, char const *argv[])
{
    std::string s = "42";

    // Runtime
    get_ref_old(s).length();
    get_ref_old(&s).length();

    // Compiletime
    get_ref_new(s).length();
    get_ref_new(&s).length();

    return 0;
}
