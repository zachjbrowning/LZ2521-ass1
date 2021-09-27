#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dict.h"
#include "BST.h"

#define MAX 8192

Dict buildDict(FILE *file) {
    Dict tree = NULL;

    char translation[MAX];
    char verb[MAX];

    while (fscanf(file, "%s", verb) != EOF) {

        fgets(translation, MAX, file);

        if (translation[strlen(translation) - 1] == '\n') {
            translation[strlen(translation) - 1] = '\0';
        }

        tree = insertNode(tree, verb, translation);
    }

    return tree;
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