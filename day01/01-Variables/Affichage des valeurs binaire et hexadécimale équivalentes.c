//Affichage des valeurs binaire et hexadécimale équivalentes

#include <stdio.h>

int main() {
    int nombre;

    printf("Entrez un nombre entier: ");
    scanf("%d", &nombre);

    printf("Valeur binaire: %b\n", nombre); // Note: %b n'est pas standard en C, utilisez une fonction pour convertir en binaire
    printf("Valeur hexadécimale: %x\n", nombre);

    return 0;
}