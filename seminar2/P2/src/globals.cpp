#include "globals.hpp"
#include <cstring>

[[nodiscard]]int cmpName(const Student& lhs, const Student& rhs)
{
    return strcmp(lhs.getName(), rhs.getName());
}

[[nodiscard]]int cmpMath(const Student& lhs, const Student& rhs)
{
    return lhs.getGrMath() < rhs.getGrMath()?-1:
            lhs.getGrMath() > rhs.getGrMath()?1:
            0;
}

[[nodiscard]]int cmpEng(const Student& lhs, const Student& rhs)
{
    return lhs.getGrEng() < rhs.getGrEng()?-1:
            lhs.getGrEng() > rhs.getGrEng()?1:
            0;
}

[[nodiscard]]int cmpHist(const Student& lhs, const Student& rhs)
{
    return lhs.getGrHist() < rhs.getGrHist()?-1:
            lhs.getGrHist() > rhs.getGrHist()?1:
            0;
}

[[nodiscard]]int cmpAvg(const Student& lhs, const Student& rhs)
{
    return lhs.getGrAvg() < rhs.getGrAvg()?-1:
            lhs.getGrAvg() > rhs.getGrAvg()?1:
            0;
}

