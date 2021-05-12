#include <iostream>
#include <exception>
#include <algorithm>
#include "Array.hpp"

int main()
{
    std::cout << "Constructing arr with capacity 10 \n";
    Array<int> arr(10);

    std::cout << "Constructing arr with no speciied capacity\n";
    Array<int> arr2;

    std::cout << "Constructing arr3 with capacity 0 \n";
    try
    {
        Array<int> arr3(0);
    }
    catch(const ArrayException& e)
    {
        std::cerr << e.what() << '\n';
    }

    arr += 5;
    arr += 9;
    std::cout << "Adding elements to arr with += : " << arr << '\n';
    arr2 = arr;
    std::cout << "Assigning arr to arr2 with = : " << arr2 << '\n';
    std::cout << "Inserting in arr2 on position 5: \n";
    try
    {
        arr2.Insert(5,3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    arr.Insert(1,arr2);
    std::cout << "Inserting arr2 in arr on pos 3:" << arr << '\n';
    arr.Delete(1);
    std::cout << "Deleting index 3 in arr : " << arr << '\n';
}