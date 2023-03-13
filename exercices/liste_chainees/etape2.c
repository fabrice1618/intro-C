#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int main()
{
    Liste liste;
    
    liste_init(&liste);
    liste_print_entete(&liste);

    return EXIT_SUCCESS;
}

