#include "Math.hpp"
#include <cstdarg>
#include <cstring>
#include <cstdlib>


int Math::Add(int a, int b)
{
    return a+b;
}


int Math::Add(int a, int b, int c)
{
    return a+b+c;
}

int Math::Add(double a, double b)
{
    return a+b;
}

int Math::Add(double a, double b, double c)
{
    return a+b+c;
}

int Math::Mul(int a,int b)
{
    return a*b;
}

int Math::Mul(int a,int b, int c)
{
    return a*b*c;
}

int Math::Mul(double a,double b)
{
    return a*b;
}

int Math::Mul(double a,double b, double c)
{
    return a*b*c;
}

int Math::Add(int count,...)
{
    int sum = 0;
    va_list vl;
    va_start(vl, count);
    for(int i = 0; i < count ; i++)
    {
        sum += va_arg(vl, int);
    }
    va_end(vl);
    return sum;
}

char* Math::Add(const char *s1, const char *s2)
{
    int bufff_len = 1;
    if( s1 != nullptr)
        bufff_len += strlen(s1);
    if( s2 != nullptr)
        bufff_len += strlen(s2);

    char* buff = (char* )malloc( bufff_len * sizeof(char));
    memset(buff, 0, bufff_len);

    if( s1 != nullptr)
        memcpy_s(buff, bufff_len, s1, strlen(s1));
    if( s2 != nullptr)
        memcpy_s(buff + strlen(s1) , bufff_len, s2, strlen(s2));

    return buff;
}