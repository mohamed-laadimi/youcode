//Conversion de la vitesse

#include<stdio.h>
int main()
{
float kmh,ms;
printf("Entre la vitesse en kilomètres par heure (km/h):");
scanf("%f",&kmh);
ms = kmh * 0.27778;
printf("Vitesse en m/s:%.2f\n",ms);
return 0;
}