//Calcul de la moyenne géométrique

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double moyenne_geometrique;

    printf("Entrez trois nombres: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    moyenne_geometrique = pow(a * b * c, 1.0/3.0);
    printf("La moyenne géométrique est: %.2lf\n", moyenne_geometrique);

    return 0;
}