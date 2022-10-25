# Part 8: Annexes

## A - historique

- En 1970, **Ken Thompson** , créa un nouveau langage : Le B, descendant du BCPL ( _Basic Combined Programming Language_ , créé en 1967 par Martin Richards). Son but était de créer un langage simple, malheureusement, son langage fût trop simple et trop dépendant de l’architecture utilisée.
- En 1971, **Dennis Ritchie** commence à mettre au point le successeur du B, le C. Le résultat est convaincant : Le C est **totalement portable** (il peut fonctionner sur tous les types de machines et de systèmes), il est de **bas niveau** (il peut créer du code pratiquement aussi rapide que de l’assembleur) et il permet de traiter des **problèmes de haut niveau**. Le C permet de quasiment tout faire, du _driver_ au jeu. Le C devient très vite populaire.
- En 1983, **Bjarne Stroustrup** des laboratoires Bell crée le C++. Il construit donc le C++ sur la base du C. Il garde une forte compatibilité avec le C. Un programme écrit en C sera compilé par un compilateur C++.
- En 1989, l’ **ANSI** ( _American National Standards Institute_ ) normalisa le C sous les dénominations **ANSI C** ou **C89**. Un programme écrit dans ce standard est compatible avec tous les compilateurs.
- En 1999, l’ **ISO** ( _International Organization for Standardization_ ) proposa une nouvelle version de la norme, qui reprenait quelques bonnes idées du langage C++. Il ajouta aussi le type long long d’une taille minimale de 64 bits, les types complexes, l’initialisation des structures avec des champs nommés, parmi les modifications les plus visibles. Le nouveau document est celui ayant autorité aujourd’hui, est connu sous le sigle **C99**.

Les langages C et C++ sont les langages les plus utilisés dans le monde de la programmation.

Remarques :
- Certaines autres extensions du C ont elles aussi été standardisées, voire normalisées. Ainsi, par exemple, des fonctions spécifiques aux systèmes **UNIX** , sur lesquels ce langage est toujours très populaire, et qui n’ont pas été intégrées dans la norme du langage C, ont servi à définir une partie de la norme **POSIX**.
- Le langage C++ est normalisé par l’ISO. Sa première normalisation date de 1998 (C++ 98 ), puis une seconde en 2003. Le standard actuel a été ratifié et publié par ISO en septembre 2011 (C++ 11 ). Les standards sont supportés progressivement par les compilateurs.

L'option -std des compilateurs gcc/g++ permet de choisir la norme à appliquer au moment de la compilation. Par exemple:-std=c89 ou c99 pour le C.

Le C++ a apporté par rapport au langage C les notions suivantes :
- les **concepts orientés objet (encapsulation, héritage et polymorphisme)** ,
- les références, 
- la vérification stricte des types,
- les valeurs par défaut des paramètres de fonctions,
- la surcharge de fonctions (plusieurs fonctions portant le même nom se distinguent par le nombre et/ou le type de leurs paramètres),
- la surcharge des opérateurs (pour utiliser les opérateurs avec les objets),
- les constantes typées,
- la possiblité de déclaration de variables entre deux instructions d’un même bloc
 
On peut passer progressivement de C à C++: il suffit en premier lieu de **changer de compilateur (par exemple gcc → g++)** , sans nécessairement utiliser les nombreuses possibilités supplémentaires qu’offre C++. Le principal intérêt du passage de C à C++ sera de profiter pleinement de la puissance de la
**programmation orientée objet (POO)**.

L'extension par défaut des fichiers écrits en langage C++ est .cpp ou .cc. Par défaut, gcc et g++ fabriquent un exécutable de nom a.out. Sinon, on peut lui indiquer le nom du fichier exécutable en utilisant l'option -o <executable>.

## B - classes d’allocation

La **classe d’allocation** détermine la façon dont l’emplacement mémoire attribué à une variable est géré. Elle peut être **statique** ou **automatique**.

- Les variables de classe statique voient leur emplacement alloué une fois pour toutes avant le début de l’exécution du programme. C’est le cas des **variables globales**.

- Les variables de classe automatique voient leur emplacement alloué au moment de l’entrée dans un bloc ou une fonction. Il est supprimé lors de la sortie de ce bloc ou de cette fonction. C’est le cas des **variables locales**.

