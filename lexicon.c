#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexicon.h"

L_Node* create_lexicon_node(char* word) {

    L_Node* node = (L_Node*) malloc(sizeof(L_Node));

    if(node == NULL)
        return NULL;

    node->word = word;
    node->next = NULL;

    return node;
}

Lexicon* create_lexicon() {

    Lexicon* lexicon = (Lexicon*) malloc(sizeof(Lexicon));

    if(lexicon == NULL)
        return NULL;

    lexicon->head = NULL;

    return lexicon;
}

int insert_begining_lexicon(Lexicon* lexicon, char* word) {

    L_Node* node = NULL;

    if(lexicon == NULL || word == NULL)
        return -1;

    node = create_lexicon_node(word);

    if(node == NULL)
        return -1;

    node->next = lexicon->head;
    lexicon->head = node;

    return 1;
}

void destruct_lexicon(Lexicon* lexicon) {

    L_Node* node = NULL;
    L_Node* temp = NULL;

    if(lexicon == NULL) return;

    node = lexicon->head;

    while(node != NULL) {

        temp = node->next;
        free(node);
        node = temp;
    }
    free(lexicon);
}

void display_lexicon(Lexicon* lexicon) {

    L_Node* node = NULL;

    if(lexicon == NULL) {
        printf("Lexique invalide.");
        return;
    }

    if(lexicon->head == NULL) {
        printf("Lexique vide.");
        return;
    }

    printf("Affichage du lexique : ");

    node = lexicon->head;

    while(node != NULL) {

        printf("%s", node->word);

        if(node->next != NULL) printf(", ");

        node = node->next;
    }
    printf("\n");
}

float jaccard_index(Lexicon* lexicon1, Lexicon* lexicon2) {

    L_Node* n1;
    L_Node* n2;

    int cmp = 0;

    unsigned int unionIndex = 0;
    unsigned int intersectIndex = 0;

    if(lexicon1 == NULL && lexicon2 == NULL)
        return -1;

    if(lexicon1 != NULL) 
        n1 = lexicon1->head;

    if(lexicon2 != NULL)
        n2 = lexicon2->head;

    while(n1 != NULL || n2 != NULL) {

        if(n1 != NULL && n2 != NULL) {

            cmp = strcmp(n1->word, n2->word);

            if(cmp < 0) {
                
                // n1->word < n2->word
                n1 = n1->next;

            } else if(cmp > 0) {

                // n2->word < n1->word
                n2 = n2->next;

            } else {

                // n1->word = n2->word
                intersectIndex += 1;
                n1 = n1->next;
                n2 = n2->next;
            }

        } else if(n1 != NULL) {

            n1 = n1->next;

        } else {

            n2 = n2->next;
        }
        unionIndex += 1;
    }
    
    // Prevent division by 0.
    if(unionIndex == 0 || intersectIndex == 0) 
        return 0;

    return (float) intersectIndex / unionIndex;
}
