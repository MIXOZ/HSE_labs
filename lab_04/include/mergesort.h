
#ifndef UNTITLED1_MERGESORT_H
#define UNTITLED1_MERGESORT_H

void merge (int * arr, int left, int mid, int right, int (*comp) (const void *, const void *)/*, int arr_type*/);
void merge_sort (int * arr, int left, int right,  int (*comp) (const void *, const void *));


#endif
