#include "../inc/Resume.h"
#include<string>
#include<vector>
using namespace std;

// Store extracted skills
void Resume::setSkills(
    vector<string> skills)
{
    this->skills = skills;
}

// Return stored skills
vector<string> Resume::getSkills() const
{
    return skills;
}