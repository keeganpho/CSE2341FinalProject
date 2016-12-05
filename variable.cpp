#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "variable.h"

Variable::Variable()
{

}

//Constructor with info passed
Variable::Variable(File f,DSString,DSString)
{
    file = f;

}

//Returns file
File& Variable::getFile()
{
    return file;

}

//Returns name of variable
DSString& Variable::getName()
{
    return name;

}

//Overloaded Equality Operator with a pointer
//that compares variable name
bool Variable::operator== (char* desired)
{
    bool checkName;
    checkName = (name==desired);
    return checkName;

}
