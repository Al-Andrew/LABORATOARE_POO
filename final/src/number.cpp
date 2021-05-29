#include "number.h"

Number::Number(int value){
    number = value;
    count = 0;
}

Number::operator int(){ 
    return number;
}

Number Number::operator+(Number n){
    return Number(number+n);
}

Number Number::operator-(Number n){
    return Number(number-n);
}

Number Number::operator*(Number n){
    return Number(number*n);
}

Number Number::operator/(Number n){
    return Number(number/n);
}

Number& Number::operator+=(Printer *p){
    if(count < 100)
        printers[count++] = p;
    return *this;
}

void Print();