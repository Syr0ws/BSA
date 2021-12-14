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

    char choice;

    do {

        display_menu();

        choice = getchar();
        clear_input();

        compute_input(choice);

    } while (choice != '9');
    
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

    switch (choice) {
    case '1':
        printf("Choix 1 : Creer un nouvel arbre.\n");
        break;
    case '2':
        printf("Choix 2 : Afficher un arbre.\n");
        break;
    case '3':
        printf("Choix 3 : Ajouter un mot dans un arbre.\n");
        break;
    case '4':
        printf("Choix 4 : Retirer un mot d'un arbre.\n");
        break;
    case '5':
        printf("Choix 5 : Verifier si un arbre est parfait.\n");
        break;
    case '6':
        printf("Choix 6 : Verifier si un arbre est equilibre.\n");
        break;
    case '7':
        printf("Choix 7 : Transformer un arbre en un lexique et l'afficher.\n");
        break;
    case '8':
        printf("Choix 8 : Tester la similarite de deux textes.\n");
        break;
    case '9':
        printf("A bientot !\n");
        break;
    default:
        printf("Erreur : Choix invalide. Veuillez reessayer.\n");
        break;
    }
}