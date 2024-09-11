#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    int id; // Numéro unique
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char dob[11]; // Date de naissance au format YYYY-MM-DD
    char department[MAX_DEPARTMENT_LENGTH];
    float general_grade;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void addStudent(int id, const char* name, const char* surname, const char* dob, const char* department, float grade) {
    if (student_count >= MAX_STUDENTS) {
        printf("La capacité maximale d'étudiants est atteinte.\n");
        return;
    }

    students[student_count].id = id;
    strncpy(students[student_count].name, name, MAX_NAME_LENGTH);
    strncpy(students[student_count].surname, surname, MAX_NAME_LENGTH);
    strncpy(students[student_count].dob, dob, 11);
    strncpy(students[student_count].department, department, MAX_DEPARTMENT_LENGTH);
    students[student_count].general_grade = grade;
    student_count++;
}

void printStudent(const Student* student) {
    printf("ID: %d\n", student->id);
    printf("Nom: %s\n", student->name);
    printf("Prénom: %s\n", student->surname);
    printf("Date de naissance: %s\n", student->dob);
    printf("Département: %s\n", student->department);
    printf("Note générale: %.2f\n", student->general_grade);
}

void displayStudentDetails(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printStudent(&students[i]);
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void modifyStudent(int id, const char* name, const char* surname, const char* dob, const char* department, float grade) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            strncpy(students[i].name, name, MAX_NAME_LENGTH);
            strncpy(students[i].surname, surname, MAX_NAME_LENGTH);
            strncpy(students[i].dob, dob, 11);
            strncpy(students[i].department, department, MAX_DEPARTMENT_LENGTH);
            students[i].general_grade = grade;
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void deleteStudent(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}

void calculateDepartmentAverage(const char* department) {
    float total = 0;
    int count = 0;

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].department, department) == 0) {
            total += students[i].general_grade;
            count++;
        }
    }

    if (count > 0) {
        printf("Moyenne générale pour le département %s : %.2f\n", department, total / count);
    } else {
        printf("Aucun étudiant trouvé dans le département %s.\n", department);
    }
}

void calculateUniversityAverage() {
    float total = 0;
    for (int i = 0; i < student_count; i++) {
        total += students[i].general_grade;
    }
    printf("Moyenne générale de l'université : %.2f\n", total / student_count);
}

void displayTopStudents() {
    if (student_count < 3) {
        printf("Moins de 3 étudiants disponibles pour afficher les meilleurs.\n");
        for (int i = 0; i < student_count; i++) {
            printStudent(&students[i]);
        }
        return;
    }

    Student top_students[3] = { students[0], students[1], students[2] };

    for (int i = 3; i < student_count; i++) {
        if (students[i].general_grade > top_students[0].general_grade) {
            top_students[0] = students[i];
            // Resort the top three
            for (int j = 0; j < 2; j++) {
                if (top_students[j].general_grade < top_students[j + 1].general_grade) {
                    Student temp = top_students[j];
                    top_students[j] = top_students[j + 1];
                    top_students[j + 1] = temp;
                }
            }
        }
    }

    printf("Top 3 des étudiants ayant les meilleures notes:\n");
    for (int i = 0; i < 3; i++) {
        printStudent(&top_students[i]);
    }
}

void displayPassingStudents(float passing_grade) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].general_grade >= passing_grade) {
            printStudent(&students[i]);
        }
    }
}

void searchStudentByName(const char* name) {
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printStudent(&students[i]);
        }
    }
}

int compareByName(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

int compareByGrade(const void* a, const void* b) {
    return ((Student*)b)->general_grade - ((Student*)a)->general_grade;
}

void sortStudentsByName() {
    qsort(students, student_count, sizeof(Student), compareByName);
}

void sortStudentsByGrade() {
    qsort(students, student_count, sizeof(Student), compareByGrade);
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Ajouter un étudiant\n");
    printf("2. Modifier un étudiant\n");
    printf("3. Supprimer un étudiant\n");
    printf("4. Afficher les détails d'un étudiant\n");
    printf("5. Calculer la moyenne générale par département\n");
    printf("6. Calculer la moyenne générale de l'université\n");
    printf("7. Afficher les statistiques\n");
    printf("8. Rechercher un étudiant par nom\n");
    printf("9. Trier les étudiants\n");
    printf("10. Quitter\n");
}

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH], dob[11], department[MAX_DEPARTMENT_LENGTH];
    float grade;
    int passing_grade;

    while (1) {
        displayMenu();
        printf("Choisissez une option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Entrez l'ID: ");
                scanf("%d", &id);
                printf("Entrez le nom: ");
                scanf("%s", name);
                printf("Entrez le prénom: ");
                scanf("%s", surname);
                printf("Entrez la date de naissance (YYYY-MM-DD): ");
                scanf("%s", dob);
                printf("Entrez le département: ");
                scanf("%s", department);
                printf("Entrez la note générale: ");
                scanf("%f", &grade);
                addStudent(id, name, surname, dob, department, grade);
                break;
            case 2:
                printf("Entrez l'ID de l'étudiant à modifier: ");
                scanf("%d", &id);
                printf("Entrez le nouveau nom: ");
                scanf("%s", name);
                printf("Entrez le nouveau prénom: ");
                scanf("%s", surname);
                printf("Entrez la nouvelle date de naissance (YYYY-MM-DD): ");
                scanf("%s", dob);
                printf("Entrez le nouveau département: ");
                scanf("%s", department);
                printf("Entrez la nouvelle note générale: ");
                scanf("%f", &grade);
                modifyStudent(id, name, surname, dob, department, grade);
                break;
            case 3:
                printf("Entrez l'ID de l'étudiant à supprimer: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            case 4:
                printf("Entrez l'ID de l'étudiant à afficher: ");
                scanf("%d", &id);
                displayStudentDetails(id);
                break;
            case 5:
                printf("Entrez le département pour calculer la moyenne: ");
                scanf("%s", department);
                calculateDepartmentAverage(department);
                break;
            case 6:
                calculateUniversityAverage();
                break;
            case 7:
                printf("Choisissez une option de statistique:\n");
                printf("1. Afficher les 3 meilleurs étudiants\n");
                printf("2. Afficher les étudiants ayant une note supérieure ou égale à une certaine valeur\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        displayTopStudents();
                        break;
                    case 2:
                        printf("Entrez la note minimale pour afficher les étudiants passant: ");
                        scanf("%d", &passing_grade);
                        displayPassingStudents(passing_grade);
                        break;
                    default:
                        printf("Option invalide.\n");
                }
                break;
            case 8:
                printf("Entrez le nom de l'étudiant à rechercher: ");
                scanf("%s", name);
                searchStudentByName(name);
                break;
            case 9:
                printf("Choisissez un critère de tri:\n");
                printf("1. Par nom\n");
                printf("2. Par note\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        sortStudentsByName();
                        break;
                    case 2:
                        sortStudentsByGrade();
                        break;
                    default:
                        printf("Option invalide.\n");
                }
                break;
            case 10:
                printf("Quitter le programme.\n");
                exit(0);
            default:
                printf("Option invalide.\n");
        }
    }

    return 0;
}