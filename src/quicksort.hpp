#ifndef QUICK_HPP
#define QUICK_HPP

#include <iostream>
#include <vector>
#include <stdlib.h>

class Quicksort {
 private:
    vector<float>& elements;

    int size;

    int partition (const int start, const int end){
        int i = start;

        for (int j = start; j < end; j++){

            if (elements[j] <= elements[end]){
                swap(i++, j);
            }
        }
        swap(i, end);

        return i;
    }

    void swap (const int i, const int j){
        float k = elements[i];
        elements[i] = elements[j];
        elements[j] = k;
    }

    void quicksort (const int start, const int end){

        if (start >= end) return;

        int pivot = partition(start, end);

        quicksort(start, pivot - 1);
        quicksort(pivot + 1, end);
    }

 public:
    explicit Quicksort (vector<float>& elements)
    :elements(elements),
     size(elements.size()){
    }

    void Sort (){
        if(size <= 1) return;

        quicksort(0, size - 1);
    }
};

#endif