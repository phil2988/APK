#include <iostream>

/*
    Enables the possibility to create objects of user-defined types from integers,
    floats, chars and string literals by defining user-defined suffixes

    All userdefined literals must have an '_'
*/

// used with custom type
struct mytype
{
    mytype ( unsigned long long m): m(m) { }
    unsigned long long m;
};

// used as conversion
constexpr long double operator"" _deg ( long double deg )
{
    return deg * 3.141592/180;
}

// used for sideeffects
void operator"" _print ( const char* str )
{
    std::cout << str;
}

mytype operator"" _mytype ( unsigned long long n )
{
    return mytype(n);
}

int main(int argc, char const *argv[])
{
    double x = 90.0_deg;
    std::cout << std::fixed << x << '\n';
    
    mytype y = 123_mytype;
    std::cout << y.m << '\n';
    
    0x123ABC_print;
    return 0;
}
