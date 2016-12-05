//Brackets are on own lines
#include "m4.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

//Constructor
m4::m4()
{

}

int m4::process(File& file)
{
    MetricAnalyzer::process(file);
    DSString temp;
    int x=0; //Line
    int curr=0;
    bool bracket = false;
    bool nonBracket = false;

    while(x < numLines)
    {
        temp = lines.get(x);
        curr=0;
        while(curr < temp.getLength())
        {
            //Character is alpha/number
            if(isalnum(temp[curr]))
            {
                nonBracket = true;
                curr++;
            }
            //Character is a space
            else if(temp[curr] == ' ')
            {
                curr++;
            }
            //Character is bracket
            else if(temp[curr] == '{' || temp[curr] == '}')
            {
                bracket = true;
                curr++;
            }
            //Character is other symbol
            else
            {
                nonBracket = true;
                curr++;
            }
        }
        //Only bracket in the line
        if(bracket && !nonBracket)
        {
            countOnlyBracket++;
        }
        //Bracket and other characters in line
        else
        {
            countNotOnlyBracket++;
        }
    }

    return 4;

}

void m4::displayMetric()
{
    cout << "Metric 4: { }" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Score: " << metric << endl;
    cout << "This metric checks if a brace {} is used on its own line. " << endl;
    cout << "{} should be on their own line to improve readibility. " << endl;
    cout << "There are " << countNotOnlyBracket <<
            " that do not follow this rule. " << endl;
    cout << "\n\n";

}

int m4::getMetric()
{
    return metric;

}
