/*
 * Corrigé de l'exercice 1 : checksum IPv4 et TCP
 *
 * Compilation : gcc -Wall -Wextra -o checksum_ip checksum_ip.c
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Offsets des en-têtes dans la trame */
#define OFFSET_IP       14      /* début de l'en-tête IP (après Ethernet) */
#define TAILLE_ETH      14
#define TAILLE_PSEUDO   12      /* taille du pseudo-en-tête TCP */
#define TAILLE_MAX      1600    /* taille du tampon de calcul TCP */

/* Trame d'étude : Ethernet + IPv4 + TCP + "Hello world!\n" (sans FCS) */
static const uint8_t trame_etude[67] = {
    0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x00, 0x0C, 0x29, 0xAA, 0xBB, 0xCC, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x35, 0x1C, 0x46, 0x40, 0x00, 0x40, 0x06, 0x9B, 0x0E, 0xC0, 0xA8, 0x01, 0x0A, 0xC0, 0xA8,
    0x01, 0x14, 0xC3, 0x50, 0x00, 0x50, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x50, 0x18,
    0x10, 0x00, 0xAC, 0xC0, 0x00, 0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C,
    0x64, 0x21, 0x0A
};

/*
 * Lit une valeur de 16 bits en big-endian (ordre réseau).
 * octets : pointeur sur l'octet de poids fort
 * retour : la valeur sur 16 bits
 */
static uint16_t lire_u16(const uint8_t *octets)
{
    return (uint16_t)((octets[0] << 8) | octets[1]);
}

/*
 * Écrit une valeur de 16 bits en big-endian (ordre réseau).
 * octets : destination (2 octets)
 * valeur : valeur à écrire
 */
static void ecrire_u16(uint8_t *octets, uint16_t valeur)
{
    octets[0] = (uint8_t)(valeur >> 8);
    octets[1] = (uint8_t)(valeur & 0xFF);
}

/*
 * Question 1 : checksum Internet (RFC 1071).
 * donnees : zone à protéger
 * taille  : nombre d'octets (pair ou impair)
 * retour  : complément à 1 de la somme en complément à 1 des mots de 16 bits
 */
uint16_t checksum_internet(const uint8_t *donnees, size_t taille)
{
    uint32_t somme = 0;     /* 32 bits pour ne pas perdre les retenues */
    size_t i = 0;

    /* Addition des mots de 16 bits */
    while (i + 1 < taille) {
        somme += lire_u16(&donnees[i]);
        i += 2;
    }

    /* Taille impaire : le dernier octet est complété par un 0x00 */
    if (i < taille) {
        somme += (uint32_t)donnees[i] << 8;
    }

    /* Repli des retenues */
    while (somme > 0xFFFF) {
        somme = (somme & 0xFFFF) + (somme >> 16);
    }

    return (uint16_t)(~somme & 0xFFFF);
}

/*
 * Retourne la longueur de l'en-tête IP en octets (champ IHL x 4).
 */
static size_t longueur_entete_ip(const uint8_t *trame)
{
    return (size_t)(trame[OFFSET_IP] & 0x0F) * 4;
}

/*
 * Question 2 : vérifie le checksum de l'en-tête IPv4.
 * trame  : trame Ethernet complète (sans FCS)
 * taille : taille de la trame en octets
 * retour : 1 si l'en-tête IP est valide, 0 sinon
 */
int verifier_checksum_ip(const uint8_t *trame, size_t taille)
{
    if (taille < TAILLE_ETH + 20) {
        return 0;
    }
    if (lire_u16(&trame[12]) != 0x0800) {      /* EtherType IPv4 ? */
        return 0;
    }
    if ((trame[OFFSET_IP] >> 4) != 4) {         /* version 4 ? */
        return 0;
    }

    size_t lg_ip = longueur_entete_ip(trame);
    if (lg_ip < 20 || TAILLE_ETH + lg_ip > taille) {
        return 0;
    }

    /* Somme calculée checksum compris : doit donner 0x0000 */
    return checksum_internet(&trame[OFFSET_IP], lg_ip) == 0x0000;
}

