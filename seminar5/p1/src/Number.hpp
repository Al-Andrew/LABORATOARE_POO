#pragma once
#include <string>

class Number
{
private:
   int m_value;
   char m_base;
   char m_base_repr[32];
   // add data members
public:

   Number(const char * value, int base); // where base is between 2 and 16
   Number(const char* value); // Assume base 10
   Number(const int value); // Assume base is 10
   Number(const Number& oth) = default;
   Number(Number&& oth) = default;
   ~Number() = default;


   friend Number operator+(Number rhs, Number lhs);
   friend Number operator-(Number rhs, Number lhs);


   char operator[](int index);

   Number& operator=(int num);
   Number& operator=(Number&& oth);
   Number& operator+=(const Number& oth);
   
   void operator--(); // prefix
   void operator--(int);// postfix

   bool operator>(Number oth);

   void SwitchBase(int newBase);
   void Print();
   std::string AsString();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base

};