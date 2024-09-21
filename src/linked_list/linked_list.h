#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "note/note.h"

typedef struct node {
    Note* note;
    struct node* next;
} node_t;

typedef node_t* linked_list;

linked_list linked_list_create(void);
linked_list linked_list_add(linked_list list, Note* note);
void linked_list_print(linked_list list);
void linked_list_free(linked_list list);

#endif