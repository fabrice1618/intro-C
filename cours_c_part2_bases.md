# Part 2: Bases du langage C

## A - Objets, types et valeurs

Pour pouvoir lire quelque chose, il faut dire où le placer ensuite. Autrement dit, il faut un “endroit” dans la mémoire de l’ordinateur où placer les données lues. On appelle cet “endroit” un **objet**.

Un objet est une région de la mémoire, dotée d’un **type** qui spécifie quelle sorte d’information on peut y placer. Un objet nommé s’appelle une **variable**. _Il est fondamentalement impossible de faire quoi que ce soit avec un ordinateur sans stocker des données en mémoire (on parle ici de la RAM)._

Exemples :
- les **entiers** sont stockés dans des objets de type int
- les **réels** sont stockés dans des objets de type float ou double
- etc ..

Une définition peut (et généralement doit) fournir une valeur initiale. Trop de programmes informatiques ont connu des bugs dûs à des oublis d’initialisation de variables... 
Le compilateur se souvient du type de chaque variable et s’assure que vous l’utilisez comme il est spécifié dans sa définition.

```C
#include <stdbool.h> /* pour le type bool en C */
#include <stdio.h>

// Variables globales
int nombreDeTours = 100; // int pour les entiers
double tempsDeVol = 3.5; // double pour les nombres en virgule flottante (double précision)
char prenom[] = "Robert"; // un tableau de caractères pour stocker les chaînes de caractères
char pointDecimal = '.'; // caractères individuels ou variables entières sur 8 bits (un octet)
bool ouvert = true; // bool pour les variables logiques (booléenes)

int main()
{
    printf("Nombre de tours: %d\n", nombreDeTours);
    printf("Temps de voll: %3.1f\n", tempsDeVol);
    printf("Prénom: %s\n", prenom);
    printf("Caractere: %c\n", pointDecimal);
    printf("Robinet: %s\n", ouvert ? "Ouvert" : "Fermé" );
}
```

## B - Types de variables

### B1 - Les types entiers :

Type | Valeurs | Commentaire
---------|----------|---------
 bool | false ou true | booléen
 unsigned char | 0 à 255 | 1 octet ou 8 bits
 [signed] char | -128 à 127 | 1 octet mais en entier relatif
 unsigned short [int] | 0 à 65535 | 2 octets ou 16 bits
 [signed] short [int] | -32768 à +32767 | 2 octets mais en entier relatif
 unsigned int | 0 à 4.295e9 | 4 octets
 [signed] int | -2.147e9 à +2.147e9 | 4 octets mais en entier relatif
 unsigned long [int] | 0 à 4.295e9 | entier sur 4 octets ou plus ; sur PC identique à "int"
 [signed] long [int] | -2.147e9 à -2.147e9 | idem mais en entier relatif
 unsigned long long [int] | 0 à 18.4e18 | sur 8 octets
 [signed] long long [int] | -9.2e18 à -9.2e18 | sur 8 octets mais en entier relatif

### B2 - Les types à virgule flottante :

Type | Précision | Format
---------|----------|---------
 float | environ 6 chiffres de précision et un exposant qui va jusqu’à ±10 ±^38 | Codage IEEE sur 4 octets
 double | environ 10 chiffres de précision et un exposant qui va jusqu’à ±10 ±^308 | Codage IEEE sur 8 octets
 long double |  | Codé sur 10 octets

### B3 - Les constantes :

- celles définies **pour le préprocesseur** : c’est simplement une **substitution syntaxique pure** . Il n’y a aucun typage de la constante.

```C
       #define PI 3.1415
```

- celles définies **pour le compilateur** : c’est une **variable typée en lecture seule**, ce qui permet des contrôles lors de la compilation.
```C
       const double pi = 3.1415; // en C++ et en C ISO
```

### B4 - La définition de synonymes de types typdedef:

Le mot réservé typedef permet simplement la définition de **synonyme de type** qui peut ensuite être utilisé à la place d’un nom de type. typedef est très utilisé car cela rend les code sources portables et lisibles, donc plus facile à maintenir et à faire évoluer.

```C
typedef int entier;
typedef float reel;

entier a;  // a de type entier donc de type int
reel x;  // x de type réel donc de type float
```

### B5 - Le type énuméré enum:

Une énumération est un type de données dont les valeurs sont des constantes nommées.
- enum permet de déclarer un **type énuméré** constitué d’un ensemble de constantes appelées **énumérateurs**.
- Une variable de type énuméré peut recevoir n’importe quel énumérateur (lié à ce type énuméré) comme valeur.
- Le premier énumérateur vaut zéro (par défaut), tandis que tous les suivants correspondent à leur précédent incrémenté de un.

