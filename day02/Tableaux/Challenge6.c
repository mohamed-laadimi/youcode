#include <stdio.h>

int main() {
    int n;
    printf("Entrez le nombre d'�l�ments du tableau : ");
    scanf("%d", &n);
    int tableau[n];
    printf("Entrez les %d �l�ments du tableau :\n", n);
    for (int i = 0; i < n; i++) {
        printf("�l�ment %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    int facteur;
    printf("Entrez le facteur de multiplication : ");
    scanf("%d", &facteur);
    for (int i = 0; i < n; i++) {
        tableau[i] *= facteur;
    }
    printf("Le tableau r�sultant est :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
