#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define HOTE  "127.0.0.1"
#define PORT  1618
#define NB_MESURES 20

/*
 * Une mesure = 3 floats : temperature (t), humidite (h), pression (p).
 * La validite n'est pas stockee : elle est calculee par valide() a partir
 * des plages physiques ci-dessous. Seuls les 3 floats sont envoyes au loader.
 *
 * Plages physiques considerees comme correctes :
 *   t : -50 a 60   (degres Celsius)
 *   h :   0 a 100  (pourcentage)
 *   p : 950 a 1050 (hPa)
 *
 * Jeu de test : 20 mesures, dont 10 erronees (50 %).
 * Les 2 premieres sont correctes, puis les erreurs sont reparties.
 */
struct mesure {
    float t;
    float h;
    float p;
};

/* Renvoie 1 si la mesure est dans les plages physiques, 0 sinon. */
static int valide(const struct mesure *m)
{
    return m->t >= -50.0f && m->t <= 60.0f
        && m->h >=   0.0f && m->h <= 100.0f
        && m->p >= 950.0f && m->p <= 1050.0f;
}

static struct mesure jeu[NB_MESURES] = {
    { 21.5f,  55.0f, 1013.2f },  /*  0 correcte */
    { 22.0f,  56.5f, 1012.8f },  /*  1 correcte */
    { 150.0f, 50.0f, 1013.0f },  /*  2 erreur : t > 60       */
    { 20.0f,  54.0f, 1011.5f },  /*  3 correcte */
    { 19.5f, 120.0f, 1010.0f },  /*  4 erreur : h > 100      */
    { 18.0f,  60.0f, 1009.0f },  /*  5 correcte */
    {-80.0f,  45.0f, 1013.0f },  /*  6 erreur : t < -50      */
    { 23.0f,  48.0f, 1014.0f },  /*  7 correcte */
    { 25.0f,  50.0f, 1500.0f },  /*  8 erreur : p > 1050     */
    { 24.0f,  52.0f, 1013.0f },  /*  9 correcte */
    { 22.0f, -10.0f, 1012.0f },  /* 10 erreur : h < 0        */
    { 21.0f,  58.0f, 1011.0f },  /* 11 correcte */
    { 30.0f,  70.0f,  500.0f },  /* 12 erreur : p < 950      */
    { 26.0f,  65.0f, 1010.0f },  /* 13 correcte */
    {200.0f, 200.0f,  200.0f },  /* 14 erreur : tout hors plage */
    { 27.0f,  62.0f, 1009.5f },  /* 15 correcte */
    { 28.0f, 110.0f, 1008.0f },  /* 16 erreur : h > 100      */
    { 29.0f,  59.0f, 1007.0f },  /* 17 correcte */
    {-100.0f, 50.0f, 2000.0f },  /* 18 erreur : t < -50 et p > 1050 */
    { 45.0f, 105.0f,  940.0f },  /* 19 erreur : h > 100 et p < 950  */
};

/* Envoie une mesure (3 floats) au loader via une nouvelle connexion TCP. */
static int envoyer(const struct mesure *m)
{
    int sock;
    struct sockaddr_in serveur;
    float trame[3];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    memset(&serveur, 0, sizeof(serveur));
    serveur.sin_family = AF_INET;
    serveur.sin_port = htons(PORT);
    serveur.sin_addr.s_addr = inet_addr(HOTE);

    if (connect(sock, (struct sockaddr *)&serveur, sizeof(serveur)) < 0) {
        perror("connect");
        close(sock);
        return -1;
    }

    trame[0] = m->t;
    trame[1] = m->h;
    trame[2] = m->p;

    if (write(sock, trame, sizeof(trame)) != (ssize_t)sizeof(trame)) {
        perror("write");
        close(sock);
        return -1;
    }

    close(sock);
    return 0;
}

int main(void)
{
    int i;
    int nb_erreurs = 0;

    for (i = 0; i < NB_MESURES; i++) {
        struct mesure *m = &jeu[i];

        if (!valide(m))
            nb_erreurs++;

        printf("[%2d] %-8s t=%-8.1f h=%-8.1f p=%-8.1f\n",
               i,
               valide(m) ? "OK" : "ERREUR",
               m->t, m->h, m->p);

        if (envoyer(m) < 0)
            fprintf(stderr, "  -> echec d'envoi de la mesure %d\n", i);

        /* Petite pause pour laisser le loader traiter la connexion. */
        usleep(100000);
    }

    printf("\n%d mesures envoyees, dont %d erronees (%d %%).\n",
           NB_MESURES, nb_erreurs, nb_erreurs * 100 / NB_MESURES);

    return 0;
}
