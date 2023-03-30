#include <limits.h>

#include "reference.h"

void swap(int *p1, int *p2)
{
    int tmp;
    
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void tri5(int *tableau, int debut, int fin)
{
    if(debut >= fin) 
        return;

    int pivot = debut;
    int montant = debut;
    int descendant = fin;

    while (montant < descendant) {
        while(tableau[montant] <= tableau[pivot] && montant < fin)
            montant++;

        while(tableau[descendant] > tableau[pivot])
            descendant--;

        if(montant < descendant) {
            swap(&tableau[montant], &tableau[descendant]);
        }
    }
    swap(&tableau[pivot], &tableau[descendant]);
    tri5(tableau, debut, descendant - 1);
    tri5(tableau, descendant + 1, fin);
}

int main() {
    
    int tableau[] = { 2, 8, 6, 4, 10, 10, 12, 2, 6, 4 }; 
    int taille_tableau = sizeof(tableau) / sizeof(int);

    init_reference(tableau, taille_tableau);

    tri5(tableau, 0, taille_tableau-1);

    controler_reference( tableau, taille_tableau);

    return EXIT_SUCCESS;
}