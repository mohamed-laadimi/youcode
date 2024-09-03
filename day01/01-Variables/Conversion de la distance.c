//Conversion de la distance

#include<stdio.h>
int main()
{
float km,yards;
printf("Entre la distance en kilomètres:");
scanf("%f",&km);
yards = km * 1093,61;
printf("Distance en:%.2f\n",yards);
return 0;
}