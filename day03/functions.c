// functions.c

#include <stdio.h>
#include <string.h>
#include "header.h"

Contact stock[MAX_NOMBRE];
int nombre_contact = 0;

void Ajouter_un_Contact() {
    if (nombre_contact < MAX_NOMBRE) {
        printf("Nom: ");
        scanf("%49s", stock[nombre_contact].nom);  // Limit input to avoid overflow
        printf("Numero de telephone: ");
        scanf("%19s", stock[nombre_contact].numero);  // Limit input to avoid overflow
        printf("Adresse e-mail: ");
        scanf("%99s", stock[nombre_contact].e_mail);  // Limit input to avoid overflow
        nombre_contact++;
    } else {
        printf("Stock plein!\n");
    }
}

void Modifier_un_Contact() {
    char nom[MAX_NOM];
    printf("Nom du Contact a mettre à jour: ");
    scanf("%49s", nom);
    for (int i = 0; i < nombre_contact; i++) {
        if (strcmp(stock[i].nom, nom) == 0) {
            printf("Nouveau numero de telephone: ");
            scanf("%19s", stock[i].numero);  // Limit input to avoid overflow
            printf("Nouvelle adresse e-mail: ");
            scanf("%99s", stock[i].e_mail);  // Limit input to avoid overflow
            printf("Contact mis a jour.\n");
            return;
        }
    }
    printf("Contact non trouve.\n");
}

void Supprimer_un_Contact() {
    char nom[MAX_NOM];
    printf("Nom du Contact a supprimer: ");
    scanf("%49s", nom);
    for (int i = 0; i < nombre_contact; i++) {
        if (strcmp(stock[i].nom, nom) == 0) {
            for (int j = i; j < nombre_contact - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nombre_contact--;
            printf("Contact supprime.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

void Afficher_Tous_les_Contacts() {
    if (nombre_contact == 0) {
        printf("Aucun contact a afficher.\n");
        return;
    }
    for (int i = 0; i < nombre_contact; i++) {
        printf("Nom: %s, Numero: %s, E-mail: %s\n", stock[i].nom, stock[i].numero, stock[i].e_mail);
    }
}

void Rechercher_un_Contact() {
    char nom[MAX_NOM];
    printf("Nom du Contact a rechercher: ");
    scanf("%49s", nom);
    for (int i = 0; i < nombre_contact; i++) {
        if (strcmp(stock[i].nom, nom) == 0) {
            printf("Contact trouve - Nom: %s, Numero: %s, E-mail: %s\n", stock[i].nom, stock[i].numero, stock[i].e_mail);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}
