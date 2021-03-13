#include <iostream>
#include "Sort.h"

using namespace std;

int main(int argc, char** argv)
{
    Sort s1;
    std::cout << "Initializer list: "<< s1.asString() << "\n";
    s1.InsertSort(true);
    std::cout << "InsertSort: " << s1.asString() << "\n\n";
    //Random constructor
    Sort s2(15,-100,100);
    std::cout << "Random: "<< s2.asString() << "\n";
    s2.BubbleSort();
    std::cout << "BubbleSort in reverse: "<< s2.asString() << "\n\n";
    //Constructor from c array
    int64_t arr[6] = {1ll, 4ll, 5ll, 6ll, 3ll, 2ll};
    Sort s3(arr,6);
    std::cout << "C array: "<< s3.asString() << "\n";
    s3.QuickSort();
    std::cout << "QuickSorted: : "<< s3.asString() << "\n\n";
    //Constructor with varargs
    Sort s4(6, 1ll, 4ll, 5ll, 6i64, 3ll, 2ll);
    std::cout << "Var-args: "<< s4.asString() << "\n";
    //Constructor from string
    Sort s5("1,4,5,6,3,2");
    std::cout << "String: "<< s5.asString() << "\n";
}
