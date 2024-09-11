// functions.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Etudiant etudiants[MAX_ETUDIANTS];
int nbEtudiants = 0;

void afficherMenu() {
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Ajouter un étudiant\n");
    printf("2. Modifier ou supprimer un étudiant\n");
    printf("3. Afficher les détails d'un étudiant\n");
    printf("4. Calculer la moyenne générale\n");
    printf("5. Statistiques\n");
    printf("6. Rechercher un étudiant\n");
    printf("7. Trier les étudiants\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
}

int estDateValide(Date d) {
    if (d.annee < 1900 || d.mois < 1 || d.mois > 12 || d.jour < 1 || d.jour > 31) {
        return 0;
    }
    if ((d.mois == 4 || d.mois == 6 || d.mois == 9 || d.mois == 11) && d.jour > 30) return 0;
    if (d.mois == 2) {
        int isLeap = (d.annee % 4 == 0 && (d.annee % 100 != 0 || d.annee % 400 == 0));
        if ((isLeap && d.jour > 29) || (!isLeap && d.jour > 28)) return 0;
    }
    return 1;
}

int trouverEtudiant(int numero) {
    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

void ajouterEtudiant() {
    if (nbEtudiants >= MAX_ETUDIANTS) {
        printf("Nombre maximum d'étudiants atteint.\n");
        return;
    }

    Etudiant e;
    printf("Numéro unique : ");
    if (scanf("%d", &e.numero) != 1) {
        printf("Erreur de saisie du numéro.\n");
        while (getchar() != '\n');
        return;
    }

    if (trouverEtudiant(e.numero) != -1) {
        printf("Numéro d'étudiant déjà existant.\n");
        return;
    }

    printf("Nom : ");
    if (scanf("%49s", e.nom) != 1) {
        printf("Erreur de saisie du nom.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Prénom : ");
    if (scanf("%49s", e.prenom) != 1) {
        printf("Erreur de saisie du prénom.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Date de naissance (JJ MM AAAA) : ");
    if (scanf("%d %d %d", &e.dateNaissance.jour, &e.dateNaissance.mois, &e.dateNaissance.annee) != 3) {
        printf("Erreur de saisie de la date.\n");
        while (getchar() != '\n');
        return;
    }
    if (!estDateValide(e.dateNaissance)) {
        printf("Date invalide.\n");
        return;
    }

    printf("Département : ");
    if (scanf("%49s", e.departement) != 1) {
        printf("Erreur de saisie du département.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Note générale : ");
    if (scanf("%f", &e.noteGenerale) != 1) {
        printf("Erreur de saisie de la note.\n");
        while (getchar() != '\n');
        return;
    }

    etudiants[nbEtudiants++] = e;
    printf("Étudiant ajouté avec succès.\n");
}

void modifierEtudiant() {
    int numero;
    printf("Entrez le numéro de l'étudiant à modifier : ");
    if (scanf("%d", &numero) != 1) {
        printf("Erreur de saisie du numéro.\n");
        while (getchar() != '\n');
        return;
    }

    int index = trouverEtudiant(numero);
    if (index == -1) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    printf("Nouveau nom (ou '.' pour ne pas changer) : ");
    char temp[MAX_NOM];
    if (scanf("%49s", temp) != 1) {
        printf("Erreur de saisie du nom.\n");
        while (getchar() != '\n');
        return;
    }
    if (strcasecmp(temp, ".") != 0) strcpy(etudiants[index].nom, temp);

    printf("Nouveau prénom (ou '.' pour ne pas changer) : ");
    if (scanf("%49s", temp) != 1) {
        printf("Erreur de saisie du prénom.\n");
        while (getchar() != '\n');
        return;
    }
    if (strcasecmp(temp, ".") != 0) strcpy(etudiants[index].prenom, temp);

    printf("Nouvelle note générale (ou -1 pour ne pas changer) : ");
    float newNote;
    if (scanf("%f", &newNote) != 1) {
        printf("Erreur de saisie de la note.\n");
        while (getchar() != '\n');
        return;
    }
    if (newNote != -1) etudiants[index].noteGenerale = newNote;

    printf("Étudiant modifié avec succès.\n");
}

void supprimerEtudiant() {
    int numero;
    printf("Entrez le numéro de l'étudiant à supprimer : ");
    if (scanf("%d", &numero) != 1) {
        printf("Erreur de saisie du numéro.\n");
        while (getchar() != '\n');
        return;
    }

    int index = trouverEtudiant(numero);
    if (index == -1) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    for (int j = index; j < nbEtudiants - 1; j++) {
        etudiants[j] = etudiants[j + 1];
    }
    nbEtudiants--;
    printf("Étudiant supprimé avec succès.\n");
}

void afficherEtudiant() {
    int numero;
    printf("Entrez le numéro de l'étudiant : ");
    if (scanf("%d", &numero) != 1) {
        printf("Erreur de saisie du numéro.\n");
        while (getchar() != '\n');
        return;
    }

    int index = trouverEtudiant(numero);
    if (index == -1) {
        printf("Étudiant non trouvé.\n");
        return;
    }

    printf("Numéro : %d\n", etudiants[index].numero);
    printf("Nom : %s\n", etudiants[index].nom);
    printf("Prénom : %s\n", etudiants[index].prenom);
    printf("Date de naissance : %d/%d/%d\n", etudiants[index].dateNaissance.jour,
           etudiants[index].dateNaissance.mois, etudiants[index].dateNaissance.annee);
    printf("Département : %s\n", etudiants[index].departement);
    printf("Note générale : %.2f\n", etudiants[index].noteGenerale);
}

void calculerMoyenne() {
    if (nbEtudiants == 0) {
        printf("Aucun étudiant enregistré.\n");
        return;
    }

    float somme = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        somme += etudiants[i].noteGenerale;
    }
    printf("Moyenne générale de l'université : %.2f\n", somme / nbEtudiants);

    char departements[MAX_ETUDIANTS][MAX_DEPARTEMENT];
    int nbDepartements = 0;

    for (int i = 0; i < nbEtudiants; i++) {
        int trouve = 0;
        for (int j = 0; j < nbDepartements; j++) {
            if (strcmp(departements[j], etudiants[i].departement) == 0) {
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strcpy(departements[nbDepartements++], etudiants[i].departement);
        }
    }

    for (int i = 0; i < nbDepartements; i++) {
        float sommeDepartement = 0;
        int nbEtudiantsDepartement = 0;
        for (int j = 0; j < nbEtudiants; j++) {
            if (strcmp(departements[i], etudiants[j].departement) == 0) {
                sommeDepartement += etudiants[j].noteGenerale;
                nbEtudiantsDepartement++;
            }
        }
        printf("Moyenne du département %s : %.2f\n", departements[i], sommeDepartement / nbEtudiantsDepartement);
    }
}

void afficherStatistiques() {
    printf("Nombre total d'étudiants : %d\n", nbEtudiants);
    if (nbEtudiants == 0) return;

    float somme = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        somme += etudiants[i].noteGenerale;
    }
    printf("Moyenne des notes : %.2f\n", somme / nbEtudiants);
}

void rechercherEtudiant() {
    char nom[MAX_NOM];
    printf("Entrez le nom de l'étudiant à rechercher : ");
    if (scanf("%49s", nom) != 1) {
        printf("Erreur de saisie du nom.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < nbEtudiants; i++) {
        if (strcasecmp(etudiants[i].nom, nom) == 0) {
            afficherEtudiant();
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void trierEtudiants() {
    for (int i = 0; i < nbEtudiants - 1; i++) {
        for (int j = i + 1; j < nbEtudiants; j++) {
            if (etudiants[i].noteGenerale < etudiants[j].noteGenerale) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Étudiants triés par note générale.\n");
}
