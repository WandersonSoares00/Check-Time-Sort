#include "utill.hpp"

template <typename T> static void fill_random(T *arr, int size){
    Random_gerator <T> ger(0, size);
    for (T *i = arr, *end = arr+size; i != end; ++i)      *i = ger();
}

template <typename T> static void fill_descend_order(T *arr, int size){
    int count = 1;
    for (int i = 0; i <size; ++i, ++count)      arr[i] = size - count;
}

template <typename T> static void fill_ascend_order(T *arr, int size){
    int count = 0;
    for (T *i = arr, *end = arr+size; i != end; ++i, ++count)      *i = count;
}
/*
template <typename T> static void fill_worst_case_qs_utill(T *arr, int *pos, int end){
    if( end >= 0 ){
        int p = pivot(0, end);
        arr[ pos[p] ] = end;
        swap (pos[p], pos[0]);
        swap (pos[0], pos[end]);
        fill_worst_case_qs_utill <T> (arr, pos, end -1);
    }
}


template <typename T> static void fill_worst_case_qs(T *arr, int size){
    int *pos = new int[size];
    fill_ascend_order <int> (pos, size);
    fill_worst_case_qs_utill <T> (arr, pos, size - 1);
    delete[] pos;
}
*/

template <typename T> static void fill_worst_case_qs(T *arr, int size){
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

template <typename T> void fill_array(T *arr, int size, char t){
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

template void fill_array<int>(int *, int, char);
template void fill_array<float>(float *, int, char);
