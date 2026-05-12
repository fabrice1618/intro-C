# TP : Exploitation de données météorologiques en C et MySQL

## Contexte

On dispose d’un fichier binaire contenant des mesures météorologiques enregistrées toutes les 10 minutes sur une journée complète (24 heures).

Le fichier contient donc **144 enregistrements**.

---

## Format du fichier binaire

Chaque enregistrement est structuré comme suit :

| Champ        | Type C    | Taille | Description                          |
|--------------|----------|--------|--------------------------------------|
| timestamp    | int32_t  | 4 octets | Temps UNIX (secondes depuis 1970)    |
| temperature  | float    | 4 octets | Température en degrés Celsius        |
| humidite     | float    | 4 octets | Humidité relative en %               |
| pression     | float    | 4 octets | Pression atmosphérique en hPa        |

Taille totale d’un enregistrement : **16 octets (144 × 16 = 2304 octets)**

Ordre des champs dans le fichier :  
timestamp → température → humidité → pression

---

## Partie 1 — Analyse du fichier (4 points)

1.1 Calculer la taille totale théorique du fichier.  
1.2 Vérifier que cette taille correspond à un nombre entier d’enregistrements.  
1.3 Expliquer pourquoi il est important de connaître précisément la taille d’un enregistrement.
1.4 Utiliser od, expliquer pourquoi cat ne fonctionne pas

---

## Partie 2 — Définition des structures (3 points)

2.1 Définir en C une structure représentant un enregistrement.  
2.2 Justifier le choix des types utilisés.  

---

## Partie 3 — Lecture du fichier binaire (5 points)

3.1 Ouvrir le fichier en mode binaire.  
3.2 Lire les enregistrements un par un.  
3.3 Stocker les données dans une structure.  
3.4 Afficher chaque enregistrement sous forme lisible.  
3.5 Gérer les erreurs d’ouverture et de lecture.

---

## Partie 4 — Exploitation des données (4 points)

4.1 Convertir le timestamp en date lisible.  
4.2 Calculer :
- la température moyenne,
- la température minimale,
- la température maximale.

4.3 Identifier l’heure correspondant à la température maximale.

---

## Partie 5 — Conception de la base de données (4 points)

5.1 Proposer un schéma relationnel pour stocker les données. MCD - diagramme de classe 

5.2 Écrire la requête SQL de création de la table.  
5.3 Justifier les types SQL choisis.

---

## Partie 6 — Installation de la bibliothèque MySQL (2 points)

6.1 Installer la bibliothèque cliente MySQL pour le langage C :

Sous Linux (Debian/Ubuntu) :
```
sudo apt update
sudo apt install libmysqlclient-dev
```

6.2 Vérifier la présence des fichiers d’en-tête (mysql.h).  
6.3 Expliquer le rôle de cette bibliothèque.

---

## Partie 7 — Connexion à MySQL en C (4 points)

7.1 Initialiser une connexion MySQL.  
7.2 Se connecter à une base de données.  
7.3 Gérer les erreurs de connexion.  
7.4 Fermer correctement la connexion.

---

## Partie 8 — Insertion des données (6 points)

8.1 Parcourir les enregistrements lus depuis le fichier.  
8.2 Insérer chaque enregistrement dans la base de données.  
8.3 Vérifier la réussite des insertions.  
8.4 Gérer les erreurs SQL.

---

## Partie 9 — Lecture depuis la base (4 points)

9.1 Écrire une requête SELECT pour récupérer toutes les données.  
9.2 Parcourir les résultats en C.  
9.3 Afficher les données récupérées.  

---

## Partie 10 — Requêtes avancées (4 points)

10.1 Écrire une requête permettant de récupérer les mesures entre deux timestamps.  
10.2 Trier les résultats par température décroissante.  
10.3 Limiter le nombre de résultats affichés.

---

## Contraintes

- Langage C obligatoire  
- Utilisation de la bibliothèque MySQL (libmysqlclient)  
- Gestion des erreurs obligatoire  
- Code structuré et commenté  

---

## Livrables

- Code source C  
- Script SQL  
- Captures d’exécution  
- Réponses aux questions  

---

## Barème indicatif

| Partie | Points |
|--------|--------|
| 1      | 4      |
| 2      | 3      |
| 3      | 5      |
| 4      | 4      |
| 5      | 4      |
| 6      | 2      |
| 7      | 4      |
| 8      | 6      |
| 9      | 4      |
| 10     | 4      |
| **Total** | **40** |
```
