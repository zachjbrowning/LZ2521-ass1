#include <stdio.h>
#include <stdlib.h>
#include "Dict.h"

#define MAX 8192


int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Invalid arguments. Correct usage:  '%s [filename].\n'", argv[0]);
        return 0;
    }

    Dict dictionary = buildDict(argv[1]);

    if (dictionary == NULL) {
        printf("Please implememnt Part 1 to use translator.\n");
        return 0;
    }

    return 0;
}