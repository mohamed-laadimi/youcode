//Challenge 1 : Paire ou Impaire

#include <stdio.h>

int main() {
    int nombre;

    // Demander à l'utilisateur de saisir un nombre
    printf("Veuillez entrer un nombre : ");
    scanf("%d", &nombre);

    // Vérifier si le nombre est pair ou impair
    if (nombre % 2 == 0) {
        printf("Le nombre %d est pair.\n", nombre);
    } else {
        printf("Le nombre %d est impair.\n", nombre);
    }

    return 0;
}