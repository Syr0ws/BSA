#ifndef _T_TREE_
#define _T_TREE_

#include "lexicon.h"

typedef struct Node {

    char* word;
    unsigned int occurrences;

    struct Node* rightChild;
    struct Node* leftChild;

} T_Node;

typedef T_Node* T_Tree;

T_Tree create_node(char* word);

T_Tree add_occurrence(T_Tree tree, char* word);

T_Tree remove_occurrence(T_Tree tree, char* word, int n);

void display_tree(T_Tree tree);

int is_perfect(T_Tree tree);

int is_equilibrate(T_Tree tree);

Lexicon* get_lexicon(T_Tree tree);

void destruct_tree(T_Tree tree);

#endif