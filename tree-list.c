#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree-list.h"

T_List* create_tree_list() {

    T_List* list = (T_List*) malloc(sizeof(T_List));

    if(list == NULL)
        return NULL;

    list->head = NULL;

    return list;
}

int insert_tree_begining(T_List* list, T_Tree tree, char* id) {

    TL_Node* node = NULL;

    if(list == NULL || id == NULL)
        return -1;

    node = (TL_Node*) malloc(sizeof(TL_Node));

    if(node == NULL)
        return -1;

    node->id = id;
    node->tree = tree;
    node->next = list->head;
    list->head = node;

    return 1;
}

int insert_tree(T_List* list, T_Tree tree, char* id) {

    TL_Node* node = get_tl_node(list, id);

    if(node == NULL) 
        return insert_tree_begining(list, tree, id);

    node->tree = tree;

    return 1;
}

int remove_tree(T_List* list, char* id) {

    TL_Node* node = NULL;
    TL_Node* previous = NULL;
    int cmp = 0;

    if(list == NULL || id == NULL)
        return -1;

    if(list->head == NULL)
        return 0;

    node = list->head;

    while(node != NULL && (cmp = strcmp(id, node->id)) != 0) {
        previous = node;
        node = node->next;
    }

    if(node == NULL)
        return 0;

    if(previous == NULL) list->head = NULL;
    else previous->next = node->next;

    free(node->id);
    free(node);

    return 1;
}

TL_Node* get_tl_node(T_List* list, char* id) {

    TL_Node* node = NULL;
    int cmp = 0;

    if(list == NULL || id == NULL)
        return NULL;

    node = list->head;

    while(node != NULL && (cmp = strcmp(id, node->id)) != 0) {
        printf("%d\n", cmp);
        node = node->next;
    }
    return node;
}

int destroy_tree_list(T_List* list) {

    TL_Node* node = NULL;
    TL_Node* temp = NULL;

    if(list == NULL)
        return -1;

    node = list->head;

    while(node != NULL) {

        temp = node->next;
        // destruct_tree(node->tree);
        free(node);
        node = temp;
    }
    free(list);
    return 1;
}