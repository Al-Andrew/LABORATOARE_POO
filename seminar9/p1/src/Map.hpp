#pragma once
#include <cstdint>


template<typename FirstType, typename SecondType>
class Pair
{
    Pair(FirstType f, SecondType s)
        :first(f), second(s) {}
    FirstType first;
    SecondType second;
};

template<typename KeyType, typename ValueType>
class Map
{
public:
    Map() = default;
    ~Map() = default;

    void Set(const KeyType& key, ValueType val);
    bool Get(const KeyType& key, ValueType& val);
    uint32_t Count();
    void Clear();
    bool Delete(const KeyType& key);
    bool Includes(const Map<KeyType, ValueType>& othr);
private:
    Pair<KeyType, ValueType> data*;
};