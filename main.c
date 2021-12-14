#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "arbre.h"
#include "tree-list.h"
#include "utils.h"

T_List* list = NULL;

void do_create_tree_list();

void do_create_tree();

void do_display_tree();

void do_add_word();

char* do_input_string(char* message, size_t size);

char* do_input_id();

void display_menu();

void memory_error();

void compute_input(char choice);

int main() {

    char choice;

    do_create_tree_list();

    do {

        display_menu();

        choice = getchar();
        clear_input();

        compute_input(choice);

    } while (choice != '9');
    
    return 0;
}

void compute_input(char choice) {

    switch (choice) {
    case '1':
        printf("Choix 1 : Creer un nouvel arbre.\n");
        do_create_tree();
        break;
    case '2':
        printf("Choix 2 : Afficher un arbre.\n");
        do_display_tree();
        break;
    case '3':
        printf("Choix 3 : Ajouter un mot dans un arbre.\n");
        do_add_word();
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

void memory_error() {
    printf("Erreur : Un probleme interne est survenu.\n");
}

char* do_input_id() {
    return do_input_string("Entrez un identifiant : \n", 10);
}

char* do_input_string(char* message, size_t size) {

    char* id = NULL;

    printf(message);
    id = input_string(10);

    if(id == NULL) memory_error();

    return id;
}

void do_create_tree_list() {

    if(list != NULL) return;

    list = create_tree_list();

    if(list == NULL) memory_error();
}

void do_create_tree() {

    char* id = NULL;
    int result = -1;

    if(list == NULL) {
        memory_error();
        return;
    }

    id = do_input_id();

    if(id == NULL) return;

    result = insert_tree(list, NULL, id);
    
    if(result == 1) 
        printf("Un arbre portant l'identifiant %s a ete cree.", id);
    else
        printf("Erreur : Un probleme est survenu lors de la creation de l'arbre.");
}

void do_display_tree() {

    TL_Node* node = NULL;
    char* id = NULL;

    id = do_input_id();

    if(id == NULL) return;

    node = get_tl_node(list, id);

    if(node != NULL) {

        printf("Affichage de l'arbre d'identifiant '%s'.\n", id);
        display_tree(node->tree, '\0');

    } else printf("Erreur : Aucun arbre ayant l'identifiant '%s' n'a ete trouve.\n", id);

    free(id);
}

void do_add_word() {

    TL_Node* node = NULL;
    T_Tree tree = NULL;

    char* word = NULL;
    char* id = NULL;
    int result = -1;

    id = do_input_id();

    if(id == NULL) return;

    node = get_tl_node(list, id);

    if(node == NULL) {
        printf("Erreur : Aucun arbre ayant l'identifiant '%s' n'a ete trouve.", id);
        return;
    }

    word = do_input_string("Entrez un mot : \n", 10);

    if(word != NULL) {

        tree = add_node(node->tree, word);

        if(tree != NULL) {

            // result = replace_tree(list, tree, id);
            printf("Le mot '%s' a ete insere dans l'arbre '%s'.\n", word, id);

        } else printf("Erreur : L'insertion du mot '%s' dans l'arbre '%s' a echoue.\n", word, id);
    }

    free(id);
    free(word);
}