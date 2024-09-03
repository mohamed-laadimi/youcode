//Volume d'une sphère

#include <stdio.h>
#include <math.h>

int main() {
    double rayon, volume;

    printf("Entrez le rayon de la sphère: ");
    scanf("%lf", &rayon);

    volume = (4.0/3.0) * M_PI * pow(rayon, 3);
    printf("Le volume de la sphère est: %.2lf\n", volume);

    return 0;
}