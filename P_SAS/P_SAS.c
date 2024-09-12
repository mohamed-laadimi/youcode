#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 1000
#define MAX_NOM 50
#define MAX_PRENOM 50
#define MAX_DEPARTEMENT 50

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int numero;
    char nom[MAX_NOM];
    char prenom[MAX_PRENOM];
    Date dateNaissance;
    char departement[MAX_DEPARTEMENT];
    float noteGenerale;
} Etudiant;

void afficherMenu();
void ajouterEtudiant();
void modifierEtudiant();
void supprimerEtudiant();
void afficherEtudiant();
void calculerMoyenne();
void afficherStatistiques();
void rechercherEtudiant();
void trierEtudiants();

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

void ajouterEtudiant() {
    if (nbEtudiants >= MAX_ETUDIANTS) {
        printf("Nombre maximum d'étudiants atteint.\n");
        return;
    }

    Etudiant e;
    printf("Numéro unique : ");
    if (scanf("%d", &e.numero) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    printf("Nom : ");
    if (scanf("%49s", e.nom) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    printf("Prénom : ");
    if (scanf("%49s", e.prenom) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    printf("Date de naissance (JJ MM AAAA) : ");
    if (scanf("%d %d %d", &e.dateNaissance.jour, &e.dateNaissance.mois, &e.dateNaissance.annee) != 3) {
        printf("Entrée invalide.\n");
        return;
    }

    printf("Département : ");
    if (scanf("%49s", e.departement) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    printf("Note générale : ");
    if (scanf("%f", &e.noteGenerale) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    etudiants[nbEtudiants++] = e;
    printf("Étudiant ajouté avec succès.\n");
}

void modifierEtudiant() {
    int numero;
    printf("Entrez le numéro de l'étudiant à modifier : ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].numero == numero) {
            printf("Nouveau nom (ou '.' pour ne pas changer) : ");
            char temp[MAX_NOM];
            if (scanf("%49s", temp) != 1) {
                printf("Entrée invalide.\n");
                return;
            }
            if (strcasecmp(temp, ".") != 0) {
                strncpy(etudiants[i].nom, temp, MAX_NOM - 1);
                etudiants[i].nom[MAX_NOM - 1] = '\0';
            }

            printf("Nouveau prénom (ou '.' pour ne pas changer) : ");
            if (scanf("%49s", temp) != 1) {
                printf("Entrée invalide.\n");
                return;
            }
            if (strcasecmp(temp, ".") != 0) {
                strncpy(etudiants[i].prenom, temp, MAX_PRENOM - 1);
                etudiants[i].prenom[MAX_PRENOM - 1] = '\0';
            }

            printf("Nouvelle note générale (ou -1 pour ne pas changer) : ");
            float newNote;
            if (scanf("%f", &newNote) != 1) {
                printf("Entrée invalide.\n");
                return;
            }
            if (newNote != -1) {
                etudiants[i].noteGenerale = newNote;
            }

            printf("Étudiant modifié avec succès.\n");
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void supprimerEtudiant() {
    int numero;
    printf("Entrez le numéro de l'étudiant à supprimer : ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].numero == numero) {
            for (int j = i; j < nbEtudiants - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            nbEtudiants--;
            printf("Étudiant supprimé avec succès.\n");
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void afficherEtudiant() {
    int numero;
    printf("Entrez le numéro de l'étudiant : ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].numero == numero) {
            printf("Numéro : %d\n", etudiants[i].numero);
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prénom : %s\n", etudiants[i].prenom);
            printf("Date de naissance : %d/%d/%d\n", etudiants[i].dateNaissance.jour,
                   etudiants[i].dateNaissance.mois, etudiants[i].dateNaissance.annee);
            printf("Département : %s\n", etudiants[i].departement);
            printf("Note générale : %.2f\n", etudiants[i].noteGenerale);
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void calculerMoyenne() {
    if (nbEtudiants == 0) {
        printf("Aucun étudiant disponible pour calculer la moyenne.\n");
        return;
    }

    float somme = 0;
    for (int i = 0; i < nbEtudiants; i++) {
        somme += etudiants[i].noteGenerale;
    }
    printf("Moyenne générale de l'université : %.2f\n", somme / nbEtudiants);

    // Calcul par département
    char departements[MAX_ETUDIANTS][MAX_DEPARTEMENT];
    int nbDepartements = 0;

    for (int i = 0; i < nbEtudiants; i++) {
        int trouve = 0;
        for (int j = 0; j < nbDepartements; j++) {
            if (strcasecmp(etudiants[i].departement, departements[j]) == 0) {
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strncpy(departements[nbDepartements], etudiants[i].departement, MAX_DEPARTEMENT - 1);
            departements[nbDepartements][MAX_DEPARTEMENT - 1] = '\0';
            nbDepartements++;
        }
    }

    for (int i = 0; i < nbDepartements; i++) {
        float sommeDep = 0;
        int nbEtudiantsDep = 0;
        for (int j = 0; j < nbEtudiants; j++) {
            if (strcasecmp(etudiants[j].departement, departements[i]) == 0) {
                sommeDep += etudiants[j].noteGenerale;
                nbEtudiantsDep++;
            }
        }
        printf("Moyenne du département %s : %.2f\n", departements[i], sommeDep / nbEtudiantsDep);
    }
}

void afficherStatistiques() {
    printf("Nombre total d'étudiants inscrits : %d\n", nbEtudiants);

    // Départements et nombre d'étudiants par département
    char departements[MAX_ETUDIANTS][MAX_DEPARTEMENT];
    int nbDepartements = 0, nbEtudiantsDep[MAX_ETUDIANTS] = {0};

    for (int i = 0; i < nbEtudiants; i++) {
        int j;
        for (j = 0; j < nbDepartements; j++) {
            if (strcasecmp(etudiants[i].departement, departements[j]) == 0) {
                nbEtudiantsDep[j]++;  // Increment the student count for the department
                break;
            }
        }
        if (j == nbDepartements) {  // If department not found, add it
            strncpy(departements[nbDepartements], etudiants[i].departement, MAX_DEPARTEMENT - 1);
            departements[nbDepartements][MAX_DEPARTEMENT - 1] = '\0';
            nbEtudiantsDep[nbDepartements++] = 1;  // Set initial count to 1 for the new department
        }
    }

    for (int i = 0; i < nbDepartements; i++) {
        printf("Nombre d'étudiants dans le département %s : %d\n", departements[i], nbEtudiantsDep[i]);
    }

    // Étudiants ayant une moyenne supérieure à un seuil
    float seuil;
    printf("Entrez le seuil de moyenne : ");
    if (scanf("%f", &seuil) != 1) {
        printf("Entrée invalide.\n");
        return;
    }
    printf("Étudiants ayant une moyenne supérieure à %.2f :\n", seuil);
    for (int i = 0; i < nbEtudiants; i++) {
        if (etudiants[i].noteGenerale > seuil) {
            printf("%s %s (%.2f)\n", etudiants[i].nom, etudiants[i].prenom, etudiants[i].noteGenerale);
        }
    }

    // Les 3 meilleurs étudiants
    Etudiant top3[3] = {etudiants[0], etudiants[0], etudiants[0]};
    for (int i = 1; i < nbEtudiants; i++) {
        if (etudiants[i].noteGenerale > top3[0].noteGenerale) {
            top3[2] = top3[1];
            top3[1] = top3[0];
            top3[0] = etudiants[i];
        } else if (etudiants[i].noteGenerale > top3[1].noteGenerale) {
            top3[2] = top3[1];
            top3[1] = etudiants[i];
        } else if (etudiants[i].noteGenerale > top3[2].noteGenerale) {
            top3[2] = etudiants[i];
        }
    }

    printf("Les 3 meilleurs étudiants :\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s %s (%.2f)\n", i + 1, top3[i].nom, top3[i].prenom, top3[i].noteGenerale);
    }

    // Étudiants ayant réussi par département
    printf("Nombre d'étudiants ayant réussi par département :\n");
    for (int i = 0; i < nbDepartements; i++) {
        int nbReussi = 0;
        for (int j = 0; j < nbEtudiants; j++) {
            if (strcasecmp(etudiants[j].departement, departements[i]) == 0 && etudiants[j].noteGenerale >= 10) {
                nbReussi++;
            }
        }
        printf("%s : %d\n", departements[i], nbReussi);
    }
}

void rechercherEtudiant() {
    printf("1. Rechercher par nom\n");
    printf("2. Afficher la liste des étudiants d'un département\n");
    int choix;
    if (scanf("%d", &choix) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    if (choix == 1) {
        char nom[MAX_NOM];
        printf("Entrez le nom à rechercher : ");
        if (scanf("%49s", nom) != 1) {
            printf("Entrée invalide.\n");
            return;
        }
        for (int i = 0; i < nbEtudiants; i++) {
            if (strcasecmp(etudiants[i].nom, nom) == 0) {
                printf("%s %s (Numéro: %d, Département: %s)\n", 
                       etudiants[i].nom, etudiants[i].prenom, 
                       etudiants[i].numero, etudiants[i].departement);
            }
        }
    } else if (choix == 2) {
        char departement[MAX_DEPARTEMENT];
        printf("Entrez le nom du département : ");
        if (scanf("%49s", departement) != 1) {
            printf("Entrée invalide.\n");
            return;
        }
        for (int i = 0; i < nbEtudiants; i++) {
            if (strcasecmp(etudiants[i].departement, departement) == 0) {
                printf("%s %s (Numéro: %d)\n", 
                       etudiants[i].nom, etudiants[i].prenom, etudiants[i].numero);
            }
        }
    } else {
        printf("Choix invalide.\n");
    }
}

void trierEtudiants() {
    printf("1. Trier par nom (A-Z)\n");
    printf("2. Trier par nom (Z-A)\n");
    printf("3. Trier par moyenne (croissant)\n");
    printf("4. Trier par moyenne (décroissant)\n");
    printf("5. Trier par réussite\n");
    int choix;
    if (scanf("%d", &choix) != 1) {
        printf("Entrée invalide.\n");
        return;
    }

    for (int i = 0; i < nbEtudiants - 1; i++) {
        for (int j = 0; j < nbEtudiants - i - 1; j++) {
            int doSwap = 0;
            switch (choix) {
                case 1:
                    doSwap = strcasecmp(etudiants[j].nom, etudiants[j + 1].nom) > 0;
                    break;
                case 2:
                    doSwap = strcasecmp(etudiants[j].nom, etudiants[j + 1].nom) < 0;
                    break;
                case 3:
                    doSwap = etudiants[j].noteGenerale > etudiants[j + 1].noteGenerale;
                    break;
                case 4:
                    doSwap = etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale;
                    break;
                case 5:
                    if (etudiants[j].noteGenerale >= 10 && etudiants[j + 1].noteGenerale < 10) {
                        doSwap = 1;
                    } else if (etudiants[j].noteGenerale >= 10 && etudiants[j + 1].noteGenerale >= 10) {
                        doSwap = etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale;
                    } else if (etudiants[j].noteGenerale < 10 && etudiants[j + 1].noteGenerale < 10) {
                        doSwap = etudiants[j].noteGenerale < etudiants[j + 1].noteGenerale;
                    }
                    break;
                default:
                    printf("Choix invalide.\n");
                    return;
            }
            if (doSwap) {
                Etudiant temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }

    printf("Liste triée :\n");
    for (int i = 0; i < nbEtudiants; i++) {
        printf("%s %s (Note: %.2f)\n", etudiants[i].nom, etudiants[i].prenom, etudiants[i].noteGenerale);
    }
}

int main() {
    int choix;
    do {
        afficherMenu();
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                printf("1. Modifier\n2. Supprimer\nChoix : ");
                int sousChoix;
                if (scanf("%d", &sousChoix) != 1) {
                    printf("Entrée invalide.\n");
                    continue;
                }
                if (sousChoix == 1) {
                    modifierEtudiant();
                } else if (sousChoix == 2) {
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
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
