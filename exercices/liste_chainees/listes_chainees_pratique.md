# Liste chainée pratique

Nous allons créer une liste simplement chainée contenant des entiers.
Vous pouvez créer des listes chaînées contenant n'importe quel type d'éléments : entiers, chaines caractères, structures, tableaux, voir même d'autres listes chaînées...

## Définition des types de données

liste1.c:

```C
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

```

- On crée le type Node qui est une structure contenant un entier (data) et un pointeur sur le prochain élément (next). 
- On crée le type List_header contenant le nombre d'éléments (count) et un pointeur sur le premier élément.

## Création d'une liste vide

liste2.c:

```C
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
} listHeader;

// Prototypes de fonctions
void listHeader_init( listHeader *liste);
void listHeader_print( listHeader *liste);

int main()
{
    listHeader liste;
    
    listHeader_init(&liste);
    listHeader_print(&liste);

    return EXIT_SUCCESS;
}

// Etat initial d'une liste
void listHeader_init( listHeader *liste)
{
    liste->count = 0;
    liste->first = NULL;
}

// Affichage données de la l'entete de la liste
void listHeader_print( listHeader *liste)
{
    printf("Entete liste:\n");
    printf("\tcount:%d\n", liste->count);
    printf("\tfirst:%p\n", liste->first);

}
```

Il est important de toujours initialiser la liste chaînée à NULL. Le cas échéant, elle sera considérée comme contenant au moins un élément. C'est une erreur fréquente. A garder en mémoire, il est plus sage de toujours initialiser vos pointeurs.

## Fonctions de gestion dynamique de mémoire

```
SYNOPSIS

#include <stdlib.h>

void *malloc(size_t size);
void free(void *ptr);

DESCRIPTION

The malloc() function allocates size bytes and returns a pointer
to the allocated memory.  The memory is not initialized.  If size
is 0, then malloc() returns either NULL, or a unique pointer
value that can later be successfully passed to free().

The free() function frees the memory space pointed to by ptr,
which must have been returned by a previous call to malloc().Otherwise, or if free(ptr) has already been called before, undefined behavior occurs.  If ptr is NULL, no operation is performed.

RETURN VALUE

The malloc() function return a pointer to the
allocated memory, which is suitably aligned for any built-in
type.  On error, these functions return NULL.  NULL may also be
returned by a successful call to malloc() with a size of zero.

The free() function returns no value.
```

## Allocation dynamique d'un élément

liste3.c

```C
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
```

## Ajout d'un élément en tête de liste

liste4.c

```C

```