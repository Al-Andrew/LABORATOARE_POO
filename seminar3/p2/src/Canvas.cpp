#include "Canvas.hpp"
#include <cstdlib>
#include <iostream>

Canvas::Canvas(int width,int height)
{
    this->width = width;
    this->height = height;
    surface = (char**)(malloc(height * sizeof(char*)));
    for (int i=0; i < this->height; ++i)
    {
        surface[i] = (char*)(malloc(width * sizeof(char)));
        memset(surface[i], ' ', this->width);
    }
}

Canvas::~Canvas()
{
    for (int i =0; i < this->height; ++i)
        free(surface[i]);
    free(surface);
}

void Canvas::Print()
{
    for(int y=0 ; y < this->height ; ++y)
    {
        for(int x=0; x < this->width ; ++x)
        {
            std::cout << surface[y][x];
        }
        std::cout << '\n';
    }
}

void Canvas::Clear()
{
    for (int i=0; i < this->height; ++i)
    {
        memset(surface[i], ' ', this->width);
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for(int i=0 ; i < this->height ; ++i)
    {
        for(int j=0; j< this->width ; ++j)
        {
            if( (i - x)*(i - x) + (j - y)^(j - y) >= ray*(ray-1) && (i - x)*(i - x) + (j - y)*(j - y) <= ray*(ray+1) )
                surface[i][j] = ch;
        }
    }
}