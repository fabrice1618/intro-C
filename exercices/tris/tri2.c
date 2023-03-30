#include "reference.h"

void swap(int *p1, int *p2)
{
    int tmp;
    
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}


void tri2(int *tab, int taille)
{
    bool tab_en_ordre = false;

    for (int i = taille - 1; i > 0 && !tab_en_ordre; i--) {

        tab_en_ordre = true;

        for (int j = 0; j < i; j++) {
            if(tab[j] > tab[j+1]) {
                swap(&tab[j], &tab[j+1]);
                tab_en_ordre = false;
            }

        }
    }
}

int main() {
    
    int tableau[] = { 10, 50, 30, 20, 40, 60 };
    int taille_tableau = sizeof(tableau) / sizeof(int);

    init_reference(tableau, taille_tableau);

    tri2(tableau, taille_tableau);

    controler_reference( tableau, taille_tableau);

    return EXIT_SUCCESS;
}