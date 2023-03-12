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

// Prototypes de fonctions
void listHeader_init( ListHeader *liste);
void listHeader_print( ListHeader *liste);
void list_print( ListHeader *liste);

int main()
{
    ListHeader liste;
    Node *node;          // creation dynamique

    listHeader_init(&liste);    // Initialisation de la liste
    
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

    listHeader_print(&liste); // Affichage de la liste
    list_print( &liste);

    // Libération de la mémoire allouée
    free(node);

    return EXIT_SUCCESS;
}

// Etat initial d'une liste
void listHeader_init( ListHeader *liste)
{
    liste->count = 0;
    liste->first = NULL;
}

// Affichage données de la l'entete de la liste
void listHeader_print( ListHeader *liste)
{
    printf("Entete liste:\n");
    printf("\tcount:%d\n", liste->count);
    printf("\tfirst:%p\n", liste->first);
}

// Affichage données de la liste
void list_print( ListHeader *liste)
{
    Node *p = liste->first;

    while (p != NULL) {
        printf("Element liste:\n");
        printf("\tdata:%d\n", p->data);
        printf("\tnext:%p\n", p->next);
        p = p->next;
    }

}