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
Node *node_create(int data);
void node_set_next(Node *node, Node *next);

int main()
{
    ListHeader liste;
    Node *node;          // creation dynamique

    listHeader_init(&liste);    // Initialisation de la liste
    
    // Création de 4 noeuds
    for (int i = 0; i < 4; i++) {
        node = node_create(i);
        node_set_next(node, liste.first);
        liste.first = node;
        liste.count++;
    }

    listHeader_print(&liste); // Affichage de la liste
    list_print( &liste);

    // Libération de la mémoire allouée
    Node *p = liste.first;
    Node *p_next;

    while (p != NULL) {
        p_next = p->next;
        free(p);
        printf("free 1 element\n");
        p = p_next;
    }

    return EXIT_SUCCESS;
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