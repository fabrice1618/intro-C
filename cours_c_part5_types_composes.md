# Part 5: Types composés

Les types composés permettent de regrouper des variables au sein d’une même entité :
- Il est possible de regrouper des variables de types différents dans des **structures de données** ;
- Il est possible de regrouper des variables de types identiques dans des **tableaux**.
- Une chaîne de caractères peut être considérée comme un type composé.
  
En C, on dispose de trois types de structures de données :
- les structures (struct)
- les unions (union)
- les champs de bits

## A - Les structures

Besoin : Il est habituel en programmation d’avoir besoin d’un mécanisme permettant de grouper un certain nombre de variables de types différents au sein d’une même entité.

Exemple : On travaille par exemple sur un fichier de personnes et on voudrait regrouper une variable de type chaîne de caractères pour le nom, une variable de type entier pour le numéro d’employé, etc.

La réponse à ce besoin est le concept d’ **enregistrement** : un enregistrement est un ensemble d’éléments de types différents repérés par un nom. Les éléments d’un enregistrement sont appelés des **champs**.

En langage C, on utlise le vocabulaire suivant :
- enregistrement → **structure**
- champ d’un enregistrement → **membre** d’une structure

Une **structure** est donc un **objet agrégé comprenant un ou plusieurs membres** d’éventuellement différents types que l’on regroupe sous un seul nom afin d’en faciliter la manipulation et le traitement.

Chacun des membres peut avoir n’importe quel type, y compris une structure, à l’exception de celle à laquelle il appartient.

### A1 - Déclaration de structure

Il y a plusieurs méthodes possibles pour déclarer des structures.

```C
struct [etiquette]
{
    type champ_1;
    ...
    type champ_n;
} [identificateur];
```

Pour déclarer une structure, on utilise le mot clé struct suivi d’une liste de déclarations entre accolades. Il est possible de faire suivre le mot struct d’un nom baptisé etiquette de la structure. Cette etiquette désigne alors cette sorte de structure et, par la suite, peut servir pour éviter d’écrire entièrement toute la déclaration. Il est aussi possible d’instancier directement une variable de nom identificateur.

Exemple de déclaration d’un type structuré:
```C
// Déclaration d’une type struct Date :
struct Date
{
    int jour;
    int mois;
    int annee;
};

// Instanciation d’une variable de type struct Date :
struct Date dateNaissance;

// Ou directement :
struct
{
    int jour;
    int mois;
    int annee;
} dateNaissance; // dateNaissance est une variable de type structuré
```
En C, le type s’appelle en fait struct Date. On préfère souvent créer un synonyme avec typedef.

Un synonyme de type structuré:
```C
// Déclaration d’une type struct Date :
struct Date
{
    int jour,
    mois,
    annee;
};

// Création d’un type synonyme :
typedef struct Date Date;

// Ou directement :
typedef struct
{
    int jour,
    mois,
    annee;
} Date;

// Une variable de type Date :
Date dateNaissance;
```
### A2 - Initialisation d’une structure

Comme pour les tableaux, les accolades peuvent être utilisées pour indiquer les valeurs initiales des membres d’une variable de type structuré. Cela ne fonctionne qu’à l’initialisation.

Ce n’est pas utilisable pour une affectation.

Initialisation d’une structure:
```C
// Une variable de type Date :
Date naissanceMarie = {7, 11, 1867}; // initialisation de la structure naissanceMarie

printf("La structure struct Date occupe une taille de %d octets\n", sizeof (struct Date));
```
La taille d’une structure est la somme des tailles de tous les objets qui la compose (cf.sizeof()). Dans notre exemple, la structure aura une taille de 3 × 4 (int) soit 12 octets.

### A3 - Accès aux membres

Pour accéder aux membres d’une structure, on utilise :
- l’opérateur d’accès .(point) pour une variable de type structuré :

```C
Date naissanceMarie = {7, 11, 1867}; // initialisation de la structure naissanceMarie

printf("Marie Curie est née le %02d/%02d/%4d\n", 
    naissanceMarie.jour, 
    naissanceMarie.mois, 
    naissanceMarie.annee);
```
- l’opérateur d’indirection->(flèche) pour un pointeur sur un type structuré :

