#include "Sort.h"
#include <random>
#include <sstream>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <cstdarg>
#include <algorithm>
#include <cstring>

Sort::Sort(uint32_t size, int64_t min, int64_t max){
    std::random_device rd;
    std::mt19937_64 engine(rd());
    std::uniform_int_distribution<> dist(min, max);
    this->m_arr = (int64_t*)malloc(sizeof(int64_t)*size);
    this->m_capacity = size;
    this->m_size = size;

    for(uint32_t i=0;i < this->m_size; ++i)
    {
        this->m_arr[i] = dist(engine);
    }
}

Sort::Sort(int64_t* vec, uint32_t size){
    this->m_arr = (int64_t*)malloc(sizeof(int64_t)*size);
    this->m_capacity = size;
    this->m_size = size;

    for(uint32_t i=0; i < size ; ++i)
    {
        this->m_arr[i] = vec[i];
    }
}

Sort::Sort(uint32_t size, ...){
    this->m_arr = (int64_t*)malloc(sizeof(int64_t)*size);
    this->m_capacity = size;
    this->m_size = size;
    va_list vl;
    va_start(vl, (int64_t)size);

    for(uint32_t i=0; i < size ; ++i)
    {
        this->m_arr[i] = va_arg(vl, int64_t);
    }

    va_end(vl);
}

Sort::Sort(const char* elements){
    //presupunem ca avem cel putin un element valid...
    uint32_t size = 1;
    //Urasc ca trebuie sa fac asta... 
    //Ar trebuii sa fac un std::count dar nu am iteratori
    for(uint32_t i=0; i < strlen(elements) ; ++i)
    {
        if(elements[i] == ',')
            size++;
    }


    this->m_arr = (int64_t*)malloc(sizeof(int64_t)*size);
    this->m_capacity = size;
    this->m_size = size;
    std::stringstream l(elements);
    //Aici ar trebuii sa fie un statefull lambda...
    {
    uint32_t i = 0;
    for(std::string buff;std::getline(l, buff, ',');)
    {   
        this->m_arr[i++] = std::atoll(buff.c_str());
    }
    }
}

Sort::Sort()
    :m_arr(new int64_t[10] {7,1,3,4,9,10,5,6,8,2})
{
    this->m_capacity = 10;
    this->m_size = 10;
}

void Sort::Print(){
    std::cout << "[ ";
    for(uint32_t i=0; i<this->m_size ; ++i)
    {
        std::cout << this->m_arr[i] << ((i + 1 < this->m_size)?", ":" ");
    }
    std::cout << "]";
}

std::string Sort::asString(){
    std::stringstream sout;
    sout << "[ ";
    for(uint32_t i=0; i<this->m_size ; ++i)
    {
       sout << this->m_arr[i] << (i + 1 < (this->m_size)? ", ": " ");
    }
    sout << "]";
    return sout.str();
}


uint32_t Sort::GetElementsCount(){
    return this->m_size;
}

int64_t Sort::GetElementFromIndex(uint32_t index){
    return (index > 0 && index < this->m_size)?this->m_arr[index]:INT64_MIN;
}

void Sort::InsertSort(){
    uint32_t i,j;
    int64_t key;
    for(i = 1; i < this->m_size - 1; ++i)
    {
        key = this->m_arr[i];
        j = i - 1;
        while( j >= 0 && this->m_arr[j] > key)
        {
            this->m_arr[j + 1] = this->m_arr[j]; 
            j = j - 1;
        }
        this->m_arr[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent){
    bool done = false;
    while(!done)
    {
        done = true;
        for(uint32_t i = 0; i < this->m_size - 1; ++i)
        {
            if( this->m_arr[i] > this->m_arr[i+1]){
                int64_t tmp = this->m_arr[i];
                this->m_arr[i] = this->m_arr[i+1];
                this->m_arr[i+1] = tmp;
                done = false;
            }
        }
    }
}
void QuickSort(bool ascendent=false);
