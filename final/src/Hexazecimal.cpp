#include "Hexazecimal.h"
#include <sstream>
#include <algorithm>

std::string Hexazecimal::GetFormatName(){ 
    return "Hexazecimal";
}

std::string Hexazecimal::FormatNumber(int number){
    std::stringstream s;
    s << std::hex << number;

    std::string res = s.str();

    std::reverse(res.begin(), res.end());

    for(int i = 0; i < res.size(); i++){
        res[i] = toupper(res[i]);
    }

    for(int i = 0,len = res.size(); i < 8 - len ; i++)
        res.push_back('0');
    res.push_back('x');
    res.push_back('0');

    std::reverse(res.begin(), res.end());

    return res;
}
