# Part 1: Premier programme, Hello world

## A - Hello world

Voici une version du premier programme que l’on étudie habituellement. Il affiche “Hello world !” à l’écran.

Dans tout ce document, si vous rencontrez la commande vi vous pourrez la remplacer par la commande nano. vi et nano sont des éditeurs de texte, nano est probablement plus simple à utiliser.

Créer un sous-répertoire code et créer le fichier hello.c
```bash
$ mkdir ~/code
$ cd ~/code
$ nano hello.c
```

Code source du fichier hello.c

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

### A1 - Explications

- Tout programme C doit posséder une (et une seule) **fonction** nommée main(dite fonction principale) pour indiquer où commencer l’exécution. 

- Une fonction est essentiellement une **suite d’instructions** que l’ordinateur exécutera dans l’ordre où elles sont écrites. Une fonction comprend quatre parties :
  - un **type de retour** : ici int(pour _integer_ ou entier) qui spécifie le type de résultat que la fonction retournera lors de son exécution. En C, le mot int est un mot réservé (un mot-clé) : il ne peut donc pas être utilisé pour nommer autre chose.
  - un **nom** : ici main, c’est le nom donné à la fonction (attention main est un mot-clé).
  - une **liste de paramètres (ou d’arguments)** entre parenthèses : ici la liste de paramètres est vide
  - un **corps de fonction** entre accolades {...} qui énumère les instructions que la fonction doit exécuter

- La plupart des instructions C se terminent par un point-virgule (;).

