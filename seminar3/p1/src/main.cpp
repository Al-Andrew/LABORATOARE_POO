#include <iostream>
#include "Math.hpp"

int main(int argc, char** argv)
{
    printf_s("ADD 2 INTS, %d \n", Math::Add(1,2));
    printf_s("ADD 3 INTS, %d \n", Math::Add(1,2,3));
    printf_s("ADD N INTS, %d \n", Math::Add(5,2,3,4,5,6));
    printf_s("ADD 2 DOUBLES, %d \n", Math::Add(1.2,2.8));
    printf_s("ADD 3 DOUBLES, %d \n", Math::Add(1.2,2.8,3.5));

    printf_s("MUL 2 INTS, %d \n", Math::Mul(1,2));
    printf_s("MUL 3 INTS, %d \n", Math::Mul(1,2,3));
    printf_s("MUL 2 DOUBLES, %d \n", Math::Mul(1.5,2.5));
    printf_s("MUL 3 DOUBLES, %d \n", Math::Mul(1.5,2.5,2.5));

    printf_s("ADD 2 STRINGS, %s \n", Math::Add("Hello ","World"));
    printf_s("ADD 2 nullptrs, %s \n", Math::Add(nullptr, nullptr)); // this doesn't crash
}