La syntaxe d’une déclaration est :
[classe_de_mémorisation] [qualifieurs] **type identificateur** [=valeur];

- Les crochets [] indiquent ce qui est **optionnel** donc non obligatoire pour réaliser une déclaration.
- classe_de_mémorisation peut prendre les valeurs suivantes : static, extern, automatic, register.

Les différentes classe de mémorisation sont :

- Cas des variables globales :
  - static: Ces variables sont globales au bloc ou au fichier de compilation et ne seront connues que du module dans lequel elles sont définies. Les **variables statiques sont initialisées à 0 par défaut**.
  - extern: extern permet de **déclarer des variables qui sont définies dans un autre fichier source**. Une telle variable est accessible par tous les modules avec lesquels une édition de liens est effectuée.
- Cas des variables locales :
  - static: La visibilité de ces variables est limitée au bloc dans lequel elles sont définies. Si un programme appelle à nouveau un bloc dans lequel une variable statique est déclarée, celle-ci **conserve sa précédente valeur**.
  - extern: Comme pour les variables globales, extern permet de déclarer des variables qui sont définies ailleurs.
  - automatic: Les variables automatiques sont considérées locales au bloc dans lequel elles sont déclarées. Un espace leur est alloué (dans la pile,stacken anglais) à chaque entrée de bloc et est libéré a chaque sortie de bloc. Une **variable automatique ne reçoit aucune valeur initiale par défaut**. L’absence de toute classe de mémorisation dans la déclaration d’une variable locale amène le compilateur à le considérer automatic.
  - register: Elles obéissent aux mêmes règles que les variables automatiques. Cependant, la désignation de register indique au compilateur que ces variables doivent être conservées dans des ressources à accès rapide du CPU (généralement dans un registre du microprocesseur). Il faut noter qu’une variable register ne possède pas d’adresse en mémoire et que par conséquent, l’opérateur & ne peut lui être appliqué. D’autre part, ce sont des variables limitées en nombre, ainsi qu’à certains types (entier, caractère ou pointeur). Son utilisation sera vue plus tard (programmation multi-tâches par exemple) car elle nécessite un bon niveau d’expertise.

En raison des risques d'effets de bord, les variables globales sont à bannir de la programmations structurée.


Les variables volatiles :
- Une variable **volatile** est une variable sur laquelle aucune optimisation de compilation n’est appliquée.
- Le mot-clé volatile existe en C/C++, mais aussi en C# et Java.
- Le préfixe volatile est notamment utilisé en programmation multi-tâche (avec des _threads_ ) quand la variable d’un programme peut être modifiée par un autre programme. Cela empêche par exemple le processeur de conserver la valeur d’une variable dans son cache. Voir aussi le mot-clé atomic.


## C - erreurs du débutant

Le bug du débutant n°1 : il ne faut pas mettre un; après un if car cela exécuterait une instruction nulle si expression est vraie. Cela donne un comportement défectueux :

```C
int a = 0;
if (a != 0); /* c’est sûrement un bug involantaire */
printf("bug : a n’est pas nul et pourtant a = %d !\n", a);
```
Le bug du débutant n°2 : il ne faut pas confondre l’opérateur ’=’ (d’affectation) avec l’opérateur ’==’ (comparaison d’égalité). Cela risque de donner un comportement défectueux :

```C
int a = 0;

if (a = 0) /* c’est sûrement un bug involantaire */
    printf("a = %d : a est égal à 0\n", a);
else 
    printf("bug : a n’est pas égal à 0 et pourtant a = %d !\n", a);
```

Le bug du débutant n°3 : il faut penser à déterminer si un break est nécessaire dans un case. Le code suivant le prouve :
```C
a = 1;
switch (a) {
    case 1: printf("a = %d : a est égal à 1\n", a); /* ne faudrait-il pas un break? */
    case 2: printf("bug : a = %d : a est égal à 2 !\n", a);
}
```

```
a = 1 : a est égal à 1
bug : a = 1 : a est égal à 2!
```

Le bug du débutant n°4 : il ne faut pas mettre un; après le while car cela exécuterait une instruction nulle si expression est vraie. Le code suivant sera dans une **boucle infinie** sans afficher aucun message "Salut" :

