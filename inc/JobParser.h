#ifndef JOBPARSER_H
#define JOBPARSER_H

#include "Job_description.h"
#include <string>

using namespace std;

class JobParser
{
public:

    JobDescription parseJob(
        const string& filename);
};

#endif