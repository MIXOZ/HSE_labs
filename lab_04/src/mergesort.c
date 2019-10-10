#include "mergesort.h"
#include <stdio.h>
#include <malloc.h>

void merge (int * arr, int left, int mid, int right, int (*comp) (const void *, const void *)/*, int arr_type*/) {
    int it_1 = 0;
    int it_2 = 0;
    int i;
    //if (arr_type == "int") int *arr = malloc((right - left) * sizeof(int));
    //if (arr_type == "char") int * arr = malloc((right-left) * sizeof(char));
    //if (arr_type == "str") int * arr = malloc((right-left) * sizeof(string));
    int * res = malloc((right - left) * sizeof(int));
    while (left + it_1 < mid && mid + it_2 < right) {
        if (comp(arr+left + it_1, arr+mid + it_2) > 0) {
            res [it_1 + it_2] = arr [left + it_1];
            it_1++;
        } else {
            res [it_1 + it_2] = arr [mid + it_2];
            it_2++;
        }
    }
    while (left + it_1 < mid) {
        res [it_1 + it_2] = arr [left + it_1];
        it_1++;
    }
    while (mid + it_2 < right) {
        res [it_1 + it_2] = arr [mid + it_2];
        it_2++;
    }
    for (i = 0; i <= it_1 + it_2; ++i) {
        arr [left + i] = res [i];
    }
    free (res);
}

void merge_sort (int * arr, int left, int right,  int (*comp) (const void *, const void *)) {
    if (left + 1 >= right)
    return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid, comp);
    merge_sort(arr, mid, right, comp);
    merge(arr, left, mid, right, comp);
}
