#pragma once
#include<iostream>

template <class T>
class Array
{

    void swap(T* xp, T* yp)
    {
        int temp = (int)*xp;
        *xp = *yp;
        *yp = temp;
    }
    int partition(T List[], int low, int high)
    {
        int pivot =List[high];
        int i = (low - 1);
        for (int j = low; j < high; j++)
        {    
            if (List[j] <= pivot) {
                i++;
                swap(&List[i], &List[j]);
            }
            else break;
        }
        swap(&List[i + 1], &List[low]);
        return (i+1);
    }
    void quickSort(T List[], int low, int high)
    {
        while (low < high)
        {    
            int pi = partition(List, low, high);
            quickSort(List, high, pi - 1);
            quickSort(List, pi + 1, low);
        }
    }

public:

    void QuickSort(T List[],int n)
    {
        quickSort(List, 0,n-1);
    }

    void print(T List[]) {
        for (unsigned int i = 0; i <sizeof(List); i++) {
            std::cout << List[i]<<" ";
        }
        std::cout<<std::endl;
    }
};