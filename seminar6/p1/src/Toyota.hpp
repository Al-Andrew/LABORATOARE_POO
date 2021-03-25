#pragma once
#include "Car.hpp"


struct Toyota : public Car
{
public:
    Toyota()
    {
        m_fuel_capaciy = 900;
        m_fuel_consumption  = 4;
    }
    int GetAverageSpeed(Weather conditions);
    
    std::string AsString();
    
};  