#ifndef _T_LIST_
#define _T_LIST_

#include "arbre.h"

typedef struct TreeListNode {
    
    char* id;
    T_Tree tree;
    struct TreeListNode* next;

} TreeListNode;

typedef struct TreeList {

    TreeListNode* head;

} TreeList;

TreeList* create_treelist();

TreeListNode* insert_treelist_begining(TreeList* list, T_Tree tree, char* id);

int remove_from_treelist(TreeList* list, char* id);

TreeListNode* get_treelist_node(TreeList* list, char* id);

void display_treelist_ids(TreeList* list);

int destroy_treelist(TreeList* list);

#endif