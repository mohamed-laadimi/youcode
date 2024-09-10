// main.c

#include <stdio.h>
#include "header.h"

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
