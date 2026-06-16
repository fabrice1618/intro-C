#include <stdio.h>
#include "Meteo.h"

#define NOM_FICHIER "weather_data.bin"

FILE *ouvrir_fichier(char *fichier)
{
    FILE *f = fopen(fichier, "rb");
    if (!f) {
        perror("Erreur ouverture");
        return NULL;
    }
    return f;    
}

void afficher_meteo(Meteo m)
{
    printf("%d | %.1f°C | %.1f%% | %.1f hPa\n", m.timestamp, m.temperature, m.humidite, m.pression);
}

int main() {
    FILE *fichier_binaire = ouvrir_fichier(NOM_FICHIER);
    if (fichier_binaire == NULL) {
        return 1;
    }

    Meteo m;
    while (fread(&m, sizeof(Meteo), 1, fichier_binaire) == 1) {
        afficher_meteo(m);
    }

    fclose(fichier_binaire);
    return 0;
}