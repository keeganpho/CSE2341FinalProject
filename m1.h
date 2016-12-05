//Line length
#ifndef M1_H
#define M1_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "file.h"
#include "metricanalyzer.h"

using namespace std;

//Inherits from MetricAnalyzer
class m1:public MetricAnalyzer
{
public:
    m1(); //Constructor
    virtual int process(File&);
    virtual void displayMetric();
    virtual int getMetric();

private:
    int metric;
    myVector<int> longLines;
    double average;

};

#endif // M1_H
