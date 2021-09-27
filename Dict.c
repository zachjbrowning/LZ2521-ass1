#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Dict.h"
#include "BST.h"
#include "List.h"

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
        searchDict(dict->right, query);
    else if (cmp < 0 )
        searchDict(dict->left, query);

    if (isSuffix(query, dict->verb)) {
        dict->noSearches++;
        printf("%s %s\n", dict->verb, dict->translation);
    }
}



// Prefix traversal, add when found and only keep top 5
static void findFrequent(Dict dict, LList list) {
    if (dict == NULL) return;

    findFrequent(dict->left, list);

    if (dict->noSearches > 0) {
        insertInOrder(list, dict->noSearches, dict);
        if (list->count > 10) removeLowest(list);
    }

    findFrequent(dict->right, list);
}

// PART 3
void listFrequent(Dict dict) {
    LList list = newList();

    findFrequent(dict, list);

    LLNode curr = list->first;
    while (curr != NULL) {
        printf("%d %s %s\n", curr->value, curr->translation->verb, curr->translation->translation);
        curr = curr->next;
    }

    freeList(list);
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