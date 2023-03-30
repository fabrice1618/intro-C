#include "reference.h"

int *tableau_reference = NULL;

void init_reference(int *source, size_t size)
{
    tableau_reference = (int *)malloc( size * sizeof(int) );
    if ( tableau_reference == NULL ) {
        fprintf(stderr, ERREUR_MEMOIRE);
        exit(1);
    }
    memcpy( tableau_reference, source, size * sizeof(int) ); 
}

int fctn_comparaison( const void *first, const void *second ) 
{
    int firstInt = * (const int *) first;
    int secondInt = * (const int *) second;

    return firstInt - secondInt;
}

void controler_reference( int *tab, int size)
{
    char etat[7];
    bool resultat = true;

    assert(tableau_reference != NULL);

    qsort( tableau_reference, size, sizeof(int), fctn_comparaison );

    for( int i = 0; i < size; i++ ) {
        if (tab[i] == tableau_reference[i])
            strcpy(etat, ETAT_OK);
        else {
            strcpy(etat, ETAT_ERREUR);
            resultat = false;
        }
        printf( "%d: %d %d %s\n", i, tableau_reference[i], tab[i], etat );
    }

    printf((resultat) ? TEST_OK : TEST_NOK);

    free(tableau_reference);
}

void dump( int *tab, int size)
{
    for( int i = 0; i < size; i++ ) {
        printf( "%d: %d\n", i, tab[i] );
    }
}
