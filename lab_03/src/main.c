#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "clist.h"

struct point {
    int x, y;
    struct intrusive_node node;
};

void add_point (struct intrusive_list * list, int x, int y) {
    struct point * p = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;
    add_node (list, &(p->node));
}


void remove_point (struct intrusive_list * list, int x, int y) {
    struct intrusive_node * cur = list->head.next;
    while (cur) {
        struct point *  p = container_of (cur, struct point, node);
        if (p->x == x && p->y == y) {
            remove_node (list, &(p->node));
            cur = cur->next;
            free (p);
            continue;
        }
        cur = cur->next;
    }
}

void show_all_points (struct intrusive_list * list) {
    for (struct intrusive_node * cur = list->head.next; cur != NULL; cur = cur->next) {
        struct point * p = container_of (cur, struct point, node);
        printf ("(");
        printf ("%d", p->x);
	printf(" ");
        printf ("%d", p->y);
	printf (")");
        printf(" ");
    }
}

void remove_all_points (struct intrusive_list * list) {
    struct intrusive_node * cur = list->head.next;
    while (cur) {
        struct point * p = container_of (cur, struct point, node);
        remove_node (list, cur);
        cur = cur->next;
        free (p);
    }
}

char act[10];

int main() {
    struct intrusive_list list;
    init_list (&list);
    int x, y;
    while (1) {
        scanf ("%6s", act);
        if (strcmp (act, "add") == 0) {
            scanf ("%d", &x);
            scanf ("%d", &y);
            add_point (&list, x, y);
        } else if (strcmp (act, "rm") == 0) {
            scanf ("%d", &x);
            scanf ("%d", &y);
            remove_point (&list, x, y);
        } else if (strcmp (act, "rma") == 0) {
            remove_all_points (&list);
        } else if (strcmp (act, "len") == 0) {
            printf ("%d", get_length (&list));
            printf ("\n");
        } else if (strcmp (act, "print") == 0) {
            show_all_points (&list);
            printf ("\n");
        } else if (strcmp (act, "exit") == 0) {
            remove_all_points (&list);
            return 0;
        } else {
            printf("Unknown command\n");
        }
    }
}

