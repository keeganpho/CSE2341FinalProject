#include "metricanalyzer.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

//Constructor
MetricAnalyzer::MetricAnalyzer()
{
    name = nullptr;
    type = 0;
    numLines = 0;
    totalMetric = 0;

}

//Processes all metrics for a certain file
int MetricAnalyzer::process(File& file)
{
    name = file.getName();
    type = file.getFileType();

    return 0;

}

//Open and parse file
void MetricAnalyzer::openFile(char* file)
{
    ifstream fin;
    fin.open(file);

    char buffer[200];
    DSString temp;

    if(!fin.is_open())
    {
        cout << "Error: File cannot open. " << endl;
        return;
    }

    while(!fin.eof())
    {
        //fin.clear();
        numLines++;
        //Read line into buffer
        fin.getline(buffer,200);
        //Add to vector of lines
        DSString temp(buffer);
        lines.pushBack(temp);
    }

}

//Return each metric's number
void MetricAnalyzer::displayMetric()
{
    cout << "This is MetricAnalyzer's method" << endl;

}

int MetricAnalyzer::getMetric()
{
    return 0;

}
