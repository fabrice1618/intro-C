#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int main()
{
    Liste liste;
    Node *node;          // creation dynamique

    liste_init(&liste);    // Initialisation de la liste
    
    // Création de 4 noeuds
    for (int i = 0; i < 4; i++) {
        node = node_create(i);
        node_set_next(node, liste.first);
        liste.first = node;
        liste.count++;
    }

    liste_print_entete(&liste); // Affichage de la liste
    liste_print( &liste);

    // Libération de la mémoire allouée
    liste_free(&liste);

    return EXIT_SUCCESS;
}
