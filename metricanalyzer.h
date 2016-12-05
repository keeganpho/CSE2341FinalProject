#ifndef METRICANALYZER_H
#define METRICANALYZER_H

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "file.h"
#include "vector.h"

using namespace std;

//Base class for Metrics
class MetricAnalyzer
{

//Virtual Functions
public:
    MetricAnalyzer(); //Constructor
    virtual int process(File&); //Processes all metrics for a certain file
    void openFile(char*);
    int getMetric();
    virtual void displayMetric();

protected:
    char* name;
    int type;
    myVector<DSString> lines;
    int numLines;
    int totalMetric;

};

#endif // METRICANALYZER_H
