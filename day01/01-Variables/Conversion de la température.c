//Conversion de la température

#include<stdio.h>
int main()
{
float celsius,kelvin;
printf("Entre la temperature en celsius:");
scanf("%f",&celsius);
kelvin = celsius + 273,15;
printf("Temperature en kelvin:%.2f\n",kelvin);
return 0;
}