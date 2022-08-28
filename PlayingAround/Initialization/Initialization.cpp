#include <iostream>
#include <array>

class Data
{
private:
    float* variables[2];
public:

    Data(float data)
    {
        std::cout << "Data class single variable data is: " << std::endl << data << std::endl;
    };

    Data(std::string name, std::string description, std::initializer_list<float> variablesGiven)
    {
        size_t size = variablesGiven.size();

        if(size > 0){
            std::copy(variablesGiven.begin(), variablesGiven.end(), *variables);
            
            std::cout << "Data class multiple variables data is: " << std::endl;

            std::cout << "Name: " << name << std::endl <<
                        "Description: " << description << std::endl <<
                        "Data: [ ";    

            for (size_t i = 0; i < size; i++)
            {
                // [] comes before *. () around array to prevent 
                std::cout << (*variables)[i] << " ";
            }
            
            std::cout << "]" << std::endl; 
        }
        else{
            std::cout << "Not inital data given!" << std::endl;
        };

   
    };

    ~Data(){};
};

struct VariableHolder{
    struct HolderLibrary {
        std::string name;
        std::string description;
        std::initializer_list<float>* variables; 
    } library;
};


int main()
{
    // What is the difference between using () and {} in constructor?
    Data d1{5.3};
    Data d2(2.4);
    Data d3("Hello", "World!", std::initializer_list<float>{5.33, 3.14});
    
    std::string vhName = "Hold";
    std::string vhDescription = "My Beer";
    std::initializer_list<float> vhData = {2.2, 2.5};

    VariableHolder vh1 {
        vhName, vhDescription, &vhData
    };

    std::cout << "variableHolder info: " << std::endl;

    std::cout << "Name: " << vh1.library.name << std::endl <<
                 "Description: " << vh1.library.description << std::endl <<
                 "variables: [ ";
    for (auto element : *vh1.library.variables)
    {
        std::cout << element << " ";
    }
    
    std::cout << "]" << std::endl;
}
