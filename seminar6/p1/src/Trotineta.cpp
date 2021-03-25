#include "Trotineta.hpp"

int Trotineta::GetAverageSpeed(Weather conditions ){
    switch ( conditions )
    {
    case Weather::Sunny:
        return 50;
        break;
    case Weather::Rainy:
        return 30;
        break;
    case Weather::Snowy:
        return 20;
        break;
    }
}

std::string Trotineta::AsString(){
    return "Trotineta";
}