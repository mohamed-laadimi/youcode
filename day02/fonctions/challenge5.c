#include <stdio.h>
unsigned long long factorielle(int n) {
    if (n == 0) {
        return 1;
    }

    unsigned long long resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat *= i;
    }

    return resultat;
}

int main() {
    int nombre;
    printf("Entrez un nombre entier positif pour calculer sa factorielle : ");
    scanf("%d", &nombre);
    if (nombre < 0) {
        printf("La factorielle n'est pas définie pour les nombres négatifs.\n");
    } else {
        printf("La factorielle de %d est : %llu\n", nombre, factorielle(nombre));
    }

    return 0;
}
