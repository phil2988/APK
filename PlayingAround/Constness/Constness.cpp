#include <iostream>

class Constness
{
private:
    int* data_;
    const char* notUsed_; 
public:
    Constness(int* data = new int(0)): data_(new int(*data)), notUsed_("h") {

    };
    ~Constness(){};
    
    int* GetNumberConst() const {
        return data_;
    }

    int* GetNumber(){
        return data_;
    }

    auto GetNumberAuto(){
        return data_;
    }

    auto GetNumberDecltypeAuto(){
        decltype(auto) number = data_;
        return number;
    }

    auto GetAddedNumberLambda(int x, int y){
        // [ capture ] ( params ) -> ret { statements }
        return [x, y]() -> int {
            return x + y;

            // Add () after lambda if it is used as a function returning stuff
        }();
    }
};


int main(int argc, char const *argv[])
{
    /* Ok notation*/
    int i = 42;
    const int ci = 43;              /* const int */
    int * const cpi = &i;           /* const pointer to int */
    const int * pci = &ci;          /* pointer to const int */
    const int * const cpci = &ci;   /* const pointer to const int */
    
    /* Better notation*/
    int n = 42;
    int const cn = 43;              /* const int */
    int * const cpn = &i;           /* const pointer to int */
    int const * pcn = &ci;          /* pointer to const int */
    int const * const cpcn = &ci;   /* const pointer to const int */

    int numb = 420;
    Constness c1(&numb);

    std::cout << "normal class normal function: " << *c1.GetNumber() << std::endl;
    std::cout << "normal class const function: " << *c1.GetNumberConst() << std::endl;

    int numb2 = 69;
    const Constness c2(&numb2);

    std::cout << "const class normal function: " /* << *c2.GetNumber() */ << std::endl; // Gives error because function is not const
    std::cout << "const class const function: " << *c2.GetNumberConst() << std::endl;
    
    std::cout << "normal class auto function: " << *c1.GetNumberAuto() << std::endl;
    std::cout << "normal class decltype auto function: " << *c1.GetNumberDecltypeAuto() << std::endl;
    
    Constness c3;
    int value = c3.GetAddedNumberLambda(5, 10);
    int value2 = [](int a = 15, int b = 11){
        return a - b;
    }();
    std::cout << "using lambda in class to add 5 to 10! result: " << value << std::endl;
    std::cout << "using lambda not in class to sub 11 from 15! result: " << value2 << std::endl;
    return 0;
}

