#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Meteo.h"

#define NOM_FICHIER "weather_data.bin"

FILE *ouvrir_fichier(char *fichier)
{
    FILE *f = fopen(fichier, "rb");
    if (!f) {
        perror("Erreur ouverture");
        return NULL;
        exit(1);
    }
    return f;    
}

int main() 
{
    FILE *fichier_binaire = ouvrir_fichier(NOM_FICHIER);

    Meteo m;
    float somme = 0, mini = 100, maxi = -100;
    time_t ts_max;
    int nb_val = 0;

    while (fread(&m, sizeof(Meteo), 1, fichier_binaire) == 1) {
        nb_val++;
        somme += m.temperature;
        if (m.temperature > maxi) {
            maxi = m.temperature;
            ts_max = m.timestamp;
        }
        if (m.temperature < mini) mini = m.temperature;
    }

    printf("Moyenne: %.1f°C\n", somme / nb_val);
    printf("Min: %.1f°C | Max: %.1f°C\n", mini, maxi);

    struct tm *t = localtime((time_t*)&ts_max);
    printf("Max à: %02d:%02d\n", t->tm_hour, t->tm_min);

    fclose(fichier_binaire);
    return 0;
}