- En C/C++, les **chaînes de caractères** sont délimitées par des double quote (")."Hello world !\n" est donc une chaîne de caractères. 
- Le code \n est un “caractère spécial” indiquant le passage à une nouvelle ligne ( _newline_ ou LF ).
- En C, on utilise printf(et scanf) pour afficher sur le flux de sortie standard (et lire sur le flux d’entrée).
- Commentaire multi-lignes : Tout ce qui est placé entre /* et */ est considéré comme un commentaire. Le contenu du commentaire est ignoré par le compilateur (la machine). Ce commentaire rend le code plus lisible pour les programmeurs. On écrit des commentaires pour décrire ce que le programme est supposé faire et, d’une manière générale, pour fournir des informations utiles impossibles à exprimer directement dans le code.

```C
/*
Ce programme affiche le message "Hello world !" à l’écran
*/
```
- Commentaire sur une seule ligne: tout ce qui est entre // et la fin de la ligne est un commentaire

```C
printf("Hello world !\n"); // Affiche "Hello world !"
```

- La fonction main de ce programme retourne la valeur 0 (return 0;) à celui qui l’a appelée. Comme main() est appelée par le “système”, il recevra cette valeur. Sur certains systèmes (Unix/Linux), elle peut servir à vérifier si le programme s’est exécuté correctement. Un zéro ( 0 ) indique alors que le programme s’est terminé avec succès (c’est une convention UNIX). Évidemment, une valeur différente de 0 indiquera que le programme a rencontré une erreur et sa valeur précisera alors le type de l’erreur.

- En C, une ligne qui commence par un # fait référence à une **directive** du préprocesseur (ou de pré-compilation). Le préprocesseur ne traite pas des instructions C(donc pas de ";"). Ici, la directive #include <stdio.h> demande à l’ordinateur de rendre accessible (d’“inclure”) des fonctionnalités contenues dans un fichier nommé stdio.h. Ce fichier est fourni avec le compilateur. Un fichier inclus au moyen de #include porte l’extension.h . On l’appelle en-tête ( _header_ ) ou **fichier d’en-tête**.

## B - Compilation

C est un langage compilé. Cela signifie que, pour pouvoir exécuter un programme, vous devez d’abord traduire sa forme lisible par un être humain, le code source, en quelque chose qu’une machine peut “comprendre”, le code machine. Cette traduction est effectuée par un programme appelé **compilateur**.

Ce que le programmeur écrit est le code source (ou programme source) et ce que l’ordinateur exécute s’appelle exécutable, code objet ou code machine.

Vous allez constater que le compilateur est plutôt pointilleux sur la syntaxe! Comme tous les programmeurs, vous passerez beacoup de temps à chercher des erreurs dans du code source. Et la plupart de temps, le code contient des erreurs! Lorsque vous coderez, le compilateur risque parfois de vous agacer.
Toutefois, il a généralement raison car vous avez certainement écrit quelque chose qui n’est pas défini précisément par la norme C et qu’il empêche de produire du code objet.

- Le compilateur est dénué de bon sens et d’intelligence (il n’est pas humain) et il est donc très pointilleux. Prenez en compte les messages d’erreur et analysez les bien car souvenez-vous en bien le compilateur est “votre ami”, et peut-être le meilleur que vous ayez lorsque vous programmez.

## C - Édition des liens

Un programme contient généralement plusieurs parties distinctes, souvent développées par des personnes différentes. Par exemple, le programme “Hello world !” est constitué de la partie que nous avons écrite, plus d’autres qui proviennent de la bibliothèque standard de C(printf par exemple).
Ces parties distinctes doivent être liées ensemble pour former un programme exécutable. Le programme qui lie ces parties distinctes s’appelle un éditeur de liens ( linker ).

Notez que le code objet et les exécutables ne sont pas portables entre systèmes. Par exemple, si vous compilez pour une machine Windows, vous obtiendrez un code objet qui ne fonctionnera pas sur une machine Linux.

Une bibliothèque n’est rien d’autre que du code (qui ne contient pas de fonction main évidemment) auquel nous accédons au moyen de **déclarations** se trouvant dans un fichier d’en-tête. Une déclaration est une suite d’instruction qui indique comment une portion de code (qui se trouve dans une bibliothèque) peut être utilisée. Le débutant a tendance à confondre bibliothèques et fichiers d’en-tête.

Une **_bibliothèque dynamique_** est une bibliothèque qui contient du code qui sera intégré au moment de l’exécution du programme. Les avantages sont que le programme est de taille plus petite et qu’il sera à jour vis-à-vis de la mise à jour des bibliothèques. L’inconvénient est que l’exécution dépend de l’existence
de la bibliothèque sur le système cible. Une bibliothèque dynamique, Dynamic Link Library (.dll) pour Windows et shared object (.so) sous UNIX/Linux, est un fichier de bibliothèque logicielle utilisé par un programme exécutable, mais n’en faisant pas partie.

## D - Les erreurs 

Les erreurs détectées :
- par le compilateur sont des erreurs de compilation (souvent dues à des problèmes de déclaration)
- celles que trouvent l’éditeur de liens sont des erreurs de liaisons ou erreurs d’édition de liens (souvent
dues à des problèmes de définition)
- Et celles qui se produiront à l’exécution seront des erreurs d’exécutions ou de “logique” (communément appelées _bugs_ ).


## E - Étapes de fabrication

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


## F - Décomposition des étapes de fabrication avec gcc:

### F1 - Création des fichiers sources

```bash
$ cd ~/code
$ vi hello2.c
$ vi say_hello.c
$ vi say_hello.h
$ vi lang_hello.h
```

fichier principal:

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

définition de la fonction say_hello()

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

fichier d'entête 

```C
// say_hello.h

#ifndef SAY_HELLO_H
#define SAY_HELLO_H

void say_hello();

#endif
```

fichier de définition des traductions

```C
// lang_hello.h

// Version Francaise
#ifdef LANG_FR
#define MSG_HELLO "Bonjour monde!\n"
#endif

// Version internationale
#ifndef LANG_EN
#define MSG_HELLO "Hello world!\n"
#endif
```

### F2 - Compilation en une étape

```bash
$ gcc -o hello2 hello2.c say_hello.c
$ ./hello2
Bonjour monde !
```

### F3 - Pré-compilation :

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

### F4 - Compilation :

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

### F5 - Assemblage :

```
$ as -o hello2.o hello2.s
$ as -o say_hello.o say_hello.s
$ file hello2.o
hello2.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
$ file say_hello.o
say_hello.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
```

### F6 - Édition des liens :

```
$ gcc -o hello2 hello2.o say_hello.o
```

```
// un seul fichier :
$ gcc <fichier.o> -o <executable>
// ou plusieurs fichiers :
$ gcc <fichier1.o> <fichier2.o> <fichiern.o> -o <executable>
// ou avec bibliothèque(s) ici m pour math :
$ gcc -lm <fichier1.o> <fichier2.o> <fichiern.o> -o <executable>
```

### F7 - Execution :

```
$ ./hello2
Bonjour monde!
```

### F8 - En conservant les étapes intermédiaires:

Compilation en une seule étape en conservant les étapes intermédiaires:

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

### F9 - Build :

Pour un projet contenant plusieurs fichiers sources, nous utilisons l'outil GNU make pour produire l'exécutable à partir des fichiers sources.

```
$ make
$ make clean
```

## G - Conclusion

Qu’y a-t-il de si important à propos du programme “Hello world !”? Son objectif était de vous familiariser avec les outils de base utilisés en programmation.

Retenez cette règle : il faut toujours prendre un exemple extrêmement simple (comme “Hello world”) à chaque fois que l’on découvre un nouvel outil. Cela permet de diviser l’apprentissage en deux parties :
- on commence par apprendre le fonctionnement de base de nos outils avec un programme élémentaire 
- puis on peut passer à des programmes plus compliqués sans être distraits par ces outils. 

Découvrir les outils et le langage simultanément est beaucoup plus difficile que de le faire un après l’autre.

_Conclusion : cette approche consistant à simplifier l’apprentissage d’une tâche complexe en la décomposant en une suite d’étapes plus petites (et donc plus faicles à gérer) ne s’applique pas uniquement à la programmation et aux ordinateurs. Elle est courante et utile dans la plupart des domaines de l’existence, notamment dans ceux qui impliquent une compétence pratique._

```
Descartes (mathématicien, physicien et philosophe français) dans le Discours de la méthode :
« diviser chacune des difficultés que j’examinerais, en autant de parcelles qu’il se pourrait, et qu’il serait requis pour les mieux résoudre. »
« conduire par ordre mes pensées, en commençant par les objets les plus simples et les plus aisés à connaître, pour monter peu à peu comme par degrés jusques à la connaissance des plus composés ... »
```

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
