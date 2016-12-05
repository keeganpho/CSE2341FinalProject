#ifndef VARIABLE_H
#define VARIABLE_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "hashtable.h"
#include "file.h"

class Variable
{
public:
    Variable(); //Constructor
    Variable(File,DSString,DSString); //Constructor with info passed
    File& getFile(); //Returns file
    DSString& getName(); //Returns name of variable
    bool operator== (char*); //Overloaded Equality Operator with a pointer
                                //that compares variable name

private:
    File file;
    DSString name;
    DSString type;

};

#endif // VARIABLE_H
