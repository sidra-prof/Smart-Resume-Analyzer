#include "../inc/JobParser.h"
#include "../inc/SkillDictionary.h"
#include "../inc/Utils.h"
#include "../inc/Job_description.h"
#include "../inc/SkillMatcher.h"
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <stdexcept>
#include<string>
#include<cctype>
#include<vector>
using namespace std;

JobDescription JobParser::parseJob(
    const string& filename)
{
    // Open file

    ifstream file(filename);

    if(!file.is_open())
    {
        throw runtime_error(
            "Unable to open job profile.");
    }

    // Read complete file

    stringstream buffer;

    buffer << file.rdbuf();

    string text = buffer.str();

    file.close();

    // Convert to lowercase

    text = Utils::toLowerCase(text);

    // Keep + # .
    // Remove other punctuation

    for(char& ch : text)
    {
        if(ch != '+' &&
           ch != '#' &&
           ch != '.')
        {
            if(ispunct(ch))
            {
                ch = ' ';
            }
        }
    }

    // Get skill dictionary

    unordered_set<string> skillDictionary =
        SkillDictionary::getSkills();

    // Store extracted skills

    unordered_set<string> detectedSkills;

    string word;

    stringstream ss(text);

    while(ss >> word)
    {
        word =
            Utils::normalizeWord(word);

        if(skillDictionary.find(word)
            != skillDictionary.end())
        {
            detectedSkills.insert(word);
        }
    }

    // Convert set → vector

    vector<string> skills(
        detectedSkills.begin(),
        detectedSkills.end());

    // Create object

    JobDescription job;

    job.setSkills(skills);

    return job;
}