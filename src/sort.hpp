#ifndef SORT_H
#define SORT_H

#include <cstdlib>
#include <iostream>
#include <random>

using std::swap;

//template <typename T> void swap(T &a, T &b);

template <typename T> void insertion_sort(T *arr, int end);

int pivot(int begin, int end);
template <typename T> static void partition_Hoare(T *arr, int begin, int end, int& p);
template <typename T> static void quick_sort_determ_utill(T *arr, int begin, int end);
template <typename T> void quick_sort_determ(T *arr, int size);

//inline int left_child(int index);
//inline int right_child(int index);
template <typename T> static void heapify(T *arr, int size, int i);
template <typename T> static void build_max_heap(T *arr, int size);
template <typename T> void heap_sort(T *arr, int size);

int pivot_rand(int begin, int end);
template <typename T> static void quick_sort_indeterm_utill(T *arr, int begin, int end);
template <typename T> void quick_sort_indeterm(T *arr, int size);


int log2(int a);
template <typename T> static void intro_sort_utill_hs(T *arr, int begin, int end, int max_depth);
template <typename T> void intro_sort_hs(T *arr, int size);

template <typename T> static void intro_sort_utill_in(T *arr, int begin, int end);
template <typename T> void intro_sort_in(T *arr, int size);

template <typename T> static void merge(T *arr, int begin, int mid, int end);
template <typename T> void merge_sort(T *arr, int size);

template <typename T> static void intro_sort_utill_ms(T *arr, int begin, int end, int max_depth);
template <typename T> void intro_sort_ms(T *arr, int size);

#endif
