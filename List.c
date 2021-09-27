#include <stdlib.h>
#include <stdio.h>
#include "List.h"

LLNode newNode(int value, Dict translation);

LList newList(void) {
    LList l = malloc(sizeof(*l));

    l->count = 0;
    l->first = NULL;
    l->last = NULL;

    return l;
}

// Doesn't bother secondary sorting because assumes PREFIX 
// traversal so what is entered first is alphabetically earlier
void insertInOrder(LList list, int value, Dict translation) {
    LLNode new = newNode(value, translation);
    list->count++;
    // BASE CASE, NO ELEMENTS
    if (list->count == 1) {
        list->first = new;
        list->last = new;
        return;
    }
    // BASE CASE, GOES AT START
    if (value > list->first->value) {
        new->next = list->first;
        new->next->previous = new;
        list->first = new;
        return;
    }

    LLNode curr = list->first;

    while (curr != NULL && value <= curr->value) {
        curr = curr->next;
    }

    // BASE CASE, GOES AT END
    if (curr == NULL) {
        new->previous = list->last;
        list->last->next = new;
        list->last = new;
    } else {
        // GENERAL CASE
        new->next = curr;
        new->previous = curr->previous;
        new->previous->next = new;
        curr->previous = new;
    }

}

void freeList(LList list) {
    LLNode curr = list->first;
    while (curr != NULL) {
        LLNode temp = curr;
        curr = curr->next;
        free(curr);
    }
    free(list);
}

void removeLowest(LList list) {
    LLNode temp = list->last;
    temp->previous->next = NULL;
    list->last = temp->previous;
    free(temp);
    list->count--;
}

/*
    HELPERS
*/

LLNode newNode(int value, Dict translation) {
    LLNode n = malloc(sizeof(*n));

    n->value = value;
    n->translation = translation;
    n->previous = NULL;
    n->next = NULL;

    return n;
}