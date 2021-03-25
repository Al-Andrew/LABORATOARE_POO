#pragma once
#include "Weather.hpp"
#include <string>

struct Car
{
public:
    int GetFuelCapacity()
    {
        return m_fuel_capaciy;
    }
    int GetFuelConsumption()
    {
        return m_fuel_consumption;
    }
    virtual int GetAverageSpeed(Weather conditions) = 0;
    virtual std::string AsString() = 0;

protected:
    int m_fuel_capaciy;
    int m_fuel_consumption;
};