#include <stdio.h>
#include <stdlib.h>

#include "arbre.h"
#include "lexicon.h"
#include "tree-list.h"
#include "utils.h"

// Global variables.

TreeList* GLOBAL_LIST = NULL;
TreeListNode* GLOBAL_NODE = NULL;

// Function declarations.

void display_tree_menu();

void display_main_menu();

void compute_tree_menu_choice(char choice);

void compute_main_menu_choice(char choice);

void open_tree_menu();

void open_main_menu();

void show_internal_error();

void mdo_select_tree();

void mdo_create_tree();

void mdo_remove_tree();

void mdo_display_tree();

void do_add_occurrence(T_Tree tree);

void do_remove_occurrence(T_Tree tree);

void do_is_perfect(T_Tree tree);

void do_is_equilibrate(T_Tree tree);

void do_display_lexicon(T_Tree tree);

char* do_input_string(char* message, size_t size);

char* do_input_id();

// Implementation.

int main() {

    GLOBAL_LIST = create_treelist();

    if(GLOBAL_LIST != NULL) {
        
        open_main_menu();
        destroy_treelist(GLOBAL_LIST);

    } else show_internal_error();

    return 0;
}

void display_tree_menu() {

    printf("\n-------- Menu Arbre --------\n");
    printf("Entrer un choix parmi les suivants :\n");
    printf("1. Ajouter un mot dans l'arbre courant.\n");
    printf("2. Retirer un mot de l'arbre courant.\n");
    printf("3. Verifier si l'arbre courant est parfait.\n");
    printf("4. Verifier si l'arbre courant est equilibre.\n");
    printf("5. Afficher le lexique de l'arbre courant.\n");
    printf("6. Afficher l'arbre courant.\n");
    printf("7. Retour au menu principal.\n");
    printf("\nArbre courant : '%s'\n", GLOBAL_NODE->id);
    printf("-----------------------------------\n");
}

void display_main_menu() {

    printf("\n-------- Menu general --------\n");
    printf("Entrer un choix parmi les suivants :\n");
    printf("1. Selectionner un arbre.\n");
    printf("2. Creer un nouvel arbre.\n");
    printf("3. Supprimer un arbre.\n");
    printf("4. Afficher un arbre.\n");
    printf("5. Afficher la liste des arbres.\n");
    printf("6. Tester la similarite de deux textes.\n");
    printf("7. Quitter.\n");
    printf("-----------------------------------\n");
}

void compute_tree_menu_choice(char choice) {

    switch (choice) {
    case '1':
        printf("Choix %c : Ajouter un mot dans l'arbre courant.\n", choice);
        do_add_occurrence(GLOBAL_NODE->tree);
        break;
    case '2':
        printf("Choix %c : Retirer un mot de l'arbre courant.\n", choice);
        do_remove_occurrence(GLOBAL_NODE->tree);
        break;
    case '3':
        printf("Choix %c : Verifier si l'arbre courant est parfait.\n", choice);
        do_is_perfect(GLOBAL_NODE->tree);
        break;
    case '4':
        printf("Choix %c : Verifier si l'arbre courant est equilibre.\n", choice);
        do_is_equilibrate(GLOBAL_NODE->tree);
        break;
    case '5':
        printf("Choix %c : Afficher le lexique de l'arbre courant.\n", choice);
        do_display_lexicon(GLOBAL_NODE->tree);
        break;
    case '6':
        printf("Choix %c : Afficher l'arbre courant.\n", choice);
        display_tree(GLOBAL_NODE->tree, '\0');
        break;
    case '7':
        printf("Choix %c : Retour au menu principal.\n", choice);
        break;
    default:
        printf("Erreur : Choix invalide. Veuillez reessayer.\n");
        break;
    }
}

void compute_main_menu_choice(char choice) {

    switch (choice) {
    case '1':
        printf("Choix %c : Selectionner un arbre.\n", choice);
        mdo_select_tree();
        break;
    case '2':
        printf("Choix %c : Creer un nouvel arbre.\n", choice);
        mdo_create_tree();
        break;
    case '3':
        printf("Choix %c : Supprimer un arbre.\n", choice);
        mdo_remove_tree();
        break;
    case '4':
        printf("Choix %c : Afficher un arbre.\n", choice);
        mdo_display_tree();
        break;
    case '5':
        printf("Choix %c : Afficher la liste des arbres.\n", choice);
        display_treelist_ids(GLOBAL_LIST);
        break;
    case '6':
        printf("Choix %c : Tester la similarite de deux textes.\n", choice);
        break;
    case '7':
        printf("A bientot !\n");
        break;
    default:
        printf("Erreur : Choix invalide. Veuillez reessayer.\n");
        break;
    }
}

