#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"




int main(int argc, char **argv) {

    Node tree = insertNode(NULL, "premiere", "firstly");

    tree = insertNode(tree, "deuxieme", "secondly");
    tree = insertNode(tree, "ameliorer", "to improve idk");
    tree = insertNode(tree, "bouger", "to move");
    tree = insertNode(tree, "courir", "to run");
    tree = insertNode(tree, "degager", "to get out of the way");

    printBST(tree);

    return 0;
}