#pragma once

using fx = long double;
using u64 = unsigned long long int;



constexpr fx operator""_Kelvin(fx a){ return (fx)a - 273.15l; }
constexpr fx operator""_Kelvin(u64 a){ return (fx)a - 273.15l; }
constexpr fx operator""_Fahrenheit(fx a) { return ((fx)a - 32.l) / 1.8l; }
constexpr fx operator""_Fahrenheit(u64 a) { return ((fx)a - 32.l) / 1.8l; }
