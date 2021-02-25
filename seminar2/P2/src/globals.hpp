#pragma once
#include "Student.hpp"

[[nodiscard]]int cmpName(const Student& lhs, const Student& rhs);
[[nodiscard]]int cmpMath(const Student& lhs, const Student& rhs);
[[nodiscard]]int cmpEng(const Student& lhs, const Student& rhs);
[[nodiscard]]int cmpHist(const Student& lhs, const Student& rhs);
[[nodiscard]]int cmpAvg(const Student& lhs, const Student& rhs);