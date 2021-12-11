#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arbre.h"

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

    // display_tree(tree, '\0');

    tree = remove_occurrence(tree, "occurrence", 2);
    tree = remove_occurrence(tree, "plein", 2);
    tree = remove_occurrence(tree, "arbre", 2);
    tree = remove_occurrence(tree, "binaire", 2);
    tree = remove_occurrence(tree, "binary", 2);
    tree = remove_occurrence(tree, "test", 2);
    tree = remove_occurrence(tree, "recherche", 2);
    tree = remove_occurrence(tree, "recherche", 2);

    // tree = remove_occurrence(tree, "binaire", 1);

    display_tree(tree, '\0');

    return 0;
}