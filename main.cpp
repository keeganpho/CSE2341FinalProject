#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "metricanalyzer.h"
#include <dirent.h>
#include "file.h"
#include "m1.h"
#include "m2.h"
#include "m3.h"
#include "m4.h"
#include "m5.h"

using namespace std;

//True- run tests   False- no tests run
#define TEST false

myVector<File> files;
void searchDir(char*); //Search through directory to extract and files to vector
int numFiles;

int runCatchTests(int argc, char* const argv[])
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run(argc, argv);

}

int main(int argc, char* argv[])
{
    int score;

    const int numMetrics = 5;
    MetricAnalyzer* metrics[numMetrics];
    metrics[0] = new m1();
    metrics[1] = new m2();
    metrics[2] = new m3();
    metrics[3] = new m4();
    metrics[4] = new m5();

    numFiles = 0; //Number of files in directory

    ofstream output(argv[3]);
    if(!output)
    {
        cerr << "Error: unable to open output file. " << endl;
    }

    //Opens directory containing multiple files
    searchDir(argv[2]);

    DSString outType(argv[1]);
    DSString directory(argv[2]);
    DSString fileName;
    cout << fileName << endl;

    output << "There are " << numFiles << " files in this path directory." << endl;

    //For all the files that exists in directory
    for(int f=0; f<numFiles; f++)
    {
        DSString temp(files.get(f).getName());
        fileName = directory + temp;
        output << "File " << f+1 << ": " << fileName << endl;

        //For the 5 metrics
        for(int i=0; i<numMetrics; i++)
        {
            //Open and parse the individual file
            metrics[i]->openFile(fileName.c_str());
            //Perform specific metric on individual file
            metrics[i]->process(files.get(f));

            //Verbose
            if(outType == "-v")
            {
                metrics[i]->displayMetric();
                score += metrics[i]->getMetric();
            }
            //Brief
            else
                cout << metrics[i]->getMetric() << endl;
            output << "Metric " << i+1 << " is complete." << endl;
            output << "\n\n";
        }

        output << fileName << " had a total score of " << score << endl;

    }


    return 0;
}

//Search through directory to extract and files to vector
void searchDir(char* arg)
{
    struct dirent *pDirent;
    DIR *pDir;
    int type;

    pDir = opendir(arg);

    if (pDir == NULL)
    {
        cerr << "Cannot open directory. " << endl;
        return;
    }
    while ( pDirent = readdir(pDir) )
    {
        char* fileName = (pDirent->d_name);

        if( (strcmp(fileName, ".") != 0) && (strcmp(fileName, "..") != 0) )
        {
            if(fileName[strlen(fileName)-1] == 'p') //.cpp file
            {
                numFiles++;
                type=1;
                File f(fileName,type);
                files.pushBack(f);
            }
            else if(fileName[strlen(fileName)-1] == 'h') //.h file
            {
                numFiles++;
                type=2;
                File f(fileName,type);
                files.pushBack(f);
            }
        }
    }

    closedir (pDir);

}
