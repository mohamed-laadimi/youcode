// main.c

#include <stdio.h>
#include "header.h"

int main() {
    int choix;

    do {
        afficherMenu();
        if (scanf("%d", &choix) != 1) {
            printf("Erreur de saisie du choix.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                printf("1. Modifier\n2. Supprimer\nVotre choix : ");
                if (scanf("%d", &choix) != 1) {
                    printf("Erreur de saisie du choix.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (choix == 1) {
                    modifierEtudiant();
                } else if (choix == 2) {
                    supprimerEtudiant();
                } else {
                    printf("Choix invalide.\n");
                }
                break;
            case 3:
                afficherEtudiant();
                break;
            case 4:
                calculerMoyenne();
                break;
            case 5:
                afficherStatistiques();
                break;
            case 6:
                rechercherEtudiant();
                break;
            case 7:
                trierEtudiants();
                break;
            case 0:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}
