//Calcul et affichage des résultats

#include <stdio.h>

int main() {
    double a, b;

    printf("Entrez deux nombres réels (a et b): ");
    scanf("%lf %lf", &a, &b);

    printf("a + b = %.2lf\n", a + b);
    printf("a - b = %.2lf\n", a - b);
    printf("a * b = %.2lf\n", a * b);
    printf("a / b = %.2lf\n", a / b);

    return 0;
}