#include <iostream>
#include "Canvas.hpp"

int main(int argc, char** argv)
{
    Canvas c(11,11);
    c.DrawCircle(5,5, 3, '/');
    c.Print();
}
