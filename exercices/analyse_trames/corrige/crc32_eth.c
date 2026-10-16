/*
 * Corrigé de l'exercice 2 : FCS Ethernet (CRC-32)
 *
 * Compilation : gcc -Wall -Wextra -O2 -o crc32_eth crc32_eth.c
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define POLYNOME_REFLECHI   0xEDB88320u
#define RESIDU_CORRECT      0x2144DF1Cu     /* CRC-32 d'une trame correcte, FCS compris */
#define TAILLE_FCS          4
#define TAILLE_MIN_SANS_FCS 60              /* 64 octets minimum, FCS compris */

/* Trame d'étude : Ethernet + IPv4 + TCP + "Hello world!\n" (sans FCS) */
static const uint8_t trame_etude[67] = {
    0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x00, 0x0C, 0x29, 0xAA, 0xBB, 0xCC, 0x08, 0x00, 0x45, 0x00,
    0x00, 0x35, 0x1C, 0x46, 0x40, 0x00, 0x40, 0x06, 0x9B, 0x0E, 0xC0, 0xA8, 0x01, 0x0A, 0xC0, 0xA8,
    0x01, 0x14, 0xC3, 0x50, 0x00, 0x50, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x50, 0x18,
    0x10, 0x00, 0xAC, 0xC0, 0x00, 0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20, 0x77, 0x6F, 0x72, 0x6C,
    0x64, 0x21, 0x0A
};

/*
 * Question 1 : division CRC « à la main », bit par bit, sur des chaînes de '0' et '1'.
 * message   : bits du message, ex. "110101"
 * polynome  : bits du polynôme générateur, ex. "1011"
 * reste     : tampon recevant le reste (taille du polynôme - 1 bits + '\0')
 */
void division_crc(const char *message, const char *polynome, char *reste)
{
    char bits[64];
    size_t lg_msg = strlen(message);
    size_t lg_poly = strlen(polynome);
    size_t lg_crc = lg_poly - 1;

    /* message suivi de lg_crc zéros */
    strcpy(bits, message);
    memset(&bits[lg_msg], '0', lg_crc);
    bits[lg_msg + lg_crc] = '\0';

    /* XOR du polynôme sous chaque bit à 1 du message */
    for (size_t i = 0; i < lg_msg; i++) {
        if (bits[i] == '1') {
            for (size_t j = 0; j < lg_poly; j++) {
                bits[i + j] = (bits[i + j] == polynome[j]) ? '0' : '1';
            }
        }
    }

    strcpy(reste, &bits[lg_msg]);
}

/*
 * Question 2 : CRC-32 Ethernet, version bit à bit.
 * donnees : octets à protéger
 * taille  : nombre d'octets
 * retour  : le CRC-32
 */
