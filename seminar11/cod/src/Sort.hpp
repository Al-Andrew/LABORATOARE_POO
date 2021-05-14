#pragma once
#include <functional>

using upos = unsigned int;

class Sort {

private:
template<typename T>
upos maxElement(T list[], upos start, upos end, std::function<bool(const T&, const T&)> compare) {
    int max = 0;
    for(upos i = start; i < end - 1 ; ++i)
        if( !compare(list[max], list[i]) )
            max = i;
    return max;
}
public:
template<typename T>
void operator()(T list[], upos start, upos end, std::function<bool(const T&, const T&)> compare = std::less<>{}) {
    for(upos i = start; i < end - 1 ; ++i)
    {
        upos max = maxElement(list, i + 1, end, compare);
        std::swap(list[i], list[max]);
    }
}
};



