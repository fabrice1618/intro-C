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

int main()
{
    ListHeader liste;
    
    listHeader_init(&liste);
    listHeader_print(&liste);

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