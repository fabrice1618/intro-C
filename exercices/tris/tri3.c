#include "reference.h"

void tri3(int *tab, int taille)
{
   for (int i = 1; i < taille; i++) {
       int elem = tab[i];

        int j = i;
        while(j > 0 && tab[j-1] > elem) {
            tab[j] = tab[j-1];
            j--;
        }
       tab[j] = elem;
   }
}


int main() {
    
    int tableau[] = { 10, 50, 30, 20, 40, 60 };
    int taille_tableau = sizeof(tableau) / sizeof(int);

    init_reference(tableau, taille_tableau);

    tri3(tableau, taille_tableau);

    controler_reference( tableau, taille_tableau);

    return EXIT_SUCCESS;
}