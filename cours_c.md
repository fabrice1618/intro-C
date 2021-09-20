# Programmation C : Notions de base

Les objectifs de ce cours sont de découvrir les bases du langage C / C ++.

## Premier programme : Hello world en C

Voici une version du premier programme que l’on étudie habituellement. Il affiche “Hello world !” à
l’écran.

```bash
$ mkdir ~/code/helloworld
$ cd ~/code/helloworld
$ vi hello.c
```

```C
// hello.c
/*
Ce programme affiche le message "Hello world !" à l’écran
*/

#include <stdio.h> /* pour pouvoir utiliser la fonction printf */

int main()
{
    printf("Hello world !\n"); // Affiche "Hello world !"

    return 0;
}

```

```bash
$ gcc -o hello hello.c
$ ./hello
Hello world !
```

### Explications

- Tout programme C doit posséder une (et une seule) **fonction** nommée main(dite fonction principale) pour indiquer où commencer l’exécution. 

- Une fonction est essentiellement une **suite d’instructions** que l’ordinateur exécutera dans l’ordre où elles sont écrites. Une fonction comprend quatre parties :
  - un **type de retour** : ici int(pour _integer_ ou entier) qui spécifie le type de résultat que la fonction
    retournera lors de son exécution. En C, le mot int est un mot réservé (un mot-clé) : il ne peut donc pas être utilisé pour nommer autre chose.
  - un **nom** : ici main, c’est le nom donné à la fonction (attention main est un mot-clé.
  - une **liste de paramètres (ou d’arguments)** entre parenthèses : ici la liste de paramètres est vide
  - un **corps de fonction** entre accolades {...} qui énumère les instructions que la fonction doit exécuter

- La plupart des instructions C se terminent par un point-virgule (;).

- En C/C++, les **chaînes de caractères** sont délimitées par des double quote (")."Hello world !\n" est donc une chaîne de caractères. 
- Le code \n est un “caractère spécial” indiquant le passage à une nouvelle ligne ( _newline_ ou LF ).
- En C, on utilise printf(et scanf) pour afficher sur le flux de sortie standard (et lire sur le flux d’entrée).
- Commentaire multi-lignes : Tout ce qui est placé entre /* et */ est considéré comme un commentaire. Le contenu du commentaire est ignoré par le compilateur (la machine). Ce commentaire rend le code plus lisible pour les programmeurs. On écrit des commentaires pour décrire ce que le programme est supposé faire et, d’une
manière générale, pour fournir des informations utiles impossibles à exprimer directement dans le code.
```C
/*
Ce programme affiche le message "Hello world !" à l’écran
*/
```
- Commentaire sur une seule ligne: tout ce qui est entre // et la fin de la ligne est un commentaire
```C
printf("Hello world !\n"); // Affiche "Hello world !"
```
- La fonction main de ce programme retourne la valeur 0 (return 0;) à celui qui l’a appelée. Comme
main() est appelée par le “système”, il recevra cette valeur. Sur certains systèmes (Unix/Linux), elle peut
servir à vérifier si le programme s’est exécuté correctement. Un zéro ( 0 ) indique alors que le programme
s’est terminé avec succès (c’est une convention UNIX). Évidemment, une valeur différente de 0 indiquera
que le programme a rencontré une erreur et sa valeur précisera alors le type de l’erreur.

- En C, une ligne qui commence par un # fait référence à une **directive** du préprocesseur (ou de
pré-compilation). Le préprocesseur ne traite pas des instructions C(donc pas de ";"). Ici, la directive
#include <stdio.h> demande à l’ordinateur de rendre accessible (d’“inclure”) des fonctionnalités contenues dans un fichier nommé stdio.h. Ce fichier est fourni avec le compilateur. Un fichier inclus au moyen de #include porte l’extension.h . On l’appelle en-tête ( _header_ ) ou **fichier d’en-tête**.

## Compilation

C est un langage compilé. Cela signifie que, pour pouvoir exécuter un programme, vous devez d’abord traduire sa forme lisible par un être humain, le code source, en quelque chose qu’une machine peut “comprendre”, le code machine. Cette traduction est effectuée par un programme appelé **compilateur**.

Ce que le programmeur écrit est le code source (ou programme source) et ce que l’ordinateur exécute s’appelle exécutable, code objet ou code machine.

Vous allez constater que le compilateur est plutôt pointilleux sur la syntaxe! Comme tous les
programmeurs, vous passerez beacoup de temps à chercher des erreurs dans du code source. Et la plupart
de temps, le code contient des erreurs! Lorsque vous coderez, le compilateur risque parfois de vous agacer.
Toutefois, il a généralement raison car vous avez certainement écrit quelque chose qui n’est pas défini
précisément par la norme C et qu’il empêche de produire du code objet.

- Le compilateur est dénué de bon sens et d’intelligence (il n’est pas humain) et il est donc très
pointilleux. Prenez en compte les messages d’erreur et analysez les bien car souvenez-vous en bien le
compilateur est “votre ami”, et peut-être le meilleur que vous ayez lorsque vous programmez.


## Édition des liens

Un programme contient généralement plusieurs parties distinctes, souvent développées par des personnes différentes. Par exemple, le programme “Hello world !” est constitué de la partie que nous avons
écrite, plus d’autres qui proviennent de la bibliothèque standard de C(printf par exemple).
Ces parties distinctes doivent être liées ensemble pour former un programme exécutable. Le programme
qui lie ces parties distinctes s’appelle un éditeur de liens ( linker ).

Notez que le code objet et les exécutables ne sont pas portables entre systèmes. Par exemple, si vous
compilez pour une machine Windows, vous obtiendrez un code objet qui ne fonctionnera pas sur une machine Linux.

Une bibliothèque n’est rien d’autre que du code (qui ne contient pas de fonction main évidemment)
auquel nous accédons au moyen de **déclarations** se trouvant dans un fichier d’en-tête. Une déclaration
est une suite d’instruction qui indique comment une portion de code (qui se trouve dans une bibliothèque)
peut être utilisée. Le débutant a tendance à confondre bibliothèques et fichiers d’en-tête.

Une **_bibliothèque dynamique_** est une bibliothèque qui contient du code qui sera intégré au moment
de l’exécution du programme. Les avantages sont que le programme est de taille plus petite et qu’il sera à
jour vis-à-vis de la mise à jour des bibliothèques. L’inconvénient est que l’exécution dépend de l’existence
de la bibliothèque sur le système cible. Une bibliothèque dynamique, Dynamic Link Library (.dll) pour
Windows et shared object (.so) sous UNIX/Linux, est un fichier de bibliothèque logicielle utilisé par un
programme exécutable, mais n’en faisant pas partie.

## Les erreurs 

Les erreurs détectées :
- par le compilateur sont des erreurs de compilation (souvent dues à des problèmes de déclaration)
- celles que trouvent l’éditeur de liens sont des erreurs de liaisons ou erreurs d’édition de liens (souvent
dues à des problèmes de définition)
- Et celles qui se produiront à l’exécution seront des erreurs d’exécutions ou de “logique” (communément appelées _bugs_ ).


## Étapes de fabrication

Les différentes étapes de fabrication d’un programme sont :
1. **Le préprocesseur** (pré-compilation)
    - Traitement des **directives** qui commencent toutes par le symbole dièse (#)
    - Inclusion de fichiers (.h) avec #include
    - Substitutions lexicales : les "macros" avec #define
2. **La compilation**
    - Vérification de la syntaxe
    - Traduction dans le langage d’assemblage de la machine cible
3. **L’assemblage**
    - Traduction finale en code machine (appelé ici code objet)
    - Production d’un fichier objet (.o ou.obj)
4. **L’édition de liens**
    - Unification des symboles internes
    - Étude et vérification des symboles externes (bibliothèques .so ou .DLL)
    - Production du programme exécutable


## Décomposition des étapes de fabrication avec gcc:

```bash
$ cd ~/code/helloworld
$ vi hello2.c
$ vi say_hello.c
$ vi say_hello.h
$ vi lang_hello.h
```

```C
// hello2.c
/*
Ce programme affiche le message de bienvenue à l’écran dans la langue configurée
*/
#include "say_hello.h"

int main()
{
    say_hello(); // Affiche Le message de bienvenue

    return 0;
}
```

```C
// say_hello.c
#include <stdio.h>
#define LANG_FR
#include "lang_hello.h"


void say_hello()
{
    printf( MSG_HELLO );
}
```

```C
// say_hello.h

#ifndef SAY_HELLO_H
#define SAY_HELLO_H

void say_hello();

#endif
```

```C
// lang_hello.h

// Version Francaise
#ifdef LANG_FR
#define MSG_HELLO "Bonjour monde!\n"
#endif

// Version internationale
#ifndef LANG_FR
#define MSG_HELLO "Hello world!\n"
#endif
```

### Compilation en une étape

```bash
$ gcc -o hello2 hello2.c say_hello.c
$ ./hello2
Bonjour monde !
```

### Pré-compilation :

Il est possible de vérifier les fichiers, juste après l'étape de préprocesseur. 

```bash
$ gcc -E -o hello2.i hello2.c 
$ gcc -E -o say_hello.i say_hello.c
```

```C
void say_hello();

int main()
{
    say_hello();

    return 0;
}
```

```C
void say_hello()
{
    printf( "Bonjour monde!\n" );
}
```

### Compilation :

```
$ gcc -S -o say_hello.s say_hello.c 
$ gcc -S -o hello2.s hello2.c 
```

```
	.file	"hello2.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	call	say_hello@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```

```
	.file	"say_hello.c"
	.text
	.section	.rodata
.LC0:
	.string	"Bonjour monde!"
	.text
	.globl	say_hello
	.type	say_hello, @function
say_hello:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```

### Assemblage :

```
$ as -o hello2.o hello2.s
$ as -o say_hello.o say_hello.s
$ file hello2.o
hello2.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
$ file say_hello.o
say_hello.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
```

### Édition des liens :

```
$ gcc -o hello2 hello2.o say_hello.o
fab@cdev:~/code/helloworld$ ./hello2
Bonjour monde!
```

```
// un seul fichier :
$ gcc <fichier.o> -o <executable>
// ou plusieurs fichiers :
$ gcc <fichier1.o> <fichier2.o> <fichiern.o> -o <executable>
// ou avec bibliothèque(s) ici m pour math :
$ gcc -lm <fichier1.o> <fichier2.o> <fichiern.o> -o <executable>
```
### En conservant les étapes intermédiaires:

```bash
$ gcc -v -save-temps hello2.c say_hello.c -o hello2
$ ls -ltr
-rw-rw-r-- 1 fab fab    83 Sep 11 16:59 say_hello.h
-rw-rw-r-- 1 fab fab   121 Sep 11 17:14 say_hello.c
-rw-rw-r-- 1 fab fab   209 Sep 11 17:15 hello2.c
-rw-rw-r-- 1 fab fab   182 Sep 11 17:16 lang_hello.h
-rw-rw-r-- 1 fab fab   265 Sep 11 17:45 hello2.i
-rw-rw-r-- 1 fab fab   597 Sep 11 17:45 hello2.s
-rw-rw-r-- 1 fab fab  1552 Sep 11 17:45 hello2.o
-rw-rw-r-- 1 fab fab 16390 Sep 11 17:45 say_hello.i
-rw-rw-r-- 1 fab fab   675 Sep 11 17:45 say_hello.s
-rw-rw-r-- 1 fab fab  1696 Sep 11 17:45 say_hello.o
-rwxrwxr-x 1 fab fab 16768 Sep 11 17:45 hello2
```

### Build :

Pour un projet contenant plusieurs fichiers sources, nous utilisons l'outil GNU make pour produire l'exécutable à partir des fichiers sources.

```
$ make
$ make clean
```

### Questions de révision

L’idée de base des questions de révision est de vous donner une chance de voir si vous avez identifié et
compris les points clés de cette partie.

**Question 1.** Citez une fonction qui doit apparaître dans tout programme C.

**Question 2.** À quoi sert la directive #include?

**Question 3.** En C, que signifie l’extension .h à la fin d’un nom de fichier?

**Question 4.** Quel est le rôle du compilateur?

**Question 5.** Que fait l’éditeur de liens pour votre programme?

**Question 6.** Que permet de faire stdin?

**Question 7.** Que permet de fairec stdout?

**Question 8.** Que contient un fichier source?

**Question 9.** Que contient un fichier objet?

**Question 10.** Qu’est-ce qu’un environnement de développement intégré (EDI)?

### Conclusion

Qu’y a-t-il de si important à propos du programme “Hello world !”? Son objectif était de vous
familiariser avec les outils de base utilisés en programmation.

Retenez cette règle : il faut toujours prendre un exemple extrêmement simple (comme “Hello world”)
à chaque fois que l’on découvre un nouvel outil. Cela permet de diviser l’apprentissage en deux parties :
on commence par apprendre le fonctionnement de base de nos outils avec un programme élémentaire
puis on peut passer à des programmes plus compliqués sans être distraits par ces outils. Découvrir les
outils et le langage simultanément est beaucoup plus difficile que de le faire un après l’autre.

_Conclusion : cette approche consistant à simplifier l’apprentissage d’une tâche complexe en la décom-
posant en une suite d’étapes plus petites (et donc plus faicles à gérer) ne s’applique pas uniquement à la
programmation et aux ordinateurs. Elle est courante et utile dans la plupart des domaines de l’existence,
notamment dans ceux qui impliquent une compétence pratique._

```
Descartes (mathématicien, physicien et philosophe français) dans le Discours de la méthode :
« diviser chacune des difficultés que j’examinerais, en autant de parcelles qu’il se pourrait,
et qu’il serait requis pour les mieux résoudre. »
« conduire par ordre mes pensées, en commençant par les objets les plus simples et les
plus aisés à connaître, pour monter peu à peu comme par degrés jusques à la connaissance
des plus composés ... »
```

## Objets, types et valeurs

Pour pouvoir lire quelque chose, il faut dire où le placer ensuite. Autrement dit, il faut un “endroit”
dans la mémoire de l’ordinateur où placer les données lues. On appelle cet “endroit” un **objet**.

Un objet est une région de la mémoire, dotée d’un **type** qui spécifie quelle sorte d’information on
peut y placer. Un objet nommé s’appelle une **variable**. _Il est fondamentalement impossible de faire quoi que ce soit avec un ordinateur sans stocker des
données en mémoire (on parle ici de la RAM)._


Exemples :
- les **entiers** sont stockés dans des objets de type int
- les **réels** sont stockés dans des objets de type float ou double
- etc ..




Une définition peut (et généralement doit) fournir une valeur initiale. Trop de programmes informatiques ont connu des bugs dûs à des oublis d’initialisation de variables... 
Le compilateur se souvient du type de chaque variable et s’assure que vous l’utilisez comme il est
spécifié dans sa définition.

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

## Types de variables

- Les types entiers :
  
```
- bool : false ou true −→ booléen
- unsigned char: 0 à 255 −→ 1 octet ou 8 bits
- [signed] char: -128 à 127 −→ 1 octet mais en entier relatif
- unsigned short [int]: 0 à 65535 −→ 2 octets ou 16 bits
- [signed] short [int]: -32768 à +32767 −→ 2 octets mais en entier relatif
- unsigned int: 0 à 4.295e9 −→ 4 octets
- [signed] int: -2.147e9 à +2.147e9 −→ 4 octets mais en entier relatif
- unsigned long [int]: 0 à 4.295e9 −→ entier sur 4 octets ou plus ; sur PC identique à "int"
- [signed] long [int]: -2.147e9 à -2.147e9−→idem mais en entier relatif
- unsigned long long [int]: 0 à 18.4e18 −→ sur 8 octets
- [signed] long long [int]: -9.2e18 à -9.2e18 −→idem mais en entier relatif
```

- Les types à virgule flottante :

```
- float: environ 6 chiffres de précision et un exposant qui va jusqu’à ±10 ±^38 −→ Codage IEEE sur 4 octets
- double: environ 10 chiffres de précision et un exposant qui va jusqu’à ±10 ±^308 −→ Codage IEEE sur 8 octets
- long double −→ Codé sur 10 octets
```

- Les constantes :
  
```
- celles définies **pour le préprocesseur** : c’est simplement une **substitution syntaxique pure** . Il n’y a aucun typage de la constante.
       #define PI 3.1415

- celles définies **pour le compilateur** : c’est une **variable typée en lecture seule** , ce qui permet des contrôles lors de la compilation.
       const double pi = 3.1415; // en C++ et en C ISO
```

- La définition de synonymes de types typdedef:

Le mot réservé typedef permet simplement la définition de **synonyme de type** qui peut ensuite être utilisé à la place d’un nom de type. typedef est très utilisé car cela rend les code sources portables et lisibles, donc plus facile à maintenir et
 à faire évoluer.

```C
typedef int entier;
typedef float reel;

entier a;  // a de type entier donc de type int
reel x;  // x de type réel donc de type float
```

- Le type énuméré enum:

Une énumération est un type de données dont les valeurs sont des constantes nommées.
- enum permet de déclarer un **type énuméré** constitué d’un ensemble de constantes appelées **énumérateurs**.
- Une variable de type énuméré peut recevoir n’importe quel énumérateur (lié à ce type énuméré) comme valeur.
- Le premier énumérateur vaut zéro (par défaut), tandis que tous les suivants correspondent à leur précédent incrémenté de un.

```C
// enum.c
#include <stdio.h>

typedef int entier;
typedef float reel;

typedef enum{FALSE,TRUE} booleen;

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

- Les pointeurs :
  
Les pointeurs sont des **variables spéciales** permettant de **stocker une adresse** (pour la manipuler
ensuite). L’adresse représente généralement l’ **emplacement mémoire d’une variable**. Comme la variable a un type, le pointeur qui stockera son adresse doit être du même type pour la manipuler convenablement.
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



## Nommer une variable

Un nom de variable est un nom principal (surtout pas un verbe) suffisamment éloquent, éventuellement complété par :

- une caractéristique d’organisation ou d’usage
- un qualificatif ou d’autres noms
- On utilisera la convention suivante : **un nom de variable commence par une lettre minuscule puis les différents mots sont repérés en mettant en majuscule la première lettre d’un nouveau mot**. Exemples : distance, distanceMax, consigneCourante, etatBoutonGaucheSouris, nbreDEssais
- Certaines abréviations sont admises quand elles sont d’usage courant : nbre(ou nb), max, min, ...
- Les lettres i, j, k utilisées seules sont usuellement admises pour les indices de boucles.
- Un nom de variable doit être uniquement composé de lettres, de chiffres et de "souligné" (_). 
- Les noms débutant par le caractère "souligné" (_) sont réservés au système, et à la bibliothèque C. Les noms débutants par un double "souligné" (__) sont réservés aux constantes symboliques privées (#define...) dans les fichiers d’en-tête (.h).
- Il est déconseillé de différencier deux identificateurs uniquement par le type de lettre (minuscule/majuscule). Les identificateurs doivent se distinguer par au moins deux caractères, parmi les 12 premiers,
car pour la plupart des compilateurs seuls les 12 premiers symboles d’un nom sont discriminants.
- Les mots clés du langage sont interdits comme noms.
- _l’objectif de respecter des règles de codage est d’augmenter la lisibilité des programmes en se
rapprochant le plus possible d’expressions en langage naturel._

## Portée d’une variable

La **portée** ( _scope_ ) d’un identifiant (variables, fonctions, ...) est l’étendue au sein de laquelle cet
identifiant est lié. En C, la portée peut être **globale** (en dehors de tout bloc{}) ou **locale** (au bloc
{}).
Des variables déclarées dans des blocs différents peuvent porter le même nom. En cas d’homonymie, le
compilateur fait une résolution au « plus proche » de l’identifiant.

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

## Instructions

Les instructions principales sont :
- l’instruction déclarative
- l’instruction d’expression, l’assignation ou affectation
- l’instruction conditionnelle
- l’instruction itérative (la boucle)
- les branchements (sans condition) en effectuant un saut avec l’instruction goto

Les instructions (ou bloc d’instruction) sont exécutées séquentiellement : cela désigne le fait de faire
exécuter par la machine une instruction, puis une autre, etc, en séquence. Cette construction se distingue
du fait d’exécuter en parallèle des instructions (cf. programmation concurrente ou multi-tâches).

## Expressions

La brique de base la plus élémentaire d’un programme est une **expression**. Une expression calcule
une **valeur** à partir d’un certain nombre d’opérandes. Cela peut être une **valeur littérale** comme 10,
’a’, 3.14, "rouge" ou le **nom d’une variable**.

exemple: longueur = 40;
- \<longueur\> ou lvalue (left value) : est un élément de syntaxe C pouvant être écrit à gauche d'un opérateur d'affectation (=). Une lvalue doit être un emplacement de stockage en mémoire d'un type précis et modifiable.
- <40> or rvalue (right value) : une rvalue est un élément de syntaxe C pouvant être écrit à droite d'un opérateur d'affectation. une rvalue est une valeur d'un type précis mains qui n'a pas forcement de zone de stockage en mémoire. Cela peut être une valeur, une constante, une variable, une expression...

On utilise aussi des opérateurs dans une instruction :
``` C
// calcule une aire
int longueur = 40;
int largeur = 20;
int aire = longueur * largeur; // * est l’opérateur de multiplication
```
De manière générale, un programme informatique est constitué d’une suite d’instructions.
Une instruction d’expression est une expression suivie d’un point-virgule (;). Le point-virgule (;)
est un élément syntaxique permettant au compilateur de “comprendre” ce que l’on veut faire dans le
code.
Dans les programmes, il faut souvent choisir entre plusieurs possibilités. Le C propose plusieurs instructions conditionnelles : l’instruction if (choisir entre deux possibilités) ou l’instruction switch(choisir entre plusieurs possibilités).
Tous les langages de programmation fournissent des moyens pratiques de faire quelque chose plusieurs fois (on parle de traitement itératif). On appelle cela une boucle ou une itération.
Le C offre plusieurs instructions itératives : la boucle while(et sa variante do ... while)
et la boucle for.

## Les opérateurs

Il existe de nombreux opérateurs : les opérateurs arithmétiques ( +, -, *, / et % ), les opérateurs
relationnels ( <, <=, >, >=, == et != ), les opérateurs logiques && (et), ||(ou) et !(non), les opérateurs
bits à bits &(et), |(ou) et ~(non) ...

Les opérateurs arithmétiques et les opérateurs relationnels ne sont définis que pour des opérandes d’un même type parmi : int, long int (et leurs variantes non signées), float, double et long double.

On peut tout de même constituer des expressions mixtes (opérandes de types différents) ou contenant
des opérandes d’autres types (bool, char et short), grâce aux conversions (transtypage ou _cast_ ) implicites
et explicites.

L’opérateur **modulo (%)** permet d’obtenir le reste d’une division. C’est un opérateur très utilisé
notamment dans l’accès à un élément d’un tableau.
Les **opérateurs logiques** &&(et), ||(ou) et !(non) acceptent n’importe quel opérande numérique
(entier ou flottant) ou pointeur, en considérant que tout opérande de valeur non nulle correspond à VRAI
(true). Les deux opérateurs && et || sont **"à court-circuit"** : le second opérande n’est évalué que si la
connaissance de sa valeur est indispensable.

```C
int a = 0;
// Danger : si le premier opérande suffit à déterminer l’évaluation du résultat logique

// Attention : a++ != 5 n’est pas évalué donc (a n’est pas incrémenté) 
// car 0 < 1 et donc toujous VRAI dans un OU**
if ( 0 < 1 || a++ != 5 ) 
    printf("VRAI !\n"); // Affiche toujours : VRAI!
else 
    printf("FAUX !\n");

// Attention : a++ != 5 n’est pas évalué donc (a n’est pas incrémenté) 
// car 1 < 0 et et donc toujous FAUX dans un ET**
if ( 1 < 0 && a++ != 5 ) 
    printf("VRAI !\n");
else 
    printf("FAUX !\n"); **// Affiche toujours : FAUX!**

printf("a = %d\n", a); **// Affichera toujours : a = 0 !!!**
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

Les opérations arithmétiques sur les pointeurs sont bien évidemment réalisées sur les adresses contenues
dans les variables pointeurs. Le type du pointeur a une influence importante sur l’opération. Supposons
un tableau t de 10 entiers (int) initialisés avec des valeurs croissantes de 0 à 9. Si on crée un pointeur
ptr sur un entier (int) et qu’on l’initialise avec l’adresse d’une case de ce tableau, on pourra alors se
déplacer avec ce pointeur sur les cases de ce tableau. Comme ptr pointe sur des entiers (c’est son type),
son adresse s’ajustera d’un décalage du nombre d’octets représentant la taille d’un entier (int). Par
exemple, une incrémentation de l’adresse du pointeur correspondra à une opération +4 (octets) si la
taille d’un int est de 4 octets!

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

Les **opérateurs unaires** (à une seule opérande) d’incrémentation (++) et de décrémentation (––)
agissent sur la valeur de leur unique opérande (qui doit être une **lvalue** ) et fournissent la valeur après
modification lorsqu’ils sont placés à gauche (comme dans ++n) ou avant modification lorsqu’ils sont
placés à droite (comme dans n––). i++ est (à première vue) équivalent à i = i + 1. Mais i++ est une _right-value_ donc ...

```C
int i = 10;

// Attention c’est une post-incrémentation : on augmente i après avoir affecté j
int j = i++; // équivalent à int j=i; i=i+1;

printf("i = %d\n", i); // Affiche : i = 11
printf("j = %d\n", j); // Affiche : j = 10
```

L’ **opérateur ternaire** ? ressemble au if(...) {...} else {...} mais joue un rôle de _right-value_ et pas de simple instruction. La syntaxe est la suivante :(A?B:C) prend la valeur de l’expression B si l’expression A est vraie, sinon la valeur de l’expression C.

```C
int age = 1; int parite; /* un booléen */

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
- ++ ~ (inverseur bit à bit)!(inverseur logique)-(unaire)&(prise d’adresse)*(indirection)
- () (conversion de type)
- \* / % (multiplication, division, modulo)
- \+ - (addition et soustraction)
- « » (décalages et envoi sur flots)
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
4. _Important :_ Si deux opérateurs possèdent la même priorité, C exécutera les opérations de la gauche
    vers la droite (sauf pour les opérateurs suivants où l’ordre est de la droite vers la gauche : ++ ~
    (inverseur bit à bit) !(inverseur logique) -(unaire) &(prise d’adresse) *(indirection) (? :) et = *= /= %= += = «= »= &= |= ~=).
5. L’ordre des opérateurs n’est donc pas innocent. En effet :3/6*6 donnera 0 alors que 3*6/6 donnera 3!
   
Conclusion : comme il est difficile de se rappeler de l’ensemble des priorités des opérateurs, le programmeur préfère coder explicitement en utilisant des parenthèses afin de s’éviter des surprises. Cela améliore aussi la lisibilité.

## Conditionner une action

La célèbre attraction du train fou est interdite aux moins de 10 ans. On souhaite écrire un programme
qui demande à l’utilisateur son âge et qui, si la personne a moins de 10 ans, affiche le texte « Accès
interdit » ; 
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

```
$ ./tester-age
8
Accès interdit
$ ./tester-age
13
```

On écrit donc le mot-clef if, la traduction en anglais de « **si** », puis on met entre parenthèses la
condition à tester, à savoir age < 10. On n’oublie pas de de mettre des accolades.

Pour exprimer la condition du « si » dans le programme, on a utilisé le symbole <, qui est l’opérateur
de comparaison strictement inférieur. De manière symétrique, l’opérateur > permet de tester si un nombre
est strictement supérieur à un autre. Lorsqu’on veut tester si un nombre est inférieur ou égal à un
autre, on utilise le symbole <=. De manière symétrique, le symbole >= permet de tester si un nombre est
supérieur ou égal à un autre.
Pour finir, le symbole == permet de tester l’égalité et la différence avec !=. Evidemment, il ne faut surtout pas confondre avec l’opérateur = qui permet d’effectuer une affectation.

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

En fait cet exemple semble seulement fonctionner comme annoncé. Ce programme dit que si ce n’est pas une conversion en _inch_ c’est forcément une conversion en _cm_. Il y a ici une dérive sur le comportement
de ce programme si l’utilisateur tape ’f’ car il convertira des _cm_ en _inches_ ce qui n’est probablement pas
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

## Les variables booléennes

En C/C++, le programme suivant :

```C
if (prix < 10) {
    printf("Pas cher");
    }
```

peut aussi s’écrire :
```C
#include <stdbool.h> /* nécessaire en C */**

bool estPasCher = (prix < 10);

if (estPasCher) {
    printf("Pas cher");
    }
```

La variable estPasCher est appelée une **variable booléenne** ou un **booléen** de type bool car elle
ne peut être que vraie ou fausse, ce qui correspond en C aux valeurs true(pour vrai) et false(pour
faux).

_N’oublier pas que le type bool est natif en C++. Par contre en C, il faut inclure stdbool.h pour pouvoir l’utiliser._

Il est bien sûr possible d’utiliser des opérateurs booléens (les opérateurs && et || ) pour combiner des
conditions et les valeurs booléennes sont également utilisables.


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

## Itérer une action

Le premier programme jamais exécuté sur un ordinateur à programme stocké en mémoire (l’EDSAC)
est un exemple d’itération. Il a été écrit et exécuté par David Wheeler au laboratoire informatique de
Cambridge le 6 mai 1949 pour calculer et afficher une simple liste de carrés comme ceci :
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
        printf( "%d\t%d\n", i, i * i ); // affiche i et son carré séparés par unetabulation
        ++i; // on incrémente le nombre et on recommence
    }

    return 0;
}
```

Les accolades {} délimitent le **corps de la boucle** : c’est-à-dire le bloc d’instructions à répéter. La
condition pour la répétition est exprimée directement dans le while. La boucle while s’exécutera **0 ou n fois**.

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
- Que se passerait-il si i n’était pas initialisé à 0? Voilà une première raison qui démontre que les     variables non initialisées sont une source d’erreurs courante.
- Que se passerait-il si on oubliait l’instruction ++i? On obtient une boucle infinie (un programme qui
    ne “répond” plus). Il faut éviter au maximum d’écrire des boucles infinies. 

Itérer sur une suite de nombres est si courant en C/C++ que l’on dispose d’une instruction spéciale
pour le faire. C’est l’instruction for qui très semblable à while sauf que la gestion de la variable de
contrôle de boucle est concentrée sur une seule ligne plus facile à lire et à comprendre. Il existe toujours
une instruction while équivalente à une instruction for.

L’instruction for concentre : **une zone d’initialisation, une zone de condition et une zone
d’opération d’incrémentation**. N’utilisez whileque lorsque ce n’est pas le cas.

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

+ Ici, on utilise la fonction puissance (pow) de la bibliothèque mathématique. Pour cela, il faut inclure
math.h en C puis effectuer l’édition des liens avec l’option-lm (ce qui est fait par défaut maintenant).

## La conversion de type (transtypage)

Le compilateur ne peut appliquer des opérateurs qu’à des opérandes de même type. Par exemple, il
n’existe pas d’addition pour : 2 + 1.5 car 2 est un entier et 1.5 est un flottant. Il faudra donc réaliser
une conversion de type ( _cast_ ). De la même manière, on ne pourra pas affecter une variable avec un type
différent. Une conversion ou promotion de type est un transtypage ( _cast_ ).


Il existe deux types de transtypages :
- sans perte : int −→ float (2 devient 2.0)
- avec perte : float −→ int (1.5 devient 1)

Les conversions peuvent être automatiques ou implicites (sans perte) par le compilateur ou forcée ou
explicites (avec ou sans perte) par le programmeur.

Les conversions d’ajustement de type automatique suivant la hiérarchie ci-dessous sont réalisées **sans
perte** :

1. char−→short int−→int−→long−→float−→double−→long double
2. unsigned int−→unsigned long−→float−→double−→long double

Une conversion implicite (automatique) peut donner lieu à un warning de la part du compilateur.

Lorsqu’elle est forçée ou explicite, on utilise l’ **opérateur de** **_cast_** en précisant le type entre parenthèses devant la variable à convertir (C/C++) :(float)a qui permet de forcer la variable a en float.

Les conversions forcées peuvent être des **conversions dégradantes (avec perte)**. Par exemple :
int b = (int)2.5;. En effet, le _cast_ (int)b donnera 2 avec une perte de la partie décimale. Cela peut
être un source d’erreur ( _bug_ ). Le cas le plus « classique » est 1 / 2 qui donne 0 et non pas 0.5, car 1 et
2 sont des entiers ce qui provoque une division entière.

La conversion peut être forcée par la lvalue: les opérateurs d'affectation (=, -=, +=...), appliqués à
des valeurs de type numérique, provoquent la conversion de leur opérande de droite dans le type de leur 
opérande de gauche. Cette conversion forcée peut être "dégradante" (avec perte).

## L’allocation dynamique de mémoire

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

Fuite de mémoire: L'allocation dynamique dans le tas ne permet pas la désallocation automatique. Chaque allo cation avec malloc() doit impérativement être libérée(détruite) avec free() sous peine de créer une fuite de mémoire. La fuite de mémoire est une zone mémoire qui a été allouée dans le tas par un programme qui a omis de la désallouer avant de se terminer. Cela rend la zone inaccessible à toute application y compris le système d'exploitation jusqu'au redémarrage du système. Si ce phénomène se produit trop fréquemment la mémoire se remplit de fuites et le système finit par tomber faute de mémoire.


!!!! Exemple à refaire avec malloc et free

Exemple d’allocation dynamique :
```C
**#include <iostream>
#include <iostream>
#include <new>**

**using namespace** std;

**int** main ()
{
**int** * p1 = new **int** ; **// pointeur sur un entier**

*p1 = 1; // ecrit 1 dans la zone mémoire allouée
cout << *p1 << endl; // lit et affiche le contenu de la zone mémoire allouée
delete p1; // libère la zone mémoire allouée
int * p2 = new int [5]; // alloue un tableau de 5 entiers en mémoire
// initialise le tableau avec des 0 (cf. la fonction memset)
for ( int i=0;i<5;i++)
{
*(p2 + i) = 0; // les 2 écritures sont possibles
p2[i] = 0; // identique à la ligne précèdente
cout << "p2[" << i << "] = " << p2[i] << endl;
}
delete [] p2; // libère la mémoire allouée
return 0;
}
```

## Questions de révision

L’idée de base des questions de révision est de vous donner une chance de voir si vous avez identifié et
compris les points clés de cette partie.

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

### Conclusion

Parce qu’il est clair que vous débutez à peine votre carrière de programmeur, n’oubliez pas qu’écrire
de bons programmes, c’est écrire des programmes corrects, simples et efficaces.

```
Rob Pike (ancien chercheur des Laboratoires Bell et maintenant ingénieur chez Google) :
«Règle n°4 : Les algorithmes élégants comportent plus d’erreurs que ceux qui sont plus
simples, et ils sont plus difficiles à appliquer. Utilisez des algorithmes simples ainsi que des
structures de données simples.»
```
Cette règle n°4 est une des instances de la philosophie de conception KISS ( _Keep it Simple, Stupid_
dans le sens de « Ne complique pas les choses ») ou Principe KISS, dont la ligne directrice de conception
préconise de rechercher la simplicité dans la conception et que toute complexité non nécessaire devrait
être évitée.

## Les types dérivés

Dans de très nombreuses situations, les types de base s’avèrent insuffisants pour permettre de traiter
un problème : il peut être nécessaire, par exemple, de stocker un certain nombre de valeurs en mémoire
afin que des traitements similaires leurs soient appliqués.

Dans ce cas, il est impensable d’avoir recours à de simples variables car tout traitement itératif serait
inapplicable. D’autre part, il s’avère intéressant de pouvoir regrouper ensemble plusieurs variables afin de
les manipuler comme un tout.

Pour répondre à tous ces besoins, le langage C/C++ comporte la notion de **type agrégé** en utilisant :
les **tableaux**. Il existe aussi les **structures** , les **unions** et les **énumérations**.
Les tableaux sont des **conteneurs** ( _container_ ), c’est-à-dire est un **objet qui contient d’autres
objets**.

```C
int tab[5];     // Déclare un tableau de 5 entiers, avec un index de 0 à 4
```

## Les chaînes de caractères

En C/C++, les **chaînes de caractères** sont délimitées par des double quote ("). "Hello world !\n" est donc une chaîne de caractères. Le code \n est un “caractère spécial” indiquant le passage à une nouvelle ligne ( _newline_ ).

Les **chaînes de caractères** contiennent donc des caractères! En C/C++, ils sont codés par défaut en
ASCII (sur 8 bits soit un octet). Un **caractère** est délimité par des guillements simples (’). En C/C++,
un **caractères** est stocké dans une variable de type char.

Une **chaîne de caractères** est délimitée par un caracère spécial de **fin de chaîne** : le caractère nul
qui a pour valeur 0 ou ’\0’. Il est automatiquement ajouté lorsqu’on utilise la notation ("").

```bash
$ man ascii
```

### Déclarations de chaînes de caractères

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

### Opérations sur les chaînes de caractères

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
if (strcmp(nom,fils) == 0) 
    printf("Les deux chaînes sont identiques.\n");
```

### Lecture de chaînes de caractères

La lecture des chaînes de caractère ( scanf()enC/C++ ) se termine sur ce qu’on appelle un espace blanc ( _whitespace_ ), c’est-à-dire le caractère espace, une tabulation ou un caractère de retour à la ligne (généralement la touche Enter ). Notez que les espaces sont ignorés par défaut.

```C
char msg[16];
scanf("%s", &msg[0]); // %s pour une chaîne mais attention au dépassement de taille (on peut uliser fgets)
scanf("%15s", &msg[0]); // on peut limiter le nombre de caractères saisis (ici 15+1 = 16)

// si votre saisie comporte des espaces, vous pouvez utiliser :
// une expression rationnelle (entre crochets) acceptant tous les caractères 
// sauf (^) le retour à la ligne (\n) :
scanf("%15[^\n]s", &msg[0]);

// ou la fonction fgets
fgets(&msg[0], 16, stdin); // attention fgets stocke le retour à ligne
```

- _Sous Linux, vous pouvez indiquer la fin d’un flux en combinant les touches_ Ctrl _+_ d _qui indiquera qu’il n’y a plus de saisie. Vous pouvez aussi stopper le programme avec_ Ctrl _+_ z _ou l’interrompre avec_ Ctrl _+_ c.
Les caractères tapés ne sont pas directement transmis au programme, mais placés (par le système) dans un tampon ( _buffer_ ). Il est possible qu’il reste des caractères d’une saisie précèdente et donc vous aurez besoin de vider le _buffer_ avant de (re)faire une saisie. La méthode pour vider le buffer clavier ( _stdin_ ) consiste à consommer tous les caractères présents dans ce buffer jusqu’à ce qu’il soit vide :

```C
int c = 0;
while ((c = getchar()) != ’\n’ && c != EOF);

// Ou :
scanf("%*[^\n]");
getchar();
```
- _EOF signifie End Of File. Pour générer un EOF avec le clavier, il suffit de taper, en début de ligne,_
Ctrl _+_ z _sous DOS/Windows et_ Ctrl _+_ d _sous UNIX, puis de valider par Entrée._

### Affichage de chaînes de caractères

Pour l’affichage des chaînes de caractère, on utilise printf() en C/C++ :
```C
char msg[] = "Bonjour"; // chaîne de caractères 
printf("msg : %s contient %d caractères\n", msg, strlen(msg)); // %s pour une chaîne
printf("premier caractère : %c\n", msg[0]); // %c pour un simple caractère
```

- _L’affichage est bufferisé lui aussi. Tant que le tampon n’est pas plein, les caractères transmis ne
seront pas effectivement affichés mais tout simplement placés dans le tampon. Pour vider le contenu du
tampon vers l’écran, il faut un retour à la ligne (\n) ou que le tampon soit plein. On peut aussi forcer le
vidage de ce tampon à l’aide de la fonction fflush(stdout) ou carrément ne pas utiliser de buffer en
appelant setbuf(stdout, NULL)._

## Les tableaux

Un **tableau** est un **ensemble d’éléments de même type** désignés par un identificateur unique (un
nom). Chaque élément est repéré par une valeur entière appelée **indice** (ou index) indiquant sa position
dans l’ensemble. Les tableaux sont toujours à bornes statiques et leur indiçage démarre toujours à partir de 0.

### Déclarations de tableaux

La forme habituelle de déclaration d’un tableau est la suivante :
type identificateur[ _dimension_ 1 ]... [ _dimensionn_ ]

Exemple de déclarations de tableaux :
```C
int notes[1000]; // un tableau de 1000 int non initialisé
float notes[1000]; // un tableau de 1000 float non initialisé
```
+ _Par “non initialisé”, on entend qu’il y a une valeur dans chaque case du tableau mais on ne la
connaît pas. Il faut donc considérer qu’il y a “n’importe quoi”! On rappelle que “rien” n’est pas une
notion en informatique car les bits prennent soit la valeur 0 soit la valeur 1 : il n’y a pas de valeur “rien”._

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

### Les tableaux à plusieurs dimensions

- _Contrairement à beaucoup d’autres langages, il n’existe pas en_ C _de véritable notion de tableaux
multidimentionnels. De tels tableaux se définissent par composition de tableaux, c’est à dire que les
éléments sont eux-mêmes des tableaux._

```C
// tableau à 2 dimensions de 2 lignes et 5 colonnes :
int m[2][5] = { 2, 6, -4, 8, 11, // initialise avec des valeurs
3, -1, 0, 9, 2 };

// tableau à 2 dimensions pour stocker plusieurs chaînes de caractères
char noms[][16] = { {"robert"},
{"roger"},
{"raymond"},
{"alphonse"} };

int x[5][12][7]; // tableau a 3 dimensions
```
### Parcourir un tableau

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

### Les tableaux et les pointeurs

- _L’identificateur du tableau (le nom de la variable)ne désigne pas le tableau dans son ensemble,
mais plus précisément l’adresse en mémoire du début du tableau (_ **_l’adresse de la première case_** _).
Ceci implique qu’il est impossible d’affecter un tableau à un autre. L’identificateur d’un tableau sera donc
"vu" comme un_ **_pointeur constant_**_._

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
_Lorsque le nom d’un tableau constitue l’argument d’une fonction, c’est l’adresse du premier élément
qui est transmise. Ses élément ne sont donc pas recopiés. Lorsque l’on passe un tableau en paramètre
d’une fonction, il n’est pas possible de connaître sa taille et il faudra donc lui passer aussi sa taille._

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

### Trier un tableau

La bibliothèque C standard offre une fonction de tri :qsort(). Elle sert à trier un tableau d’éléments
à l’aide d’une fonction de comparaison à fournir. Pour l’utiliser, vous devez inclure le fichier <stdlib.h>.

qsort() trie les éléments dans l’ordre que vous lui demandez. Plus précisément, vous donnez à qsort()
une fonction de comparaison. Cette fonction prend deux éléments A et B, et indique si A doit être avant
ou après B dans le tableau trié. La fonction de comparaison est donc vitale, c’est elle qui indique dans
quel ordre et selon quels critères il faut trier le tableau.

La fonction de comparaison a le prototype suivant :
int compareValeurs(const void* val1, const void* val2)

Elle reçoit en argument deux pointeurs val1 et val2, et retourne un entier. val1 et val2 sont des
pointeurs constants sur les éléments à comparer. Le const empêchera la fonction de comparaison de
modifier le contenu du tableau pendant le tri. Le type void * est ici obligatoire car la fonction ne peut
pas connaître avant le type des éléments à comparer. Elle utilise donc des pointeurs génériques (void *)
qu’il faudra “caster” (transtyper) vers les types désirés.

- _Si la fonction de comparaison est <=, alors à la fin du tri du tableaua[0..n-1] les éléments sont
réordonnés de telle manière que a[0] <= a[1] <= ... <= a[n-1]. Si on utilise la fonction>=, cela
donnera a[0] >= a[1] >= ... >= a[n-1]._

Seul le signe de la valeur retournée par la fonction de comparaison compte. Par exemple on peut
retourner -1 pour A avant B, +1 pour A après B, et 0 (zéro) si l’ordre ne compte pas.

Fonction de comparaison de deux entiers:
```C
#include <stdlib.h>

int compareEntiers( const void * val1, const void * val2)
{
    int i1 = *( const int *)val1; // on caste sur un type entier
    int i2 = *( const int *)val2; // on caste sur un type entier

    if (i1 == i2)
        return 0;
    if (i1 < i2)
        return -1;
    else
        return +1;
}

qsort(valeurs, nbValeurs, sizeof (valeurs[0]), compareEntiers);
```
En pratique, pour trier un tableau valeurs contenant nbValeurs éléments, on donnera à la fonction
qsort()les arguments suivants :
- Le nom du tableau,valeurs
- Le nombre d’éléments du tableau,nbValeurs
- La taille en octets de chaque élément,sizeof(valeurs[0])
- Le nom de la fonction de comparaison,compareEntiers

_Pour rechercher des valeurs dans un tableau, vous pouvez utiliser la fonction bsearch() de la
bibliothèque C standard, déclarée dans le fichier <stdlib.h>. Cette fonction, qui ressemble beaucoup
à qsort(), permet d’effectuer une recherche dichotomique. bsearch() recherche une valeur dans un
tableau initialement trié et prend en argument l’objet cherché (la clé), le tableau, et la fonction de
comparaison qui permet de savoir si un élément donné est situé avant ou après la clé, ou bien est égal à
la clé_.

### Les tableaux dynamiques

Pour allouer dynamiquement des tableaux en C, il faut utiliser les fonctions malloc() et free():
```C
int *T; // pointeur sur un entier

// allocation dynamique d’un tableau de 10 int (un int est codé sur 4 octets)

T = ( int *)malloc( sizeof ( int ) * 10); // alloue 4 * 10 octets en mémoire

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
_La fonction realloc() modifie la taille d’un bloc de mémoire déjà alloué._


### Questions de révision

L’idée de base des questions de révision est de vous donner une chance de voir si vous avez identifié et
compris les points clés de cette partie.

**Question 21.** Sur combien de bits est codé un caractère ASCII?

**Question 22.** Quelle est la taille en bits d’une variable de typechar?

**Question 23.** Quelle est la valeur en hexadécimale du caractère ASCII ’A’?

**Question 24.** Quelle est la différence entre une chaîne de caractères et un tableau de caractères?

**Question 25.** Quelle est la taille en caractères de la chaîne de caractères “hello”?

**Question 26.** Quelle est la valeur de l’indice pour accèder à la première case d’un tableau?

**Question 27.** Quelle est la taille en octets d’un tableau de 100 entiers (int)?

**Question 28.** Dans la déclaration int t[10]? Que représente réellement la variable t?

**Question 29.** Que fait l’instruction t[5] = 2;?

**Question 30.** Que provoque l’instructiont[10] = 2;?

### Conclusion

Les types sont au centre de la plupart des notions de programmes corrects, et certaines des techniques
de construction de programmes les plus efficaces reposent sur la conception et l’utilisation des types.

```
Rob Pike (ancien chercheur des Laboratoires Bell et maintenant ingénieur chez Google) :
«Règle n°5 : Les données prévalent sur le code. Si vous avez conçu la structure des données
appropriée et bien organisé le tout, les algorithmes viendront d’eux-mêmes. La structure des
données est le coeur de la programmation, et non pas les algorithmes.»
```

## Les fonctions

### Programmation procédurale

D’un certain point de vue, un programme informatique ne fait jamais rien d’autre que **traiter des
données**. Comme on l’a déjà vu, un programme accepte des entrées et produit des sorties :

- _Un_ **_traitement est tout simplement l’action de produire des sorties à partir d’entrées_**_.
Les entrées dans une partie de programme sont souvent appelées des_ **_arguments_** _(ou_ **_paramètres_** _) et
les sorties d’une partie de programme des_ **_résultats_**_._

La majeure partie du travail d’un programmeur est : comment exprimer un programme sous la forme
d’un ensemble de parties (des sous-programmes) qui coopèrent et comment peuvent-elles partager et
échanger des données?

Par parties de programme (ou de code), on entend des entités (ou modules) comme une **fonction**
produisant un résultat à partir d’un ensemble d’arguments en entrée.

+ _Exemple : un traitement comme produire le résultat (sortie) 7 à partir de l’argument (entrée) 49 au
moyen de la fonction racineCarree._

En langage C, on pratique la programmation procédurale. La programmation procédurale se
fonde sur le concept d’appel de procédure. Une procédure, aussi appelée routine , sous-routine ou
fonction , contient simplement une série d’étapes à réaliser. Un appel de procédure (ou de fonction)
déclenche l’exécution de la série d’instructions qui la compose.
En programmation procédurale, un programme n’est plus une simple séquence d’instructions mais un
ensemble de sous-programmes (en C, des fonctions) s’appelant entre eux :

Le déroulement d’un programme est le suivant :
- L’exécution du programme commence toujours par l’exécution de la fonction principale (la fonction main() en C/C++)
- L’appel à une fonction permet de déclencher son exécution, en interrompant le déroulement séquentiel des instructions de la fonction principale
- Le déroulement des instructions de la fonction principale reprend, dès que la fonction appelée est terminée, à l’instruction qui suit l’appel

Décomposer un programme en fonctions conduit souvent à diminuer la complexité d’un problème et permet de le résoudre plus facilement.

L’utilisation des fonctions permettra :
- d’éviter de répéter plusieurs fois les mêmes lignes de code : ceci simplifie le code, améliore la lisibilité et facilite la maintenance.
- de généraliser certaines parties de code : la décomposition en fonction permettra la réutilisation du code dans d’autres contextes (cf. bibliothèque logicielle).

On décomposera un programme en fonctions parce que procéder ainsi :
- rend le traitement distinct du point de vue logique
- rend le programme plus clair et plus lisible
- permet d’utiliser la fonction à plusieurs endroits dans un programme (à chaque fois qu’on en a besoin)
- facilitera les tests (on simulera des entrées et on comparera le résultat obtenu à celui attendu)

Bonnes pratiques :
- les programmes sont généralement plus facile à écrire, à comprendre et à maintenir lorsque chaque fonction réalise une seule action logique et bien évidemment celle qui correspond à son nom ;
- on limitera la taille des fonctions à une valeur comprise entre **10 à 15 lignes maximum** ;
- les fonctions se concentrent sur le traitement qu’elles doivent réaliser et n’ont pas (la plupart du temps) à réaliser la saisie de leurs entrées et l’affichage de leur sortie. On évitera le plus possible d’utiliser des saisies et des affichages dans les fonctions pour permettre notamment leur ré-utilisation.

### Fonction vs Procédure

Il existe deux types de sous-programmes :
- Les **fonctions**
    - Sous-programme qui retourne **une et une seule valeur** : permet de ne récupérer qu’ **un résultat**.
    - Par convention, ce type de sous-programme ne devrait pas interagir avec l’environnement (écran,
       utilisateur).
- Les **procédures**
    - Sous-programme qui ne retourne **aucune valeur** : permet de produire **0 à** **_n_** **résultats**
    - Par convention, ce type de sous-programme peut interagir avec l’environnement (écran, utilisateur).
- _Cette distinction ne se retrouve pas dans tous les langages de programmation! Le_ C _/_ C _++n’admet
que le concept de fonction qui servira à la fois pour écrire des fonctions et des procédures._

### Pour les fonctions en C/C++, il faut distinguer :
- la **déclaration** qui est une instruction fournissant au compilateur un certain nombre d’informations concernant une fonction (qui déclare son existence). Il existe une forme recommandée dite **prototype** :
```C
// fichier en-tête (.h)
int plus(int, int);
```
- la **définition** qui revient à écrire le **corps** de la fonction (qui définit donc les traitements effectués dans le bloc {} de la fonction)
```C
// fichier source (.c ou .cpp)
int plus(int a, int b) { return a + b; }
```
- l’ **appel** qui est son utilisation. Il doit correspondre à la déclaration faite au compilateur qui le vérifie.
```C
 // fichier source (.c ou .cpp)
int res = plus(2, 2);
```
_La définition d’une fonction tient lieu de déclaration. Mais elle doit être "connue" avant son
utilisation (un appel). Sinon, le compilateur gcc génèrera un message d’avertissement (warning) qui
indiquera qu’il a lui-même fait une déclaration implicite de cette fonction (ce n’est pas une bonne chose).
Par contre, le compilateur g++ génèrera une erreur :’...’ was not declared in this scope._

+ C _/_ C _++supporte la_ **_récursivité_** _: c’est une technique qui permet à une fonction de s’auto-appeler. La récursivité est une manière simple et élégante de résoudre certains problèmes algorithmiques, notamment en mathématique, mais cela ne s’improvise pas!_

## Déclaration de fonction

Une fonction se caractérise par :
- son **nom** (un identificateur)
- sa **liste de paramètre(s)** : le nombre et le type de paramètre(s) (la liste peut être vide)
- son **type de retour** (un seul résultat)
- _Comme une procédure ne retourne aucune valeur, son type de retour sera void._
Ces informations sont communément appelées le **prototype** de la fonction :

```C
// Le prototype de la fonction calculeNombreDeSecondes :
int calculeNombreDeSecondes( int heures, int minutes, int secondes)

// Soit :
// - son nom : calculeNombreDeSecondes
// - sa liste de paramètre(s) : elle reçoit 3 int
// - son type de retour : int
```

C’est ce qu’il est nécessaire de connaître pour appeler une fonction.
Quand une fonction n’est pas encore définie, il est possible de déclarer son existence afin de pouvoir l’appeler. Il faut pour cela indiquer son prototype, suivi d’un point-virgule :
```C
// La déclaration de la fonction calculeNombreDeSecondes :
int calculeNombreDeSecondes( int heures, int minutes, int secondes);
```
_Les déclarations de fonction sont placées dans des fichiers d’en-tête (header) d’extension.h. Si vous voulez utiliser (i.e. appeler) une fonction, il faudra donc inclure le fichier d’en-tête correspondant (#include). Un fichier d’en-tête regroupe un ensemble de déclarations._

```C
// Le fichier d’en-tête temps.h
#ifndef TEMPS_H /* si l’étiquette TEMPS_H n’est pas défini */
#define TEMPS_H /* alors on définit l’étiquette TEMPS_H */

int calculeNombreDeSecondes( int heures, int minutes, int secondes);

#endif /* finsi TEMPS_H */
```
Le langage C n’interdit pas l’inclusion multiple de fichiers d’en-tête mais il n’accepte pas toujours de déclarer plusieurs fois la même chose! Par précaution, il faut donc s’assurer par des directives de pré-compilation (#ifndef, #define et #endif) que l’inclusion du fichier sera unique. Les directives de
pré-compilation (ou préprocesseur) commencent toujours par un dièse (#). Ce ne sont donc pas des instructions du langage C.

Si vous voulez utiliser (i.e. appeler) une fonction, il faudra donc inclure le fichier d’en-tête correspon
dant :
```C
#include "temps.h"

// Vous pouvez maintenant utiliser (appeler) la fonction calculeNombreDeSecondes :
int s = calculeNombreDeSecondes(1, 0, 0);
```

Si vous créer vos propres fichiers d’en-tête, il est conseillé d’indiquer le nom du fichier entre
guillemets ("temps.h") dans la directive de pré-compilation#include. Vous pourrez indiquer le chemin
où se trouve vos propres fichiers d’en-tête avec l’option -I du compilateur gcc/g++. On n’utilisera pas
les délimiteurs <> (#include <stdio.h>) qui sont réservés pour les fichiers d’en-tête systèmes. Dans ce
cas, le compilateur connaît les chemins d’installation de ces fichers.

```bash
$ ls
main.c temps.c include/
$ ls include/
temps.h
$ gcc -I./include -c temps.c
$ gcc -I./include -c main.c
```

## Définition de fonction

La **définition** d’une fonction revient à écrire le **corps** de la fonction dans le bloc{}. Cela définira la
suite d’instructions qui sera exécutée à chaque appel de la fonction.

```C
#include "temps.h"

// La définition de la fonction calculeNombreDeSecondes :
int calculeNombreDeSecondes( int heures, int minutes, int secondes)
{
    return ((heures*3600) + (minutes*60) + secondes);
}
```

Attention à ne pas mettre de point-virgule à la fin du prototype! Si vous déclarer votre propre
fonction, il vous faudra absolumment la définir si vous voulez passer l’étape de l’édition de lien (ld).
Sinon, vous obtiendrez une erreur :undefined reference.

Pour que la fonction puisse effectivement retourner une valeur, il faut qu’elle contienne une instruction
composée du mot-clé return et de la valeur que l’on veut retourner. L’instruction return quitte la
fonction et transmet la valeur qui suit au programme appelant.

_Dans le cas des fonctions dont le type de retour est void, il est également possible d’utiliser
l’instruction return. Elle n’est alors suivie d’aucune valeur et a simplement pour effet de quitter la
fonction immédiatement._

## Appel de fonction

Un appel à une fonction signifie qu’on lui demande d’exécuter son traitement. 
Une fonction peut être utilisée :
- comme une **opérande** dans une expression, à partir du moment où il y a concordance de types ;
- comme une **instruction**.

```C
// Appel de la fonction calculeNombreDeSecondes :
int s = calculeNombreDeSecondes(1, 0, 0);
```

Soit la fonction carre() ci-dessous :
```
// Déclaration :
// Calcule et retourne le carré d’un nombre
int carre( int ); // le nom du paramètre n’est pas obligatoire

// Définition :
// Calcule et retourne le carré d’un nombre
 // le nom du paramètre est obligatoire
int carre( int x)
{
    // le paramètre x est une variable locale à la fonction
    return x*x;
}

// L’appel doit correspondre à la déclaration faite au compilateur qui le vérifie :
// Principe : on n’est pas obligé d’utiliser le résultat de retour 
// mais on doit donner à la fonction exactement les arguments qu’elle exige

int c5 = carre(2); // Correct

int valeur = 2;
int c6 = carre(valeur); // Correct (valeur est copié dans x)

// Mais on peut faire des erreurs :
int c1 = carre(); // Erreur : pas assez d’argument
int c2 = carre; // Erreur : parenthèses manquantes
int c3 = carre(1, 2); // Erreur : trop d’arguments
int c4 = carre("deux"); // Erreur : mauvais type d’argument car un int attendu

// Attention :
carre(2); // probablement une erreur car la valeur retour n’est pas utilisée

// Soyez vigilant :
int x = 2;
int c7 = carre(x); // Correct (x est copié dans x)
// après l’appel : x contient toujours 2 et c7 contient 4
```

## Programmation modulaire

Le découpage en fonctions d’un programme permet la programmation modulaire :
Par la suite, un utilitaire comme make permettra d’automatiser la fabrication de programme. Il utilise
un fichier de configuration appelé _makefile_ qui porte souvent le nom de Makefile. Ce fichier décrit des cibles (qui sont souvent des fichiers, mais pas toujours), de quelles autres cibles elles dépendent, et par
quelles actions (des commandes) y parvenir. Au final, le fichier Makefile contient l’ensemble des règles
de fabrication du programme :

Exemple de fichier Makefile :
```Makefile
CC=gcc
RM=rm

TARGET := calculTemps

all: $(TARGET)

main.o: main.c temps.h
    $(CC) -o $@ -c $<

temps.o: temps.c temps.h
    $(CC) -o $@ -c $<

$(TARGET): main.o temps.o
    $(CC) -o $(TARGET) $^

clean:
    $(RM) -f $(TARGET) *.o *~
```

La fabrication de l’exécutable est assurée ensuite par l’utilitaire make:
```bash
$ make
gcc -o main.o -c main.c
gcc -o temps.o -c temps.c
gcc -o calculTemps main.o temps.o
$ ./calculTemps
```
+ _Avec son système de dépendance, make ne compile que ce qui est nécessaire. Lire :https://fr.wikipedia.org/wiki/Make._

## Passage de paramètre(s)

### Passage par valeur

Lorsque l’on passe une valeur en paramètre à une fonction, cette valeur est copiée dans une variable
locale de la fonction correspondant à ce paramètre. Cela s’appelle un passage par valeur.
'Dans un passage par valeur, il est impossible pour une fonction de modifier les paramètres qu’elle reçoit. 

Essayons de permuter deux variables :
```C
// Tente de permuter deux entiers
void permute( int a, int b)
{
    printf("avant [permute] : a=%d et b=%d\n", a, b); // affiche : a=5 et b=3
    int temp = a;
    a = b;
    b = temp;
    printf("après [permute] : a=%d et b=%d\n", a, b); // affiche : a=3 et b=5
}

int main()
{
    int a = 5, b = 3;
    printf("avant [main] : a=%d et b=%d\n", a, b); // affiche : a=5 et b=3
    permute(a, b);
    printf("après [main] : a=%d et b=%d\n", a, b); // affiche : a=5 et b=3
    return 0;
}
```
_Les variables a et b sont locales au bloc ({}) où elles sont définies. Des variables définies dans des
blocs différents peuvent porter le même nom._

### Passage par adresse

Pour permettre à une fonction de modifier les paramètres qu’elle reçoit, il faudra passer les adresses
des variables comme paramètres. On utilise dans ce cas des pointeurs. Cela s’appelle un **passage par adresse** :

```C
// Permute deux entiers
void permute( int *pa, int *pb)
{
    printf("avant [permute] : a=%d et b=%d\n", *pa, *pb); // affiche : a=5 et b=3
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("après [permute] : a=%d et b=%d\n", *pa, *pb); // affiche : a=3 et b=5
}

int main()
{
    int a = 5, b = 3;

    printf("avant [main] : a=%d et b=%d\n", a, b); // affiche : a=5 et b=3
    permute(&a, &b); // passe l’adresse des variables a et b
    printf("après [main] : a=%d et b=%d\n", a, b); // affiche : a=3 et b=5

    return 0;
}
```

Le passage d’un tableau en paramètre d’une fonction est évidemment possible :
```C
#include <stdio.h>

void raz( int t[], int n) /* équivalent à : void raz(int *t, int n) */
{
    int i;

    for (i=0;i<n;i++)
        t[i] = 0;
}

int main()
{
    int t[2] = { 2, 3 }; // 2 éléments

    printf("avant [main] : t[0] = %d et t[1] = %d\n", t[0], t[1]); // affiche t[0] = 2 et t[1] = 3
    raz(t, 2); // équivalent à : raz(&t[0], 2);
    printf("après [main] : t[0] = %d et t[1] = %d\n", t[0], t[1]); // affiche t[0] = 0 et t[1] = 0

    return 0;
}
```

Le tableau passé en paramètre a bien été modifié car la fonction raz() à travailler avec l’adresse
du tableau. Les cases du tableau n’ont pas été recopiées et la fonction accède au tableau original. On
rappelle qu’il n’existe pas de variable désignant un tableau comme un tout. Quand on déclare int t[2],
t ne désigne pas l’ensemble du tableau mais l’adresse de la première case. t est une **constante de type
pointeur** vers un int dont la valeur est &t[O], l’adresse du premier élément du tableau.

_C’est une très bonne chose en fait car dans le cas d’un "gros tableau", on évite ainsi de recopier
toutes les cases. Le passage par adresse sera beaucoup plus efficace et rapide._

## Valeur de retour

Par définition, une fonction fournit un **résultat**. Pour cela, on lui déclare un **type de retour** et on
renvoie une valeur (du type déclaré) avec l’instruction **return**. Cette instruction provoque évidemment
la sortie de la fonction appelée. La valeur de retour peut servir à **renvoyer un résultat** ou **un état sur l’exécution** de la fonction appelée.

Certains programmeurs utilisent donc la valeur de retour pour indiquer si la fonction a réalisé son
traitement avec succès ou si elle a rencontré une erreur. C’est le cas de beaucoup de fonctions systèmes.
On distingue différentes pratiques pour la convention du type de retour :

- valeur de retour de type booléen (bool) :true(succès) ou false(erreur)
- valeur de retour de type entière (int) : 0 (succès) ou !=0(un code d’erreur)
- valeur de retour de type entière (int) : 1 (succès) ou <0(un code d’erreur)

Il ne faut jamais négliger ce type de code de retour lorsqu’on utilise une fonction. Prenons un exemple : vous appelez une fonction pour créer un répertoire (man 2 mkdir) puis une fonction pour copier un fichier dans ce répertoire. Si la création du répertoire échoue, cela ne sert à rien d’essayer de copier ensuite le fichier. La réussite (ou l’échec) de la première action conditionne l’exécution de la deuxième action. Si vous ne testez jamais les codes de retour de fonction, vous allez provoquer des cascades d’erreurs.

Dans certaines situations extrêmes, vous risquer d’avoir besoin de sortir immédiatement du programme quelque soit l’endroit où vous êtes. Vous pouvez utiliser la fonction exit() qui termine normalement un
programme en indiquant une valeur de retour. Évidemment, la fonction exit() ne revient jamais.

Quitter un programme:
```C
#include <stdio.h>
#include <stdlib.h> /* pour exit() */
#include <sys/stat.h> /* pour mkdir() */
#include <sys/types.h>

int main()
{
    mode_t mode = 0750;
    int retour;

    retour = mkdir("./dossier", mode); // Création d’un répertoire

    // Une erreur s’est-elle produite?
    if (retour == -1) {
        // La fonction perror() affiche un message d’erreur décrivant la dernière erreur
        // rencontrée durant un appel système ou une fonction de bibliothèque
        perror("mkdir");

        // Cela ne sert à rien de continuer, on quitte le programme en indiquant qu’on a rencontré une erreur
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS; // sortir de la fonction main() revient à quitter le programme
}
```
Cela donne :
```bash
$ gcc mkrep.c

$ ./a.out
$ ls -l
-rwxrwxr-x 1 tv tv 8,3K août 9 10:47 a.out*
drwxr-x--- 2 tv tv 4,0K août 9 10:47 dossier/
-rw-rw-r-- 1 tv tv 329 août 9 10:47 mkrep.c
$ ./a.out
mkdir: File exists
```

## Nommer une fonction

Un nom de fonction est construit à l’aide d’un verbe (surtout pas un nom), et éventuellement d’éléments supplémentaires comme :
- une quantité
- un complément d’objet
- un adjectif représentatif d’un état

_Une fonction est composée d’une série d’instructions qui effectue un traitement. Il faut donc utiliser un verbe pour caractériser l’action réalisée par la fonction._
On utilisera la convention suivante : **un nom de fonction commence par une lettre minuscule puis les différents mots sont repérés en mettant en majuscule la première lettre d’un nouveau mot.**
Le verbe peut être au présent de l’indicatif ou à l’infinitif. L’adjectif représentatif d’un état concerne surtout les fonctions booléennes. La quantité peut, le cas échéant, enrichir le sens du complément.
Exemples : void ajouter(), void sauverValeur(), estPresent(), estVide(), videAMoitieLeReservoir(), ...
_Les mots clés du langage sont interdits comme noms._
Les noms des paramètres d’une fonction sont construits comme les noms de variables : ils commencent,
notamment par une minuscule. L’ordre de définition des paramètres doit respecter la règle suivante :
nomFonction(parametrePrincipal, listeParametres)
où parametrePrincipal est la donnée principale sur laquelle porte la fonction, la listeParametres
ne comportant que des données secondaires, nécessaires à la réalisation du traitement réalisé par la
fonction.
Exemple :ajouter(float mesures[], float uneMesure)
Le rôle de cette fonction est d’ajouter une mesure à un ensemble de mesures(qui est la donnée principale) et non, d’ajouter un ensemble de mesures à une mesure.
- _Bonne pratique : L’objectif de la programmation procédurale est de décomposer un traitement de
grande taille en plusieurs parties plus petites jusqu’à obtenir quelque chose de suffisamment simple à
comprendre et à résoudre (cf. Descartes et son discours de la méthode). Pour cela, on va_ **_s’obliger à
limiter la taille de nos fonctions à une valeur comprise entre 10 à 15 lignes maximum_**
_(accolades exclues)._


## La fonction main

Tout programme C/C++ doit posséder une **fonction** nommée main (dite fonction principale) pour indiquer où commencer l’exécution. La fonctionmain()représente le point d’entrée (et de sortie) d’un programme exécuté par le “système” (c’est-à-dire le système d’exploitation).

La fonction main():
```C
// Forme simplifiée :
int main()
{

    return 0; // on doit retourner une valeur entière
}
```

```C
// Forme normalisée :
int main( int argc, char **argv)
{

    return 0; // on doit retourner une valeur entière
}
```

```C
// Forme normalisée :
int main( int argc, char *argv[])
{

    return 0; // on doit retourner une valeur entière
}
```

**Paramètres d’entrée :** la fonction main() reçoit deux paramètres (ils peuvent être ignorés) :
un entier (int) qui précisera le nombre d’arguments passés au programme et un tableau de chaînes de caractères (char ** ou char *[]) qui contiendra la liste de ses arguments.

Les arguments d’un programme :
```C
#include <stdio.h>

int main( int argc, char **argv )
{
    int i;

    printf( "nb d’arguments = %d\n", argc );

    for ( i=0; i<argc; i++ )
        printf( "argv[%d] = %s\n", i, argv[i] );

    return 0;
}
```

```bash
$ ./a.out les parametres du programme
nb d’arguments = 5
argv[0] = ./a.out
argv[1] = les
argv[2] = parametres
argv[3] = du
argv[4] = programme

$ ./a.out
nb d’arguments = 1
argv[0] = ./a.out
```

_Il existe une fonction getopt() qui permet d’analyser plus facilement les options d’une ligne de commande (man 3 getopt)._

**Valeur de retour :** la fonction main() doit retourner une valeur entière (int). Sur certains
systèmes (Unix/Linux), elle peut servir à vérifier si le programme s’est exécuté correctement. Un zéro ( 0 )
indique alors que le programme s’est terminé avec succès (c’est une convention). Évidemment, une valeur
différente de 0 indiquera que le programme a rencontré une erreur. Et sa valeur précisera alors le type de
l’erreur. Sur un système Unix/Linux, la dernière valeur de retour reçue est stockée dans une variable $?
du _shell_.

La valeur de retour d’un programme
```C
#include <stdio.h>

// Exemple : on peut vérifier que l’on reçu le nombre suffisant d’arguments
int main( int argc, char **argv)
{
    if (argc < 2)
        return 1;
    
    return 0;
}
```

```bash
$ ./a.out les parametres du programme
$ echo $?
0

$ ./a.out
$ echo $?
1
```

## Fonctions statiques

Par défaut, lorsqu’une fonction est définie dans un fichier C/C++, elle peut être utilisée dans tout autre fichier pourvu qu’elle soit déclarée avant son utilisation. Dans ce cas, la fonction est dite **externe**(mot-clé extern).
Il peut cependant être intéressant de définir des fonctions locales à un fichier, soit afin de résoudre des conflits de noms (entre deux fonctions de même nom et de même signature mais dans deux fichiers différents), soit parce que la fonction est uniquement d’intérêt local. LeC/C++fournit donc le mot clé static qui, une fois placé devant la définition et les éventuelles déclarations d’une fonction, la rend unique et utilisable uniquement dans ce fichier. À part ce détail, les fonctions statiques s’utilisent exactement comme des fonctions classiques.

Cas des variables :
Le mot clé static, placé devant le nom d’ **une variable globale** (une variable déclarée en dehors de
tout bloc{}), a le même effet que pour les fonctions statiques. On parle alors de variable globale cachée.

Le mot clé static, placé devant le nom d’une **variable locale** (une variable déclarée dans un bloc
{}), rend la variable persistante (la variable conserve sa valeur) entre chaque entrée dans le bloc.

Variable locale statique:
```C
#include <stdio.h>
void compte()
{
    static int compteur = 0; // la variable compteur conservera sa valeur entre chaque appel

    ++compteur;
    printf("La fonction a été appelée : %d fois\n", compteur);
}

int main()
{
    compte();
    compte();
    compte();

    return 0;
}
```

```bash
$ ./a.out
La fonction a été appelée : 1 fois
La fonction a été appelée : 2 fois
La fonction a été appelée : 3 fois
```

### Nombre variable de paramètres

En général, les fonctions ont un nombre constant de paramètres. 
Le C et le C++ disposent toutefois d’un mécanisme qui permet au programmeur de réaliser des fonctions
dont le nombre et le type des paramètres sont variables. C’est le cas par exemple des fonctions printf()
et scanf().

Pour indiquer au compilateur qu’une fonction peut accepter une liste de paramètres variable, il faut
simplement utiliser des points de suspensions dans la liste des paramètres dans les déclarations et la
définition de la fonction :

type identificateur(paramètres, ...)
Dans tous les cas, il est nécessaire que la fonction ait au moins un paramètre classique. Les paramètres
classiques doivent impérativement être avant les points de suspensions.

On utilisera le type va_list et les expressions va_start, va_arg et va_end pour récupérer les
arguments de la liste de paramètres variable, un à un. Pour cela, il faudra inclure le fichier d’en-tête
stdarg.h.

Nombre variable de paramètres:
```C
#include <stdarg.h>

/* effectue la somme de compte flottants (float ou double) et la renvoie dans un double */
double somme( int compte, ...)
{
    double resultat = 0; /* Variable stockant la somme */
    va_list varg; /* Variable identifiant le prochain paramètre */
    va_start(varg, compte); /* Initialisation de la liste */

    /* Parcours de la liste */
    while (compte != 0) {
        resultat = resultat + va_arg(varg, double ); /* récupère le prochain paramètre dans la liste */
        compte = compte-1;
        }
    va_end(varg);
    return resultat;
}

int main()
{
    double total = 0;

    total = somme(3, 1.5, 2.5, 5.); // 4 paramètres
    printf("%.1f\n", total); // affiche 9.0

    total = somme(2, 1.5, 2.5); // et maintenant 3 paramètres
    printf("%.1f\n", total); // affiche 4.0

    return 0;
}
```

## Pointeur vers une fonction

Le nom d’une fonction est une constante de type pointeur.
Pointeur sur une fonction:
```C
// une fonction
int f( int x, int y)
{
    return x+y;
}

// un pointeur sur une fonction :
// pf est un pointeur vers une fonction admettant 2 entiers en paramètres et retournant un entier
int (*pf)( int , int ); 

pf = f; // pf pointe vers la fonction f

// appel :
printf("%d\n", (*pf)(3, 5)); // affiche 8
```

### Questions de révision

L’idée de base des questions de révision est de vous donner une chance de voir si vous avez identifié et
compris les points clés de cette partie.

**Question 31.** Quelles sont les quatre parties d’une fonction?

**Question 32.** Comment s’appelle une fonction qui ne retourne aucun résultat?

**Question 33.** Citer les trois types de passage de paramètres?

**Question 34.** Donner la déclation d’une fonction foo qui reçoit en paramètres un tableau d’entiers et
le nombre d’éléments qu’il contient et qui retourne la somme de ces élèments.

### Conclusion

Il est indispensable de décomposer un traitement de grande taille en plusieurs parties plus petites
jusqu’à obtenir quelque chose de suffisamment simple à comprendre et à résoudre. Cette approche
consistant à décomposer une tâche complexe en une suite d’étapes plus petites (et donc plus facile à
gérer) ne s’applique pas uniquement à la programmation et aux ordinateurs. Elle est courante et utile
dans la plupart des domaines de l’existence.

```
Descartes (mathématicien, physicien et philosophe français) dans le Discours de la méthode :
«diviser chacune des difficultés que j’examinerais, en autant de parcelles qu’il se pourrait,
et qu’il serait requis pour les mieux résoudre.»
```
## Types composés

Les types composés permettent de regrouper des variables au sein d’une même entité :
- Il est possible de regrouper des variables de types différents dans des **structures de données** ;
- Il est possible de regrouper des variables de types identiques dans des **tableaux**.
- Une chaîne de caractères peut être considérée comme un type composé.
  
En C, on dispose de trois types de structures de données :
- les structures (struct)
- les unions (union)
- les champs de bits

### Structures

Besoin : Il est habituel en programmation d’avoir besoin d’un mécanisme permettant de grouper un certain nombre de variables de types différents au sein d’une même entité.

Exemple : On travaille par exemple sur un fichier de personnes et on voudrait regrouper une variable de type chaîne de caractères pour le nom, une variable de type entier pour le numéro d’employé, etc.

La réponse à ce besoin est le concept d’ **enregistrement** : un enregistrement est un ensemble d’éléments
de types différents repérés par un nom. Les éléments d’un enregistrement sont appelés des **champs**.

En langage C, on utlise le vocabulaire suivant :
- enregistrement−→ **structure**
- champ d’un enregistrement−→ **membre** d’une structure

Une **structure** est donc un **objet agrégé comprenant un ou plusieurs membres** d’éventuellement différents types que l’on regroupe sous un seul nom afin d’en faciliter la manipulation et le traitement.

Chacun des membres peut avoir n’importe quel type, y compris une structure, à l’exception de celle à laquelle il appartient.

#### Déclaration de structure

Il y a plusieurs méthodes possibles pour déclarer des structures.
```
struct [etiquette]
{
    type champ_1;
    ...
    type champ_n;
} [identificateur];
```

Pour déclarer une structure, on utilise le mot clé struct suivi d’une liste de déclarations entre
accolades. Il est possible de faire suivre le mot struct d’un nom baptisé etiquette de la structure. Cette
etiquette désigne alors cette sorte de structure et, par la suite, peut servir pour éviter d’écrire entièrement toute la déclaration. Il est aussi possible d’instancier directement une variable de nom identificateur.

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
} dateDeces; // dateDeces est une variable de type structuré
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
#### Initialisation d’une structure

Comme pour les tableaux, les accolades peuvent être utilisées pour indiquer les valeurs initiales des
membres d’une variable de type structuré. Cela ne fonctionne qu’à l’initialisation.
Ce n’est pas utilisable pour une affectation.

Initialisation d’une structure:
```C
// Une variable de type Date :
Date naissanceMarie = {7, 11, 1867}; // initialisation de la structure naissanceMarie

printf("La structure struct Date occupe une taille de %d octets\n", sizeof (struct Date));
```
_La taille d’une structure est la somme des tailles de tous les objets qui la compose (cf.sizeof()). Dans notre exemple, la structure aura une taille de_ 3 × 4 _(int) soit 12 octets._

#### Accès aux membres

Pour accéder aux membres d’une structure, on utilise :
- l’opérateur d’accès.(point) pour une variable de type structuré :
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

#### Affectation de structure

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

#### Tableaux de structures

Une déclaration de tableau de structures se fait selon le même modèle que la déclaration d’un tableau dont les éléments sont de type simple :
```C
struct Date t[100]; // 100 éléments de type struct Date

// Ou :
Date t[100]; // 100 éléments de type Date

// Chaque élément du tableau est de type Date :
for (i=0<100;i++)
    printf("%02d/%02d/%4d\n", t[i].jour, t[i].mois, t[i].annee);
```

#### Liste de structures

Une des utilisations fréquentes des structures, est de créer des listes de structures chaînées. Pour cela,
il faut que chaque structure contienne un membre qui soit de type **pointeur** vers une structure du même
type. Cela se fait de la façon suivante :

```
struct personne
{
    ... **/* les différents membres */**

    struct personne *suivant;
};
```
_La dernière structure de la liste devra avoir un membre suivant dont la valeur sera le pointeur NULL pour indiquer la fin._

Quand on crée une liste chaînée, on ne sait généralement pas à la compilation combien elle comportera
d’éléments à l’exécution. Pour pouvoir créer des listes, il est donc nécessaire de pouvoir allouer de l’espace
dynamiquement :

Allocation dynamique d’une structure:
```C
#include <stdlib.h>

struct personne *p;

// Allocation :
p = malloc( **sizeof** (struct personne));

// Libération :
free(p);
```

### Union

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

_La taille mémoire de la variable valeurCapteur est égale à la taille mémoire du plus grand type qu’elle contient (ici c’est float)._

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

### Champs de bits

Besoin : Il est parfois nécessaire pour un programmeur de décrire en termes de bits la structure d’une information.
Les champs de bits ("Drapeaux" ou " Flags "), qui ont leur principale application en informatique industrielle, sont des structures qui ont la possibilité de regrouper (au plus juste) plusieurs valeurs. La
taille d’un champ de bits ne doit pas excéder celle d’un entier. Pour aller au-delà, on créera un deuxième champ de bits.
On utilisera le mot clé struct et on donnera le type des groupes de bits, leurs noms, et enfin leurs tailles.
_Il est autorisé de ne pas donner de nom aux champs de bits qui ne sont pas utilisés._

```
struct [etiquette]
{
    type champ_1 : nombre_de_bits;
    type champ_2 : nombre_de_bits;
    [...]
    type champ_n : nombre_de_bits;
} [identificateur];
```

Si on reprend le type structuré Date, on peut maintenant décomposer ce type en trois groupes de bits
(jour,mois et annee) avec le nombre de bits suffisants pour coder chaque champ. Les différents groupes
de bits seront tous accessibles comme des variables classiques d’une structure ou d’une union.

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
_La taille mémoire d’une variable de ce type sera égale à 2 octets (5 + 4 + 7 = 16 bits)._

### Questions de révision

**Question 36.** Donner la déclaration d’une structure Voiture qui possède les champs suivants : la capacité du réservoir et le nombre de chevaux fiscaux?

**Question 37.** Quelle est la taille en octets d’une structure qui contient 2 champs : un entier (int) et
un flottant (float)?

**Question 38.** Quelle est la taille en octets d’une union qui contient 2 champs : un entier (int) et un
flottant (float)?

**Question 39.** Donner la déclaration d’un type énuméré CouleurCarte pour les quatres couleurs de cartes à jouer?

**Question 40.** Peut-on réaliser des tableaux de structures? Peut-on réaliser des structures qui contiennent
des tableaux?

### Conclusion

Les types sont au centre de la plupart des notions de programmes corrects, et certaines des techniques
de construction de programmes les plus efficaces reposent sur la conception et l’utilisation des types.

```
Rob Pike (ancien chercheur des Laboratoires Bell et maintenant ingénieur chez Google ) :
« Règle n°5 : Les données prévalent sur le code. Si vous avez conçu la structure des données
appropriée et bien organisé le tout, les algorithmes viendront d’eux-mêmes. La structure des
données est le coeur de la programmation, et non pas les algorithmes. »
```
## Le préprocesseur

#define
#include
#ifdef
#ifndef
#endif
#pragma

## Annexes

### Annexe 0 : historique

- En 1970, **Ken Thompson** , créa un nouveau langage : LeB, descendant du BCPL ( _Basic Combined Programming Language_ , créé en 1967 par Martin Richards). Son but était de créer un langage simple, malheureusement, son langage fût trop simple et trop dépendant de l’architecture utilisée.
- En 1971, **Dennis Ritchie** commence à mettre au point le successeur du B, le C. Le résultat est convaincant : Le C est **totalement portable** (il peut fonctionner sur tous les types de machines et de systèmes), il est de **bas niveau** (il peut créer du code pratiquement aussi rapide que de l’assembleur) et il permet de traiter des **problèmes de haut niveau**. Le C permet de quasiment tout faire, du _driver_ au jeu. Le C devient très vite populaire.
- En 1983, **Bjarne Stroustrup** des laboratoires Bell crée leC++. Il construit donc le C++ sur la base     du C. Il garde une forte compatibilité avec le C. Un programme écrit en C sera compilé par un compilateur C++.
- En 1989, l’ **ANSI** ( _American National Standards Institute_ ) normalisa le C sous les dénominations     **ANSI C** ou **C89**. Un programme écrit dans ce standard est compatible avec tous les compilateurs.
- En 1999, l’ **ISO** ( _International Organization for Standardization_ ) proposa une nouvelle version de la norme, qui reprenait quelques bonnes idées du langageC++. Il ajouta aussi le typelong long d’une taille minimale de 64 bits, les types complexes, l’initialisation des structures avec des champs nommés, parmi les modifications les plus visibles. Le nouveau document est celui ayant autorité aujourd’hui, est connu sous le sigle **C99**.

Les langages C et C++ sont les langages les plus utilisés dans le monde de la programmation.

Remarques :
- Certaines autres extensions du C ont elles aussi été standardisées, voire normalisées. Ainsi, par exemple, des fonctions spécifiques aux systèmes **UNIX** , sur lesquels ce langage est toujours très populaire, et qui n’ont pas été intégrées dans la norme du langage C, ont servi à définir une partie de la norme **POSIX**.
- Le langage C++ est normalisé par l’ISO. Sa première normalisation date de 1998 (C++ 98 ), puis une seconde en 2003. Le standard actuel a été ratifié et publié par ISO en septembre 2011 (C++ 11 ). Les standards sont supportés progressivement par les compilateurs.

L'option-std des compilateurs gcc/g++ permet de choisir la norme à appliquer au moment de la compilation.Par exemple:-std=c89 ou c99 pour le C.

Le C++ a apporté par rapport au langage C les notions suivantes :
- les **concepts orientés objet (encapsulation, héritage et polymorphisme)** ,
- les références, la vérification stricte des types,
- les valeurs par défaut des paramètres de fonctions,
- la surcharge de fonctions (plusieurs fonctions portant le même nom se distinguent par le nombre et/ou le type de leurs paramètres),
- la surcharge des opérateurs (pour utiliser les opérateurs avec les objets), les constantes typées,
- la possiblité de déclaration de variables entre deux instructions d’un même bloc
 
On peut passer progressivement de C à C++: il suffit en premier lieu de **changer de compilateur (par exemple gcc** −→ **g++)** , sans nécessairement utiliser les nombreuses possibilités supplémentaires
qu’offre C++. Le principal intérêt du passage de C à C++ sera de profiter pleinement de la puissance de la
**programmation orientée objet (POO)**.


L'extension par défaut des fichiers écrits en langage C++ est .cpp ou .cc. Pardéfaut, gcc et g++ fabriquent un exécutable de nom a.out. Sinon, on peut lui indiquer le nom du fichier exécutable en utilisant l'option -o <executable>.

### Annexe 2 : classe d’allocation

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

En raison des risques d'effets de bord, les variables globales sont à bannir de la programmations tructurée.


Les variables volatiles :
- Une variable **volatile** est une variable sur laquelle aucune optimisation de compilation n’est appliquée.
- Le mot-clé volatile existe en C/C++, mais aussi en C# et Java.
- Le préfixe volatile est notamment utilisé en programmation multi-tâche (avec des _threads_ ) quand la variable d’un programme peut être modifiée par un autre programme. Cela empêche par exemple le processeur de conserver la valeur d’une variable dans son cache. Voir aussi le mot-clé atomic.

### Annexe 3 : printf() et scanf()

Il exste trois flux de base pour chaque programme :
- stdin(0) : Entrée standard (par défaut le clavier)
- stdout(1) : Sortie standard (par défaut l’écran)
- stderr(2) : Sortie erreur (par défaut l’écran également)
- En C, un flux est un canal destiné à transmettre ou à recevoir de l’information. Il peut s’agir de fichier ou de périphériques.

Pour afficher des résultats à l’écran, il faudra écrire sur le flux stdout. Pour cela, on utilise généralement
la fonction printf() (déclarée dans stdio.h):

```C
#include <stdio.h>

printf("Hello World!\n");

// ce qui correspond à :
fprintf(stdout, "Hello World!\n");

// ou :
write(1, "Hello World!\n"); // 1 étant le descripteur de stdout

//Pour afficher une erreur, il est recommandé de la faire dans le flux stderr
fprintf(stderr, "Ceci est une erreur.\n");
```

_Si on ne désire pas l’affichage des messages d’erreur d’un programme, il suffit de rediriger son flux
stderr vers le périphérique null. 
Par exemple :
```bash
$ ./a.out 2> /dev/null
```

La fonction printf() (ainsi que sprintf() et fprintf() prend en argument une chaîne de format qui spécifie les types de ses autres arguments. La chaîne de format deprintf()est riche en possibilités, car elle indique non seulement le type des arguments mais aussi la manière de les écrire. Par exemple, vous pouvez choisir le nombre de chiffres après la virgule d’un nombre flottant. Chaque code spécial de la chaîne de format est précédé d’un %. Si vous voulez écrire le symbole %, vous devez l’écrire deux fois :%%.

```C
printf("%d\n", 42); // affichage d’un entier
printf("Taux de réussite : %.1f %%\n", 92.9); // Taux de réussite : 92.9 %
```

Chaque code spécial est découpé en plusieurs sections (les sections entre crochets sont facultatives) :
%[largeur][.precision]type

1. Largeur : nombre minimum de caractères à écrire, printf() complètera si nécessaire par des espaces sur la gauche, la valeur est alignée à droite.
2. Précision : nombre de chiffres après la virgule à écrire pour les nombres flottants, précédé d’un point. La valeur est automatiquement arrondie : le dernier chiffre est incrémenté s’il y a besoin.
3. Type : le type de la valeur à écrire


Voici les différents types utilisables :
- %d    int             entier 32 bits en décimal
- %u    unsigned int    entier 32 bits non signé en décimal
- %x    int             entier 32 bits en hexadécimal (en minuscules et %X en majuscules)
- %lld long long int entier 64 bits
- %f float ou double avec par défaut 6 chiffres après la virgule
- %g float ou double en utilisant la notation 1.234e5 quand cela est approprié
- %c char caractère unique
- %s char* chaîne de caractères
- %p void* l’adresse mémoire en hexadécimal


```
$ man 3 printf
```

La fonction scanf() permet de lire des données sur l’entrée standard (stdin). Cette fonction prend comme premier argument une chaîne de format, qui indique combien de variables vous souhaitez lire, et de quel type. Ensuite vous donnez passer en arguments des pointeurs sur les variables qui recevront le résultat, dans l’ordre de la chaîne de format.

Prenons le cas le plus simple :
```C
#include <stdio.h>

// lire un entier et le placer dans la variable n :
int n;
scanf("%d", &n); // ne pas oubliez le & qui donne l’adresse de la variable n, 
                // c’est nécessaire ici pour que la fonction puisse modifier la variable passée en argument

// lire deux entiers :
int a, b;
scanf("%d %d", &a, &b);
```
- _La lecture des chaînes de caractère (avec scanf() en_ C _/_ C _++) se termine sur ce qu’on appelle un espace blanc (whitespace), c’est-à-dire le caractère espace, une tabulation ou un caractère de retour à la ligne (généralement la touche_ Enter _). Notez que les espaces sont ignorés par défaut. Sous Linux, vous pouvez indiquer la fin d’un flux (EOF) en combinant les touches_ Ctrl _+_ d _qui indiquera qu’il n’y a plus de saisie. Vous pouvez aussi stopper le programme avec_ Ctrl _+_ z _ou l’interrompre avec_ Ctrl _+_ c_._

La chaîne de format se compose de codes spéciaux indiquant le type des valeurs à lire. Chaque code est précédé du symbole %. Il en existe une multitude, nous nous contenterons ici de ceux dont vous aurez
besoin :
- %d int entier 32 bits en décimal
- %lld long long int entier 64 bits
- %f float nombre réel simple précision
- %lf double nombre réel double précision
- %c char caractère unique
- %s char* chaîne de caractères
- 
```
$ man 3 scanf
```

### Annexe 4 : erreurs du débutant

Le bug du débutant n°1 : il ne faut pas mettre un; après un if car cela exécuterait une instruction
nulle si expression est vraie. Cela donne un comportement défectueux :

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
### Annexe 5 : opérations sur les nombres réels

La bibliothèque C standard contient une série de fonctions de calcul sur les flottants (racine carrée,
logarithme, sinus, etc.), que l’on peut utiliser en incluant le fichier math.h: fabs(), floor(), fmod(),
exp(), log(), log10(), sqrt(x), pow(), sin(x), cos(x), tan(), ...
Une des différences majeures entre le traitement des entiers et des flottants est la perte de précision.
Avec les entiers, les calculs sont toujours exacts, du moment que l’on ne dépasse pas la capacité des entiers.
Avec les flottants, chaque opération (addition, multiplication, etc.) induit une **perte de précision**.
Il existe deux types de flottants en C/C++: float et double. Les double (codés sur 8 octets) ont une
meilleur précision que les float(codés sur 4 octets). Il donc est conseillé de toujours utiliser des double
afin de garder la meilleure précision possible, le seul intérêt des float est qu’ils prennent deux fois moins
de place en mémoire.
Si vous calculez : 1e10 + 1e-10 = 1.00000000000000000001e10, l’ordinateur arrondira à 1.00000000000000e10
= 1e10 (15 chiffres pour un double). On a donc des cas où A + B = A même si B != 0. Il faut également
faire attention à l’ordre des calculs. Par exemple A + (B - C) peut être différent de (A + B) - C. Si A =
1e-10, B = 1e10, C = 1e10, on a A + (B - C) = A + 0 = 1e-10 mais (A + B) - C = B - C = 0.

À cause des pertes de précision, les flottants sont rarement exactement égaux à leur valeur approchée,
surtout si l’on utilise des fonctions comme la racine carrée, le sinus, ...
Prenons par exemple le code suivant :
```C
double x = 2.;

x = sqrt(x); // Racine carrée de x
x = x * x; // x^2
if (x == 2.)
    printf("OK\n");
```

On s’attend à voir ce programme écrire OK. Il n’en est rien! À cause des pertes de précision, x n’est
pas égal à 2 à la fin du programme, mais à un nombre presque égal à 2 et différent de 2, comme 2.0000000000000004.
On ne peut donc pas tester l’égalité entre deux nombres réels.
Pour déterminer si deux nombres réels sont égaux, il faut commencer par calculer la différence des
deux nombres. Si la différence est très proche de zéro, c’est-à-dire si la valeur absolue de la différence est
très petite, alors on considère que les nombres sont égaux.
Concrètement, pour comparer x et y, on commence par définir une constante très petite que l’on nomme traditionnellement epsilon , et on teste si |x - y| < epsilon. La fonction fabs() calcule la valeur
absolue.

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

