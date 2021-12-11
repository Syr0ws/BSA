#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arbre.h"

unsigned int input_number(char* msg);

void clear_input();

void compute_input(char choice);

void display_menu();

int main() {

    T_Tree tree = NULL;

    tree = add_node(tree, "occurrence");
    tree = add_node(tree, "binaire");
    tree = add_node(tree, "binary");
    tree = add_node(tree, "recherche");
    tree = add_node(tree, "test");
    tree = add_node(tree, "plein");
    tree = add_node(tree, "arbre");
    tree = add_node(tree, "binaire");
    tree = add_node(tree, "plein");
    tree = add_node(tree, "occurrence");

    display_tree(tree, '\0');

    char c;

    do {

        display_menu();

        c = getchar();
        clear_input();

        compute_input(c);

    } while (c != '9');
    
    return 0;
}

unsigned int input_number(char* msg) {

    unsigned int number;

    printf("%s\n", msg);

    scanf("%u", &number);
    clear_input();

    return number;
}

void clear_input() {

    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void display_menu() {

    printf("\n-------- Menu de selection --------\n");
    printf("Entrer un choix parmi les suivants :\n");
    printf("1. Creer un nouvel arbre.\n");
    printf("2. Afficher un arbre.\n");
    printf("3. Ajouter un mot dans un arbre.\n");
    printf("4. Retirer un mot d'un arbre.\n");
    printf("5. Verifier si un arbre est parfait.\n");
    printf("6. Verifier si un arbre est equilibre.\n");
    printf("7. Transformer un arbre en un lexique (liste lineairement chainee) et afficher le lexique.\n");
    printf("8. Tester la similarite de deux textes.\n");
    printf("9. Quitter.\n");
    printf("-----------------------------------\n");
}

void compute_input(char choice) {

}