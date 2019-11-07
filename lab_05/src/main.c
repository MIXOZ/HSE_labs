#include "point_list.h"
#include "clist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

int kol = 0;

point_node *get_point(intrusive_node *node);

void count (intrusive_node *node, void *data) {
    (void) node;
    (void) data;
    kol++;
}

void apply(intrusive_list *list, void (*op)(intrusive_node *node, void *data), void *data) {
    intrusive_node *head = &list->head;
    intrusive_node *node = head->next;
    for (; node != head; node = node->next)
        op(node, data);
}

void print_point_screen (intrusive_node *node, void *data) {
    char *format = data;
    point_node *pnode = get_point(node);
    printf (format, pnode->x, pnode->y);
}

void print_point_file (intrusive_node *node, void *data) {
    FILE *file;
    file = fopen (data, "a");
    point_node *pnode = get_point(node);
    fprintf (file, "%d %d\n", pnode->x, pnode->y);
    fclose(file);
}

void print_point_bin_file (intrusive_node *node, void *data) {
    FILE *file;
    file = fopen (data, "ab");
    point_node *pnode = get_point(node);
    uint8_t kor[6];
    kor[2] = pnode->x >> 16 & 255;
    kor[1] = pnode->x >> 8 & 255;
    kor[0] = pnode->x & 255;
    kor[5] = pnode->y >> 16 & 255;
    kor[4] = pnode->y >> 8 & 255;
    kor[3] = pnode->y & 255;
    fwrite(kor, 1, 6, file);
    fclose(file);
}

int main(int argc, char *argcom[]) {
    intrusive_list list;
    intrusive_list *l = &list;
    init_list(l);

    (void) argc;

    int first, second;

    if (strcmp(argcom[1], "loadtext") == 0) {
        FILE *ftxt = NULL;
        ftxt = fopen (argcom[2], "r");
        assert (ftxt != NULL);
        while (fscanf(ftxt, "%d %d", &first, &second) != EOF) {
            add_point(l, first, second);
        }
        fclose(ftxt);
    } else if (strcmp(argcom[1], "loadbin") == 0) {
        FILE *fbin = NULL;
        uint8_t kor[6];
        fbin = fopen(argcom[2], "rb");
        assert (fbin != NULL);
        while (fread(kor, 1, 6, fbin) == 6) {
            first = kor[0] + kor[1] * 256 + kor[2] * 256 * 256;
            second = kor[3] + kor[4] * 256 + kor[5] * 256 * 256;
            add_point(l, first, second);
        }
        fclose(fbin);
    }

    if (strcmp(argcom[3], "savebin") == 0) {
        apply(l, print_point_bin_file, argcom[4]);
    } else if (strcmp(argcom[3], "print") == 0) {
        apply(l, print_point_screen, argcom[4]);
    } else if (strcmp(argcom[3], "count") == 0) {
        apply(l, count, argcom[4]);
        printf("%d\n", kol);
    } else if (strcmp(argcom[3], "savetext") == 0) {
        apply(l, print_point_file, argcom[4]);
    }

    remove_all_points(l);

    return 0;
}