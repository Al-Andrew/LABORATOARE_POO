#include "Student.hpp"
#include <iostream>
#include <sstream>

void Student::setName(std::string name)
{
    this->m_name = name;
}

void Student::setGrMath(float grade)
{
    if( grade >= 1.0f && grade <= 10.0f)
    this->m_grMath = grade;
}

void Student::setGrEng(float grade)
{
    if( grade >= 1.0f && grade <= 10.0f)
    this->m_grEng = grade;
}

void Student::setGrHist(float grade)
{
    if( grade >= 1.0f && grade <= 10.0f)
    this->m_grHist = grade;
}

[[nodiscard]] const char* Student::getName() const
{
    return m_name.c_str();
}

[[nodiscard]] float Student::getGrMath() const
{
    return m_grMath;
}

[[nodiscard]] float Student::getGrEng() const
{
    return m_grEng;
}

[[nodiscard]] float Student::getGrHist() const
{
    return m_grHist;
}

[[nodiscard]] float Student::getGrAvg() const
{
    return (m_grHist + m_grMath + m_grEng)/3.0f;
}

void Student::print() const
{
    std::cout << this->m_name << ": M=" << m_grMath 
                              << " E="  << m_grEng
                              << " H="  << m_grHist
                              << " A="  << this->getGrAvg();
}

[[nodiscard]] std::string Student::asString() const
{
    std::stringstream s;

    s << this->m_name << ": M=" << m_grMath 
                      << " E="  << m_grEng
                      << " H="  << m_grHist
                      << " A="  << this->getGrAvg();

    return s.str();
}