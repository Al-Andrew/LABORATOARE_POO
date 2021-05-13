#pragma once
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iostream>

using usize = std::size_t;

template <typename T>
using il = std::initializer_list<T>;

template<typename T, typename U>
bool operator==(il<T> l, U arr[]){
    auto a = std::mismatch(l.begin(), l.end(), arr);
    return a.first == l.end();
}
