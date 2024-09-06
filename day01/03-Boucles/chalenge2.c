//Factorielle d'un Nombre

#include <stdio.h>
int main() {
    int n;
    printf("Entrez un nombre entier positif : ");
    scanf("%d", &n);

    if (n < 0) {
        printf("La factorielle est définie uniquement pour les entiers positifs.\n");
    } else {

        unsigned int r = 1;
    for (int i = 1; i <= n; i++) {
        r *= i;
    }
        printf("%d! = %u\n", n, r);
    }
    return 0;
}