```C
// enum.c
#include <stdio.h>

typedef int entier;
typedef float reel;

typedef enum{FALSE, TRUE} booleen;

enum couleur_carte {
    TREFLE = 1, /* un énumérateur */
    CARREAU, /* 1+1 donc CARREAU = 2 */
    COEUR = 4, /* en C, les énumérateurs sont équivalents à des entiers (int) */
    PIQUE = 8 /* il est possible de choisir explicitement les valeurs (ou de certaines d’entre elles). */
};

enum JourDeSemaine { LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE };

int main()
{
    entier e = 1;
    reel r = 2.5;
    booleen fini = FALSE;
    enum couleur_carte carte = CARREAU;

    printf( "Le nouveau type entier possède une taille de %ld octets (ou %ld bits)\n", 
            sizeof(entier), 
            sizeof(entier)*8 );
    printf( "La variable e a pour valeur %d et occupe %ld octets\n", e, sizeof(e) );
    printf( "La variable r a pour valeur %.1f et occupe %ld octets\n", r, sizeof(r) );
    printf( "La variable fini a pour valeur %d et occupe %ld octets\n", fini, sizeof(fini) );
    printf( "La variable carte a pour valeur %d et occupe %ld octets\n", carte, sizeof(carte) );
    return 0;
}
```

### B6 - Les pointeurs :
  
Les pointeurs sont des **variables spéciales** permettant de **stocker une adresse** (pour la manipuler ensuite). L’adresse représente généralement l’ **emplacement mémoire d’une variable**. Comme la variable a un type, le pointeur qui stockera son adresse doit être du même type pour la manipuler convenablement.
Le type void* représentera un type générique de pointeur: en fait cela permet d'indiquer que l'on ne sait pas encore sur quel type il pointe.

Utilisation des pointeurs :

- On utilise l’étoile * pour **déclarer un pointeur**.
- On utilise le & devant une variable pour **initialiser ou affecter un pointeur** avec une **adresse**.
- On utilise l’étoile * devant le pointeur pour **accéder au contenu à l’adresse** (indirection).

```C
#include <stdio.h>

int main()
{
    int i = 2;      // Déclaration d'un entier
    int *ptrInt;    // Déclaration d'un pointeur sur un entier

    ptrInt = &i;    // le pointeur ptrInt contient l'adresse de la variable i
    *ptrInt = 3;    // Modifier le contenu de l'entier pointé par ptrInt avec 3, donc la variable i

    printf("La variable i vaut %d et son adresse en mémoire est %lX\n", i, (unsigned long)ptrInt );
}
```


## C - Nommer une variable

Un nom de variable est un nom principal (surtout pas un verbe) suffisamment éloquent, éventuellement complété par :