/*
 * Question 4 : calcule le checksum TCP (pseudo-en-tête + en-tête TCP + données).
 * Le champ checksum de la trame est ignoré (considéré à 0x0000).
 * trame  : trame Ethernet complète (sans FCS)
 * taille : taille de la trame en octets
 * retour : le checksum TCP à placer dans l'en-tête
 */
uint16_t checksum_tcp(const uint8_t *trame, size_t taille)
{
    uint8_t tampon[TAILLE_MAX];
    size_t lg_ip = longueur_entete_ip(trame);
    size_t lg_totale_ip = lire_u16(&trame[OFFSET_IP + 2]);
    size_t lg_tcp = lg_totale_ip - lg_ip;           /* en-tête TCP + données */
    size_t offset_tcp = OFFSET_IP + lg_ip;

    if (offset_tcp + lg_tcp > taille || TAILLE_PSEUDO + lg_tcp > TAILLE_MAX) {
        return 0;
    }

    /* Pseudo-en-tête : IP source, IP destination, zéro, protocole, longueur TCP */
    memcpy(&tampon[0], &trame[OFFSET_IP + 12], 4);
    memcpy(&tampon[4], &trame[OFFSET_IP + 16], 4);
    tampon[8] = 0x00;
    tampon[9] = trame[OFFSET_IP + 9];
    ecrire_u16(&tampon[10], (uint16_t)lg_tcp);

    /* Segment TCP, avec le champ checksum (offset 16 du segment) à zéro */
    memcpy(&tampon[TAILLE_PSEUDO], &trame[offset_tcp], lg_tcp);
    ecrire_u16(&tampon[TAILLE_PSEUDO + 16], 0x0000);

    return checksum_internet(tampon, TAILLE_PSEUDO + lg_tcp);
}

/*
 * Vérifie le checksum TCP de la trame.
 * retour : 1 si le checksum calculé est égal au checksum reçu, 0 sinon
 */
int verifier_checksum_tcp(const uint8_t *trame, size_t taille)
{
    size_t offset_tcp = OFFSET_IP + longueur_entete_ip(trame);

    return checksum_tcp(trame, taille) == lire_u16(&trame[offset_tcp + 16]);
}

/*
 * Pour aller plus loin : forge l'en-tête IP en recalculant son checksum.
 * trame : trame Ethernet complète, modifiée sur place
 */
void forger_checksum_ip(uint8_t *trame)
{
    size_t lg_ip = longueur_entete_ip(trame);

    ecrire_u16(&trame[OFFSET_IP + 10], 0x0000);
    ecrire_u16(&trame[OFFSET_IP + 10], checksum_internet(&trame[OFFSET_IP], lg_ip));
}

/*
 * Affiche une trame en hexadécimal, 16 octets par ligne.
 */
static void afficher_hexa(const uint8_t *trame, size_t taille)
{
    for (size_t i = 0; i < taille; i++) {
        printf("%02X%c", trame[i], (i % 16 == 15 || i == taille - 1) ? '\n' : ' ');
    }
}

/*
 * Question 3 : affiche les principaux champs de la trame.
 */
static void afficher_champs(const uint8_t *trame)
{
    const uint8_t *ip = &trame[OFFSET_IP];
    const uint8_t *tcp = &ip[longueur_entete_ip(trame)];
    uint8_t flags = tcp[13];

    printf("MAC destination : %02X:%02X:%02X:%02X:%02X:%02X\n",
           trame[0], trame[1], trame[2], trame[3], trame[4], trame[5]);
    printf("MAC source      : %02X:%02X:%02X:%02X:%02X:%02X\n",
           trame[6], trame[7], trame[8], trame[9], trame[10], trame[11]);
    printf("EtherType       : 0x%04X\n", lire_u16(&trame[12]));
    printf("IP source       : %u.%u.%u.%u\n", ip[12], ip[13], ip[14], ip[15]);
    printf("IP destination  : %u.%u.%u.%u\n", ip[16], ip[17], ip[18], ip[19]);
    printf("TTL             : %u\n", ip[8]);
    printf("Protocole       : %u\n", ip[9]);
    printf("Port source     : %u\n", lire_u16(&tcp[0]));
    printf("Port destination: %u\n", lire_u16(&tcp[2]));
    printf("Flags TCP       :%s%s%s%s%s%s\n",
           (flags & 0x20) ? " URG" : "", (flags & 0x10) ? " ACK" : "",
           (flags & 0x08) ? " PSH" : "", (flags & 0x04) ? " RST" : "",
           (flags & 0x02) ? " SYN" : "", (flags & 0x01) ? " FIN" : "");
}

