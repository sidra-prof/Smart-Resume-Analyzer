#include "../inc/ReportGenerator.h"
#include <fstream>
#include <iostream>

using namespace std;

void ReportGenerator::generateReport(
    vector<string> matched,
    vector<string> missing,
    double score
)
{
    ofstream report("output/report.txt");

    if(!report)
    {
        cout << "Unable to create report file.\n";
        return;
    }

    report << "========== ATS REPORT ==========\n\n";

    report << "Matched Skills:\n";

    for(string skill : matched)
    {
        report << "- " << skill << "\n";
    }

    report << "\n";

    report << "Missing Skills:\n";

    for(string skill : missing)
    {
        report << "- " << skill << "\n";
    }

    report << "\n";

    report << "ATS Score: "
           << score
           << "%\n\n";

    report.close();

    cout << "\nReport Generated Successfully!\n";
}