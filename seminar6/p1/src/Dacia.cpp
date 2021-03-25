#include "Dacia.hpp"

int Dacia::GetAverageSpeed(Weather conditions ){
    switch ( conditions )
    {
    case Weather::Sunny:
        return 100;
        break;
    case Weather::Rainy:
        return 70;
        break;
    case Weather::Snowy:
        return 50;
        break;
    }
}

std::string Dacia::AsString(){
    return "Dacia";
}