#include<stdio.h>
int multiplication(int a,int b)
{
    return a*b;
}
int main()
{
    int x,y;
    printf("entrer le premiere number:");
    scanf("%d",&x);
    printf("entrer le deusieme number:");
    scanf("%d",&y);
    int R = multiplication (x,y);
    printf("la multiplication du %d et %d est egale: %d", x,y,R);
    return 0;
}
