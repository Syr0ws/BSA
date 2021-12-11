typedef struct Node {

    char* word;
    unsigned int occurrences;

    struct Node* rightChild;
    struct Node* leftChild;

} T_Node;

typedef T_Node* T_Tree;

T_Tree create_node(char* word);

T_Tree add_node(T_Tree tree, char* word);

T_Tree remove_occurrence(T_Tree tree, char* word, int n);

void display_tree(T_Tree tree, char first);

int is_tree_perfect(T_Tree tree);

int is_equilibrate(T_Tree tree);

int height(T_Tree tree);

int size(T_Tree tree);