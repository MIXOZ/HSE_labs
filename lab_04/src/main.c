#include <stdio.h>
#include "mergesort.h"

int  i;
int arr[10];
int comp (const void * a, const void * b) {
    return *(int*)b - *(int*)a;
}

int main(void) {
    //scanf("%d", n);
    for (i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, 9, comp);
    for (i = 0; i < 10; ++i) {
        printf("%d", arr[i]);
    }

    return 0;
}