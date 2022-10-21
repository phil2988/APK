#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <iterator>
#include <vector>

class File
{
private:
    char _mode[3];
    FILE *_fp;
    bool isWritable();
public:
    File(const char*, const char*);
    ~File();
    std::string Read();
    void Write(const char*);
};

File::File(const char * filename, const char * mode)
    : _mode("")
{
    strcat(this->_mode, mode);
    strcat(this->_mode, "t");

    std::cout << "Opening file " << filename << " in mode " << this->_mode << std::endl;

    _fp = fopen(filename, this->_mode); 
}

File::~File()
{
    fclose(this->_fp);
}

std::string File::Read(){
    char buff[255] = "";
    fgets(buff, 255, this->_fp);
    std::cout << "Reading content of file:" << std::endl;
    std::cout << buff << std::endl;
    return buff;
}
 
void File::Write(const char* newText){
    if(!isWritable()){
        std::cout << "File is not in a mode which allows writing!" << std::endl;
        return;
    }
    std::cout << "Writing to file..." << std::endl;
}

bool File::isWritable(){
    return 
        strstr(this->_mode, "r+") && 
        strstr(this->_mode, "r+") && 
        strstr(this->_mode, "r"); 
}
