#pragma once
#include "Car.hpp"


class Trotineta : public Car
{
public:
    Trotineta()
    {
        m_fuel_capaciy = 300;
        m_fuel_consumption  = 5;
    }
    int GetAverageSpeed(Weather conditions);

    std::string AsString();

};  