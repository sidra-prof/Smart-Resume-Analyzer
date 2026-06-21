#include "../inc/SkillMatcher.h"
#include<string>
#include <unordered_set>
#include<vector>
#
using namespace std;

// Returns matched skills

vector<string> SkillMatcher::getMatched(
    vector<string> resumeSkills,
    vector<string> jobSkills)
{
    unordered_set<string> resumeSet(
        resumeSkills.begin(),
        resumeSkills.end());

    vector<string> matched;

    for(string skill : jobSkills)
    {
        if(resumeSet.find(skill)
            != resumeSet.end())
        {
            matched.push_back(skill);
        }
    }

    return matched;
}

// Returns missing skills

vector<string> SkillMatcher::getMissing(
    vector<string> resumeSkills,
    vector<string> jobSkills)
{
    unordered_set<string> resumeSet(
        resumeSkills.begin(),
        resumeSkills.end());

    vector<string> missing;

    for(string skill : jobSkills)
    {
        if(resumeSet.find(skill)
            == resumeSet.end())
        {
            missing.push_back(skill);
        }
    }

    return missing;
}