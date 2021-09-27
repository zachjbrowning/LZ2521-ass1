#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Dict.h"
#include "BST.h"

#define MAX 8192

static bool isSuffix(char *suffix, char *msg);

Dict buildDict(FILE *file) {
    Dict tree = NULL;

    char translation[MAX];
    char verb[MAX];

    while (fscanf(file, "%s ", verb) != EOF) {

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
    if (dict == NULL) return;

    int cmp = strcmp(query, dict->verb);
    if (cmp > 0) 
        return;
    else if (cmp < 0 )
        searchDict(dict->left, query);

    if (isSuffix(query, dict->verb))
        printf("%s %s\n", dict->verb, dict->translation);
}



// PART 3
void listFrequent(Dict dict) {
    return;
}

// ALSO NEED IMPLEMENTING
void freeDict(Dict dict) {
    freeBST(dict);
}


/*
        HELPERS
*/


static bool isSuffix(char *suffix, char *msg) {
    int suffixLen = strlen(suffix);
    int msgLen = strlen(msg);
    if (suffixLen > msgLen) return false;
    for (int i = 0; i < suffixLen; i++) {
        if (suffix[i] != msg[i]) return false;
    }
    return true;
}