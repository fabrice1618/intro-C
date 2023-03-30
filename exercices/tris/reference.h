#ifndef REFERENCE_H
#define REFERENCE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define ERREUR_MEMOIRE "Erreur plus de mémoire\n"
#define ETAT_OK "OK"
#define ETAT_ERREUR "ERREUR"
#define TEST_OK "Test OK: étape réussie :)\n"
#define TEST_NOK "Test NOK: recommencer ;)\n"

void init_reference(int *source, size_t size);
void controler_reference( int *tab, int size);
void dump( int *tab, int size);

#endif