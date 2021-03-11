#pragma once
#include <stdint.h>
#include <string>

class Sort{

    private:
    int64_t* m_arr;
    uint32_t m_size;
    uint32_t m_capacity;


    public:
    Sort();
    Sort(uint32_t size, int64_t min, int64_t max);
    Sort(int64_t* vec, uint32_t size);
    Sort(uint32_t size, ...);
    Sort(const char* elements);

    void InsertSort();
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);

    void Print();
    std::string asString();
    uint32_t  GetElementsCount();
    int64_t  GetElementFromIndex(uint32_t index);

};