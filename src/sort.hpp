#ifndef SORT_H
#define SORT_H

#include <cstdlib>
#include <iostream>
#include <random>
#include "utill.hpp"

using std::swap;


template <typename T> void insertion_sort(T *arr, int size){
    for (T *v = arr+1; v < arr+size; ++v){
        T key = *v;
        T *l = v - 1;
        while ( l >= arr && *l > key ){
            *(l+1) = *l;
            --l;
        }
        *(l+1) = key;
    }
}

    /*    Deterministic Quick sort     */

inline int pivot(int begin, int end){
    return begin + (end-begin)/2;
}

template <typename T> static void partition_Hoare(T *arr, int begin, int end, int& p){
    T piv = arr[p];
    swap <T> (arr[begin], arr[p]);
    int i = begin;
    int j = end + 1;

    while( i < j ){
        while( arr[--j] > piv);
        while( arr[++i] < piv && i < j);
        
        if ( i < j)
            swap <T> (arr[i], arr[j]);
    }

    swap <T> (arr[begin], arr[j]);

    p = j;
}

template <typename T> static void quick_sort_determ_utill(T *arr, int begin, int end){
    if ( begin < end)    {
        int p = pivot(begin, end);
        partition_Hoare <T> (arr, begin, end, p);
        quick_sort_determ_utill <T> (arr, begin, p - 1);
        quick_sort_determ_utill <T> (arr, p + 1, end);
    }
}

template <typename T> void quick_sort_determ(T *arr, int size){
    quick_sort_determ_utill(arr, 0, size - 1);
}

    /*     Heap Sort    */


template <typename T> static void heapify(T *arr, int size, int i){
    int child = 2 * i + 1;

    while( child < size ) {
        if( child + 1 < size && arr[child+1] > arr[child] )
            ++child;
        if( arr[child] > arr[i]  ){
            swap <T> (arr[child], arr[i]);
            i = child;
            child = 2 * i + 1;
        }
        else
            break;
    }
}

template <typename T> static void build_max_heap(T *arr, int size){
    for ( int i = size / 2 - 1; i >= 0; --i )
        heapify <T> (arr, size, i);
}

template <typename T> void heap_sort(T *arr, int size){
    build_max_heap <T> (arr, size);
    for( int i = size - 1; i >= 0; --i ){
        swap(arr[0], arr[i]);
        heapify <T> (arr, i, 0);
    }
}

    /*    Indeterministic Quick Sort   */

int pivot_rand(int begin, int end){
    //ger.param(std::uniform_int_distribution<int>::param_type(begin, end));
    return rand() % (end - begin + 1) + begin;
}

template <typename T> static void quick_sort_indeterm_utill(T *arr, int begin, int end){
    if ( begin < end)    {
        int p = pivot_rand(begin, end);
        partition_Hoare <T> (arr, begin, end, p);
        quick_sort_indeterm_utill <T> (arr, begin, p - 1);
        quick_sort_indeterm_utill <T> (arr, p + 1, end);
    }
}

template <typename T> void quick_sort_indeterm(T *arr, int size){
    quick_sort_indeterm_utill(arr, 0, size - 1);
}

    /*  Merge Sort  */


template <typename T> static void merge(T *arr, int begin, int mid, int end){
    int i = begin, k = 0;
    int j = mid;
    T *temp = new T[end - begin];

    while (i < mid && j < end){
        if ( arr[i] < arr[j] )   temp[k] = arr[i++];
        else                     temp[k] = arr[j++];
        k++;
    }
    
    while (i < mid)     temp[k++] = arr[i++];
    while (j < end )    temp[k++] = arr[j++];
    
    for(k = 0; k < end - begin; k++)    arr[begin + k] = temp[k];
    delete[] temp;
}

template <typename T> void merge_sort(T *arr, int size){
    int block = 1;
    int i, end; // subarray arr[i .. end-1]

    while( block < size ){
        i = 0;
        while( i + block < size ){
            end = i + (2 * block);
            if ( end > size )
                end = size;
            merge <T> (arr, i, i + block, end);
            i = i + 2 * block;
        }
        block = 2 * block;
    }
}

    /*   Intro Sort with Heap sort  */


int log2(int a){
    int count = 0;
    for (; a != 1; a >>= 1)     ++count;
    return count;
}

template <typename T> static void intro_sort_utill_hs(T *arr, int begin, int end, int max_depth){
    if (begin >= end)
        return;

    if(end - begin < 16)
        return insertion_sort <T> (arr + begin, end - begin + 1);

    if (max_depth == 0)
        return heap_sort <T> (arr + begin, end - begin + 1);

    int p = pivot(begin, end);
    partition_Hoare <T> (arr, begin, end, p);
    intro_sort_utill_hs <T>(arr, begin, p - 1, max_depth - 1);
    intro_sort_utill_hs <T> (arr, p + 1, end, max_depth - 1);
}

template <typename T> void intro_sort_hs(T *arr, int size){
    int d = log2(size);
    intro_sort_utill_hs <T>(arr, 0, size - 1, 2*d);
}

    /*   Intro Sort with Insertion sort  */


template <typename T> static void intro_sort_utill_in(T *arr, int begin, int end, int max_depth){
    if (begin >= end)
        return;
    
    if (end - begin < 16)
        return insertion_sort <T> (arr + begin, end - begin + 1);

    if (max_depth == 0)
        return merge_sort <T> (arr + begin, end - begin + 1);

    int p = pivot(begin, end);
    partition_Hoare <T> (arr, begin, end, p);
    intro_sort_utill_in <T>(arr, begin, p - 1, max_depth);
    intro_sort_utill_in <T> (arr, p + 1, end, max_depth);
}

template <typename T> void intro_sort_in(T *arr, int size){
    int d = log2(size);
    intro_sort_utill_in <T>(arr, 0, size - 1, 2*d);
}

    /*   Intro Sort with Merge Sort and Insertion Sort  */


template <typename T> static void intro_sort_utill_ms(T *arr, int begin, int end, int max_depth){
    if (begin >= end)
        return;

    if (end - begin < 16)
        return insertion_sort <T> (arr + begin, end - begin + 1);
    
    if (max_depth == 0)
        return merge_sort <T> (arr + begin, end - begin + 1);
    
    int p = pivot(begin, end);
    partition_Hoare <T> (arr, begin, end, p);
    intro_sort_utill_ms <T>(arr, begin, p - 1, max_depth - 1);
    intro_sort_utill_ms <T> (arr, p + 1, end, max_depth - 1);
}

template <typename T> void intro_sort_ms(T *arr, int size){
    int d = log2(size);
    intro_sort_utill_hs <T>(arr, 0, size - 1, (int) 1.5*d);
}


#endif