```C  
struct Date naissanceMarie = {7, 11, 1867}; // initialisation de la structure naissanceMarie
struct Date *p_naissanceMarie = &naissanceMarie;

printf("Marie Curie est née le %02d/%02d/%4d\n", 
    p_naissanceMarie->jour,
    p_naissanceMarie->mois, 
    p_naissanceMarie->annee);

// Ou :
printf("Marie Curie est née le %02d/%02d/%4d\n", 
    (*p_naissanceMarie).jour->jour, 
    (*p_naissanceMarie).mois, 
    (*p_naissanceMarie).annee);
```

### A4 - Affectation de structure

Il suffit d’accéder aux membres d’une structure pour leurs affecter une valeur.

```C
struct Date naissanceMarie = {7, 11, 1867}; // initialisation de la structure naissanceMarie
struct Date uneDate;

// Quelques affectations :
uneDate.jour = 1;
scanf("%d", &uneDate.mois);
uneDate.jour = naissanceMarie.annee;
```

Il est aussi possible d’affecter des structures de même type entre elles. Dans ce cas, les valeurs sont copiées.
```C
struct Date naissanceMarie = {7, 11, 1867};
struct Date copie;

copie = uneDate;
```

Ainsi, lorsque vous prenez une structure en paramètre d’une fonction, la valeur donnée à l’appel de la fonction est copiée dans l’emplacement mémoire du paramètre. Le paramètre a ainsi son propre emplacement mémoire. Si la structure est très grosse, appeler la fonction va donc nécessiter un espace supplémentaire, et une copie qui peut prendre du temps. Pour éviter cela, on pourra utiliser un **passage par adresse** en C/C++.

Aucune comparaison n’est possible sur les structures, même pas les opérateurs == et !=.

### A5 - Tableaux de structures

Une déclaration de tableau de structures se fait selon le même modèle que la déclaration d’un tableau dont les éléments sont de type simple :

```C
struct Date t[100]; // 100 éléments de type struct Date

// Ou :
Date t[100]; // 100 éléments de type Date

// Chaque élément du tableau est de type Date :
for (i=0<100;i++)
    printf("%02d/%02d/%4d\n", t[i].jour, t[i].mois, t[i].annee);
```

### A6 - Liste de structures

Une des utilisations fréquentes des structures, est de créer des listes de structures chaînées. Pour cela, il faut que chaque structure contienne un membre qui soit de type **pointeur** vers une structure du même type. Cela se fait de la façon suivante :

```
struct personne
{
    ... **/* les différents membres */**

    struct personne *suivant;
};
```
La dernière structure de la liste devra avoir un membre suivant dont la valeur sera le pointeur NULL pour indiquer la fin.

Quand on crée une liste chaînée, on ne sait généralement pas à la compilation combien elle comportera d’éléments à l’exécution. Pour pouvoir créer des listes, il est donc nécessaire de pouvoir allouer de l’espace dynamiquement :

Allocation dynamique d’une structure:
```C
#include <stdlib.h>

struct personne *p;

// Allocation :
p = malloc( sizeof(struct personne) );

// Libération :
free(p);
```

## B - Union

Besoin : Il est parfois nécessaire de manipuler des variables auxquelles on désire affecter des valeurs de type différents.

Une **union** est conceptuellement identique à une structure mais peut, à tout moment, contenir n’importe lequel des différents champs.

Une union définit en fait **plusieurs manières de regarder le même emplacement mémoire**. A l’exception de ceci, la façon dont sont déclarés et référencées les structures et les unions est identique.

```
union [etiquette] {
    type champ_1;
    ...
    type champ_n;
} [identificateur];
```

Exemple : On va déclarer une union pour conserver la valeur d’une mesure issue d’un capteur générique, qui peut par exemple fournir une mesure sous forme d’un char(-128 à +127), d’un int(-2147483648 à 2147483647) ou d’un float. valeurCapteur pourra, à tout moment, contenir soit un entier,soit un réel,soit un caractère.

```C
union mesureCapteur
{
    int iVal;
    float fVal;
    char cVal;
} valeurCapteur;
```

La taille mémoire de la variable valeurCapteur est égale à la taille mémoire du plus grand type qu’elle contient (ici c’est float).

Utilisation d’une union:

```C
#include <stdio.h>
typedef union mesureCapteur
{
    int iVal;
    float fVal;
    char cVal;
} Capteur;

int main()
{
    Capteur vitesseVent, temperatureMoteur, pressionAtmospherique;

    pressionAtmospherique.iVal = 1013; /* un int */
    temperatureMoteur.fVal = 50.5; /* un float */
    vitesseVent.cVal = 2; /* un char */

    printf("La pression atmosphérique est de %d hPa\n", pressionAtmospherique.iVal);
    printf("La température du moteur est de %.1f °C\n", temperatureMoteur.fVal);
    printf("La vitesse du vent est de %d km/h\n", vitesseVent.cVal);

    printf("Le type Capteur occupe une taille de %d octets\n", sizeof (Capteur));

    return 0;
}
```

