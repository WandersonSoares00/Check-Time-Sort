#ifndef UTILL_HPP
#define UTILL_HPP

#include <iostream>
#include <chrono>
#include <random>
#include <type_traits>
#include "sort.hpp"

template <typename T>
class Random_gerator{
    using DistributionType = typename std::conditional<
        std::is_integral<T>::value,
        std::uniform_int_distribution<T>,
        std::uniform_real_distribution<T>
    >::type;

    std::random_device rd;
    std::mt19937 ger;
    DistributionType dist;

public:

    Random_gerator(T a, T b) : ger{rd()}, dist{a, b} {};
    
    T operator() (){    return dist(ger);   }
};

template <typename T>
static void fill_random(T *arr, int size){
    Random_gerator <T> ger(0, size);
    for (T *i = arr, *end = arr+size; i != end; ++i)      *i = ger();
}

template <typename T>
static void fill_descend_order(T *arr, int size){
    int count = 1;
    for (int i = 0; i <size; ++i, ++count)      arr[i] = size - count;
}

template <typename T>
static void fill_ascend_order(T *arr, int size){
    int count = 0;
    for (T *i = arr, *end = arr+size; i != end; ++i, ++count)      *i = count;
}

template <typename T>
static void fill_worst_case_qs(T *arr, int size){
    int *pos = new int[size];
    fill_ascend_order <int> (pos, size);
    
    for (int i = size-1; i >= 0; --i){
        int p = pivot(0, i);
        arr[ pos[p] ] = i;
        swap (pos[p], pos[0]);
        swap (pos[0], pos[i]);
    }

    delete[] pos;
}

template <typename T>
void fill_array(T *arr, int size, char t){
    switch (t){
        case 'A':
            fill_random <T> (arr, size);         break;
        case 'C':
            fill_ascend_order <T>(arr, size);    break;
        case 'D':
            fill_descend_order <T>(arr, size);   break;
        case 'P':
            fill_worst_case_qs <T>(arr, size);   break;
        default:
            throw std::invalid_argument("Use: A (aleatória), C (ordem crescente), D (ordem decrescente), e P (pior caso).");
    }
}


template <typename T>
class SortingTime{
    T *v, *cpy_v;
    int size;
    public:

    SortingTime(T **v, int size);
    ~SortingTime();

    void copy(T *v1, T *v2);
    bool is_sorted();
    double time( void (*sort)(T *, int) );
};

template <typename T>
SortingTime<T> :: SortingTime(T **v, int size){
    this-> size = size;
    *v = new int[size];
    this-> v = *v;
    cpy_v    = new T[size];
}

template <typename T>
SortingTime<T> :: ~SortingTime(){  delete[] cpy_v; delete[] v; }

template <typename T>
void SortingTime<T> :: copy(T *v1, T *v2){
    T *j = v2;
    for(T *i = v1, *end = v1+size; i != end; ++i, ++j)
        *j = *i;
}

template <typename T>
bool SortingTime<T> :: is_sorted(){
    for( T *i = v+1, *end = v+size; i != end; ++i )
        if ( *(i-1) > *i )
            return false;
    return true;
}

template <typename T>
double SortingTime<T> :: time( void (*sort)(T *, int) ){
    copy (v, cpy_v);

    auto start = std::chrono::steady_clock::now();
    sort(v, size);
    auto finish = std::chrono::steady_clock::now();
    
    std::chrono::duration<double> d = finish - start;

    if (!is_sorted())
        throw std::logic_error("Vetor não ordenado corretamente.");

    copy (cpy_v, v);

    return d.count();
}

#endif


