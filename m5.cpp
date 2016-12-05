//Variable Names
#include "m5.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

//Constructor
m5::m5()
{

}

int m5::process(File& file)
{
    m3::process(file);
    average = 0;
    int tempSize;
    char* temp;
    for(int i=0; i<varNames.getSize(); i++)
    {
        tempSize = strlen(varNames.get(i));
        average = average + tempSize;
        average = average / 2;
        //If variable size is greater than 10
        if(tempSize > 10)
        {
            metric += 10;
            longVar.pushBack(i);
        }
    }

    return 5;

}

void m5::displayMetric()
{
    cout << "Metric 5" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Score: " << metric << endl;
    cout << "The average length of variable names is " <<
            average << " characters. " << endl;
    cout << "Good variable names are under the length of 10. " << endl;
    cout << "There are " << longVar.getSize() << " brackets that are too long. " << endl;
    cout << "Change the names of the following variables: " << endl;
    for(int i=0; i<longVar.getSize(); i++)
    {
        int temp = longVar.get(i);
        cout << varNames.get(temp) << endl;
    }
    cout << "----------------------------------------------" << endl;
    cout << "\n\n";
}
int m5::getMetric()
{
    return metric;

}
