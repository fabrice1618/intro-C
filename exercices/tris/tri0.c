#include <time.h>

#include "reference.h"

bool tableau_trie(int *tab, int taille)
{
    bool resultat = true;
    int precedent = tab[0];
    int i = 1;

    while (resultat && i < taille) {
        if (tab[i] < precedent) 
            resultat = false;
        else
            precedent = tab[i++];
    }

    return resultat;
}

void tri0(int *tab, int taille)
{
    int aleatoire1;
    int aleatoire2;
    int tmp;
    int compteur = 0;

    assert( taille > 0 && taille < RAND_MAX);

    srand( time(NULL) );

    while (tableau_trie(tab, taille) == false) {

        aleatoire1 = rand() % taille;
        aleatoire2 = rand() % taille;

        if (aleatoire1 != aleatoire2) {
            tmp = tab[aleatoire1];
            tab[aleatoire1] = tab[aleatoire2];
            tab[aleatoire2] = tmp;         
        }
        
        if (++compteur % 100 == 0)
            printf("Compteur: %d\n", compteur);
    }
}

int main() {
    
    int tableau[] = { 10, 50, 30, 20, 40, 60 };
    int taille_tableau = sizeof(tableau) / sizeof(int);

    init_reference(tableau, taille_tableau);

    tri0(tableau, taille_tableau);

    controler_reference( tableau, taille_tableau);

    return EXIT_SUCCESS;
}