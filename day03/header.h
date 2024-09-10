// header.h

#ifndef HEADER_H
#define HEADER_H

#define MAX_NOMBRE 100
#define MAX_NOM 50
#define MAX_EMAIL 100
#define MAX_NUMERO 20

typedef struct {
    char nom[MAX_NOM];
    char numero[MAX_NUMERO];
    char e_mail[MAX_EMAIL];
} Contact;

extern Contact stock[MAX_NOMBRE];
extern int nombre_contact;

void Ajouter_un_Contact();
void Modifier_un_Contact();
void Supprimer_un_Contact();
void Afficher_Tous_les_Contacts();
void Rechercher_un_Contact();

#endif // HEADER_H
