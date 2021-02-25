#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
    this->count = 0;
}

bool NumberList::Add(int x)
{
    if(count >= 10)
        return false;
    
    this->numbers[this->count++] = x;
    return true;
}

void NumberList::Sort()
{
    bool isDone = false;
    while(!isDone)
    {
        isDone = true;
        for(int i = 0; i < this->count - 1 ; i++)
            if( this->numbers[i] > this->numbers[i+1])
            {
                int tmp = this->numbers[i];
                this->numbers[i] = this->numbers[i+1];
                this->numbers[i+1] = tmp;
                isDone = false;
            }
    }
}

void NumberList::Print()
{
    printf_s("[ ");
    for(int i=0; i < this->count ; i++)
    {
        printf_s("%d", this->numbers[i]);
        if( i+1 >= this->count)
            printf_s(" ");
        else
            printf_s(", ");
    }
    printf_s("]");
}