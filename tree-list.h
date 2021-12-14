#ifndef _T_LIST_
#define _T_LIST_

#include "arbre.h"

typedef struct TL_Node {
    
    char* id;
    T_Tree tree;
    struct TL_Node* next;

} TL_Node;

typedef struct T_List {

    TL_Node* head;

} T_List;

T_List* create_tree_list();

int insert_tree_begining(T_List* list, T_Tree tree, char* id);

int insert_tree(T_List* list, T_Tree tree, char* id);

int remove_tree(T_List* list, char* id);

TL_Node* get_tl_node(T_List* list, char* id);

int destroy_tree_list(T_List* list);

#endif