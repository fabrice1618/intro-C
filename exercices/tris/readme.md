# Les tris

## Objectif

Pour chacun des programmes de tri ci-dessous, votre objectif est de comprendre le code, de pouvoir expliquer le fonctionnement de l'algorithme avec vos propres mots et/ou avec un schéma. Ensuite, vous évaluerez l'efficacité de l'algorithme en terme d'espace mémoire utilisé et de vitesse de traitement, appelé la compléxité. Finalement, vous essaierez de retrouver le nom original de cet algorithme classique.

## Test des algorithmes

Pour que vous puissiez expérimenter vos propres évolutions de ces programmes, ils sont inclus dans un mini-framework de test permettant de vérifier que vos résultats de tri sont corrects. Etudier quelles sont les fonctionnalités définies dans les fichiers reference.c et reference.h ?

## Méthode d'analyse proposée

1. Lire le code et identifer les fonctions inconnues de vous. Consulter les pages man pour ces fonctions (paramètres et valeurs de retour)
2. Repérer les parties les plus simples du code que vous comprennez d'emblée et commenter le code
3. A ce point, il ne reste plus que quelques parties que vous pourrez étudier plus en détail. Par exemple en faisant un schéma.
4. expliquer le fonctionnement de l'algorithme avec vos propres mots, le plus simplement possible et éventuellement en vous aidant d'un schéma
5. identifier les techniques ré-utilisables dans d'autres contextes ( par exemple gestion mémoire, assertions, gestion des erreurs...)
6. déterminer la compléxité des algorithmes
7. donner un nom parmi les choix suivants aux différents algorithmes : Le tri par sélection, Le tri par tas, le tri à bulles, le tri à paniers, le tri Quicksort, le tri par insertion.
8. écrire votre propre évolution du code

## tri0 exemple - niveau "carton"

Le code source de tri0.c:

```C
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
```

### 1 - Les fonctions nouvelles

La fonction assert est utilisée en phase de test pour stopper l'éxécution du programme quand la condition n'est pas respectée

```C
    assert( taille > 0 && taille < RAND_MAX);
```

La fonction srand() permet d'initialiser le générateur de nombres aléatoires. 
La fonction rand() retourne un nombre entier compris entre 0 et RAND_MAX. Le modulo permet de limiter les valeurs à "taille"

```C
srand( time(NULL) );
aleatoire1 = rand() % taille;
```

### 2-1 - les fichiers reference.c et reference.h

Le fichier d'entête reference.h permet d'importer les fonctions init_reference() et controler_reference() du fichier reference.c que vous étudierez en détail vous même. Pour l'instant nous pouvons dire que ces fonctions initialisent le système de test et contrôlent que le résultat obtenu est correct.


```C
#include "reference.h"

init_reference(tableau, taille_tableau);
controler_reference( tableau, taille_tableau);
```

### 2-2 - Le tableau d'origine

Le première ligne déclare le tableau et la seconde calcule sa taille en nombre d'éléments.

```C
    int tableau[] = { 10, 50, 30, 20, 40, 60 };
    int taille_tableau = sizeof(tableau) / sizeof(int);
```

### 3-1 - fonction tableau_trie()

Analyse de la fonction :

```C
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
```

état initial :
```C
    bool resultat = true;
    int precedent = tab[0];
    int i = 1;
```

La valeur qui sera retournée par la fonction par la variable "resultat" est initialisée à true. Elle ne peut passer à la valeur false que dans le cas où **(tab[i] < precedent)**

**int precedent = tab[0];** la valeur "précédent" prends la valeur du premier élément du tableau

**i** est l'indice de lecture du tableau et commence à 1 (la valeur à l'indice 0 est dans "precedent")

**precedent = tab[i++];** la variable "precedent" prends la valeur à l'indice **i** puis **i** est incrémenté.

**while (resultat && i < taille)** La boucle continue tant que le tableau est trié (si le tableau n'est pas trié resultat passe à false) et que l'indice est plus petit que la taille du tableau.

### 3-2 - fonction tri0()

```C
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
```

- La boucle continue tant que le tableau n'est pas trié. 
- Le programme tire au hasard 2 indices aleatoire1 et aleatoire2. 
- Les deux éléments désignés sont échangés
- puis le programme reprends la boucle si le tableau n'est pas trié

### 4 - Explication

C'est un programme de tri aléatoire. Il inverse 2 valeurs du tableau tant que le tableau n'est pas trié entièrement.

### 5-1 - ré-utilisable - tirage aléatoire

```C
srand( time(NULL) );
aleatoire1 = rand() % taille;
```

### 5-2 - Affichage d'un compteur une fois sur 100

```C
        if (++compteur % 100 == 0)
            printf("Compteur: %d\n", compteur);
```

### 5-3 - assertions

Test d'un programme

```C
    assert( taille > 0 && taille < RAND_MAX);
```

### 6 - Complexité

Impossible à évaluer. L'efficacité de l'algorithme est aléatoire, de relativement rapide à très lent.

### 7 - Identification algorithme

Tri aléatoire


## tri1 - niveau "bois"

## tri2 - niveau "fer"

## tri3 - niveau "bronze"

## tri4 - niveau "argent"

## tri5 - niveau "or"
