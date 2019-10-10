#ifndef UNTITLED1_MERGESORT_H
#define UNTITLED1_MERGESORT_H
#include <stddef.h>

void merge (void * arr, size_t elem, size_t elem_size, int (*comp) (const void *, const void *));
void merge_sort (void * arr, size_t elem, size_t elem_size,  int (*comp) (const void *, const void *));


#endif
