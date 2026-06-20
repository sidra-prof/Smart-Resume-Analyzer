#ifndef RESUME_H
#define RESUME_H

#include <vector>
#include <string>

using namespace std;

class Resume
{
private:

    vector<string> skills;

public:

    void setSkills(
        vector<string> skills);

    vector<string> getSkills() const;
};

#endif