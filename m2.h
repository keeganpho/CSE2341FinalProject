//Comments
#ifndef M2_H
#define M2_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "file.h"
#include "metricanalyzer.h"

using namespace std;

//Inherits from MetricAnalyzer
class m2:public MetricAnalyzer
{
public:
    m2(); //Constructor
    virtual int process(File&);
    virtual void displayMetric();
    virtual int getMetric();
    int blockComment(int);

private:
    int metric;
    int numComments; //Comment lines
    double ratio;

};

#endif // M2_H
