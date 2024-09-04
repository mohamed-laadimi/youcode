#include<stdio.h>
int max (int x,int y)
{
    if(x>y)
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
    int R = max(x,y);
    printf("le max du %d et %d est egale: %d", x,y,R);
    return 0;
}
