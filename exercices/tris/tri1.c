#include "reference.h"

void swap(int *p1, int *p2)
{
    int tmp;
    
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void tri1(int *tab, int taille)
{
    for(int i = taille; i > 1 ; i--) {

        int indice_max = 0;

        for (int j = 1; j < i; j++) 
            if(tab[j] > tab[indice_max])
                indice_max = j;

        swap(&tab[i-1], &tab[indice_max]);
    }
}

int main() {
    
    int tableau[] = { 10, 50, 30, 20, 40, 60 };
    int taille_tableau = sizeof(tableau) / sizeof(int);

    init_reference(tableau, taille_tableau);

    tri1(tableau, taille_tableau);

    controler_reference( tableau, taille_tableau);

    return EXIT_SUCCESS;
}