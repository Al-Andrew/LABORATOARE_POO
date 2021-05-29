#include "Decimal.h"
#include <string>

std::string Decimal::GetFormatName(){ 
    return "Decimal";
}

std::string Decimal::FormatNumber(int number){
    return std::to_string(number);
}