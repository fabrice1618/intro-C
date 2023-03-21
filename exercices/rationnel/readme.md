# Les nombres rationnels

## Introduction

Nous travaillons ici sur les nombres rationnels. Un nombre rationnel sera représenté par une structure Rationnel à deux champs : un champ num représentant le numérateur et un champ den représentant le dénominateur d’une fraction. 

Définition de la structure utilisée:
```C
typedef struct rationnel_t
{
    int num;        // Numérateur
    int den;        // Dénominateur
} Rationnel;
```

Vous disposez d'une base de programme (incomplète) qui lance automatiquement des tests qui permettront de vérifier le fonctionnement des fonctions que vous aurez écrites. Les tests sont organisés en 2 niveaux. Chaque niveau teste chacune des opérations addition, soustraction, multiplication et division. Le programme indique si chaque test est réussi ou échoué. Un niveau est réussi si les 4 tests du niveau sont réussis. Vous ne pouvez tenter le 2ème niveau que si vous avez réussi le premier niveau.

Votre objectif est d'écrire les fonctions permettant de réaliser les opérations addition, soustraction, multiplication et division sur des nombres rationnels.

Le fichier dont vous disposez est rationnel.c. Vous ne pouvez pas modifier le début du fichier  (avant la ligne 146). Tel quel, le programme ne peut pas faire l'édition de lien car il manque les 4 fonctions réalisant les 4 opérations.

Le prototype des fonctions est imposé:

```C
Rationnel addition_rationnelle(Rationnel r1, Rationnel r2);
Rationnel soustraction_rationnelle(Rationnel r1, Rationnel r2);
Rationnel multiplication_rationnelle(Rationnel r1, Rationnel r2);
Rationnel division_rationnelle(Rationnel r1, Rationnel r2);
```

Le fichier rendu devra être nommé sous la forme: rationnel_prenom_nom.c

## Critères de notation

Les coefficients sont donnés à titre indicatif et peuvent évoluer.

Critère | Coefficient 
---------|----------
 nommage du fichier | 1 
 Le programme compile | 2 
 Qualité algorithme | 2 
 Tests niveau 1 | 2 
 Tests niveau 2 | 2 
 Nommage variables | 1 
 Commentaires | 1 
