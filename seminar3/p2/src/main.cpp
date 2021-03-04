#include <iostream>
#include "Canvas.hpp"

int main(int argc, char** argv)
{
    Canvas c(25,25);
    c.DrawCircle(12,12, 10, '0'); // Face border
    c.FillCircle(12,12, 10, '~'); // Face color
    c.DrawRect(0,0,24,24, ' +'); // Border
    c.FillRect(7,8,9,10, '/'); // left eye
    c.FillRect(15,8,17,10, '\\'); // right eye
    c.DrawLine(9,17,11,20, '\\'); // left mouth-part
    c.DrawLine(13,19,15,16, '/'); // right mouth-part
    c.SetPoint(12,19, '-'); // bottom mouth-pwrt
    c.Print();
    c.Clear();
    c.Print();

}
