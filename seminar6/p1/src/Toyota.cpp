#include "Toyota.hpp"

int Toyota::GetAverageSpeed(Weather conditions ){
    switch ( conditions )
    {
    case Weather::Sunny:
        return 110;
        break;
    case Weather::Rainy:
        return 75;
        break;
    case Weather::Snowy:
        return 54;
        break;
    }
}

std::string Toyota::AsString(){
    return "Toyota";
}