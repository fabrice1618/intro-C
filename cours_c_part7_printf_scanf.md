# Part 7: printf() et scanf()

Il exste trois flux de base pour chaque programme :
- stdin(0) : Entrée standard (par défaut le clavier)
- stdout(1) : Sortie standard (par défaut l’écran)
- stderr(2) : Sortie erreur (par défaut l’écran également)
- En C, un flux est un canal destiné à transmettre ou à recevoir de l’information. Il peut s’agir de fichier ou de périphériques.

## A - printf()

Pour afficher des résultats à l’écran, il faudra écrire sur le flux stdout. Pour cela, on utilise généralement la fonction printf() (déclarée dans stdio.h):

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

Si on ne désire pas l’affichage des messages d’erreur d’un programme, il suffit de rediriger son flux stderr vers le périphérique null. 

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


Format | Type | Description
---------|----------|---------
 %d | int | entier 32 bits en décimal
 %u | unsigned int | entier 32 bits non signé en décimal
 %x | int | entier 32 bits en hexadécimal (en minuscules et %X en majuscules)
 %lld | long long int | entier 64 bits
 %f | float ou double | avec par défaut 6 chiffres après la virgule
 %g | float ou double | en utilisant la notation 1.234e5 quand cela est approprié
 %c | char | caractère unique
 %s | char* | chaîne de caractères
 %p | void* | l’adresse mémoire en hexadécimal

```
$ man 3 printf
```

## B- scanf()

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
- La lecture des chaînes de caractère (avec scanf() en C/C++) se termine sur ce qu’on appelle un espace blanc (whitespace), c’est-à-dire le caractère espace, une tabulation ou un caractère de retour à la ligne (généralement la touche Enter ). Notez que les espaces sont ignorés par défaut. Sous Linux, vous pouvez indiquer la fin d’un flux (EOF) en combinant les touches Ctrl + d qui indiquera qu’il n’y a plus de saisie. Vous pouvez aussi stopper le programme avec Ctrl + z ou l’interrompre avec Ctrl + c.

La chaîne de format se compose de codes spéciaux indiquant le type des valeurs à lire. Chaque code est précédé du symbole %. Il en existe une multitude, nous nous contenterons ici de ceux dont vous aurez besoin :


Format | Type | Description
---------|----------|---------
 %d | int | entier 32 bits en décimal
 %lld | long long int | entier 64 bits
 %f | float ou double | avec par défaut 6 chiffres après la virgule
 %lf | double | nombre réel double précision
 %c | char | caractère unique
 %s | char* | chaîne de caractères
 %p | void* | l’adresse mémoire en hexadécimal


```
$ man 3 scanf
```
