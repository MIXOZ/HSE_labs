#include "mergesort.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>

void merge (void * arr, size_t elem, size_t elem_size, int (*comp) (const void *, const void *)) {
    char * res = (char*)malloc(elem * elem_size);
    char * mid = (char*)arr + (elem / 2) * elem_size;
    char * right = (char*)arr + elem * elem_size;
    char * I_left = arr;
    char * I_right = mid;
    while ((char*)I_left < (char*)mid && (char*)I_right < (char*)right) {
        if (comp(I_left, I_right) > 0) {
            memcpy (res, I_left, elem_size);
            I_left += elem_size;
        } else {
            memcpy (res, I_right, elem_size);
            I_right += elem_size;
        }
        res += elem_size;
    }
    while ((char*)I_left < (char*)mid) {
        memcpy (res, I_left, elem_size);
        I_left += elem_size;
        res += elem_size;
    }
    while ((char*)I_right < (char*)right) {
        memcpy (res, I_right, elem_size);
        I_right += elem_size;
        res += elem_size;
    }
    res -= elem * elem_size;
    for (size_t i = 0; i < elem * elem_size; i += elem_size) {
        memcpy(arr + i, res + i, elem_size);
    }
    free (res);
}

void merge_sort (void * arr, size_t elem, size_t elem_size,  int (*comp) (const void *, const void *)) {
    if (elem == 1)
    return;
    size_t mid = elem / 2;
    merge_sort((char*) arr, mid, elem_size, comp);
    merge_sort((char*) arr + mid * elem_size, elem - mid, elem_size, comp);
    merge(arr, elem, elem_size, comp);
}
