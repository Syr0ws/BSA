#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree-list.h"

TreeList* create_treelist() {

    TreeList* list = (TreeList*) malloc(sizeof(TreeList));

    if(list == NULL)
        return NULL;

    list->head = NULL;

    return list;
}

TreeListNode* insert_treelist_begining(TreeList* list, T_Tree tree, char* id) {

    TreeListNode* node = NULL;

    if(list == NULL || id == NULL)
        return NULL;

    node = (TreeListNode*) malloc(sizeof(TreeListNode));

    if(node == NULL)
        return NULL;

    node->id = id;
    node->tree = tree;
    node->next = list->head;
    list->head = node;

    return node;
}

int remove_from_treelist(TreeList* list, char* id) {

    TreeListNode* node = NULL;
    TreeListNode* previous = NULL;
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

    if(previous == NULL) list->head = node->next;
    else previous->next = node->next;

    destruct_tree(node->tree);

    free(node->id);
    free(node);

    return 1;
}

TreeListNode* get_treelist_node(TreeList* list, char* id) {

    TreeListNode* node = NULL;
    int cmp = 0;

    if(list == NULL || id == NULL)
        return NULL;

    node = list->head;

    while(node != NULL && (cmp = strcmp(id, node->id)) != 0) {
        node = node->next;
    }
    return node;
}

void destroy_treelist(TreeList* list) {

    TreeListNode* node = NULL;
    TreeListNode* temp = NULL;

    if(list == NULL) return;

    node = list->head;

    while(node != NULL) {

        temp = node->next;

        destruct_tree(node->tree);

        free(node);
        node = temp;
    }
    free(list);
}

void display_treelist_ids(TreeList* list) {

    TreeListNode* node = NULL;

    if(list == NULL) {
        printf("List d'arbres invalide.\n");
        return;
    }

    if(list->head == NULL) {
        printf("Liste d'arbres vide.\n");
        return;
    }

    node = list->head;

    printf("Affichage du contenu de la liste d'arbres :\n");

    while(node != NULL) {
        printf("- %s\n", node->id);
        node = node->next;
    }
}