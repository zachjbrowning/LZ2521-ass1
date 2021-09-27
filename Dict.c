#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dict.h"

typedef struct dictNode Node;

typedef struct _dictNode {
    char *verb;
    char *translation;
    Node *left;
    Node *right;
} dictNode;

Dict buildDict(char *filename) {
    return NULL;
}

// PART 2
void searchDict(Dict dict, char *query) {
    return;
}

// PART 3
void listFrequent(Dict dict) {
    return;
}

// ALSO NEED IMPLEMENTING
void freeDict(Dict dict) {
    return;
}