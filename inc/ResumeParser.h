#ifndef RESUMEPARSER_H
#define RESUMEPARSER_H

#include "Resume.h"

class ResumeParser
{
public:

    Resume parseResume(const string& filename);
};

#endif