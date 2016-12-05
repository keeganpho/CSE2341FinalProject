//Primitive Variables- # times used
#ifndef M3_H
#define M3_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "file.h"
#include "metricanalyzer.h"
#include "hashtable.h"
#include "avltree.h"

using namespace std;

//Inherits from MetricAnalyzer
class m3:public MetricAnalyzer
{
public:
    m3(); //Constructor
    virtual int process(File&);
    virtual void displayMetric();
    virtual int getMetric();
    int findInt(DSString&); //Find "int", if exists
    int findDouble(DSString&); //Find "double", if exists
    int findFloat(DSString&); //Find "float", if exists
    int findLong(DSString&); //Find "long", if exists
    int findShort(DSString&); //Find "short", if exists
    int findByte(DSString&); //Find "byte", if exists
    int findChar(DSString&); //Find "char", if exists
    int findBool(DSString&); //Find "bool", if exists
    void calculate();
    void checkList();

protected:
    int metric;
    HashTable<char*,int> list;
    myVector<char*> varNames;
    myVector<char*> varOnce;
    int totalVariables;
    int newVariables;
    double average;
    int usedOnce;

};

#endif // M3_H
