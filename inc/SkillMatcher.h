#ifndef SKILLMATCHER_H
#define SKILLMATCHER_H

#include <vector>
#include <string>

using namespace std;

class SkillMatcher
{
private:
    vector<string> matched;
    vector<string> missing;

public:
    void compareSkills(
        vector<string> resumeSkills,
        vector<string> jobSkills
    );

    vector<string> getMatched();
    vector<string> getMissing();
};

#endif