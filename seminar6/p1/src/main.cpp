#include <iostream>
#include "Circuit.hpp"
#include "Dacia.hpp"
#include "Toyota.hpp"
#include "Trotineta.hpp"

int main()
{
   Circuit c;
   c.SetLength(100);
   c.SetWeather(Weather::Rainy);
   c.AddCar(new Dacia);
   c.AddCar(new Toyota);
   c.AddCar(new Trotineta);
   c.Race();
   c.ShowFinalRanks();
   c.ShowDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit

   return 0;
}