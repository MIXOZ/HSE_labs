#include <stdio.h>
#include "clist.h"

void init_list(struct intrusive_list * list) {
    list->head.next = NULL;
    list->head.prev = NULL;
}

void add_node(struct intrusive_list * list, struct intrusive_node * node) {
    if (list->head.next == NULL) {
        node->prev = &(list->head);
        node->next = NULL;
        list->head.next = node;
    } else {
        node->next = list->head.next;
        list->head.next->prev = node;
        node->prev = &(list->head);
        list->head.next = node;
    }
}

void remove_node(struct intrusive_list * list, struct intrusive_node * node) {
    if (node->next != NULL && node->prev != &(list->head)) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    } else if (node->next == NULL && node->prev != &(list->head)) {
        node->prev->next = NULL;
    } else if (node->next != NULL && node->prev == &(list->head)) {
        node->next->prev = &(list->head);
        list->head.next = node->next;
    } else {
        list->head.next = NULL;
    }
}

int get_length(struct intrusive_list * list) {
    int count = 0;
    for (struct intrusive_node * cur = list->head.next; cur; cur = cur->next) {
        count++;
    }
    return count;
}
