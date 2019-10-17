#include "mergesort.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int comp_int (const void * a, const void * b) {
    assert (a != NULL);
    assert (b != NULL);
    return *(const int*)b - *(const int*)a;
}
int comp_char (const void * a, const void * b) {
    assert (a != NULL);
    assert (b != NULL);
    return *(const char*)b - *(const char*)a;
}
int comp_str (const void * a, const void * b) {
    assert (a != NULL);
    assert (b != NULL);
    return strcmp(*(char**)b, *(char**)a);
}

int main(int argc, char ** argv) {
    if (strcmp(argv[1], "int") == 0) {
        int arr[argc - 2];
        for (int i = 2; i < argc; ++i) {
            arr[i - 2] = atoi(argv[i]);
        }
        merge_sort (&arr, argc - 2, sizeof(int), comp_int);
        for (int i = 0; i < argc - 2; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else if (strcmp(argv[1], "str") == 0) {
        char * arr[argc - 2];
        for (int i = 2; i < argc; ++i) {
            arr[i - 2] = argv[i];
        }
        merge_sort (&arr, argc - 2, sizeof(char *), comp_str);
        for (int i = 0; i < argc - 2; ++i) {
            printf("%s ", arr[i]);
        }
        printf("\n");
    } else if (strcmp(argv[1], "char") == 0) {
        char arr[argc - 2];
        for (int i = 2; i < argc; ++i) {
            arr[i - 2] = argv[i][0];
        }
        merge_sort (&arr, argc - 2, sizeof(char), comp_char);
        for (int i = 0; i < argc - 2; ++i) {
            printf("%c ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
