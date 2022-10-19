/*
    Idea: To pass arguments perfectly from call site to usage site

*/

#include <string>

template<typename T, typename Arg>
T* createT(Arg&& arg)
{
    return new T(forward<args>(t));
}

template<class T>
constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept
{
    return static_cast<T&&>(t);
}

int main(int argc, char const *argv[])
{
    // calling with int
    int* i = createT<int>(42); // a prvalue

    // calling with string
    std::string s{"42"};
    std::string* s1 = createT<std::string>(s); // an lvalue
    
    // calling with move
    std::string* s2 = createT<std::string>(std::move(s)); // a xvalue

    // calling with const string
    const std::string cs{"42"};
    
    const std::string* s3 = createT<const std::string>(cs); // an lvalue


    return 0;
}
