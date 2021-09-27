typedef struct node *Node;

struct node {
    char *verb;
    char *translation;
    int noSearches;
    int height;
    Node left;
    Node right;
};

void freeBST(Node n);
Node insertNode(Node n, char *verb, char *translation);
void printBST(Node n);

