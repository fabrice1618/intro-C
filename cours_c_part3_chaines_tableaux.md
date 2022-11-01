# Part 3: Les chaines de caractères, les tableaux

Dans de très nombreuses situations les types de base s’avèrent insuffisants pour permettre de traiter un problème : il peut être nécessaire, par exemple, de stocker un certain nombre de valeurs en mémoire afin que des traitements similaires leurs soient appliqués.

Dans ce cas, il est impensable d’avoir recours à de simples variables car tout traitement itératif serait inapplicable. D’autre part, il s’avère intéressant de pouvoir regrouper ensemble plusieurs variables afin de les manipuler comme un tout.

Pour répondre à tous ces besoins, le langage C/C++ comporte la notion de **type agrégé** en utilisant les **tableaux**. 

Les tableaux sont des **conteneurs** ( _container_ ), c’est-à-dire est un **objet qui contient d’autres objets**.

```C
int tab[5];     // Déclare un tableau de 5 entiers, avec un index de 0 à 4
```

## A - Les chaînes de caractères

En C/C++, les **chaînes de caractères** sont délimitées par des double quote ("). "Hello world !\n" est donc une chaîne de caractères. Le code \n est un “caractère spécial” indiquant le passage à une nouvelle ligne ( _newline_ ).

Les **chaînes de caractères** contiennent donc des caractères! En C/C++, ils sont codés par défaut en ASCII (sur 8 bits soit un octet). Un **caractère** est délimité par des guillements simples (’). En C/C++, un **caractères** est stocké dans une variable de type char.

Une **chaîne de caractères** est délimitée par un caracère spécial de **fin de chaîne** : le caractère nul qui a pour valeur 0 ou ’\0’. Il est automatiquement ajouté lorsqu’on utilise la notation ("").

```bash
$ man ascii
```

### A1 - Déclarations de chaînes de caractères

En C, il n’y a pas de type dédié et on utilisera des tableaux de caratères.

```C
// une chaîne de caractères délimitée par un fin de chaîne (le fin de chaîne est ajouté automatiquement ici)
char nom[] = "Robert"; // la taille est calculée automatiquement (ici 6+1 = 7 carctères)

// un autre tableau de 6 caractères peut stocker une chaîne de 5 caractères (6-1 pour le fin de chaîne)
char autre[6];

// un tableau de caractères (ce n’est pas à proprement parler une chaîne de caractères 
// car il n’y a pas de fin de chaîne )
char tab[4] = { ’a’, ’b’, ’c’, ’d’ };

// une chaîne de caractères (il y a le fin de chaîne)
char chaine[4] = { ’a’, ’b’, ’c’, ’\0’ };

// Un simple caractère
char lettre = ’A’; // le caractère ASCII ’A’ soit 0x41
```

### A2 - Opérations sur les chaînes de caractères

En C, il faut passer par des fonctions: strcpy() pour copier une chaîne, strcat() pour la concaténation ou strcmp() pour la comparaison. Ces fonctions ont besoin impérativement que les chaînes de caractères se terminent par un fin de chaîne (caractère nul). Attention aussi aux dépassements de taille!

Liste des fonctions manipulant des chaines de caractères
```
$ man string
```

```C
#include <string.h> /* pour les fonctions str... */

char nom[] = "Arizona"; // ici autorisé car c’est une initialisation et non une affectation
char fils[16];

strcpy(fils, nom); // copie nom dans fils
strcat(fils, " Junior"); // concatène deux chaînes

// comparaison de chaînes
if (strcmp(nom, fils) == 0) 
    printf("Les deux chaînes sont identiques.\n");
```

### A3 - Lecture de chaînes de caractères

La lecture des chaînes de caractère ( scanf() en C/C++ ) se termine sur ce qu’on appelle un espace blanc ( _whitespace_ ), c’est-à-dire le caractère espace, une tabulation ou un caractère de retour à la ligne (généralement la touche Enter ). Notez que les espaces sont ignorés par défaut.

```C
char msg[16];
scanf("%s", &msg[0]); // %s pour une chaîne mais attention au dépassement de taille (on peut utiliser fgets)
scanf("%15s", &msg[0]); // on peut limiter le nombre de caractères saisis (ici 15+1 = 16)

// si votre saisie comporte des espaces, vous pouvez utiliser :
// une expression rationnelle (entre crochets) acceptant tous les caractères 
// sauf (^) le retour à la ligne (\n) :
scanf("%15[^\n]s", &msg[0]);

// ou la fonction fgets
fgets(&msg[0], 16, stdin); // attention fgets stocke le retour à ligne
```

_Sous Linux, vous pouvez indiquer la fin d’un flux en combinant les touches_ Ctrl _+_ d _qui indiquera qu’il n’y a plus de saisie. Vous pouvez aussi stopper le programme avec_ Ctrl _+_ z _ou l’interrompre avec_ Ctrl _+_ c.
Les caractères tapés ne sont pas directement transmis au programme, mais placés (par le système) dans un tampon ( _buffer_ ). Il est possible qu’il reste des caractères d’une saisie précèdente et donc vous aurez besoin de vider le _buffer_ avant de (re)faire une saisie. La méthode pour vider le buffer clavier ( _stdin_ ) consiste à consommer tous les caractères présents dans ce buffer jusqu’à ce qu’il soit vide :

```C
int c = 0;
while ((c = getchar()) != ’\n’ && c != EOF);

// Ou :
scanf("%*[^\n]");
getchar();
```
_EOF signifie End Of File. Pour générer un EOF avec le clavier, il suffit de taper, en début de ligne,_Ctrl _+_ z _sous DOS/Windows et _Ctrl_+_d_sous UNIX, puis de valider par Entrée._

### A4 - Affichage de chaînes de caractères

Pour l’affichage des chaînes de caractère, on utilise printf() en C/C++ :
```C
char msg[] = "Bonjour"; // chaîne de caractères 
printf("msg : %s contient %d caractères\n", msg, strlen(msg)); // %s pour une chaîne
printf("premier caractère : %c\n", msg[0]); // %c pour un simple caractère
```

_L’affichage est bufferisé lui aussi. Tant que le tampon n’est pas plein, les caractères transmis ne seront pas effectivement affichés mais tout simplement placés dans le tampon. Pour vider le contenu du tampon vers l’écran, il faut un retour à la ligne (\n) ou que le tampon soit plein. On peut aussi forcer le
vidage de ce tampon à l’aide de la fonction fflush(stdout) ou carrément ne pas utiliser de buffer en appelant setbuf(stdout, NULL)._

## B - Les tableaux

Un **tableau** est un **ensemble d’éléments de même type** désignés par un identificateur unique (un nom). Chaque élément est repéré par une valeur entière appelée **indice** (ou index) indiquant sa position dans l’ensemble. Les tableaux sont toujours à bornes statiques et leur indiçage démarre toujours à partir de 0.

### B1 - Déclarations de tableaux

La forme habituelle de déclaration d’un tableau est la suivante :
type identificateur[ _dimension_ 1 ]... [ _dimensionn_ ]

Exemple de déclarations de tableaux :
```C
int notes[1000]; // un tableau de 1000 int non initialisé
float notes[1000]; // un tableau de 1000 float non initialisé
```
+ _Par “non initialisé”, on entend qu’il y a une valeur dans chaque case du tableau mais on ne la connaît pas. Il faut donc considérer qu’il y a “n’importe quoi”! On rappelle que “rien” n’est pas une notion en informatique car les bits prennent soit la valeur 0 soit la valeur 1 : il n’y a pas de valeur “rien”._

Déclaration et initialisation de tableaux en C/C++ :
```C
int notes[1000] = {0}; // un tableau de 1000 int initialisé à 0
float f[1000] = {0.}; // un tableau de 1000 float initialisé à 0

int coefficients[4] = { ’1’, ’2’, ’2’, ’4’ }; // un tableau de 4 entiers

// La dimension d’un tableau peut être omise si le compilateur peut en définir la valeur
float t[] = {2., 7.5, 4.1}; // tableau de 3 éléments

// Et seulement avec le compilateur g++ :
// On peut utiliser une variable
int nbProduits = 1000;
int stock[nbProduits] = {0};
// et une saisie
int nbCases;
scanf("%d", &nbCases);
int cases[nbCases] = {0}; // certaines versions n’admettent pas l’initialisation
```
Sinon il vous faudra le faire manuellement :
```C
int nbEleves = 30;
int presences[nbEleves];
int i;

// Avec une boucle :
for (i=0;i<nbEleves;i++) {
    presences[i] = 1; // ici 1 est la valeur initiale
    }

// Avec la fonction memset :
memset(&presences[0], 0, 30* sizeof ( int ));
```

### B2 - Les tableaux à plusieurs dimensions

- _Contrairement à beaucoup d’autres langages, il n’existe pas en_ C _de véritable notion de tableaux multidimentionnels. De tels tableaux se définissent par composition de tableaux, c’est à dire que les éléments sont eux-mêmes des tableaux._

```C
// tableau à 2 dimensions de 2 lignes et 5 colonnes :
int m[2][5] = { 2, 6, -4, 8, 11, // initialise avec des valeurs
3, -1, 0, 9, 2 };

// tableau à 2 dimensions pour stocker plusieurs chaînes de caractères
char noms[][16] = { 
    {"robert"},
    {"roger"},
    {"raymond"},
    {"alphonse"} 
};

int x[5][12][7]; // tableau a 3 dimensions
```
### B3 - Parcourir un tableau

Pour parcourir un tableau, il faut utiliser une boucle :
```C
int nbQuestions = 20;
int points[nbQuestions];
int i;

// saisir des données dans un tableau :
for (i=0;i<nbQuestions;i++) {
    scanf("%d", &points[i]);
    }

// afficher des données d’un tableau :
for (i=0;i<nbQuestions;i++) {
    printf("%d\n", points[i]);
    }
```

Le plus grand danger dans la manipulation des tableaux est d’accéder en écriture en dehors du tableau. Cela provoque un accès mémoire interdit qui n’est pas contrôlé au moment de la compilation. Par contre, lors de l’exécution, cela provoquera une exception de violation mémoire ( segmentation fault ) qui se traduit généralement par une sortie prématurée du programme avec un message "Erreur de segmentation".

### B4 - Les tableaux et les pointeurs

- L’identificateur du tableau (le nom de la variable) ne désigne pas le tableau dans son ensemble, mais plus précisément l’adresse en mémoire du début du tableau ( **l’adresse de la première case** ).
Ceci implique qu’il est impossible d’affecter un tableau à un autre. L’identificateur d’un tableau sera donc "vu" comme un **pointeur constant**.

```C
#define MAX 20 // définit l’étiquette MAX egale à 20

// Attention :
int a[MAX], b[MAX];

a = b; // cette affectation est interdite! Il faudra faire une boucle pour traiter chaque case
```

La dimension d’un tableau peut être omise dans 2 cas :
- le compilateur peut en définir la valeur
```C
    int t[] = {2, 7, 4}; // tableau de 3 éléments
```
- l’emplacement mémoire correspondant a été réservé
```C  
    // la fonction fct admet en parametre
    void fct( int t[]) // un tableau d’entiers qui existe déjà
```    
Lorsque le nom d’un tableau constitue l’argument d’une fonction, c’est l’adresse du premier élément qui est transmise. Ses élément ne sont donc pas recopiés. Lorsque l’on passe un tableau en paramètre d’une fonction, il n’est pas possible de connaître sa taille et il faudra donc lui passer aussi sa taille.

Utilisation des pointeurs avec les tableaux :
```C
int t[5] = {0, 2, 3, 6, 8}; // un tableau de 5 entiers
int *p1 = NULL; // le pointeur est initialisé à NULL (précaution obligatoire)
int *p2; // pointeur non initialisé : il pointe donc sur n’importe quoi (gros danger)

p1 = t; // p1 pointe sur t c’est-a-dire la première case du tableau
// identique a : p1 = &t[0];

p2 = &t[1]; // p2 pointe sur le 2eme élément du tableau

*p1 = 4; // la première case du tableau est modifiée
printf("%d ou %d\n", *p1, t[0]); // affiche 4 ou 4

printf("%d ou %d\n", *p2, t[1]); // affiche 2 ou 2
p2 += 2; // p2 pointe sur le 4eme élément du tableau (indice 3)
printf("%d ou %d\n", *p2, t[3]); // affiche 6 ou 6

// on peut utiliser les [] sur un pointeur :
p1[1] = 8; // identique à : *(p1+1) = 8; ou a : t1[1] = 8;
printf("%d\n", t[1]); // affiche 8

// et inversement :
*(t1+1) = 10; // identique à : t1[1] = 10;
printf("%d\n", t[1]); // affiche 10
```

### B5 - Trier un tableau

La bibliothèque C standard offre une fonction de tri :qsort(). Elle sert à trier un tableau d’éléments à l’aide d’une fonction de comparaison à fournir. Pour l’utiliser, vous devez inclure le fichier <stdlib.h>.

qsort() trie les éléments dans l’ordre que vous lui demandez. Plus précisément, vous donnez à qsort() une fonction de comparaison. Cette fonction prend deux éléments A et B, et indique si A doit être avant ou après B dans le tableau trié. La fonction de comparaison est donc vitale, c’est elle qui indique dans
quel ordre et selon quels critères il faut trier le tableau.

La fonction de comparaison a le prototype suivant :
int compareValeurs(const void* val1, const void* val2)

Elle reçoit en argument deux pointeurs val1 et val2, et retourne un entier. val1 et val2 sont des pointeurs constants sur les éléments à comparer. Le const empêchera la fonction de comparaison de modifier le contenu du tableau pendant le tri. Le type void * est ici obligatoire car la fonction ne peut pas connaître avant le type des éléments à comparer. Elle utilise donc des pointeurs génériques (void *) qu’il faudra “caster” (transtyper) vers les types désirés.

Si la fonction de comparaison est <=, alors à la fin du tri du tableau a[0..n-1] les éléments sont réordonnés de telle manière que a[0] <= a[1] <= ... <= a[n-1]. 

Si on utilise la fonction >=, cela donnera a[0] >= a[1] >= ... >= a[n-1].

Seul le signe de la valeur retournée par la fonction de comparaison compte. Par exemple on peut retourner -1 pour A avant B, +1 pour A après B, et 0 (zéro) si l’ordre ne compte pas.

Fonction de comparaison de deux entiers:
```C
#include <stdlib.h>

int compareEntiers( const void * val1, const void * val2)
{
    int i1 = *(const int*)val1; // on caste sur un type entier
    int i2 = *(const int*)val2; // on caste sur un type entier

    if (i1 == i2)
        return 0;
    if (i1 < i2)
        return -1;
    else
        return +1;
}

qsort(valeurs, nbValeurs, sizeof (valeurs[0]), compareEntiers);
```
En pratique, pour trier un tableau valeurs contenant nbValeurs éléments, on donnera à la fonction qsort()les arguments suivants :
- Le nom du tableau: valeurs
- Le nombre d’éléments du tableau: nbValeurs
- La taille en octets de chaque élément: sizeof(valeurs[0])
- Le nom de la fonction de comparaison: compareEntiers

Pour rechercher des valeurs dans un tableau, vous pouvez utiliser la fonction bsearch() de la bibliothèque C standard, déclarée dans le fichier <stdlib.h>. Cette fonction, qui ressemble beaucoup à qsort(), permet d’effectuer une recherche dichotomique. bsearch() recherche une valeur dans un tableau initialement trié et prend en argument l’objet cherché (la clé), le tableau, et la fonction de comparaison qui permet de savoir si un élément donné est situé avant ou après la clé, ou bien est égal à la clé.

### B6 - Les tableaux dynamiques

Pour allouer dynamiquement des tableaux en C, il faut utiliser les fonctions malloc() et free():
```C
int *T; // pointeur sur un entier

// allocation dynamique d’un tableau de 10 int (un int est codé sur 4 octets)

T = ( int *)malloc( sizeof( int ) * 10); // alloue 4 * 10 octets en mémoire

// initialise le tableau avec des 0
for ( int i=0;i<10;i++) {
    *(T+i) = 0; // les 2 écritures sont possibles
    T[i] = 0; // identique à la ligne précèdente
    }

// ou avec la fonction memset
memset(T, 0, sizeof ( int )*10); // il faudra alors inclure string.h

// libération de la mémoire
free(T);
```

La fonction realloc() modifie la taille d’un bloc de mémoire déjà alloué.


## C - Conclusion

Les types sont au centre de la plupart des notions de programmes corrects, et certaines des techniques de construction de programmes les plus efficaces reposent sur la conception et l’utilisation des types.

```
Rob Pike (ancien chercheur des Laboratoires Bell et maintenant ingénieur chez Google) :
«Règle n°5 : Les données prévalent sur le code. Si vous avez conçu la structure des données appropriée et bien organisé le tout, les algorithmes viendront d’eux-mêmes. La structure des données est le coeur de la programmation, et non pas les algorithmes.»
```

**Question 21.** Sur combien de bits est codé un caractère ASCII?

**Question 22.** Quelle est la taille en bits d’une variable de type char?

**Question 23.** Quelle est la valeur en hexadécimale du caractère ASCII ’A’?

**Question 24.** Quelle est la différence entre une chaîne de caractères et un tableau de caractères?

**Question 25.** Quelle est la taille en caractères de la chaîne de caractères “hello”?

**Question 26.** Quelle est la valeur de l’indice pour accèder à la première case d’un tableau?

**Question 27.** Quelle est la taille en octets d’un tableau de 100 entiers (int)?

**Question 28.** Dans la déclaration int t[10]? Que représente réellement la variable t?

**Question 29.** Que fait l’instruction t[5] = 2;?

**Question 30.** Que provoque l’instruction t[10] = 2;?