#include "../inc/ResumeParser.h"
#include "../inc/JobParser.h"
#include "../inc/SkillMatcher.h"
#include "../inc/ATSCalculator.h"
#include "../inc/ReportGenerator.h"

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main()
{
    try
    {
        cout << "=====================================\n";
        cout << "      SMART RESUME ANALYZER\n";
        cout << "=====================================\n\n";

        // Automatically discover job roles

        vector<string> jobFiles;

        for(const auto& file :
            fs::directory_iterator("data/jobs"))
        {
            if(file.path().extension() == ".txt")
            {
                jobFiles.push_back(
                    file.path().string());
            }
        }

        if(jobFiles.empty())
        {
            throw runtime_error(
                "No job profiles found.");
        }

        cout << "Available Job Roles\n\n";

        for(size_t i = 0;
            i < jobFiles.size();
            i++)
        {
            cout << i + 1
                 << ". "
                 << fs::path(jobFiles[i]).stem().string()
                 << endl;
        }

        int choice;

        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice < 1 ||
           choice > jobFiles.size())
        {
            throw runtime_error(
                "Invalid Job Selection.");
        }

        string selectedJobFile =
            jobFiles[choice - 1];

        // Parse Resume

        ResumeParser resumeParser;

        Resume resume =
            resumeParser.parseResume(
                "data/resumes/resume1.txt");

        // Parse Selected Job

        JobParser jobParser;

        JobDescription job =
            jobParser.parseJob(
                selectedJobFile);

        // Skill Matching

        SkillMatcher matcher;

        vector<string> matchedSkills =
            matcher.getMatched(
                resume.getSkills(),
                job.getSkills());

        vector<string> missingSkills =
            matcher.getMissing(
                resume.getSkills(),
                job.getSkills());

        // ATS Score

        ATSCalculator calculator;

        double score =
            calculator.calculateScore(
                matchedSkills.size(),
                job.getSkills().size());

        // Output

        cout << "\n=============================\n";
        cout << "Detected Skills\n";
        cout << "=============================\n";

        for(string skill :
            resume.getSkills())
        {
            cout << skill << endl;
        }

        cout << "\n=============================\n";
        cout << "Matched Skills\n";
        cout << "=============================\n";

        for(string skill :
            matchedSkills)
        {
            cout << skill << endl;
        }

        cout << "\n=============================\n";
        cout << "Missing Skills\n";
        cout << "=============================\n";

        if(missingSkills.empty())
        {
            cout << "None\n";
        }
        else
        {
            for(string skill :
                missingSkills)
            {
                cout << skill << endl;
            }
        }

        cout << "\nATS Score : "
             << score
             << "%\n";

        string recommendation;

        if(score >= 80)
        {
            recommendation =
                "Highly Recommended";
        }
        else if(score >= 60)
        {
            recommendation =
                "Recommended";
        }
        else
        {
            recommendation =
                "Needs Improvement";
        }

        cout << "Recommendation : "
             << recommendation
             << endl;

        // Generate Report

        ReportGenerator report;

        report.generateReport(
            matchedSkills,
            missingSkills,
            score);

        cout << "\nReport Generated Successfully.\n";
    }
    catch(exception& e)
    {
        cout << "\nError : "
             << e.what()
             << endl;
    }

    return 0;
}