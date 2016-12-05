//Line length
#include "m1.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

//Constructor
m1::m1()
{


}

//Check line length
int m1::process(File& file)
{
    MetricAnalyzer::process(file);
    int lineLength;
    int total;

    //For each line in the file
    for(int i=0; i<numLines; i++)
    {
        lineLength = lines[i].getLength();
        //If line is greater than 120, increase metric by 10
        if(lineLength > 120)
        {
            metric+=10;
            longLines.add(i);
        }
        //If greater that 150, increase metric by 10 again
        if(lineLength > 150)
        {
            metric+=10;
        }
        total += lineLength;
    }
    if(numLines != 0)
        average = total / numLines;

    return 1;

}

void m1::displayMetric()
{
    cout << "Metric 1: Line length" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Score: " << metric << endl;
    cout << "'Good code' is 80-120 characters. " << endl;
    cout << "The average number of characters for each line " <<
            "in this file is " << average << " characters. " << endl;
    cout << "There are " << longLines.getSize() <<
            " lines that are over 120 characters: " << endl;
    for(int x=0; x<longLines.getSize(); x++)
    {
        cout << "Line " << longLines.get(x) << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << "\n\n";


}

int m1::getMetric()
{
    return metric;

}


