#include <iostream>
#include "Map.hpp"
#include <map>


int main()
{
    Map<int, const char *> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto[key, value, index] : m)
    {
        printf("Index:%lld, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%lld, Key=%d, Value=%s\n", index, key, value);
    }

    m.Print();

    return 0;
}