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
void lire_matrice(Matrice *matrice, char *nomfichier);

int main()
{
    Matrice matrice;
    char nom_fichier[NOMFICHIER_MAX];

    printf("Lire dans fichier : ");
    scanf("%s", nom_fichier);
    lire_matrice(&matrice, nom_fichier);

    printf("Nombre de lignes = %d\n", matrice.row);
    printf("Nombre de colonnes = %d\n", matrice.col);

    printf("La matrice 2D = \n");
    afficher_matrice(&matrice);

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
            fprintf(fp, "%d\t", matrice->cell[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Lire la matrice dans le fichier en parametre
void lire_matrice(Matrice *matrice, char *nomfichier)
{
    FILE *fp;

    fp = fopen(nomfichier, "r");

    fscanf(fp, "%d", &matrice->row);
    fscanf(fp, "%d", &matrice->col);

    for (int i = 0; i < matrice->row; i++) {
        for (int j = 0; j < matrice->col; j++) {
            fscanf(fp, "%d", &matrice->cell[i][j]);
        }
    }

    fclose(fp);
}
