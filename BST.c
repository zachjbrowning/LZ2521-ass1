#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

static Node rotateLeft(Node n);
static Node rotateRight(Node n);
static int  height(Node n);
static int  max(int a, int b);
static Node newNode(char *verb, char *translation);


void freeBST(Node n) {
    if (n != NULL) {
        freeBST(n->left);
        freeBST(n->right);
        free(n->verb);
        free(n->translation);
    }
}

Node insertNode(Node n, char *verb, char *translation) {
    if (n == NULL) {
        return newNode(verb, translation);
    }

    // Insert recursively
    int newVerb = strcmp(verb, n->verb);
    if (newVerb < 0) {
        n->left = insertNode(n->left, verb, translation);
    } else if (newVerb > 0) {
        n->right = insertNode(n->right, verb, translation);
    } else {
        return n;
    }

    n->height = 1 + max(height(n->left), height(n->right));
    
    int lHeight = n->left == NULL ? -1 : n->left->height;
    int rHeight = n->right == NULL ? -1 : n->right->height;
    
    if (lHeight - rHeight > 1) {
        if (n->left != NULL && strcmp(n->verb, n->left->verb) > 0) {
            n->left = rotateLeft(n->left);
        }
        n = rotateRight(n);
    } else if (rHeight - lHeight > 1) {
        if (n->right != NULL && strcmp(n->verb, n->right->verb) < 0) {
            n->right = rotateRight(n->right);
        }
        n = rotateLeft(n);
    }
    return n;


}

typedef unsigned long long uint64;
static void doShow(Node n, int level, uint64 arms);

void printBST(Node n) {
    if (n != NULL && n->height >= 64) {
    printf("Tree is too tall!\n");
    } else {
        doShow(n, 0, 0);
    }
}

static void doShow(Node n, int level, uint64 arms) {
    if (n == NULL) return;

    printf("%s : %s (height: %d)\n", n->verb, n->translation, n->height);

    if (n->left != NULL) {
        for (int i = 0; i < level; i++) {
            if ((1LLU << i) & arms) {
                printf("│     ");
            } else {
                printf("      ");
            }
        }
        printf("%s", n->right != NULL ? "┝━╸L: " : "┕━╸L: ");
        if (n->right != NULL) {
            arms |= (1LLU << level);
        } else {
            arms &= ~(1LLU << level);
        }
        doShow(n->left, level + 1, arms);
    }

    if (n->right != NULL) {
        for (int i = 0; i < level; i++) {
            if ((1LLU << i) & arms) {
                printf("│     ");
            } else {
                printf("      ");
            }
        }
        printf("┕━╸R: ");
        arms &= ~(1LLU << level);
        doShow(n->right, level + 1, arms);
    }
}

/*
        STATIC FUNCTIONS
*/


static Node newNode(char *verb, char *translation) {
    Node n = malloc(sizeof(*n));
    
    n->verb = malloc(sizeof(char) * (strlen(verb) + 1));
    n->translation = malloc(sizeof(char) * (strlen(translation) + 1));
    
    strcpy(n->verb, verb);
    strcpy(n->translation, translation);
    
    n->noSearches = 0;
    n->height = 0;
    n->left = NULL;
    n->right = NULL;

    return n;
}

static Node rotateLeft(Node n) {
    if (n == NULL) return NULL;
    if (n->right == NULL) return n;
    Node p = n->right;
    n->right = p->left;
    p->left = n;
    int lHeight = n->left == NULL ? -1 : n->left->height;
    int rHeight = n->right == NULL ? -1 : n->right->height;
    p->height = lHeight + 2 > p->height ? lHeight + 2 : p->height;
    n->height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
    return p;
}

static Node rotateRight(Node n) {
    if (n == NULL) return NULL;
    if (n->left == NULL) return n;
    Node p = n->left;
    n->left = p->right;
    p->right = n;
    int rHeight = n->right == NULL ? -1 : n->right->height;
    int lHeight = n->left == NULL ? -1 : n->left->height;
    p->height = rHeight + 2 > p->height ? rHeight + 2 : p->height;
    n->height = rHeight > lHeight ? rHeight + 1 : lHeight + 1;
    return p;
}

static int height(Node n) {
    if (n == NULL) {
        return -1;
    } else {
        return n->height;
    }
}

static int max(int a, int b) {
    return a > b ? a : b;
}