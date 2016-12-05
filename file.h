#ifndef FILE_H
#define FILE_H

#include "DSString.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

class File
{
public:
    File(); //Constructor
    File(char*,int); //Constructor with passed name and type
    char* getName(); //Return file's name
    int getFileType(); //Return file's type
    //File& operator=(File&);

private:
    char* name;
    int type;
        //1: .cpp
        //2: .h
};

#endif // FILE_H