- une caractéristique d’organisation ou d’usage
- un qualificatif ou d’autres noms
- On utilisera la convention suivante : **un nom de variable commence par une lettre minuscule puis les différents mots sont repérés en mettant en majuscule la première lettre d’un nouveau mot**. Exemples : distance, distanceMax, consigneCourante, etatBoutonGaucheSouris, nbreDEssais
- Certaines abréviations sont admises quand elles sont d’usage courant : nbre(ou nb), max, min, ...
- Les lettres i, j, k utilisées seules sont usuellement admises pour les indices de boucles.
- Un nom de variable doit être uniquement composé de lettres, de chiffres et de "souligné" (_). 
- Les noms débutant par le caractère "souligné" (_) sont réservés au système, et à la bibliothèque C. Les noms débutants par un double "souligné" (__) sont réservés aux constantes symboliques privées (#define...) dans les fichiers d’en-tête (.h).
- Il est déconseillé de différencier deux identificateurs uniquement par le type de lettre (minuscule/majuscule). Les identificateurs doivent se distinguer par au moins deux caractères, parmi les 12 premiers, car pour la plupart des compilateurs seuls les 12 premiers symboles d’un nom sont discriminants.
- Les mots clés du langage sont interdits comme noms.
- _l’objectif de respecter des règles de codage est d’augmenter la lisibilité des programmes en se rapprochant le plus possible d’expressions en langage naturel._

## D - Portée d’une variable

La **portée** ( _scope_ ) d’un identifiant (variables, fonctions, ...) est l’étendue au sein de laquelle cet identifiant est lié. En C, la portée peut être **globale** (en dehors de tout bloc{}) ou **locale** (au bloc {}).
Des variables déclarées dans des blocs différents peuvent porter le même nom. En cas d’homonymie, le compilateur fait une résolution au « plus proche » de l’identifiant.

```C
#include <stdio.h>

int uneVariableGlobale; // initialisée par défaut à 0

int main(int argc, char* argv[])
{
    int uneVariableLocale; // non initialisée par défaut

    uneVariableLocale = 1;

    {
    int uneVariableLocaleBloc; // non initialisée par défaut

    uneVariableLocaleBloc = 42;
    printf( "uneVariableLocaleBloc = %d\n", uneVariableLocaleBloc );
    }

    // la variable i est locale bloc for :
    for( int i=0; i<3; i++ ) printf( "i = %d\n", i );

    printf( "uneVariableLocale = %d\n", uneVariableLocale );
    printf( "uneVariableGlobale = %d\n", uneVariableGlobale );

    return 0;
}
```

```bash
$ gcc -o portee portee.c 
$ ./portee 
uneVariableLocaleBloc = 42
i = 0
i = 1
i = 2
uneVariableLocale = 1
uneVariableGlobale = 0
```

## E - Instructions

Les instructions principales sont :
- l’instruction déclarative
- l’instruction d’expression, l’assignation ou affectation
- l’instruction conditionnelle
- l’instruction itérative (la boucle)
- les branchements (sans condition) en effectuant un saut avec l’instruction goto

Les instructions (ou bloc d’instruction) sont exécutées séquentiellement : cela désigne le fait de faire exécuter par la machine une instruction, puis une autre, etc, en séquence. Cette construction se distingue du fait d’exécuter en parallèle des instructions (cf. programmation concurrente ou multi-tâches).

## F - Expressions

La brique de base la plus élémentaire d’un programme est une **expression**. Une expression calcule une **valeur** à partir d’un certain nombre d’opérandes. Cela peut être une **valeur littérale** comme 10, ’a’, 3.14, "rouge" ou le **nom d’une variable**.

exemple: longueur = 40;
- \<longueur\> ou **lvalue** (left value) : est un élément de syntaxe C pouvant être écrit à gauche d'un opérateur d'affectation (=). Une lvalue doit être un emplacement de stockage en mémoire d'un type précis et modifiable.
- <40> or **rvalue** (right value) : une rvalue est un élément de syntaxe C pouvant être écrit à droite d'un opérateur d'affectation. une rvalue est une valeur d'un type précis mains qui n'a pas forcement de zone de stockage en mémoire. Cela peut être une valeur, une constante, une variable, une expression...

On utilise aussi des opérateurs dans une instruction :

``` C
// calcule une aire
int longueur = 40;
int largeur = 20;
int aire = longueur * largeur; // * est l’opérateur de multiplication
```

De manière générale, un programme informatique est constitué d’une suite d’instructions.
Une instruction d’expression est une expression suivie d’un point-virgule (;). Le point-virgule (;) est un élément syntaxique permettant au compilateur de “comprendre” ce que l’on veut faire dans le code.

Dans les programmes, il faut souvent choisir entre plusieurs possibilités. Le C propose plusieurs instructions conditionnelles : l’instruction if (choisir entre deux possibilités) ou l’instruction switch(choisir entre plusieurs possibilités).

Tous les langages de programmation fournissent des moyens pratiques de faire quelque chose plusieurs fois (on parle de traitement itératif). On appelle cela une boucle ou une itération.
Le C offre plusieurs instructions itératives : la boucle while (et sa variante do ... while) et la boucle for.

## G - Les opérateurs

Il existe de nombreux opérateurs : les opérateurs arithmétiques ( +, -, *, / et % ), les opérateurs relationnels ( <, <=, >, >=, == et != ), les opérateurs logiques && (et), ||(ou) et !(non), les opérateurs bits à bits &(et), |(ou) et ~(non) ...

Les opérateurs arithmétiques et les opérateurs relationnels ne sont définis que pour des opérandes d’un même type parmi : int, long int (et leurs variantes non signées), float, double et long double.

On peut tout de même constituer des expressions mixtes (opérandes de types différents) ou contenant des opérandes d’autres types (bool, char et short), grâce aux conversions (transtypage ou _cast_ ) implicites et explicites.

L’opérateur **modulo (%)** permet d’obtenir le reste d’une division. C’est un opérateur très utilisé notamment dans l’accès à un élément d’un tableau.

Les **opérateurs logiques** &&(et), ||(ou) et !(non) acceptent n’importe quel opérande numérique (entier ou flottant) ou pointeur, en considérant que tout opérande de valeur non nulle correspond à VRAI (true). Les deux opérateurs && et || sont **"à court-circuit"** : le second opérande n’est évalué que si la
connaissance de sa valeur est indispensable.

```C
int a = 0;
// Danger : si le premier opérande suffit à déterminer l’évaluation du résultat logique

// Attention : a++ != 5 n’est pas évalué donc (a n’est pas incrémenté) 
// car 0 < 1 et donc toujous VRAI dans un OU
if ( 0 < 1 || a++ != 5 ) 
    printf("VRAI !\n"); // Affiche toujours : VRAI!
else 
    printf("FAUX !\n");

// Attention : a++ != 5 n’est pas évalué donc (a n’est pas incrémenté) 
// car 1 < 0 et et donc toujous FAUX dans un ET
if ( 1 < 0 && a++ != 5 ) 
    printf("VRAI !\n");
else 
    printf("FAUX !\n"); // Affiche toujours : FAUX!

printf("a = %d\n", a); // Affichera toujours : a = 0 !!!
```

Il ne faut pas confondre les opérateurs logiques avec les opérateurs bit à bit. Pour les opérateurs bit à bit, il est conseillé d’utiliser la représentation en hexadécimale :

```C
unsigned char a = 1; unsigned char b = 0;
unsigned char aa = 20; /* non nul donc VRAI en logique */
unsigned char bb = 0xAA;

/* Ne pas confondre!
! : inverseur logique 
~ : inverseur bit à bit  */
printf("a = %u - !a = %u - ~a = %u (0x%hhX)\n", a, !a, ~a, ~a);
printf("b = %u - !b = %u - ~b = %u (0x%hhX)\n", b, !b, ~b, ~b);

printf("aa = %u (0x%hhX) - !aa = %u - ~aa = %u (0x%hhX)\n", aa, aa, !aa, ~aa, ~aa);
printf("bb = %u (0x%hhX) - !bb = %u - ~bb = %u (0x%hhX)\n", bb, bb, !bb, ~bb, ~bb);
```

```
a = 1 - !a = 0 - ~a = 4294967294 (0xFE)
b = 0 - !b = 1 - ~b = 4294967295 (0xFF)
aa = 20 (0x14) - !aa = 0 - ~aa = 4294967275 (0xEB)
bb = 170 (0xAA) - !bb = 0 - ~bb = 4294967125 (0x55)
```

Les opérateurs d’affectation ( =, +=, -=, *=, /=, %=, &=, ^=, |=, <<= et >>= ) nécessitent une lvalue pour l’opérande de gauche. L’affectation à la déclaration d’une variable est appelée " **déclaration avec initialisation** ", par exemple : int a = 5; déclare a et l’initialise avec la valeur entière 5. Ce n’est
donc pas le même opérateur que l’affectation.

Les opérations arithmétiques sur les pointeurs sont bien évidemment réalisées sur les adresses contenues dans les variables pointeurs. Le type du pointeur a une influence importante sur l’opération. Supposons un tableau t de 10 entiers (int) initialisés avec des valeurs croissantes de 0 à 9. Si on crée un pointeur
ptr sur un entier (int) et qu’on l’initialise avec l’adresse d’une case de ce tableau, on pourra alors se déplacer avec ce pointeur sur les cases de ce tableau. Comme ptr pointe sur des entiers (c’est son type), son adresse s’ajustera d’un décalage du nombre d’octets représentant la taille d’un entier (int). Par exemple, une incrémentation de l’adresse du pointeur correspondra à une opération +4 (octets) si la taille d’un int est de 4 octets!

```C
int t[10] = { 0,1,2,3,4,5,6,7,8,9 };
int *ptr; // un pointeur pour manipuler des int

ptr = &t[5]; // l’adresse d’une case du tableau
printf("Je pointe sur la case : %d (%p)\n", *ptr, ptr); // Je pointe sur la case : 5 (0xbf8d87b8)

ptr++; // l’adresse est incrémentée de 4 octets pour pointer sur l’int suivant

printf("Maintenant, je pointe sur la case : %d (%p)\n", *ptr, ptr); // Maintenant, je pointe sur la case : 6 (0xbf8d87bc)

ptr -= 4; // en fait je recule de 4 int soit 4*4 octets pour la valeur de l’adresse
printf("Maintenant, je pointe sur la case : %d (%p)\n", *ptr, ptr); // Maintenant, je pointe sur la case : 2 (0xbf8d87ac)
```

Les **opérateurs unaires** (à une seule opérande) d’incrémentation (++) et de décrémentation (--) agissent sur la valeur de leur unique opérande (qui doit être une **lvalue** ) et fournissent la valeur après modification lorsqu’ils sont placés à gauche (comme dans ++n) ou avant modification lorsqu’ils sont
placés à droite (comme dans n--). i++ est (à première vue) équivalent à i = i + 1. Mais i++ est une _right-value_ donc ...

```C
int i = 10;

// Attention c’est une post-incrémentation : on augmente i après avoir affecté j
int j = i++; // équivalent à int j=i; i=i+1;

printf("i = %d\n", i); // Affiche : i = 11
printf("j = %d\n", j); // Affiche : j = 10
```

L’ **opérateur ternaire** ? ressemble au if(...) {...} else {...} mais joue un rôle de _right-value_ et pas de simple instruction. La syntaxe est la suivante :(A?B:C) prend la valeur de l’expression B si l’expression A est vraie, sinon la valeur de l’expression C.

```C
int age = 1; 
int parite; /* un booléen */

printf("J’ai %d an%c\n", age, age > 1? ’s’ : ’’); // J’ai 1 an
printf("Je suis %s\n", age >= 18? "majeur" : "mineur"); // Je suis mineur
parite = (age%2 == 0? 1 : 0 );
printf("Parité = %d\n\n", parite); // Parité = 0

age = 20;
printf("J’ai %d an%c\n", age, (age > 1)? ’s’ : ’’); // J’ai 20 ans
printf("Je suis %s\n", (age >= 18)? "majeur" : "mineur"); // Je suis majeur
parite = (age%2 == 0? 1 : 0 );
printf("Parité = %d\n", parite); // Parité = 1
```

Les opérateurs ont une priorité entre eux comme pour l’addition et la multiplication en mathématique.
Liste des opérateurs du plus prioritaire au moins prioritaire :
- . -> [] (référence et sélection)()(appel de fonction)()(parenthèses)sizeof()
- ++(unaire) ~(inverseur bit à bit) !(inverseur logique) --(unaire) &(prise d’adresse) *(indirection)
- () (conversion de type)
- \* / % (multiplication, division, modulo)
- \+ - (addition et soustraction)
- << >> (décalages et envoi sur flots)
- < <= > >= (comparaisons)
- == != (comparaisons)
- & (ET bit à bit)
- ^ (OU-Exclusif bit à bit)
- | (OU-Inclusif bit à bit)
- && (ET logique)
- || (OU logique)
- (? : ) (expression conditionnelle ou opérateur ternaire)
- = *= /= %= += = «= »= &= |= ~=
- , (mise en séquence d’expressions)


Quelques exemples :

1. y = (x+5) est équivalent à : y = x+5 car l’opérateur + est prioritaire sur l’opérateur d’affectation =.
2. (i++) * (n+p) est équivalent à : i++ * (n+p) car l’opérateur ++ est prioritaire sur *. En revanche,     * est prioritaire sur +, de sorte qu’on ne peut éliminer les dernières parenthèses.
3. moyenne = 5 + 10 + 15 / 3 donnera 20 ( / est plus prioritaire que le + ). Il faut alors imposer l’ordre en l’indiquant avec des parenthèses : moyenne = (5 + 10 + 15) / 3
4. _Important :_ Si deux opérateurs possèdent la même priorité, C exécutera les opérations de la gauche vers la droite (sauf pour les opérateurs suivants où l’ordre est de la droite vers la gauche : ++(unaire) ~(inverseur bit à bit) !(inverseur logique) --(unaire) &(prise d’adresse) *(indirection) (? :) et = *= /= %= += = «= »= &= |= ~=).
5. L’ordre des opérateurs n’est donc pas innocent. En effet :3/6*6 donnera 0 alors que 3*6/6 donnera 3!
   
Conclusion : comme il est difficile de se rappeler de l’ensemble des priorités des opérateurs, le programmeur préfère coder explicitement en utilisant des parenthèses afin de s’éviter des surprises. Cela améliore aussi la lisibilité.

## H - Conditionner une action

La célèbre attraction du train fou est interdite aux moins de 10 ans. On souhaite écrire un programme qui demande à l’utilisateur son âge et qui, si la personne a moins de 10 ans, affiche le texte « Accès interdit » ; 
ce qui peut se rédiger comme cela en pseudo code:
```
Variable age : Entier

age <- Lire un entier
Si age < 10
    Ecrire "Accès interdit"
```

Cela se traduit en C:

```C
int age;

scanf("%d", &age);

if (age < 10) {
    printf("Accès interdit\n");
    }
```

```bash
$ ./tester-age
8
Accès interdit
$ ./tester-age
13
```

On écrit donc le mot-clef if, la traduction en anglais de « **si** », puis on met entre parenthèses la condition à tester, à savoir age < 10. On n’oublie pas de de mettre des accolades.

Les opérateurs de comparaison:


Opérateur | Signification 
---------|----------
 < | strictement inférieur 
 \> | strictement supérieur 
 <= | inférieur ou égal 
 \>= | supérieur ou égal 
 == | égalité 
 != | différence 

Evidemment, il ne faut surtout pas confondre avec l’opérateur = qui permet d’effectuer une affectation.

Par exemple, le code suivant permet de tester si la température de l’eau a atteint 100 degrés :
```C
int temperature;

scanf("%d", &temperature);

if (temperature >= 100) {
    printf("L’eau bout !");
    }
```

Conversion cm/inch (version 1):
```C
#include <stdio.h>

int main()
{
    const double conversion = 2.54; // nombre de cm pour un pouce (inch)
    int longueur = 1; // longueur (en cm ou en in)
    char unite = 0; // ’c’ pour cm ou ’i’ pour inch

    printf("Donnez une longueur suivi de l’unité (c ou i):\n");
    scanf("%d %c", &longueur, &unite );

    if (unite == ’i’)
        printf( "%d in == %f cm\n", longueur, conversion*longueur );
    else
        printf( "%d cm == %f cm\n", longueur, longueur/conversion );
}
```

En fait cet exemple semble seulement fonctionner comme annoncé. Ce programme dit que si ce n’est pas une conversion en _inch_ c’est forcément une conversion en _cm_. Il y a ici une dérive sur le comportement de ce programme si l’utilisateur tape ’f’ car il convertira des _cm_ en _inches_ ce qui n’est probablement pas
ce que l’utilisateur désirait. Un programme doit se comporter de manière sensée même si les utilisateurs ne le sont pas.


Conversion cm/inch (version 2):
```C
if (unite == ’i’)
    printf( "%d in == %f cm\n", longueur, conversion*longueur );
else if (unite == ’c’)
    printf( "%d cm == %f cm\n", longueur, longueur/conversion );
else
    printf( "Désolé, je ne connais pas cette unité %c\n", unite );
```

Conversion cm/inch (version 3)
```C
#include <stdio.h>

int main()
{
    const double conversion = 2.54; // nombre de cm pour un pouce (inch)
    int longueur = 1; // longueur (en cm ou en in)
    char unite = 0; // ’c’ pour cm ou ’i’ pour inch

    printf("Donnez une longueur suivi de l’unité (c ou i):\n");
    scanf("%d %c", &longueur, &unite );

    switch (unite) {
    case ’i’:
        printf( "%d in == %f cm\n", longueur, conversion*longueur );
        break;
    case ’c’:
        printf( "%d cm == %f cm\n", longueur, longueur/conversion );
        break;
    default:
        printf( "Désolé, je ne connais pas cette unité %c\n", unite );
        break;
    }
}
```

L’instruction switch utilisée ici sera toujours plus claire que des instructions if imbriquées, surtout si l’on doit comparer à de nombreuses constantes.

Vous devez garder en mémoire ces particularités quand vous utilisez un switch:
- la valeur utilisée pour le switch() doit être un entier, un char ou une énumération (on verra cela plus tard). Vous ne pourrez pas utiliser une chaine par exemple.
- les valeurs des étiquettes utilisées dans les case doivent être des expressions constantes (voir plus loin).vous ne pouvez pas utiliser de variables.
- vous ne pouvez pas utiliser la même valeur dans deux case
- vous pouvez utiliser plusieurs case menant à la même instruction
- l’erreur la plus fréquente dans un switch est l’oubli d’un break pour terminer un case. Comme ce n’est pas une obligation, le compilateur ne détectera pas ce type d’erreur.

## I - Les variables booléennes

En C/C++, le programme suivant :

```C
if (prix < 10) {
    printf("Pas cher");
    }
```

peut aussi s’écrire :
```C
#include <stdbool.h> /* nécessaire en C */

bool estPasCher = (prix < 10);

if (estPasCher) {
    printf("Pas cher");
    }
```

La variable estPasCher est appelée une **variable booléenne** ou un **booléen** de type bool car elle ne peut être que vraie ou fausse, ce qui correspond en C aux valeurs true(pour vrai) et false(pour faux).

_N’oublier pas que le type bool est natif en C++. Par contre en C, il faut inclure stdbool.h pour pouvoir l’utiliser._

Il est bien sûr possible d’utiliser des opérateurs booléens (les opérateurs && et || ) pour combiner des conditions et les valeurs booléennes sont également utilisables.


Voici quelques extraits de code à titre d’exemple :
```C
bool estSenior = (age >= 60);
bool estJeune = (age <= 25) && (age >= 12);
bool reductionPossible = (estSenior || estJeune);

if (reductionPossible) {
    printf("Réduction!");
    }

while (motDePasse != secret || agePersonne <= 3) {
    printf("Accès refusé : mauvais mot de passe ou personne trop jeune\n");
    scanf("%d %d", &agePersonne, &motDePasse);
    }

while (nbPersonnes <= nbMax && temperature <= 45) {
    printf("Portes ouvertes\n");
    nbPersonnes = nbPersonnes + 1;
    scanf("%d", &temperature);
    }
```

## J - Itérer une action, les boucles

Le premier programme jamais exécuté sur un ordinateur à programme stocké en mémoire (l’EDSAC) est un exemple d’itération. Il a été écrit et exécuté par David Wheeler au laboratoire informatique de Cambridge le 6 mai 1949 pour calculer et afficher une simple liste de carrés comme ceci :
```
0 0
1 1
2 4
3 9
4 16
...
98 9604
99 9801
```
Le premier programme jamais écrit (version while):
```C
// Calcule et affiche une liste de carrés

#include <stdio.h>

int main()
{
    int i = 0; // commencer à 0

    // tant que i est inférieur strict à 100 : on s’arrête quand i a atteint la valeur 100
    while (i < 100) {
        printf( "%d\t%d\n", i, i * i ); // affiche i et son carré séparés par une tabulation
        ++i; // on incrémente le nombre et on recommence
    }

    return 0;
}
```

Les accolades {} délimitent le **corps de la boucle** : c’est-à-dire le bloc d’instructions à répéter. La condition pour la répétition est exprimée directement dans le while. La boucle while s’exécutera **0 ou n fois**.

Il existe aussi une boucle **do ... while** à la différence près que cette boucle sera exécutée **au moins une fois**.

```C
// faire
do {
    printf( "%d\t%d\n", i, i * i ); // affiche i et son carré séparés par unetabulation
    ++i; // on incrémente le nombre et on recommence
}
while (i < 100); // tant que i est inférieur strict à 100
```

Donc écrire une boucle est simple. Mais cela peut s’avérer dangereux :
- Que se passerait-il si i n’était pas initialisé à 0? Voilà une première raison qui démontre que les variables non initialisées sont une source d’erreurs courante.
- Que se passerait-il si on oubliait l’instruction ++i? On obtient une boucle infinie (un programme qui ne “répond” plus). Il faut éviter au maximum d’écrire des boucles infinies. 

Itérer sur une suite de nombres est si courant en C/C++ que l’on dispose d’une instruction spéciale pour le faire. C’est l’instruction for qui très semblable à while sauf que la gestion de la variable de contrôle de boucle est concentrée sur une seule ligne plus facile à lire et à comprendre. Il existe toujours
une instruction while équivalente à une instruction for.

L’instruction for concentre : **une zone d’initialisation, une zone de condition et une zone d’opération d’incrémentation**. N’utilisez while que lorsque ce n’est pas le cas.

Le premier programme jamais écrit (version for):
```C
// Calcule et affiche une liste de carrés

#include <stdio.h>
#include <math.h>

int main() 
{
    /* exécute le bloc d’instructions de la boucle :
    avec i commençant à 0 (initialisation)
    tant que i est inférieur strict à 100 (condition)
    en incrémentant i après chaque exécution du bloc d’instruction (opération d’incrémentation) 
    */
    for ( int i = 0; i < 100; i++)
        printf( "%d\t%d\n", i, pow(i, 2) ); // affiche i et son carré séparés par une tabulation

    return 0;
}

```

+ Ici, on utilise la fonction puissance (pow) de la bibliothèque mathématique. Pour cela, il faut inclure math.h en C puis effectuer l’édition des liens avec l’option -lm (ce qui est fait par défaut maintenant).

## K - La conversion de type (transtypage)

Le compilateur ne peut appliquer des opérateurs qu’à des opérandes de même type. Par exemple, il n’existe pas d’addition pour : 2 + 1.5 car 2 est un entier et 1.5 est un flottant. Il faudra donc réaliser une conversion de type ( _cast_ ). De la même manière, on ne pourra pas affecter une variable avec un type différent. Une conversion ou promotion de type est un transtypage ( _cast_ ).

Il existe deux types de transtypages :
- sans perte : int → float (2 devient 2.0)
- avec perte : float → int (1.5 devient 1)

Les conversions peuvent être automatiques ou implicites (sans perte) par le compilateur ou forcée ou explicites (avec ou sans perte) par le programmeur.

Les conversions d’ajustement de type automatique suivant la hiérarchie ci-dessous sont réalisées **sans perte** :

1. char → short int → int → long → float → double → long double
2. unsigned int → unsigned long → float → double → long double

Une conversion implicite (automatique) peut donner lieu à un warning de la part du compilateur.

Lorsqu’elle est forçée ou explicite, on utilise l’ **opérateur de** **_cast_** en précisant le type entre parenthèses devant la variable à convertir (C/C++) :(float)a qui permet de forcer la variable a en float.

Les conversions forcées peuvent être des **conversions dégradantes (avec perte)**. Par exemple : int b = (int)2.5;. En effet, le _cast_ (int)b donnera 2 avec une perte de la partie décimale. Cela peut être un source d’erreur ( _bug_ ). Le cas le plus « classique » est 1 / 2 qui donne 0 et non pas 0.5, car 1 et
2 sont des entiers ce qui provoque une division entière.

La conversion peut être forcée par la lvalue: les opérateurs d'affectation (=, -=, +=...), appliqués à des valeurs de type numérique, provoquent la conversion de leur opérande de droite dans le type de leur opérande de gauche. Cette conversion forcée peut être "dégradante" (avec perte).

## L - L’allocation dynamique de mémoire

Rappels : La mémoire dans un ordinateur est une **succession d’octets (soit 8 bits)** , organisés les uns à la suite des autres et **directement accessibles par une adresse**.


En C/C++, la mémoire pour stocker des variables est organisée en deux catégories :

1. La pile ( stack )
- La pile (stack) est l'endroit où sont stockés les paramètres d'appel et les variables locales des fonctions.
- La pile ( _stack_ ) est un **espace mémoire réservé au stockage des variables désallouées automatiquement**.
- Sa taille est limitée mais on peut la régler (appel POSIX setrlimit).
- La pile est bâtie sur le modèle **LIFO** ( _Last In First Out_ )

2. le tas ( _heap_ )
- Le tas ( _heap_ ) est l’autre **segment de mémoire utilisé lors de l’allocation dynamique** de mémoire durant l’exécution d’un programme informatique.
- Sa taille est souvent considére comme illimitée mais elle est en limitée réalité.
- Les fonctions malloc et free en C, permettent, respectivement, d’allouer et désallouer la mémoire sur le tas.
- La mémoire allouée dans le tas doit être désallouée explicitement.

_LIFO_, _Last In First Out_, _Dernier Entré - Premier  Sorti_ :. Il faut voir cet espace mémoire comme une pile d’assiettes où on a le droit d’empiler/dépiler qu’une seule assiette à la fois. Par contre on a le droit d’empiler des assiettes de taille différente. Lorsque l’on ajoute des assiettes on les empile par le haut, les unes au dessus des autres. Quand on les "dépile" on le fait en commençant aussi par le haut, soit par la dernière posée. Lorsqu’une valeur est dépilée elle est effacée de la mémoire.

Fuite de mémoire: L'allocation dynamique dans le tas ne permet pas la désallocation automatique. Chaque allocation avec malloc() doit impérativement être libérée(détruite) avec free() sous peine de créer une fuite de mémoire. La fuite de mémoire est une zone mémoire qui a été allouée dans le tas par un programme qui a omis de la désallouer avant de se terminer. Cela rend la zone inaccessible à toute application y compris le système d'exploitation jusqu'au redémarrage du système. Si ce phénomène se produit trop fréquemment la mémoire se remplit de fuites et le système finit par tomber faute de mémoire.


Exemple d’allocation dynamique en C++:
```C
#include <iostream>
#include <new>

using namespace std;

int main ()
{
    int * p1 = new int ; // pointeur sur un entier

    *p1 = 1; // ecrit 1 dans la zone mémoire allouée
    cout << *p1 << endl; // lit et affiche le contenu de la zone mémoire allouée
    delete p1; // libère la zone mémoire allouée

    int * p2 = new int [5]; // alloue un tableau de 5 entiers en mémoire
    // initialise le tableau avec des 0 (cf. la fonction memset)
    for ( int i=0; i<5; i++) {
        *(p2 + i) = 0; // les 2 écritures sont possibles
        p2[i] = 0; // identique à la ligne précèdente
        cout << "p2[" << i << "] = " << p2[i] << endl;
    }
    delete [] p2; // libère la mémoire allouée

    return 0;
}
```

## M - Conclusion

Parce qu’il est clair que vous débutez à peine votre carrière de programmeur, n’oubliez pas qu’écrire de bons programmes, c’est écrire des programmes corrects, simples et efficaces.

```
Rob Pike (ancien chercheur des Laboratoires Bell et maintenant ingénieur chez Google) :
«Règle n°4 : Les algorithmes élégants comportent plus d’erreurs que ceux qui sont plus simples, et ils sont plus difficiles à appliquer. Utilisez des algorithmes simples ainsi que des structures de données simples.»
```
Cette règle n°4 est une des instances de la philosophie de conception KISS ( _Keep it Simple, Stupid_ dans le sens de « Ne complique pas les choses ») ou Principe KISS, dont la ligne directrice de conception préconise de rechercher la simplicité dans la conception et que toute complexité non nécessaire devrait
être évitée.

**Question 11.** Qu’est-ce qu’une variable?

**Question 12.** En C/C++, pourquoi doit-on lui donner un type?

**Question 13.** Peut-on nommer une variable par un verbe? Pourquoi?

**Question 14.** Quelle est la différence entre une initialisation et une affectation?

**Question 15.** Qu’est-ce qu’une _lvalue_?

**Question 16.** Qu’est-ce qu’une variable booléenne?

**Question 17.** Dans quel cas doit-on utiliser l’instruction switch?

**Question 18.** Quelle est la différence entre une boucle do ... while et une boucle while?

**Question 19.** Dans quel cas doit-on utiliser la boucle for?

**Question 20.** Peut-on tester l’égalité entre deux nombres flottants?
