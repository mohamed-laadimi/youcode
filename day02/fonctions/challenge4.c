#include<stdio.h>
int min (int x,int y)
{
    if(x<y)
    {
        return x;
    }
    else
    {
     return y;
    }
}
int main()
{
    int x,y;
    printf("entrer premiere number:");
    scanf("%d",&x);
    printf("entrer dousieme number:");
    scanf("%d",&y);
    int R = min(x,y);
    printf("le min du %d et %d est egale: %d", x,y,R);
    return 0;
}
