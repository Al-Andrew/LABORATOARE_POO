#include "Number.hpp"
#include <cstring>
#include <algorithm>
#include <iostream>

// 0 1 2 3 4 5 6 7 8 9 A B C D E F
int get_value(char c)
{
    if( c >= '0' && c <= '9')
        return c - '0';
    else if( c >= 'A' && c <= 'F')
        return (c - 'A') + 10;
}

char get_char(int v)
{
    if( v >= 0 && v <= 9)
        return '0' + v;
    else if( v >= 10 && v <= 15)
        return (v-10) + 'A';
}


int base_to_dec(const char* repr, int base)
{
    int len = strlen(repr) - 1;
    int val = 1;
    int ret = 0;
    for(int i = len ; i >= 0 ; i--)
    {
        ret += get_value(repr[i]) * val;
        val *= base; 
    }
    return ret;
}

void dec_to_base(int val, int base, char* repr)
{
    char ret[32];
    int cif;
    int pos=0;
    while(val != 0)
    {
        cif = val % base;
        ret[pos++] = get_char(cif);
        val = val / base;
    }
    ret[pos] = '\0';
    std::string tmp(ret);
    std::reverse(std::begin(tmp), std::end(tmp));
    strcpy(repr, tmp.c_str());
}


Number::Number(const char * value, int base)
{
    strcpy(m_base_repr, value);
    m_base = base;
    m_value = base_to_dec(value, base);
}

Number::Number(const char* value)
{
    strcpy(m_base_repr, value);
    m_base = 10;
    m_value = base_to_dec(value, 10);
}

Number::Number(const int value)
{
    m_base = 10;
    m_value = value;
    dec_to_base(value, 10, m_base_repr);
}

void Number::SwitchBase(int newBase)
{
    m_base = newBase;
    dec_to_base(m_value, newBase, m_base_repr);
}

void Number::Print()
{
    std::cout << m_base_repr;
}

std::string Number::AsString()
{
    return std::string(m_base_repr);
}

int  Number::GetDigitsCount()
{
    return strlen(m_base_repr);
}

int  Number::GetBase()
{
    return m_base;
} 

Number operator+(Number rhs, Number lhs)
{
    int base = rhs.m_base;
    if( rhs.m_base < lhs.m_base )
        base = lhs.m_base;

    Number n(rhs.m_value + lhs.m_value);
    n.SwitchBase(base);
    return n;
}

Number operator-(Number rhs, Number lhs)
{
    int base = rhs.m_base;
    if( rhs.m_base < lhs.m_base )
        base = lhs.m_base;

    Number n(rhs.m_value - lhs.m_value);
    n.SwitchBase(base);
    return n;
}
char Number::operator[](int index)
{
    return m_base_repr[index];
}

bool Number::operator>(Number oth)
{
    return m_value > oth.m_value;
}


Number& Number::operator=(Number&& oth)
{
    if(this == &oth)
        return *this;

    int base = m_base > oth.m_base ? m_base : oth.m_base ;
    
    m_value = oth.m_value;
    this->SwitchBase(base);
    m_base = base;

    return *this;
}

Number& Number::operator=(int num)
{
    if(m_value == num)
        return *this;

    m_value = num;
    this->SwitchBase(m_base);
    return *this;
}

Number& Number::operator+=(const Number& oth)
{
    int base = m_base > oth.m_base ? m_base : oth.m_base ;
    m_value += oth.m_value;
    this->SwitchBase(base);
    return *this;
}

void Number::operator--()
{
    strcpy(m_base_repr, m_base_repr + 1);
    m_value = base_to_dec(m_base_repr, m_base);
} // prefix

void Number::operator--(int)
{
    m_base_repr[strlen(m_base_repr) - 1] = '\0';
    m_value = base_to_dec(m_base_repr, m_base);
}// postfix