#include "linked_list.h"

//----------------------------------------------------
linked_list linked_list_create()
{
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return NULL;
    }

    head->note = NULL;
    head->next = NULL;
    return head;
}

//----------------------------------------------------
linked_list linked_list_add(linked_list list, Note* note)
{
    node_t * head = NULL;

    if(list->note == NULL) {
        list->note = note;
        return list;
    }

    head = malloc(sizeof(node_t));
    if (head == NULL) {

        return list;
    }
    else {
        head->note = note;
        head->next = list;
    }
    return head;
}

uint32_t linked_list_free(linked_list* list)
{   
    linked_list current = *list;
    linked_list temp = NULL;
    int i = 0;
    while(current != NULL) {
        if(current->note != NULL) {
            free(current->note);
            current->note = NULL;
        }
        ++i;
        temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }
    return i;
}

void linked_list_print(linked_list list)
{
    linked_list current = list;

    while (current != NULL) {
        printf("---------------------------------\nID: %d\nTITLE: %s\n", current->note->id, current->note->title);
        current = current->next;
    }
}