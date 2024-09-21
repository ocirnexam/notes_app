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

void linked_list_free(linked_list list)
{   
    node_t *current = list;
    node_t *temp = NULL;
    while(current != NULL) {
        if(current->note != NULL) {
            free(current->note);
        }
        temp = current;
        current = current->next;
        free(temp);
    }
}

void linked_list_print(linked_list list)
{
    linked_list current = list;

    while (current != NULL) {
        printf("---------------------------------\nID: %d\nTITLE: %s\nCONTENT: %s\n", current->note->id, current->note->title, current->note->content);
        current = current->next;
    }
}