```
La pression atmosphérique est de 1013 hPa
La température du moteur est de 50.5 °C
La vitesse du vent est de 2 km/h
Le type Capteur occupe une taille de 4 octets
```

## C - Champs de bits

Besoin : Il est parfois nécessaire pour un programmeur de décrire en termes de bits la structure d’une information.
Les champs de bits ("Drapeaux" ou " Flags "), qui ont leur principale application en informatique industrielle, sont des structures qui ont la possibilité de regrouper (au plus juste) plusieurs valeurs. La
taille d’un champ de bits ne doit pas excéder celle d’un entier. Pour aller au-delà, on créera un deuxième champ de bits.
On utilisera le mot clé struct et on donnera le type des groupes de bits, leurs noms, et enfin leurs tailles.

Il est autorisé de ne pas donner de nom aux champs de bits qui ne sont pas utilisés.

```
struct [etiquette]
{
    type champ_1 : nombre_de_bits;
    type champ_2 : nombre_de_bits;
    [...]
    type champ_n : nombre_de_bits;
} [identificateur];
```

Si on reprend le type structuré Date, on peut maintenant décomposer ce type en trois groupes de bits (jour,mois et annee) avec le nombre de bits suffisants pour coder chaque champ. Les différents groupes de bits seront tous accessibles comme des variables classiques d’une structure ou d’une union.

Le champ de bits Date:
```C
struct Date
{
    unsigned short jour : 5; // 2^5 = 0-32 soit de 1 à 31
    unsigned short mois : 4; // 2^4 = 0-16 soit de 1 à 12
    unsigned short annee : 7; // 2^7 = 0-128 soit de 0 à 99 (sans les siècles)
};

int main ( int argc, char **argv)
{
    struct Date naissanceRitchie = {9, 9, 41};
    struct Date naissanceThompson = {4, 2, 43};
    struct Date mortRitchie = {12, 10, 11};

    printf("Dennis Ritchie est né le %02d/%02d/%2d\n", 
        naissanceRitchie.jour,
        naissanceRitchie.mois, 
        naissanceRitchie.annee);
    printf("Dennis Ritchie est mort le %02d/%02d/%2d\n\n", 
        mortRitchie.jour, 
        mortRitchie.mois, 
        mortRitchie.annee);
    printf("Ken Thompson est né le %02d/%02d/%2d\n", 
        naissanceThompson.jour,
        naissanceThompson.mois, 
        naissanceThompson.annee);

    printf( "La structure champs de bits date occupe une taille de %d octets\n", sizeof (struct date) );
    return 0;
}
```

```
Dennis Ritchie est né le 09/09/41
Dennis Ritchie est né le 09/09/41
Dennis Ritchie est mort le 12/10/11
Ken Thompson est né le 04/02/43

La structure champs de bits date occupe une taille de 2 octets
```

La taille mémoire d’une variable de ce type sera égale à 2 octets (5 + 4 + 7 = 16 bits).

## D - Conclusion

Les types sont au centre de la plupart des notions de programmes corrects, et certaines des techniques de construction de programmes les plus efficaces reposent sur la conception et l’utilisation des types.

```
Rob Pike (ancien chercheur des Laboratoires Bell et maintenant ingénieur chez Google ) :
« Règle n°5 : Les données prévalent sur le code. Si vous avez conçu la structure des données appropriée et bien organisé le tout, les algorithmes viendront d’eux-mêmes. La structure des données est le coeur de la programmation, et non pas les algorithmes. »
```

**Question 36.** Donner la déclaration d’une structure Voiture qui possède les champs suivants : la capacité du réservoir et le nombre de chevaux fiscaux?

**Question 37.** Quelle est la taille en octets d’une structure qui contient 2 champs : un entier (int) et un flottant (float)?

**Question 38.** Quelle est la taille en octets d’une union qui contient 2 champs : un entier (int) et un flottant (float)?

**Question 39.** Donner la déclaration d’un type énuméré CouleurCarte pour les quatres couleurs de cartes à jouer?

**Question 40.** Peut-on réaliser des tableaux de structures? Peut-on réaliser des structures qui contiennent des tableaux?
