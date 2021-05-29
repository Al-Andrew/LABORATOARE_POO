#pragma once
#include "Printer.h"

class Decimal : public Printer{
public:
    std::string GetFormatName();
    std::string FormatNumber(int number);
};