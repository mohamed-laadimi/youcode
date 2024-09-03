#include<stdio.h>
int main()
{
    int n ;
    printf("entrez les elements du tableau :\n", );
    scanf("%d",&n);
    int tableau[n];
    for (int i = 0; i < n; i++)
    {
    printf("element %d : ", i + 1);
    scanf("%d", &tableau[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",tableau[i]);
    }
    return 0;
}
