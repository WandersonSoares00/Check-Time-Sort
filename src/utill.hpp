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

template <typename T> static void fill_random(T *arr, int size);

template <typename T> static void fill_descend_order(T *arr, int size);

//template <typename T> static void fill_worst_case_qs_utill(T *arr, int *pos, int end);
template <typename T> static void fill_worst_case_qs(T *arr, int size);

template <typename T> static void fill_ascend_order(T *arr, int size);

template <typename T> void fill_array(T *arr, int size, char t);

template <typename T> class SortingTime{
    T *v, *cpy_v;
    int size;
    public:

    SortingTime(T *v, int size);
    ~SortingTime();

    void copy(T *v1, T *v2);
    bool is_sorted();
    double time( void (*sort)(T *, int) );
};

template <typename T>
SortingTime<T> :: SortingTime(T *v, int size){
    this-> v = v;
    this-> size = size;
    cpy_v = new T[size];
}

template <typename T>
SortingTime<T> :: ~SortingTime(){  delete[] cpy_v;  }

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


