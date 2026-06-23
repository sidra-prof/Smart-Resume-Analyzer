#include "../inc/ATSCalculator.h"

double ATSCalculator::calculateScore(
    int matchedSkills,
    int totalRequiredSkills
)
{
    if(totalRequiredSkills == 0)
    {
        return 0;
    }

    return ((double)matchedSkills /
            totalRequiredSkills) * 100;
}