#include <iostream>
#include "Student.hpp"
#include "globals.hpp"


int main(int argc, char** argv)
{
    Student s1;  // create and assign values to s1
    s1.setName("Marius");
    s1.setGrMath(5.6f);
    s1.setGrEng(8.9f);
    s1.setGrHist(9.5);
    
    Student s2; // create and assign values to s2
    s2.setName("George");
    s2.setGrMath(7.f);
    s2.setGrMath(0.5); // this won't change the grade because it's outside of the given range
    s2.setGrEng(8.9f);
    s2.setGrHist(8.6);

    std::cout << s1.asString() << "\n" << s2.asString() << "\n"; // print the twho students info
    std::cout << cmpName(s1,s2) << " "  // print all the comparison results
              << cmpMath(s1,s2) << " "
              << cmpEng(s1,s2) << " "
              << cmpHist(s1,s2) << " "
              << cmpAvg(s1,s2) << "\n";
              
}
