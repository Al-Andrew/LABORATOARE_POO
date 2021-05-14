#include <iostream>
#include "Sort.hpp"


int main(int argc, char** argv)
{
    int arr[] = {3, 0, 1, 5, 4, 2};
    upos n = 6;
    Sort{}(arr, 0, n);
    for(upos i = 0; i < n ; i++)
        std::cout << arr[i] << " " ;

}
