#include <iostream>

// < c++17
// End marker
void ya_printf_old(const char *s)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                throw std::runtime_error("invalid format string: missing arguments");
            }
        }
        std::cout << *s++;
    }
}

// Variadic function
template<typename T, typename... Args>
void ya_printf_old(const char *s, T value, Args... args)
{
    while (*s) {
        if (*s == '%') {
            if (*(s + 1) == '%') {
                ++s;
            }
            else {
                std::cout << value;
                ya_printf_old(s + 1, args...);
                // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
    throw std::logic_error("extra arguments provided to printf");
}

// > c++17
// End marker
// Function has to be defined first otherwise template ya_printf() cant find it...
void ya_printf(const char *s){};
template<typename T, typename... Args>
void ya_printf(const char *s, T value, Args... args){};

int main(int argc, char const *argv[])
{
    std::string s1 = "55";
    std::string s2 = "81";

    ya_printf("Sensor values %d, %d", s1, s2);
    return 0;
}
