//Surface d'un rectangle

#include <stdio.h>

int main() {
    double longueur, largeur, surface;

    printf("Entrez la longueur du rectangle: ");
    scanf("%lf", &longueur);
    printf("Entrez la largeur du rectangle: ");
    scanf("%lf", &largeur);

    surface = longueur * largeur;
    printf("La surface du rectangle est: %.2lf\n", surface);

    return 0;
}