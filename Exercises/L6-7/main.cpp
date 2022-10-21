#include "file.cpp"

int main(int argc, char const *argv[])
{
    const char* fileName = "file.txt";
    const char* mode = "r+";

    File file(fileName, mode);
    
    file.Read();
    file.Write("Another Hello");
    return 0;
}
