
#include <stdio.h>

typedef struct node *Dict;

// PART 1
Dict buildDict(FILE *file);

// PART 2
void searchDict(Dict dict, char *query);

// PART 3
void listFrequent(Dict dict);


// YOU ALSO NEED TO IMPLEMENT
void freeDict(Dict dict);