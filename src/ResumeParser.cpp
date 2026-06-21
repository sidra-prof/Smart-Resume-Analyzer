#include "../inc/ResumeParser.h"
#include "../inc/SkillDictionary.h"
#include "../inc/Utils.h"
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <stdexcept>
#include <cctype>

using namespace std;

Resume ResumeParser::parseResume(
    const string& filename)
{
    // Open Resume File

    ifstream file(filename);

    if(!file.is_open())
    {
        throw runtime_error(
            "Unable to open resume file.");
    }

    // Read Complete Resume

    stringstream buffer;

    buffer << file.rdbuf();

    string text = buffer.str();

    file.close();

    // Convert To Lowercase

    text =
        Utils::toLowerCase(text);

    // Keep + # .
    // Remove Other Punctuation

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

    // Load Skill Dictionary

    unordered_set<string>
    skillDictionary =
        SkillDictionary::getSkills();

    // Store Detected Skills

    unordered_set<string>
    detectedSkills;

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

    // Convert Set To Vector

    vector<string> skills(
        detectedSkills.begin(),
        detectedSkills.end());

    // Create Resume Object

    Resume resume;

    resume.setSkills(skills);

    return resume;
}