#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include <vector>
#include <string>

using namespace std;

class JobDescription
{
private:

    string jobTitle;

    vector<string> skills;

public:

    void setJobTitle(string title);

    void setSkills(vector<string> skills);

    string getJobTitle() const;

    vector<string> getSkills() const;
};

#endif