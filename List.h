#include "Dict.h"
typedef struct llnode *LLNode;
struct llnode {
    int value;
    Dict translation;
    LLNode previous;
    LLNode next;
};

typedef struct llist *LList;
struct llist{
    int count;
    LLNode first;
    LLNode last;
};

LList newList(void);
void insertInOrder(LList list, int value, Dict translation);
void freeList(LList list);
void removeLowest(LList list);