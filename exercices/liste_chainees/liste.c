#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

// Etat initial d'une liste
void liste_init( Liste *liste )
{
    liste->count = 0;
    liste->first = NULL;
}

// Affichage données de la l'entete de la liste
void liste_print_entete( Liste *liste )
{
    printf("Entete liste: count=%d first=%p\n", liste->count, liste->first);
}

// Affichage des elements de la liste
void liste_print( Liste *liste)
{
    Node *p = liste->first;

    while (p != NULL) {
        printf("\tElement: data:%d next:%p\n", p->data, p->next);
        p = p->next;
    }
}

// Creation dynamique d'un noeud
Node *node_create(int data)
{
    Node *node;          // creation dynamique

    node = malloc( sizeof(Node) );
    if (node == NULL) {
        fprintf(stderr, "Erreur allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation du noeud
    node->data = data;
    node->next = NULL;

    return(node);
}

// Affecter element suivant à un noeud
void node_set_next(Node *node, Node *next)
{
    node->next = next;
}

// Libération de la mémoire allouée pour les éléments de la liste
void liste_free(Liste *liste)
{
    Node *p = liste->first;
    Node *p_next;

    while (p != NULL) {
        p_next = p->next;
        free(p);
        p = p_next;
    }
}