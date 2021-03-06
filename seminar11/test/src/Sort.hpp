#pragma once
#include<iostream>

template <class T>
class Sort
{
    static void swap(T* xp, T* yp)
    {
        int temp = (int)*xp;
        *xp = *yp;
        *yp = temp;
    }
    static int partition(T List[], int low, int high)
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
    static void quickSort(T List[], int low, int high)
    {
        if (low < high)
        {    
            int pi = partition(List, low, high);
            quickSort(List, high, pi - 1);
            quickSort(List, pi + 1, low);
        }
    }

public:

    static void QuickSort(T List[],int n)
    {
        quickSort(List, 0,n-1);
    }

    static void print(T List[]) {
        for (unsigned int i = 0; i <sizeof(List); i++) {
            std::cout << List[i]<<" ";
        }
        std::cout<<std::endl;
    }
};
