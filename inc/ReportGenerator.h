#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>

using namespace std;

class ReportGenerator
{
public:
    void generateReport(
        vector<string> matched,
        vector<string> missing,
        double score
    );
};

#endif