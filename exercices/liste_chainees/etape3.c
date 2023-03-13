#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int main()
{
    Liste liste;
    Node *node;          // creation dynamique

    liste_init(&liste);    // Initialisation de la liste
    
    // Allocation dynamique d'un noeud
    node = malloc( sizeof(Node) );
    if (node == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation du noeud
    node->data = 42;
    node->next = NULL;

    // Ajout du noeud à la liste
    liste.first = node;
    liste.count++;

    liste_print_entete(&liste); // Affichage de la liste
    liste_print( &liste);

    // Libération de la mémoire allouée
    free(node);

    return EXIT_SUCCESS;
}


