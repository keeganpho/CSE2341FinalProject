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

    if(type == 1)
        cout << "This is a .cpp file. " << endl;
    else
        cout << "This is a .h file. " << endl;

    return 0;

}

//Open and parse file
void MetricAnalyzer::openFile(char* file)
{
    //Should this call parent openFile(file) ?
    ifstream fin;
    fin.open(file);

    char buffer[200];

    if(!fin.is_open())
        cout << "Error: File cannot open. " << endl;

    while(!fin.eof())
    {
        numLines++;
        //Read line into buffer
        fin.getline(buffer,200);
        //Add to vector of lines
        DSString temp(buffer);
        lines.add(temp);
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
