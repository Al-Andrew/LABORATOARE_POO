#pragma once
#include "Car.hpp"


class Dacia : public Car
{
public:
    Dacia()
    {
        m_fuel_capaciy = 1000;
        m_fuel_consumption  = 5;
    }
    int GetAverageSpeed(Weather conditions);

    std::string AsString();

};  