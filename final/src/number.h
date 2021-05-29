#pragma once
#include <iostream>
#include "Printer.h"

class Number{
private:
    int number;
    int count;
    Printer* printers[100];

public:
    Number(int value);

    operator int();

    Number operator+(Number n);
    Number operator-(Number n);
    Number operator*(Number n);
    Number operator/(Number n);

    Number& operator+=(Printer* p);

    void Print(){ 
        for(int i = 0; i < count ; ++i){
            auto p = printers[i];
            std::cout << "Format: " << p->GetFormatName() << " Value: " << p->FormatNumber(number) << "\n"; 
        }
    }
};