#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "arbre.h"

// General utils functions

char* to_lowercase(char* word) {

    char* lowercase = NULL;
    unsigned int length = 0, i = 0;

    if(word == NULL) return NULL;

    length = strlen(word);
    lowercase = malloc((length + 1) * sizeof(char));

    if(lowercase == NULL) return NULL;

    for(i; i < length; i++) lowercase[i] = tolower(word[i]);

    lowercase[i] = '\0';

    return lowercase;
}

char* dynstrcpy(char* str) {

    char* copy = NULL;
    unsigned int length;

    if(str == NULL) return NULL;

    length = strlen(str);

    if(length == 0) return NULL;

    copy = (char*) malloc(length * sizeof(char));

    if(copy != NULL) strcpy(copy, str);

    return copy;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// Binary search trees related utils functions

T_Node* find_node(T_Tree tree, char* word) {

    T_Node* current = tree;
    int cmp = 1;

    if(tree == NULL || word == NULL) return NULL;

    while(current != NULL && cmp != 0) {

        cmp = strcmp(current->word, word);

        if(cmp == 1) current = current->leftChild;
        else if(cmp == -1) current = current->rightChild;
    }
    return current;
}

T_Node* find_desc_successor(T_Node* node) {

    T_Node* current = NULL;

    if(!node->rightChild) return NULL;

    current = node->rightChild;

    while(current && current->leftChild) current = current->leftChild;

    return current;
}

int tree_height(T_Tree tree) {

    if(tree == NULL) 
        return -1;

    if(tree->leftChild == NULL && tree->rightChild == NULL) 
        return 0;

    return 1 + max(tree_height(tree->leftChild), tree_height(tree->rightChild));
}

unsigned int tree_size(T_Tree tree) {

    unsigned int nodes = 0;

    if(tree != NULL)
        nodes += 1;

    if(tree->leftChild)
        nodes += tree_size(tree->leftChild);

    if(tree->rightChild)
        nodes += tree_size(tree->rightChild);

    return nodes;
}

void destruct_node(T_Node* node) {

    if(node == NULL) return;

    free(node->word);
    free(node);
}

// Functions

T_Node* create_node(char* word) {

    T_Node* node = 0;

    if(word == NULL) return node;

    node = (T_Node*) malloc(sizeof(T_Node));

    if(node == NULL) return node;

    node->word = word;
    node->occurrences = 1;
    node->leftChild = 0;
    node->rightChild = 0;

    return node;
}

T_Tree add_node(T_Tree tree, char* word) {

    T_Node* node = 0;
    T_Node* current = tree;
    T_Node* previous = 0;
    char* lowercase = 0;
    unsigned int found = 0;
    int cmp = 0;

    lowercase = to_lowercase(word);

    if(lowercase == NULL) return NULL;

    while(current != NULL && !found) {

        previous = current;

        cmp = strcmp(current->word, word);

        if(cmp == 0) {

            free(lowercase);
            current->occurrences++;
            found = 1;

        } else if(cmp == 1) { 
        
            current = current->leftChild;

        } else current = current->rightChild;
    }

    if(found) return tree;

    node = create_node(lowercase);

    if(node == NULL) { 
        free(lowercase); 
        return NULL; 
    }

    if(previous == NULL) return node;

    cmp = strcmp(previous->word, word);

    if(cmp == 1) previous->leftChild = node;
    else if(cmp == -1) previous->rightChild = node;

    return tree;
}

T_Tree remove_occurrence(T_Tree tree, char* word, int n) {

    T_Node* temp = NULL;
    char* copy = NULL;
    int cmp = 0;

    if(tree == NULL) 
        return NULL;

    cmp = strcasecmp(tree->word, word);

    // Mot plus petit -> suppression dans sous-arbre gauche. 
    if(cmp == 1) {
        tree->leftChild = remove_occurrence(tree->leftChild, word, n);
        return tree;
    }

    // Mot plus grand -> suppression dans sous-arbre droit. 
    if(cmp == -1) {
        tree->rightChild = remove_occurrence(tree->rightChild, word, n);
        return tree;
    }

    // Cas où le nb occurrences à supprimer < nb occurrences mot.
    // Transtypage utilisé à cause de la conversion unsigned int -> int.
    if((int) (tree->occurrences) - n > 0) {
        tree->occurrences -= n;
        return tree;
    }

    // Cas 1 : Deux fils.
    if(tree->leftChild != NULL && tree->rightChild != NULL) {

        // Dans la suppression, on n'a besoin que de la définition
        // partielle du successeur d'un noeud. Il aura toujours un
        // successeur dans ce cas.
        temp = find_desc_successor(tree);

        if(temp == NULL)
            return tree;

        copy = dynstrcpy(temp->word);

        if(copy == NULL) 
            return tree;

        tree->word = copy;
        tree->occurrences = temp->occurrences;
        tree->rightChild = remove_occurrence(tree->rightChild, temp->word, temp->occurrences);

        return tree;
    }

    // Cas 2 : 1 fils (gauche).
    if(tree->leftChild != NULL) {
        temp = tree->leftChild;
        destruct_node(tree);
        return temp;
    }

    // Cas 3 : 1 fils (droit).
    if(tree->rightChild != NULL) {
        temp = tree->rightChild;
        destruct_node(tree);
        return temp;
    }

    // Cas 4 : Aucun fils.
    destruct_node(tree);

    return NULL;
}

void display_tree(T_Tree tree, char current) {

    if(tree == NULL) {
        printf("Arbre vide.");
        return;
    }

    if(tree->leftChild) 
        display_tree(tree->leftChild, tree->word[0]);

    if(current != tree->word[0]) printf("%c-- ", toupper(tree->word[0]));
    else printf("    ");
    
    printf("%s [%d]\n", tree->word, tree->occurrences);

    if(tree->rightChild)
        display_tree(tree->rightChild, tree->word[0]);
}

int is_tree_perfect(T_Tree tree) {

    int height = tree_height(tree);
    int size = tree_size(tree);

    return size == pow(2, height+1) - 1;
}