/*
 * Affiche le résultat des deux vérifications pour une trame.
 */
static void afficher_verifications(const uint8_t *trame, size_t taille)
{
    printf("  checksum IP  : %s\n",
           verifier_checksum_ip(trame, taille) ? "correct" : "INCORRECT");
    printf("  checksum TCP : %s\n",
           verifier_checksum_tcp(trame, taille) ? "correct" : "INCORRECT");
}

int main(void)
{
    uint8_t trame[sizeof trame_etude];
    const size_t taille = sizeof trame_etude;

    /* Question 1 : mini-exemple du cours */
    const uint8_t mini[] = { 0xF0, 0x00, 0x20, 0x01 };
    printf("=== Mini-exemple F0 00 20 01 ===\n");
    printf("checksum = 0x%04X (attendu 0xEFFD)\n\n", checksum_internet(mini, sizeof mini));

    /* Question 3 : décodage de la trame */
    printf("=== Trame d'étude (%zu octets) ===\n", taille);
    afficher_hexa(trame_etude, taille);
    printf("\n");
    afficher_champs(trame_etude);

    /* Checksum IP recalculé avec le champ à zéro */
    memcpy(trame, trame_etude, taille);
    ecrire_u16(&trame[OFFSET_IP + 10], 0x0000);
    printf("\nchecksum IP calculé  = 0x%04X (attendu 0x9B0E)\n",
           checksum_internet(&trame[OFFSET_IP], longueur_entete_ip(trame)));

    /* Question 4 : checksum TCP */
    printf("checksum TCP calculé = 0x%04X (attendu 0xACC0)\n\n",
           checksum_tcp(trame_etude, taille));

    printf("Trame d'origine :\n");
    afficher_verifications(trame_etude, taille);

    /* Question 5 : erreurs de transmission simulées */
    memcpy(trame, trame_etude, taille);
    trame[29] ^= 0x01;
    printf("\nErreur 1 : un bit de l'IP source inversé (trame[29] ^= 0x01) :\n");
    afficher_verifications(trame, taille);
    printf("  -> l'adresse IP est dans l'en-tête IP ET dans le pseudo-en-tête TCP\n");

    memcpy(trame, trame_etude, taille);
    trame[56] = 'X';
    printf("\nErreur 2 : un octet des données modifié (trame[56] = 'X') :\n");
    afficher_verifications(trame, taille);
    printf("  -> le checksum IP ne protège pas les données\n");

    /* Pour aller plus loin : passage dans un routeur (TTL - 1) */
    memcpy(trame, trame_etude, taille);
    trame[OFFSET_IP + 8]--;
    forger_checksum_ip(trame);
    printf("\nTTL passé à %u : nouveau checksum IP = 0x%04X (attendu 0x9C0E)\n",
           trame[OFFSET_IP + 8], lire_u16(&trame[OFFSET_IP + 10]));
    afficher_verifications(trame, taille);

    /* Pour aller plus loin : permutation de deux mots non détectée */
    memcpy(trame, trame_etude, taille);
    trame[OFFSET_IP + 4] = trame_etude[OFFSET_IP + 6];  /* Identification */
    trame[OFFSET_IP + 5] = trame_etude[OFFSET_IP + 7];  /* <-> Flags/Fragment */
    trame[OFFSET_IP + 6] = trame_etude[OFFSET_IP + 4];
    trame[OFFSET_IP + 7] = trame_etude[OFFSET_IP + 5];
    printf("\nErreur 3 : mots Identification et Flags/Fragment permutés :\n");
    afficher_verifications(trame, taille);
    printf("  -> l'addition est commutative : la permutation passe inaperçue\n");

    return 0;
}
