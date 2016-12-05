#ifndef M5_H
#define M5_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "file.h"
#include "m3.h"

using namespace std;

//Inherits from MetricAnalyzer
class m5:public m3
{
public:
    m5(); //Constructor
    virtual int process(File&);
    virtual int getMetric();
    virtual void displayMetric();

private:
    int metric;
    double average;
    LinkedList<int> shortVar;

};

#endif // M5_H
