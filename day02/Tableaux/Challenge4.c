#include<stdio.h>
int main()
{
    int n;
      printf("Entrez le nombre d'éléments du tableau : ");
      scanf("%d", &n);
      int tableau[n];
        for (int i = 0; i < n; i++)
       {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
       }
       for (int i = 0; i < n; i++)
       {
        printf("%d \n",tableau[i]);
       }
       int max ;
        for (int i = 1; i < n; i++)
        {
           if (tableau[i] > max)

            max = tableau[i];
        }
        printf("Le maximum des éléments du tableau est : %d\n", max);

       return 0;
}
