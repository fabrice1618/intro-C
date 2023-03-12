#include <stdlib.h>
#include <stdio.h>

// Element de la liste
typedef struct node {
    int data;
    struct node *next;
} Node;

// Entete de la liste
typedef struct header {
    int count;
    Node *first;
} ListHeader;

int main()
{
    ListHeader liste;
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

    // Affichage de la liste
    printf("Entete liste:\n");
    printf("\tcount:%d\n", liste.count);
    printf("\tfirst:%p\n", liste.first);

    p = liste.first;
    while (p != NULL) {
        printf("Element liste:\n");
        printf("\tdata:%d\n", p->data);
        printf("\tnext:%p\n", p->next);
        p = p->next;
    }

    return EXIT_SUCCESS;
}
