#pragma once 
#include "Car.hpp"
#include <vector>
#include <string>

struct Circuit
{
public:
    void SetLength(int len);
    void SetWeather(Weather conditions);
    void AddCar(Car* car);

    void Race();
    void ShowFinalRanks();
    void ShowDidNotFinish();
private:
    int m_len;
    Weather m_conditions;
    std::vector<std::pair<std::string, float>> m_rankings;
    std::vector<std::string> m_not_finished;
    std::vector<Car*> m_cars;
};