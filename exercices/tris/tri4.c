#include <limits.h>

#include "reference.h"

void tri4(int *tab, int taille)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int *paniers;
    int nb_paniers;

    for (int i = 0; i < taille; i++) {
        if (tab[i] < mini)
            mini = tab[i];
        if (tab[i] > maxi)
            maxi = tab[i];
    }

    nb_paniers = maxi - mini + 1;
    paniers = (int *)calloc( nb_paniers, sizeof(int) );
    if ( paniers == NULL ) {
        fprintf(stderr, ERREUR_MEMOIRE);
        exit(1);
    }

    for (int i = 0; i < taille; ++i) {
        int indice_panier = tab[i] - mini;
        paniers[indice_panier]++;
    }

    int pos = 0;
    for (int i = 0; i < nb_paniers; i++) {
        for ( int j = 0; j < paniers[i]; j++) {
            tab[pos++] = i + mini;
        }
    }

    free(paniers);
}

int main() {
    
    int tableau[] = { 2, 8, 6, 4, 10, 10, 12, 2, 6, 4 }; 
    int taille_tableau = sizeof(tableau) / sizeof(int);

    init_reference(tableau, taille_tableau);

    tri4(tableau, taille_tableau);

    controler_reference( tableau, taille_tableau);

    return EXIT_SUCCESS;
}