//Affichage Température

#include <stdio.h>

int main() {
    float celsius;

    printf("Entrez la température en Celsius: ");
    scanf("%f", &celsius);

    if (celsius < 0) {
        printf("État de l'eau: Solide\n");
    } else if (celsius < 100) {
        printf("État de l'eau: Liquide\n");
    } else {
        printf("État de l'eau: Gaz\n");
    }

    return 0;
}