```C
long compteur = 15;

while (compteur > 0); // c’est sûrement un bug involantaire
    {
    printf("Salut\n");
    compteur = compteur - 1;
    } // ici non plus ne pas mettre de ;
```


Le bug du débutant n°5 : il ne faut pas mettre un; à la fin d’un for car cela exécuterait une instruction nulle si expression est vraie. Le code suivant n’affichera qu’un seul message "Salut" car le for boucle dans le vide :

```C
long compteur;

for (compteur = 0; compteur < 15; compteur++); // c’est sûrement un bug involantaire
    {
    printf("Salut\n");
    }
```

Le bug du débutant n°6 : il ne faut pas oublier les accolades {} à la suite d’une instruction conditionnelle if/else ou itérative for/while sinon vous n’exécuterez qu’un seule instruction au lieu de plusieurs. Par exemple :
Si temperature >= 100
    Écrire "L’eau bout !"
    Écrire "Préparons le thé"
```

Il ne faut pas coder :
```C
if (temperature >= 100)
    printf("L’eau bout !\n");
    printf("Préparons le thé\n");
```

Si la témpérature est égale ou supérieure à 100, ce code affichera :
```
L’eau bout!
```

La bonne traduction de l’algorithme est la suivante :
```C
if (temperature >= 100) {
    printf("L’eau bout !\n");
    printf("Préparons le thé\n");
    }
```
## D - opérations sur les nombres réels

La bibliothèque C standard contient une série de fonctions de calcul sur les flottants (racine carrée, logarithme, sinus, etc.), que l’on peut utiliser en incluant le fichier math.h: fabs(), floor(), fmod(), exp(), log(), log10(), sqrt(x), pow(), sin(x), cos(x), tan(), ...

Une des différences majeures entre le traitement des entiers et des flottants est la perte de précision.

Avec les entiers, les calculs sont toujours exacts, du moment que l’on ne dépasse pas la capacité des entiers.

Avec les flottants, chaque opération (addition, multiplication, etc.) induit une **perte de précision**.

Il existe deux types de flottants en C/C++: float et double. Les double (codés sur 8 octets) ont une meilleure précision que les float(codés sur 4 octets). Il donc est conseillé de toujours utiliser des double afin de garder la meilleure précision possible, le seul intérêt des float est qu’ils prennent deux fois moins
de place en mémoire.

Si vous calculez : 1e10 + 1e-10 = 1.00000000000000000001e10, l’ordinateur arrondira à 1.00000000000000e10 = 1e10 (15 chiffres pour un double). 

On a donc des cas où A + B = A même si B != 0. Il faut également
faire attention à l’ordre des calculs. Par exemple A + (B - C) peut être différent de (A + B) - C. Si A = 1e-10, B = 1e10, C = 1e10, on a A + (B - C) = A + 0 = 1e-10 mais (A + B) - C = B - C = 0.

À cause des pertes de précision, les flottants sont rarement exactement égaux à leur valeur approchée, surtout si l’on utilise des fonctions comme la racine carrée, le sinus, ...

Prenons par exemple le code suivant :
```C
double x = 2.;

x = sqrt(x); // Racine carrée de x
x = x * x; // x^2
if (x == 2.)
    printf("OK\n");
```

On s’attend à voir ce programme écrire OK. Il n’en est rien! À cause des pertes de précision, x n’est pas égal à 2 à la fin du programme, mais à un nombre presque égal à 2 et différent de 2, comme 2.0000000000000004.

On ne peut donc pas tester l’égalité entre deux nombres réels.
Pour déterminer si deux nombres réels sont égaux, il faut commencer par calculer la différence des deux nombres. Si la différence est très proche de zéro, c’est-à-dire si la valeur absolue de la différence est très petite, alors on considère que les nombres sont égaux.

Concrètement, pour comparer x et y, on commence par définir une constante très petite que l’on nomme traditionnellement epsilon , et on teste si |x - y| < epsilon. La fonction fabs() calcule la valeur absolue.

```C
#include <math.h>

const double epsilon = 1e-10;

double x = 2.;
x = sqrt(x); // Racine carrée de x
x = x * x; // x^2

if (fabs(x - 2.) < epsilon)
    printf("OK\n");

// pour tester si x est égal à zéro, il faut faire :
if (fabs(x) < epsilon)
    printf("x est égal à 0 !\n");
```
