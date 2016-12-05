#ifndef DSSSTRING
#define DSSSTRING

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>

using namespace std;

class DSString
{

    private:

        char* str;
        int length;
        int cap;
        char error = '\0';


    public:

        DSString(); //Constructor
        DSString(const char*); //Copy Constructor with a pointer
        DSString(const DSString&); //Copy Constructor
        int getLength(); //Returns length of string
        DSString& operator= (char*); //Overloaded Assignment Operator
        DSString& operator= (const DSString&); //Overloaded Assignment Operator reference
        DSString operator+ (const char*); //Overloaded Addition Operator
        DSString operator+ (DSString&); //Overloaded Addition Operator reference
        bool operator== (char*); //Overloaded Equality Operator with a pointer
        bool operator== (const DSString&); //Overloaded Equality Operator reference
        bool operator!= (char*); //Overloaded Inequality Operator with a pointer
        bool operator!= (const DSString&); //Overloaded Inequality Operator with reference
        bool operator> (const DSString&); //Overloaded Greater Than Operator with reference
        bool operator< (const DSString&); //Overloaded Less Than Operator with reference
        char& operator[] (const int); //Returns element in certain position

        int size(); //Returns the length of the string
        DSString& substring(int, int); //Returns a section of string
        char* c_str(); //Returns character pointer

        DSString& toUpper(); //Converts Lower to Uppercase
        DSString& toLower(); //Converts Upper to Lowercase

        void readFile();


        friend std::ostream& operator<< (std::ostream&, const DSString&); //Outstream
        friend std::istream& operator>> (std::istream&, DSString&); //Instream

        ~DSString(); //Destructor

};


#endif
