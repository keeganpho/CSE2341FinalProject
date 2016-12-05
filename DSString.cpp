#include <cstring>
#include <iostream>
#include "DSString.h"
#include <stdexcept>
#include <fstream>

using namespace std;

//Constructor
DSString::DSString():str('\0'), length(0), cap(0)
{
    //str = new char[10];
}

//Copy Constructor with a passed char pointer
DSString::DSString(const char * input)
{

    length = strlen(input) + 1; //Length will be length of input plus one for the nullptr
    cap = length+25;
    str = new char[cap]; //Dynamicall allocate
    for(int x = 0; x < length; x++)
        str[x] = input[x]; //Putting elements into str
    str[length] = '\0';

}

//Copy Constructor
DSString::DSString(const DSString& S)
{

    if(S.str != '\0') //If element is not empty
    {
        str = new char[S.cap]; //Dynamically allocate
        this-> cap = S.cap; //New capacity
        this-> length = S.length + 1; //New length
        for (int x=0; x<length; x++)
            str[x] = S.str[x]; //Copying elements into str
        str[length] = '\0';

    }

}

//Returns length of string
int DSString::getLength()
{
    return length;

}

//Overloaded Assignment Operator with char pointer
DSString& DSString::operator= (char* rhs)
{
    int s = strlen(str);
    memcpy(str
           ,rhs,s+1);
    length = s;

    return *this;

//    if(str != '\0') //If left isn't empty
//         delete[] str; //Delete elements
//    if(rhs != '\n') //If rhs isn't empty
//    {
//        int clength=0; //Length of rhs
//        int i=0; //Indexer
//        while(rhs[i] != '\n') //While rhs has elements
//        {
//            clength++; //Length of rhs
//            i++; //Indexer
//        }

//        this-> str = new char [clength]; //Dynamically allocate to new length

//        for(int x=0; x<clength; x++)
//            str[x] = rhs[x]; //Put new elements into str
//    }

//    return *this; //Return address
}

//Overloaded assignment operator
DSString& DSString::operator= (const DSString& rhs)
{
    length = rhs.length;
    //delete [] str;
    str = new char[length];
    for(int i = 0 ; i < (length -1);i++)
    {
        str[i] = rhs.str[i];
    }
    str[(length -1)] = '\0';
    return *this;

}

//Overloaded Addition Operator
DSString DSString::operator+ (const char* rhs)
{
    int tempLength = strlen(rhs);
    DSString addString = new char[length + tempLength + 1];
    char* temp = new char[length + tempLength + 1];

    for(int i = 0; i< this-> length; i++)
    {
        temp[i] = this-> str[i];
    }

    int k=0;
    for(int n = this-> length; n< length + tempLength + 1; n++)
    {
        temp[n] = this->str[k];
        k++;
    }

    temp[length + tempLength] = '\0';
    addString.length = length + tempLength + 1;
    addString.str = new char [length + tempLength + 1];
    for(int x = 0; x<length + tempLength; x++)
    {
        addString.str[x] = rhs[x];
    }

    return addString; //Return new string

}

//Overloaded Addition Operator
DSString DSString::operator+ (DSString& rhs)
{
    int size = (this->getLength() - 1) + (rhs.getLength() - 1) + 1;
    char* temp = new char[size];
    for(int i = 0; i<(this->getLength() - 1); i++)
    {
        temp[i] = this->str[i];
    }
    int j = 0;
    for(int k = (this->getLength() - 1), j=0; k < (size-1); k++, j++)
    {
        temp[k] = rhs.c_str()[j];
    }

    if(temp[size -1 ] != '\0')
    {
        temp[size -1] = '\0';
    }

    DSString S3(temp);
    delete[] temp;
    return S3;

}

//Overloaded Equality Operator with char pointer
bool DSString::operator== (char* rhs)
{
    bool equals = false;
    int counter = 0;

    while(rhs[counter] != '\0')
    {
        counter++;
    }

    if(counter != this-> length)
        equals = false;
    else
    {
         for(int i=0; i<counter; i++)
         {
             if(rhs[i] != this-> str[i])
                 equals = false;
             else
                 equals = true;
         }
         return equals;
    }

}

