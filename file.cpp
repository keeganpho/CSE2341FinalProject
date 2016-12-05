#include "file.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

//Constructor
File::File()
{

}

//Constructor with passed info
File::File(char* n, int t)
{
    name = n;
    type = t;

}

//Return file's name
char* File::getName()
{
    return name;

}

//Return file's type
int File::getFileType()
{
    return type;
    //1: .cpp
    //2: .h

}

//Overloaded assignment operator
//File& File::operator=(File& rhs)
//{
//    name = rhs.getName();
//    type = rhs.getFileType();
//    return *this; //Return address

//}

