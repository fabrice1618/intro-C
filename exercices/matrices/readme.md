# Les matrices

## La structure

Nos matrices seront d'une taille maximale de 10 par 10 pour un premier paramétrage. Il sera simple à changer grâces aux constantes de configuration.

```C
#define ROW_MAX 10
#define COL_MAX 10
#define NOMFICHIER_MAX 20
```

La structure Matrice contient les données dans le champ cell qui est un tableau à 2 dimensions. La structure contient aussi la taille réelle lignes et colonnes.

```C
typedef struct matrice_t {
    int row;
    int col;
    int cell[ROW_MAX][COL_MAX];
} Matrice;
```
## Premier programme : ecrire.c

Ce programme permet à l'utilisateur de saisir une matrice et de l'enregistrer dans un fichier.

```bash
$ ./ecrire
Nombre de lignes = 2
Nombre de colonnes = 3
Entrez les 6 éléments de la matrice : 
(0, 0) = 1
(0, 1) = 2
(0, 2) = 3
(1, 0) = 4
(1, 1) = 5
(1, 2) = 6
La matrice 2D = 
1	2	3	
4	5	6	
Ecriture dans fichier : mat1.txt

$ cat mat1.txt 
2
3
1
2
3
4
5
6
```

## Deuxième programme: lire.c

Ce programme permet de lire un fichier et d'initialiser une matrice

```bash
$ ./lire
Lire dans fichier : mat1.txt
Nombre de lignes = 2
Nombre de colonnes = 3
La matrice 2D = 
1	2	3	
4	5	6	
```

## transposer une matrice: transpose.c

```bash
$ ./transpose
Lire dans fichier : mat1.txt
Matrice initiale
Nombre de lignes = 2
Nombre de colonnes = 3
1	2	3	
4	5	6	
Matrice transposee
Nombre de lignes = 3
Nombre de colonnes = 2
1	4	
2	5	
3	6	
```

## ajouter 2 matrices: addition.c

```bash
$ ./addition
Lire matrice1 dans fichier : mat1.txt
Lire matrice2 dans fichier : mat2.txt
Matrice1 initiale
Nombre de lignes = 2
Nombre de colonnes = 3
1	2	3	
4	5	6	
Matrice2 initiale
Nombre de lignes = 2
Nombre de colonnes = 3
1	1	1	
1	1	1	
Matrice resultat
Nombre de lignes = 2
Nombre de colonnes = 3
2	3	4	
5	6	7	
```

## multiplier 2 matrices: multiplication.c


