# Exercice en C BSQ

## Sujet

```
Nom du programme: bsq
Dossier de rendu : ex00 /
Fichiers de rendu Makefile et tous les fichiers necessaires
Makefile Yes
Arguments Fichier(s) dans le(s)quel(s) lire le carré
Fonctions externes autorisées: open, close, read, write, malloc, free, exit
Libft autorisée Ne concerne pas ce projet
Description Écrivez un programme qui dessine et affiche à l’écran le plus grand carré possible dans la zone donnée
```
- Il s’agit de trouver le plus grand carré possible sur un plateau en évitant des obstacles.
- Un plateau vous est transmis dans un fichier passé en argument du programme.
- La première ligne du plateau contient les informations pour lire la carte :
    - Le nombre de lignes du plateau ;
    - Le caractère "vide" ;
    - Le caractère "obstacle" ;
    - Le caractère "plein".
- Le plateau est composé de lignes de ’caractères "vide"’ et de ’caractères "obstacle"’.
- Le but du programme est de remplacer les’caractères "vide"’ par des ’caractères "plein"’pour représenter le plus grand carré possible.
- Dans le cas où plusieurs solutions existent, on choisira de représenter le carré le plus en haut puis le plus à gauche.
- Votre programme doit accepter de 1 à n paramètres.
- Lorsque votre programme recoit plusieurs paramètres en argument, chaque solution ou map error doit être suivi d’un line break.
- Si il n’y a aucun argument, votre fonction doit lire le carré sur l’entrée standard.
- Vous devez rendre un Makefile qui compile votre projet. Votre Makefile ne doit pas relink.
- Définition d’une carte valide :
    - Toutes les lignes doivent avoir la même longueur.
    - Il y a au moins une ligne d’au moins une case.
    - À la fin de chaque ligne, il y a un retour à la ligne.
    - Les caractères présent dans la carte doivent être uniquement ceux présenté à la première ligne.
    - La carte est invalide si un caractère manque sur la première ligne, ou si deux caractères (parmis vide, plein, et obstacles) sont identiques.
    - Les caractères peuvent être n’importe quel caractère imprimable, même des nombres.
    - En cas de carte invalide, vous afficherez sur la sortie d’erreur :map error suivi d’un retour à la ligne. Le programme passera ensuite au traitement du plateau suivant.

- Exemple de fonctionnement :

```
%>cat example_file
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
%>./bsq example_file
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
%>
```

C’est bien un carré. Même si cela n’y ressemble pas visuellement.


## Annexe

- Générateur de plateaux perl

```
#!/usr/bin/perl

use warnings;
use strict;

die "program x y density" unless (scalar(@ARGV) == 3);

my ($x, $y, $density) = @ARGV;

print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print "o";
        }
        else {
            print ".";
        }
    }
    print "\n";
}
```

