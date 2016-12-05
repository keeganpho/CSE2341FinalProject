//Brackets are on own lines
#ifndef M4_H
#define M4_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "file.h"
#include "metricanalyzer.h"

using namespace std;

//Inherits from MetricAnalyzer
class m4:public MetricAnalyzer
{
public:
    m4(); //Constructor
    virtual int process(File&);
    virtual void displayMetric();
    virtual int getMetric();

private:
    int metric;
    int countOnlyBracket;
    int countNotOnlyBracket;

};

#endif // M4_H
