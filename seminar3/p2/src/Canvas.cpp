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
            std::cout << ' ' << surface[y][x];
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

void Canvas::SetPoint(int x, int y, char ch)
{
    this->surface[y][x] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for(int i=0 ; i < this->height ; ++i)
    {
        for(int j=0; j < this->width ; ++j)
        {
            if( (i-y)*(i-y) + (j-x)*(j-x) >= (ray-1)*(ray-1) && (i-y)*(i-y) + (j-x)*(j-x) <= (ray + 1)*(ray + 1) )
            {
                this->surface[i][j] = ch;
            }
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for(int i=0 ; i < this->height ; ++i)
    {
        for(int j=0; j < this->width ; ++j)
        {
            if( (i-y)*(i-y) + (j-x)*(j-x) < (ray-1)*(ray-1) )
            {
                this->surface[i][j] = ch;
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for(int i=left ; i <= right ; ++i)
    {
        this->surface[top][i] = ch;
    }
    for(int i=left ; i <= right ; ++i)
    {
        this->surface[bottom][i] = ch;
    }
    for(int i=top ; i <= bottom ; ++i)
    {
        this->surface[i][left] = ch;
    }
    for(int i=top ; i <= bottom ; ++i)
    {
        this->surface[i][right] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for(int i=top ; i <= bottom ; ++i)
    {
        for(int j=left ; j <= right ; ++j)
        {
            this->surface[i][j] = ch;
        }
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double derr = std::abs( dy / dx );

    double err = 0.0;
    int y = y1;
    for( int x = x1 ; x <= x2 ; x += (dx > 0 ? 1:-1) )
    {
        this->surface[y][x] = ch;
        err += derr;
        if( derr >= 0.5 )
        {
            y += (dy > 0 ? 1:-1) ;
            err = err - 1;
        }
    }

}