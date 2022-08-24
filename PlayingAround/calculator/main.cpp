#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    bool running = true;
    
    cout << "Calculator started!" << endl;
    while(running){
        
        const int inputMaxLength = 10;
        const char* expectedInput = "q";
        char key[inputMaxLength];
        
        cin.getline(key, inputMaxLength);

        if(key == expectedInput){
            running = false;
        }
    }

    return 0;
}
