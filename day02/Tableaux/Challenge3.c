#include<stdio.h>
int main()
{
    int n;
      printf("Entrez le nombre d'�l�ments du tableau : ");
      scanf("%d", &n);
      int tableau[n];
       printf("Entrez les %d �l�ments du tableau :\n", n);
       for (int i = 0; i < n; i++)
       {
        printf("�l�ment %d : ", i + 1);
        scanf("%d", &tableau[i]);
       }
        int somme = 0;
        for (int i = 0; i < n; i++)
    {
        somme += tableau[i];
    }
       printf("La somme des �l�ments du tableau est : %d\n", somme);

       return 0;
}
