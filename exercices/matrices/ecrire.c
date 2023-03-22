#include <stdio.h>
#include <stdlib.h>

#define MATRICE_MAX 10
#define NOMFICHIER_MAX 20
#define CHECK_ROW(x) ((x) > 0 && (x) < MATRICE_MAX)
#define CHECK_COL(x) ((x) > 0 && (x) < MATRICE_MAX)

typedef struct matrice_t {
    int row;
    int col;
    int cell[MATRICE_MAX][MATRICE_MAX];
} Matrice;

void afficher_matrice(Matrice *matrice);
void saisie_matrice(Matrice *matrice);
void ecrire_matrice(Matrice *matrice, char *nom_fichier);

int main()
{
    Matrice matrice;
    int taille;
    char nom_fichier[NOMFICHIER_MAX];

    printf("Nombre de lignes = ");
    scanf("%d", &taille);
    if ( CHECK_ROW(taille) )
        matrice.row = taille;
    else
        return EXIT_FAILURE;

    printf("Nombre de colonnes = ");
    scanf("%d", &taille);
    if ( CHECK_COL(taille) )
        matrice.col = taille;
    else
        return EXIT_FAILURE;

    printf("Entrez les %d éléments de la matrice : \n", matrice.row * matrice.col);
    saisie_matrice(&matrice);

    printf("La matrice 2D = \n");
    afficher_matrice(&matrice);

    printf("Ecriture dans fichier : ");
    scanf("%s", nom_fichier);
    ecrire_matrice(&matrice, nom_fichier);

    return EXIT_SUCCESS;
}

// Saisir une matrice au clavier
void saisie_matrice(Matrice *matrice)
{
    int val;

    for (int i = 0; i < matrice->row; i++) {
        for (int j = 0; j < matrice->col; j++) {
            printf("(%d, %d) = ", i, j);
            scanf("%d", &val);
            matrice->cell[i][j] = val;            
        }
    }
}

// Afficher la matrice à l'écran
void afficher_matrice(Matrice *matrice)
{
    for (int i = 0; i < matrice->row; i++) {
        for (int j = 0; j < matrice->col; j++) {
            printf("%d\t", matrice->cell[i][j]);
        }
        printf("\n");
    }
}

// Ecrire la matrice dans le fichier en parametre
void ecrire_matrice(Matrice *matrice, char *nomfichier)
{
    FILE *fp;

    fp = fopen(nomfichier, "w");

    fprintf(fp, "%d\n", matrice->row);
    fprintf(fp, "%d\n", matrice->col);

    for (int i = 0; i < matrice->row; i++) {
        for (int j = 0; j < matrice->col; j++) {
            fprintf(fp, "%d\n", matrice->cell[i][j]);
        }
    }

    fclose(fp);
}