void open_tree_menu() {

    char choice;

    do {

        display_tree_menu();

        choice = getchar();
        clear_input();

        compute_tree_menu_choice(choice);

    } while(choice != '7');
}

void open_main_menu() {

    char choice;

    do {

        display_main_menu();

        choice = getchar();
        clear_input();

        compute_main_menu_choice(choice);

    } while(choice != '7');
}

void show_internal_error() {
    printf("Erreur : Un probleme interne est survenu. Veuillez ressayer.");
}

void mdo_select_tree() {

    char* id = NULL;
    int result = -1;

    id = do_input_id();

    if(id == NULL) return;

    GLOBAL_NODE = get_treelist_node(GLOBAL_LIST, id);

    if(GLOBAL_NODE != NULL) {

        free(id); // Liberation mémoire.
        open_tree_menu();

    } else {

        printf("Aucun arbre ayant l'identifiant '%s' n'a ete trouve.\n", id);
        free(id);
    }
}

void mdo_create_tree() {

    char* id = NULL;
    int result = -1;

    id = do_input_id();

    if(id == NULL) return;

    GLOBAL_NODE = insert_treelist_begining(GLOBAL_LIST, NULL, id);

    if(GLOBAL_NODE != NULL) {

        printf("Un arbre d'identifiant '%s' a ete cree.\n", id);
        open_tree_menu(); // Ouverture du menu pour l'arbre créé.

    } else {

        free(id);
        show_internal_error();
    }
}

void mdo_remove_tree() {

    char* id = NULL;
    int result = -1;

    id = do_input_id();

    // Erreur sur la saisie de l'identifiant.
    if(id == NULL) return;

    result = remove_from_treelist(GLOBAL_LIST, id);

    if(result == 1) 
        printf("L'arbre d'identifiant '%s' a ete supprime.\n", id);
    else if(result == 0) 
        printf("Aucun arbre ayant l'identifiant '%s' n'a ete trouve.\n", id);
    else 
        show_internal_error();

    free(id);
}

void mdo_display_tree() {

    TreeListNode* node = NULL;
    char* id = NULL;
    int result = -1;

    id = do_input_id();

    // Erreur sur la saisie de l'identifiant.
    if(id == NULL) return;

    node = get_treelist_node(GLOBAL_LIST, id);

    if(node != NULL) {

        free(id); // Liberation mémoire.
        display_tree(node->tree, '\0');

    } else {

        printf("Aucun arbre ayant l'identifiant '%s' n'a ete trouve.\n", id);
        free(id);
    }
}

void do_add_occurrence(T_Tree tree) {

    T_Tree new = NULL;
    char* word = do_input_string("Entrez un mot :\n", 10);

    if(word != NULL) {

        new = add_occurrence(tree, word);

        if(new != NULL) {

            printf("Le mot '%s' a ete insere dans l'arbre.\n", word);
            GLOBAL_NODE->tree = new;
            free(word);

        } else show_internal_error();

    } else show_internal_error();
}

void do_remove_occurrence(T_Tree tree) {

    T_Tree new = NULL;
    char* word = do_input_string("Entrez un mot :\n", 10);

    if(word != NULL) {

        new = remove_occurrence(tree, word, 1);

        printf("Le mot '%s' a ete supprime de l'arbre.\n", word);

        if(new != GLOBAL_NODE->tree) 
            GLOBAL_NODE->tree = new;

        free(word);

    } else show_internal_error();
}

void do_is_perfect(T_Tree tree) {
    
    int result = is_perfect(tree);

    if(result == 1)
        printf("L'arbre est parfait.\n");
    else if(result == 0)
        printf("L'arbre n'est pas parfait.\n");
    else 
        show_internal_error();
}

void do_is_equilibrate(T_Tree tree) {

    int result = is_equilibrate(tree);

    if(result == 1)
        printf("L'arbre est equilibre.\n");
    else if(result == 0)
        printf("L'arbre n'est pas equilibre.\n");
    else 
        show_internal_error();
}

void do_display_lexicon(T_Tree tree) {

    Lexicon* lexicon = get_lexicon(tree);

    if(lexicon != NULL) {

        display_lexicon(lexicon);
        destruct_lexicon(lexicon);

    } else show_internal_error();
}

char* do_input_id() {
    return do_input_string("Entrez un identifiant : \n", 10);
}

char* do_input_string(char* message, size_t size) {

    char* id = NULL;

    printf(message);
    id = input_string(10);

    if(id == NULL) show_internal_error();

    return id;
}