//Overloaded Equality Operator
bool DSString::operator== (const DSString& rhs)
{
    bool equals = false;
    if (this-> length == rhs.length) //Both strings of same length
    {
        int i=0;
        while(i != length)
        {
            if(this-> str[i] != rhs.str[i]) //At first instance of not matching characters, returns false
                equals = false;
            else
                equals = true;
            i++;
        }
        equals = true;
    }
    else //Both strings of different length, not equal
        equals = false;
    return equals;
}

//Overloaded Inequality Operator with char pointer
bool DSString::operator!= (char* rhs)
{
    bool notEqual;
    notEqual = !(this->str == rhs);
    return notEqual;

}

//Overloaded Inequality Operator with refeerence
bool DSString::operator!= (const DSString& rhs)
{
    bool notEqual;
    notEqual = !(this->str == rhs.str);
    return notEqual;
}

//Overloaded Greater Than Operator
bool DSString::operator> (const DSString& rhs)
{

    if (strcmp(str, rhs.str) < 0) //This str has a lesser value than rhs
        return false;
    else //This str has a greater value than rhs
        return true;
}

//Overloaded Less Than Operator
bool DSString::operator< (const DSString& rhs)
{

    if (strcmp(str, rhs.str) < 0) //This str has a lower value than rhs
        return true;
    else //This str has a greater value than rhs
        return false;
}

//Returns element in specific position
char& DSString::operator[](const int x)
{
    if(x<0) //If index is negative
    {
        int size = this->length;
        return str[size+x-1]; //Returns index number from back
    }
    else //Index is positive
        return str[x];

}

//Returns the length of the character pointer
int DSString::size()
{
    int x=0;
    while( str[x] != '\0') //Counts until there is a null
        x++;
    return x;

}

//Returns a section of the String
DSString& DSString::substring(int start, int end)
{
    DSString temp;
    int n=0;
    int size = 0;
    //DSString sub;
    if( end >= 0 && end>start && start >= 0) //If end index is positive and less than start index and start indec is positive
    {
        size = end - start;
        temp.str = new char[size];
        for (int i = start; i < end; i++) //Add from start index to end index
        {
            temp.str[n] = str[i]; //Adding deired elements into temp string
            n++;
        }
        return temp;

    }

    else if(end<0 && start >= 0) //If end index is negative and start index is positive
    {
        size = (length+end) - start;
        temp.str = new char[size];
        for (int i = start; i < length + end - 1; i++) //Add from start to the length of string minus the end index
        {
            temp.str[n] = str[i]; //Adding deired elements into temp string
            n++;
        }
        return temp;

    }

}

//Returns character pointer
char* DSString::c_str()
{

    return str;

}

//Convert Lower to Uppercase
DSString& DSString::toUpper()
{
    DSString temp;
    int n=0;
    int size=this->length;
    char* c = str;
    int i=0;
    while(c[i] != '\0')
    {
        if((int)c[i]>96 &&(int) c[i]<123)
            c[i] = (int)c[i]-32;
        i++;
    }
    temp.str = new char [size];
    for(int i=0; i<size; i++)
    {
        temp.str[i] = c[i];
    }

    return temp;

}

//Convert Upper to Lowercase
DSString& DSString::toLower()
{
    char* c = str;
    int i=0;
    DSString temp;
    int size=this->length;
    while(c[i] != '\0')
    {
        if((int)c[i]>64 && (int)c[i]<91)
            c[i] = (int)c[i]+32;
        i++;
    }
    temp.str = new char [size];
    for(int i=0; i<size; i++)
    {
        temp.str[i] = c[i];
    }

    return temp;
}

//Outstream
ostream& operator<< (ostream& os, const DSString& s)
{

    os << s.str;
    return os;

}

istream& operator>> (istream& in, DSString& s)
{
    char temp[50];
    in >> temp;
    s = DSString(temp);
    return in;

}

//Destructor
DSString::~DSString()
{
    if(length > 0)
        delete [] str; //Deletes pointer array

}




