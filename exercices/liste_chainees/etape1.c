#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int main()
{
    Liste liste;
    Node node;          // creation statique
    Node *p;

    // Initialisation de la liste
    liste.count = 0;
    liste.first = NULL;

    // Initialisation du noeud
    node.data = 42;
    node.next = NULL;

    // Ajout du noeud à la liste
    liste.first = &node;
    liste.count++;

    // Affichage de l'entete de la liste
    printf("Entete liste: count=%d first=%p\n", liste.count, liste.first);

    // Affichage des elements de la liste
    p = liste.first;
    while (p != NULL) {
        printf("\tElement: data:%d next:%p\n", p->data, p->next);
        p = p->next;
    }

    return EXIT_SUCCESS;
}
