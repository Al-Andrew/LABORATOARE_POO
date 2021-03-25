#include "Circuit.hpp"
#include <algorithm>
#include <iostream>

void Circuit::SetLength(int len)
{
    m_len = len;
}

void Circuit::SetWeather(Weather conditions)
{
    m_conditions = conditions;
}

void Circuit::AddCar(Car* car)
{
    m_cars.push_back(car);
}

void Circuit::Race()
{
    for( auto car : m_cars)
    {
        float range =  (float)car->GetFuelCapacity() / (float)car->GetFuelConsumption();
        float time =  (float)m_len / (float)car->GetAverageSpeed(m_conditions); 
        //std::printf("Car: %s, rage: %f, time %f\n", car->AsString().c_str(), range,time);
        if ( range < m_len )
            m_not_finished.push_back(car->AsString());
        else 
            m_rankings.push_back(std::make_pair(car->AsString(), time));

    }
    std::sort(std::begin(m_rankings), std::end(m_rankings), [](std::pair<std::string,float> a, std::pair<std::string,float> b){
            return a.second <= b.second;
        });
}

void Circuit::ShowFinalRanks()
{
    std::cout << "The final rankings are:\n";
    for(auto car : m_rankings)
    {
        std::cout << car.first << " finished with a time of " << car.second << "\n";
    }
}

void Circuit::ShowDidNotFinish()
{
    std::cout << "The fowllowing cars did not finish the race:\n";
    for(auto car : m_not_finished)
    {
        std::cout << car << "\n";
    }
}


