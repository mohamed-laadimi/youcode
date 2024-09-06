#include <stdio.h>

int main() {
    int n;
    int somme = 0;

    // Demander à l'utilisateur d'entrer un nombre entier
    printf("Entrez un nombre entier n: ");
    scanf("%d", &n);

    // Vérifier que n est positif
    if (n < 1) {
        printf("Le nombre doit être un entier positif.\n");
        return 1; // Quitter le programme avec un code d'erreur
    }

    // Calculer la somme des n premiers nombres naturels
    for (int i = 1; i <= n; i++) {
        somme += i;
    }

    // Afficher le résultat
    printf("La somme des %d premiers nombres naturels est: %d\n", n, somme);

    return 0;
}
