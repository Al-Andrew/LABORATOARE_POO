#pragma once
#include <string>
#include <cstdint>


class Student
{
    private:
    std::string m_name;
    float m_grMath;
    float m_grEng;
    float m_grHist;

    public:
    Student() = default;

    void setName(std::string name);
    void setGrMath(float grade);
    void setGrEng(float grade);
    void setGrHist(float grade);

    [[nodiscard]] const char* getName() const;
    [[nodiscard]] float getGrMath() const;
    [[nodiscard]] float getGrEng() const;
    [[nodiscard]] float getGrHist() const;
    [[nodiscard]] float getGrAvg() const;

    [[nodiscard]] std::string asString() const;
    void print() const;
};