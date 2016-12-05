//Comments
#include "m2.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

//Constructor
m2::m2()
{

}

int m2::process(File& file)
{
    MetricAnalyzer::process(file);
    DSString temp;
    int x=0; //Line
    int curr=0;
    while(x < numLines)
    {
        temp = lines.get(x);
        curr=0;
        while((curr-1) < temp.getLength())
        {
            //Start of block comment
            if(temp[curr] == '/' && temp[curr+1] == '*')
            {
                x++;
                x = blockComment(x);
                numComments++;
                break;
            }
            //Comment
            else if(temp[curr] == '/' && temp[curr+1] == '/')
            {
                numComments++;
                break;
            }
            //Not a block comment
            else
                curr++;
        }
        x++; //Increment lines index
    }

    ratio = numComments/numLines;
    ratio = ratio*100;
    cout << "The ratio of comment lines to total lines is: ";
    cout << numComments << ":" << numLines << " or " << ratio << "%" << endl;

    //Less than 10%
    if(ratio < 10)
    {
        metric+=10;
    }
    //Greater than %20
    if(ratio > 20)
    {
        metric+=10;
    }

    return 2;

}

void m2::displayMetric()
{
    cout << "Metric 2: Comments" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Score: " << metric << endl;
    cout << "The average percentage of comments per file is " << "___" << endl;
    cout << "This file has " << numLines << " lines of code." << endl;
    cout << "There are " << numComments << " lines of comments. " << endl;
    cout << "Percentage: " << ratio << "% comments" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "\n\n";

}

int m2::getMetric()
{
    return metric;

}

int m2::blockComment(int l)
{
    DSString temp;
    int curr;
    temp = lines.get(l);
    while((curr-1) < temp.getLength())
    {
        //End of block comment
        if(temp[curr] == '*' && temp[curr+1] == '/')
        {
            return l;
        }
        //Not */
        else
            curr++;
    }
    numComments++;
    l++;
    blockComment(l);

}
