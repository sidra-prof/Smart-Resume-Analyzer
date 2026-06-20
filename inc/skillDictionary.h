#ifndef SKILLDICTIONARY_H
#define SKILLDICTIONARY_H

#include <unordered_set>
#include <string>

using namespace std;

class SkillDictionary
{
public:

    static unordered_set<string> getSkills()
    {
        return
        {
            // Programming Languages
            "c++",
            "c#",
            "java",
            "python",
            "javascript",

            // Web Development
            "html",
            "css",
            "react",
            "nodejs",

            // Databases
            "sql",
            "mysql",
            "mongodb",

            // Tools
            "git",
            "github",
            "docker",

            // Cloud
            "aws",
            "azure",

            // Operating Systems
            "linux",
            "windows",

            // Data Science
            "pandas",
            "numpy",
            "matplotlib",

            // AI / ML
            "machinelearning",
            "deeplearning",
            "tensorflow",
            "pytorch",

            // Computer Science Fundamentals
            "dsa",
            "oop",
            "os",
            "dbms",
            "cn"
        };
    }
};

#endif