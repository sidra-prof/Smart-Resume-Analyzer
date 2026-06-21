#ifndef SKILLMATCHER_H
#define SKILLMATCHER_H

#include <vector>
#include <string>

using namespace std;

class SkillMatcher
{
public:

    vector<string> getMatched(
        vector<string> resumeSkills,
        vector<string> jobSkills);

    vector<string> getMissing(
        vector<string> resumeSkills,
        vector<string> jobSkills);
};

#endif