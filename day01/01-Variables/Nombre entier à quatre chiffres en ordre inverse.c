 //Nombre entier à quatre chiffres en ordre inverse

 #include <stdio.h>

int main() {
    int nombre, inverse;

    printf("Entrez un nombre entier à quatre chiffres: ");
    scanf("%d", &nombre);

    inverse = (nombre % 10) * 1000 + ((nombre / 10) % 10) * 100 + ((nombre / 100) % 10) * 10 + (nombre / 1000);
    printf("L'inverse est: %d\n", inverse);

    return 0;
}