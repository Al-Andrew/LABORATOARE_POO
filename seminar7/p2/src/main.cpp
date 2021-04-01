#include <iostream>
#include <algorithm>
#include <numeric>
#include "Vector.hpp"

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    Vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 0);
    std::cout << "Vec initialized with iota: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vec.push_back(32);
    vec.push_back(12);
    vec.push_back(112);
    std::cout << "Vec after push_backs: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vec.emplace(31,3);
    vec.emplace(11, 4);
    vec.emplace(111, 5);
    std::cout << "Vec after emplace: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vec.sort();
    std::cout << "Vec after default sort: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    vec.sort(cmp);
    std::cout << "Vec after sort with custom comparison: ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    std::cout << "I can get an element by index: vec[5]=" << vec[5]<<"\n";
    
    std::cout << "Please input an index to set: ";
    int i;
    std::cin >> i;
    std::cout << "Setting : vec["<< i << "] = ";
    int n;
    std::cin >> n;
    vec[i] = n;

    std::cout << "Please input an element to search for ";
    std::cin >> i;
    std::cout << "Element: " << i << " fond at position: " << vec.find(i) << "\n";

    std::cout << "The vector now has " << vec.size() << " elements";

}
