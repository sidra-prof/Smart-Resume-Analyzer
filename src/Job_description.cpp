#include "../inc/Job_description.h"

void JobDescription::setJobTitle(
    string title)
{
    jobTitle = title;
}

void JobDescription::setSkills(
    vector<string> skills)
{
    this->skills = skills;
}

string JobDescription::getJobTitle() const
{
    return jobTitle;
}

vector<string> JobDescription::getSkills() const
{
    return skills;
}