//Primitive Variables- # times used
#include "m3.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <ctype.h>

using namespace std;

//Constructor
m3::m3()
{

}

int m3::process(File& file)
{
    MetricAnalyzer::process(file);
    DSString temp;
    char* name;
    int tempPos;
    int pos; //First position of desired

    for(int i=0; i<numLines; i++)
    {
        temp = lines.get(i);

        pos = findInt(temp);
        //If it does exist
        if(pos != -1)
        {
            //First character after "int"
            tempPos = pos+3;
            //Now goes to first non-Space char after "int"
            while(temp[tempPos] == ' ')
            {
                tempPos++;
            }
            int x=0; //Index of name
            while(isalpha(temp[tempPos]))
            {
                name[x] = temp[tempPos];
                tempPos++;
                x++;
            }

            //Insert into hashTable
            //If key exists, then increment value
            if(list.getItemByKey(name) != -1)
            {
                list.incrementValue(name);
                totalVariables++;
            }
            //Else, insert name into hashTable with value of 1
            else
            {
                list.insert(name,1);
                varNames.pushBack(name);
                newVariables++;
            }

        }

        pos = findDouble(temp);
        //If it does exist
        if(pos != -1)
        {
            //First character after "double"
            tempPos = pos+3;
            //Now goes to first non-Space char after "double"
            while(temp[tempPos] == ' ')
            {
                tempPos++;
            }
            int x=0; //Index of name
            while(isalpha(temp[tempPos]))
            {
                name[x] = temp[tempPos];
                tempPos++;
                x++;
            }

            //Insert into hashTable
            //If key exists, then increment value
            if(list.getItemByKey(name) != -1)
            {
                list.incrementValue(name);
                totalVariables++;
            }
            //Else, insert name into hashTable with value of 1
            else
            {
                list.insert(name,1);
                newVariables++;
            }

        }

        pos = findFloat(temp);
        //If it does exist
        if(pos != -1)
        {
            //First character after "float"
            tempPos = pos+3;
            //Now goes to first non-Space char after "float"
            while(temp[tempPos] == ' ')
            {
                tempPos++;
            }
            int x=0; //Index of name
            while(isalpha(temp[tempPos]))
            {
                name[x] = temp[tempPos];
                tempPos++;
                x++;
            }

            //Insert into hashTable
            //If key exists, then increment value
            if(list.getItemByKey(name) != -1)
            {
                list.incrementValue(name);
                totalVariables++;
            }
            //Else, insert name into hashTable with value of 1
            else
            {
                list.insert(name,1);
                newVariables++;
            }

        }

        pos = findLong(temp);
        //If it does exist
        if(pos != -1)
        {
            //First character after "long"
            tempPos = pos+3;
            //Now goes to first non-Space char after "long"
            while(temp[tempPos] == ' ')
            {
                tempPos++;
            }
            int x=0; //Index of name
            while(isalpha(temp[tempPos]))
            {
                name[x] = temp[tempPos];
                tempPos++;
                x++;
            }

            //Insert into hashTable
            //If key exists, then increment value
            if(list.getItemByKey(name) != -1)
            {
                list.incrementValue(name);
                totalVariables++;
            }
            //Else, insert name into hashTable with value of 1
            else
            {
                list.insert(name,1);
                newVariables++;
            }

        }

        pos = findChar(temp);
        //If it does exist
        if(pos != -1)
        {
            //First character after "char"
            tempPos = pos+3;
            //Now goes to first non-Space char after "char"
            while(temp[tempPos] == ' ')
            {
                tempPos++;
            }
            int x=0; //Index of name
            while(isalpha(temp[tempPos]))
            {
                name[x] = temp[tempPos];
                tempPos++;
                x++;
            }

            //Insert into hashTable
            //If key exists, then increment value
            if(list.getItemByKey(name) != -1)
            {
                list.incrementValue(name);
                totalVariables++;
            }
            //Else, insert name into hashTable with value of 1
            else
            {
                list.insert(name,1);
                newVariables++;
            }

        }

        pos = findBool(temp);
        //If it does exist
        if(pos != -1)
        {
            //First character after "double"
            tempPos = pos+3;
            //Now goes to first non-Space char after "double"
            while(temp[tempPos] == ' ')
            {
                tempPos++;
            }
            int x=0; //Index of name
            while(isalpha(temp[tempPos]))
            {
                name[x] = temp[tempPos];
                tempPos++;
                x++;
            }

            //Insert into hashTable
            //If key exists, then increment value
            if(list.getItemByKey(name) != -1)
            {
                list.incrementValue(name);
                totalVariables++;
            }
            //Else, insert name into hashTable with value of 1
            else
            {
                list.insert(name,1);
                newVariables++;
            }

        }
    }

    calculate();

    return 3;

}

void m3::displayMetric()
{
    cout << "Metric 3: Primitive Variables" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Score: " << metric << endl;
    cout << "This metric checks if variables are being used more than once in a file. " << endl;
    cout << "This ensure that variables are not created without a purpose. " << endl;
    cout << "It counts how many times a variable is being used in a file. " << endl;
    cout << "There are " << newVariables << " in this file. " << endl;
    cout << "The average amount of times a variable is being used throughout this file is " <<
            average << " times. " << endl;
    checkList();
    cout << "This file contains " << usedOnce << " variables that are not used. " << endl;
    cout << "Bad variables: " << endl;
    for(int i=0; i<usedOnce; i++)
    {
        cout << varOnce.get(i) << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << "\n\n";

}

void m3::checkList()
{
//    int tempKey;
//    for(int i=0; i<list.getLength(); i++)
//    {
//        tempKey = list.getItemByKey(varNames[i]);
//        if(tempKey == 1)
//        {
//            usedOnce++;
//            varOnce.pushBack(varNames[i]);
//        }

//    }

}

int m3::getMetric()
{
    return metric;

}

//Find "int", if exists
int m3::findInt(DSString& string)
{
  int len = 3;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "int")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find "double", if exists
int m3::findDouble(DSString& string)
{
  int len = 6;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "double")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find substring "float", if exists
int m3::findFloat(DSString& string)
{
  int len = 5;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "float")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find substring "long", if exists
int m3::findLong(DSString& string)
{
  int len = 4;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "long")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find substring "short", if exists
int m3::findShort(DSString& string)
{
  int len = 4;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "short")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find substring "byte", if exists
int m3::findByte(DSString& string)
{
  int len = 4;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "byte")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find substring "char", if exists
int m3::findChar(DSString& string)
{
  int len = 4;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "char")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

//Find substring "bool", if exists
int m3::findBool(DSString& string)
{
  int len = 4;
  int strLen = string.getLength();
  int f = 0;
  int pos;
  DSString b = "";

  for(int i=0; i < (strLen-len); i++)
  {
    for(int j=i,k=0; j < (i+len); j++,k++)
      b[k] = string[j];

    if(b == "bool")
    {
      f = 1;
      pos = i;
      break;
    }
  }
  if(f == 1)
    return pos;
  else
    return -1;

}

void m3::calculate()
{
    if(newVariables != 0)
        average = totalVariables / newVariables;
}
