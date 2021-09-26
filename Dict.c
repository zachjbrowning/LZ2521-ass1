#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dict.h"

typedef struct _dictNode *Node;

typedef struct _dictNode {
    char *verb;
    char *translation;
    Node left;
    Node right;
};

Dict buildDict(char *filename) {
    return NULL;
}

// PART 2
void searchDict(char *query) {
    return;
}

// PART 3
void listFrequent() {
    return;
}