uint32_t calcul_crc32(const uint8_t *donnees, size_t taille)
{
    uint32_t crc = 0xFFFFFFFFu;

    for (size_t i = 0; i < taille; i++) {
        crc ^= donnees[i];
        for (int bit = 0; bit < 8; bit++) {
            if (crc & 1) {
                crc = (crc >> 1) ^ POLYNOME_REFLECHI;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc ^ 0xFFFFFFFFu;
}

/*
 * Question 4 : ajoute le FCS en fin de trame, octet de poids faible en premier.
 * trame           : tampon d'au moins taille_sans_fcs + 4 octets
 * taille_sans_fcs : taille de la trame avant ajout du FCS
 */
void ajouter_fcs(uint8_t *trame, size_t taille_sans_fcs)
{
    uint32_t fcs = calcul_crc32(trame, taille_sans_fcs);

    for (int i = 0; i < TAILLE_FCS; i++) {
        trame[taille_sans_fcs + i] = (uint8_t)(fcs >> (8 * i));
    }
}

/*
 * Question 5 : vérifie le FCS d'une trame.
 * trame  : trame complète, FCS compris
 * taille : taille de la trame, FCS compris
 * retour : 1 si le FCS est correct, 0 sinon
 */
int verifier_fcs(const uint8_t *trame, size_t taille)
{
    if (taille < TAILLE_FCS) {
        return 0;
    }

    size_t lg = taille - TAILLE_FCS;
    uint32_t recu = (uint32_t)trame[lg]
                  | (uint32_t)trame[lg + 1] << 8
                  | (uint32_t)trame[lg + 2] << 16
                  | (uint32_t)trame[lg + 3] << 24;

    return calcul_crc32(trame, lg) == recu;
}

/*
 * Variante : vérification par le résidu, sans extraire le FCS.
 */
int verifier_fcs_residu(const uint8_t *trame, size_t taille)
{
    return calcul_crc32(trame, taille) == RESIDU_CORRECT;
}

/*
 * Pour aller plus loin : version par table.
 * table[n] contient l'effet des 8 décalages sur l'octet n.
 */
static uint32_t table_crc[256];

void initialiser_table_crc32(void)
{
    for (uint32_t n = 0; n < 256; n++) {
        uint32_t crc = n;
        for (int bit = 0; bit < 8; bit++) {
            crc = (crc & 1) ? (crc >> 1) ^ POLYNOME_REFLECHI : crc >> 1;
        }
        table_crc[n] = crc;
    }
}

uint32_t calcul_crc32_table(const uint8_t *donnees, size_t taille)
{
    uint32_t crc = 0xFFFFFFFFu;

    for (size_t i = 0; i < taille; i++) {
        crc = (crc >> 8) ^ table_crc[(crc ^ donnees[i]) & 0xFF];
    }
    return crc ^ 0xFFFFFFFFu;
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

static void afficher_verification(const char *titre, const uint8_t *trame, size_t taille)
{
    printf("%s : %s\n", titre, verifier_fcs(trame, taille) ? "trame valide" : "trame INVALIDE");
}

int main(void)
{
    char reste[8];
    uint8_t trame[sizeof trame_etude + TAILLE_FCS];
    const size_t taille = sizeof trame_etude;
    const size_t taille_fcs = taille + TAILLE_FCS;

    /* Question 1 : divisions à la main */
    printf("=== Division CRC à la main (polynôme 1011) ===\n");
    division_crc("110101", "1011", reste);
    printf("CRC(110101) = %s (attendu 111)\n", reste);
    division_crc("100100", "1011", reste);
    printf("CRC(100100) = %s (attendu 101)\n", reste);
    division_crc("100100101", "1011", reste);
    printf("Reste de 100100 101 = %s (attendu 000)\n\n", reste);

    /* Question 3 : jeux de test */
    printf("=== Jeux de test ===\n");
    printf("CRC-32(\"123456789\") = 0x%08X (attendu 0xCBF43926)\n",
           calcul_crc32((const uint8_t *)"123456789", 9));
    printf("CRC-32(trame)       = 0x%08X (attendu 0xDB88FFBF)\n\n",
           calcul_crc32(trame_etude, taille));

    /* Question 4 : ajout du FCS */
    memcpy(trame, trame_etude, taille);
    ajouter_fcs(trame, taille);
    printf("=== Trame avec FCS (%zu octets) ===\n", taille_fcs);
    afficher_hexa(trame, taille_fcs);
    printf("FCS sur le câble : %02X %02X %02X %02X (attendu BF FF 88 DB)\n\n",
           trame[taille], trame[taille + 1], trame[taille + 2], trame[taille + 3]);

    /* Question 5 : vérification */
    printf("=== Vérifications ===\n");
    afficher_verification("Trame d'origine", trame, taille_fcs);
    printf("CRC-32 de la trame FCS compris : 0x%08X (attendu 0x2144DF1C)\n",
           calcul_crc32(trame, taille_fcs));

    /* Question 6 : erreurs simulées */
    memcpy(trame, trame_etude, taille);
    ajouter_fcs(trame, taille);
    trame[56] ^= 0x01;
    afficher_verification("Un bit des données inversé", trame, taille_fcs);

    memcpy(trame, trame_etude, taille);
    ajouter_fcs(trame, taille);
    trame[18] = trame_etude[20];        /* Identification <-> Flags/Fragment */
    trame[19] = trame_etude[21];
    trame[20] = trame_etude[18];
    trame[21] = trame_etude[19];
    afficher_verification("Deux mots de l'en-tête IP permutés", trame, taille_fcs);
    printf("  -> le checksum IP ne voit pas la permutation, le CRC-32 la détecte\n\n");

    /* Question 7 : trame ARP trop courte, complétée par du bourrage */
    uint8_t arp[TAILLE_MIN_SANS_FCS + TAILLE_FCS] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,     /* MAC destination : diffusion */
        0x00, 0x0C, 0x29, 0xAA, 0xBB, 0xCC,     /* MAC source */
        0x08, 0x06,                             /* EtherType : ARP */
        0x00, 0x01, 0x08, 0x00, 0x06, 0x04,     /* Ethernet / IPv4, tailles 6 et 4 */
        0x00, 0x01,                             /* requête */
        0x00, 0x0C, 0x29, 0xAA, 0xBB, 0xCC,     /* MAC émetteur */
        0xC0, 0xA8, 0x01, 0x0A,                 /* IP émetteur : 192.168.1.10 */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,     /* MAC cible : inconnue */
        0xC0, 0xA8, 0x01, 0x14                  /* IP cible : 192.168.1.20 */
    };                                          /* octets 42 à 59 : bourrage à 0 */
    ajouter_fcs(arp, TAILLE_MIN_SANS_FCS);
    printf("=== Trame ARP : 42 octets + 18 de bourrage + FCS ===\n");
    afficher_hexa(arp, sizeof arp);
    afficher_verification("Trame ARP", arp, sizeof arp);
    printf("\n");

    /* Pour aller plus loin : comparaison bit à bit / table */
    static uint8_t gros_tampon[10 * 1024 * 1024];
    for (size_t i = 0; i < sizeof gros_tampon; i++) {
        gros_tampon[i] = (uint8_t)(i * 31 + 7);
    }
    initialiser_table_crc32();

    clock_t debut = clock();
    uint32_t crc_bit = calcul_crc32(gros_tampon, sizeof gros_tampon);
    double duree_bit = (double)(clock() - debut) / CLOCKS_PER_SEC;

    debut = clock();
    uint32_t crc_table = calcul_crc32_table(gros_tampon, sizeof gros_tampon);
    double duree_table = (double)(clock() - debut) / CLOCKS_PER_SEC;

    printf("=== Comparaison sur 10 Mio ===\n");
    printf("bit à bit : 0x%08X en %.3f s\n", crc_bit, duree_bit);
    printf("par table : 0x%08X en %.3f s\n", crc_table, duree_table);
    printf("résultats %s\n", crc_bit == crc_table ? "identiques" : "DIFFÉRENTS");

    return 0;
}
