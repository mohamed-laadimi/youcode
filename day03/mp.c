#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 100

typedef struct {
    char nom[50];
    int numero[10];
    char e_mail[100];
} Contact;

Contact stock[MAX_NOMBRE];
int nombre_contact = 0;

void Ajouter_un_Contact() {
    if (nombre_contact < MAX_NOMBRE) {
        printf("Nom: ");
        scanf("%s", stock[nombre_contact].nom);
        printf("Numéro de téléphone: ");
        scanf("%d", &stock[nombre_contact].numero);
        printf("Adresse e-mail: ");
        scanf("%s", stock[nombre_contact].e_mail);
        nombre_contact++;
    } else {
        printf("Stock plein!\n");
    }
}

void Modifier_un_Contact() {
    char nom[50];
    printf("Nom du Contact à mettre à jour: ");
    scanf("%s", nom);
    for (int i = 0; i < nombre_contact; i++) {
        if (strcmp(stock[i].nom, nom) == 0) {
            printf("Nouveau numéro de téléphone: ");
            scanf("%d", &stock[i].numero);
            printf("Nouvelle adresse e-mail: ");
            scanf("%s", stock[i].e_mail);
            printf("Contact mis à jour.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

void Supprimer_un_Contact() {
    char nom[50];
    printf("Nom du Contact à supprimer: ");
    scanf("%s", nom);
    for (int i = 0; i < nombre_contact; i++) {
        if (strcmp(stock[i].nom, nom) == 0) {
            for (int j = i; j < nombre_contact - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nombre_contact--;
            printf("Contact supprimé.\n");
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

void Afficher_Tous_les_Contacts() {
    if (nombre_contact == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }
    for (int i = 0; i < nombre_contact; i++) {
        printf("Nom: %s, Numéro: %d, E-mail: %s\n", stock[i].nom, stock[i].numero, stock[i].e_mail);
    }
}

void Rechercher_un_Contact() {
    char nom[50];
    printf("Nom du Contact à rechercher: ");
    scanf("%s", nom);
    for (int i = 0; i < nombre_contact; i++) {
        if (strcmp(stock[i].nom, nom) == 0) {
            printf("Contact trouvé - Nom: %s, Numéro: %d, E-mail: %s\n", stock[i].nom, stock[i].numero, stock[i].e_mail);
            return;
        }
    }
    printf("Contact non trouvé.\n");
}

int main() {
    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un Contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un Contact\n");
        printf("4. Afficher Tous les Contacts\n");
        printf("5. Rechercher un Contact\n");
        printf("6. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: Ajouter_un_Contact(); break;
            case 2: Modifier_un_Contact(); break;
            case 3: Supprimer_un_Contact(); break;
            case 4: Afficher_Tous_les_Contacts(); break;
            case 5: Rechercher_un_Contact(); break;
            case 6: printf("Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 6);

    return 0;
}