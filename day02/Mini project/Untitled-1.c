#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char titre[50];
    char auteur[50];
    float prix;
    int quantite;
} Livre;

Livre stock[MAX_BOOKS];
int nombreDeLivres = 0;

void ajouterLivre() {
    if (nombreDeLivres < MAX_BOOKS) {
        printf("Titre du livre: ");
        scanf("%s", stock[nombreDeLivres].titre);
        printf("Auteur du livre: ");
        scanf("%s", stock[nombreDeLivres].auteur);
        printf("Prix du livre: ");
        scanf("%f", &stock[nombreDeLivres].prix);
        printf("Quantité en stock: ");
        scanf("%d", &stock[nombreDeLivres].quantite);
        nombreDeLivres++;
    } else {
        printf("Stock plein!\n");
    }
}

void afficherLivres() {
    for (int i = 0; i < nombreDeLivres; i++) {
        printf("Titre: %s, Auteur: %s, Prix: %.2f, Quantité: %d\n", stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
    }
}

void rechercherLivre() {
    char titre[50];
    printf("Titre du livre à rechercher: ");
    scanf("%s", titre);
    for (int i = 0; i < nombreDeLivres; i++) {
        if (strcmp(stock[i].titre, titre) == 0) {
            printf("Livre trouvé - Titre: %s, Auteur: %s, Prix: %.2f, Quantité: %d\n", stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void mettreAJourQuantite() {
    char titre[50];
    int nouvelleQuantite;
    printf("Titre du livre à mettre à jour: ");
    scanf("%s", titre);
    for (int i = 0; i < nombreDeLivres; i++) {
        if (strcmp(stock[i].titre, titre) == 0) {
            printf("Nouvelle quantité: ");
            scanf("%d", &nouvelleQuantite);
            stock[i].quantite = nouvelleQuantite;
            printf("Quantité mise à jour.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void supprimerLivre() {
    char titre[50];
    printf("Titre du livre à supprimer: ");
    scanf("%s", titre);
    for (int i = 0; i < nombreDeLivres; i++) {
        if (strcmp(stock[i].titre, titre) == 0) {
            for (int j = i; j < nombreDeLivres - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nombreDeLivres--;
            printf("Livre supprimé.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

void afficherNombreTotal() {
    int total = 0;
    for (int i = 0; i < nombreDeLivres; i++) {
        total += stock[i].quantite;
    }
    printf("Nombre total de livres en stock: %d\n", total);
}

int main() {
    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres\n");
        printf("7. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterLivre(); break;
            case 2: afficherLivres(); break;
            case 3: rechercherLivre(); break;
            case 4: mettreAJourQuantite(); break;
            case 5: supprimerLivre(); break;
            case 6: afficherNombreTotal(); break;
            case 7: printf("Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 7);

    return 0;
}