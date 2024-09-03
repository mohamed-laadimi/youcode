//Affichage Informations

#include<stdio.h>
int main()
{
char nom[100],prenom[100],sexe[100],email[100];
int age;
printf("Entre votre nom:");
scanf("%s",nom);
printf("Entre votre prenom:");
scanf("%s",prenom);
printf("Entre votre age:");
scanf("%d",&age);
printf("Entre votre sexe:");
scanf("%s",sexe);
printf("Entre votre email:");
scanf("%s",email);
printf("Nom:%s\nPrenom:%s\nAge:%d\nSexe:%s\nEmail:%s\n",nom,prenom,age,sexe,email);
return 0;
}