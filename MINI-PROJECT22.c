#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct Contact{
    char nom[20];
    char numero[20];
    char email[50];
    int id;
};

int main() {
   
    struct Contact crt[100]; 
    int countdown = 0;
    char nom[20],num[20],email[50];
while(1) {
    int choi;
    printf("1-Ajouter un Contact: \n");
    printf("2-Modifier un Contact: \n");
    printf("3-Supprimer un Contact: \n");
    printf("4-Afficher Tous les Contacts: \n");
    printf("5-Rechercher un Contact: \n");
    printf("Choisissez l'une des options ci-dessus: ");
    scanf("%d",&choi);

    switch (choi) {
    case 1:
    printf("Entrer votre nom: \n");
    scanf("%s",&nom);
    printf("Entrer votre numéro de téléphone: \n");
    scanf("%s",&num);
    printf("Entrer votre adresse e-mail: \n");
    scanf("%s",&email);
    
    for (int i = 0; i <= countdown; i++) {
         if (strcmp(crt[i].email, email) == 0) {
            printf("\n\nAdresse e-mail deja exist!\n\n");
            sleep(2);
            break;
        }
        if (i == countdown) {
        strcpy(crt[countdown].nom, nom);
        strcpy(crt[countdown].numero, num);
        strcpy(crt[countdown].email, email);
        crt[countdown].id = countdown;
        countdown++;

        printf("\n\nLe contact ajoute avec success!\n\n");
        sleep(2);
        break;
    }
    }
    break;
    case 2:
    printf("Entrer votre nom: ");
    scanf("%s",nom);
    for (int i = 0; i <= countdown; i++) {
         if (strcmp(crt[i].nom, nom) == 0) {
           printf("Entrer votre nouveau nom: \n");
            scanf("%s",&nom);
            printf("Entrer votre nouveau numéro de téléphone: \n");
            scanf("%s",&num);
            printf("Entrer votre nouveau adresse e-mail: \n");
            scanf("%s",&email);
        strcpy(crt[i].nom, nom);
        strcpy(crt[i].numero, num);
        strcpy(crt[i].email, email);
        printf("\nVotre information est mise a jouré avec success!\n");
        sleep(2);
        break;
             }
        if (i == countdown) {
            printf("\nVotre contact n'exist pas\n");
            break;
        }
        }
    break;
    case 3:
    printf("Entrer votre nom: ");
    scanf("%s",nom);
    for (int i = 0; i <= countdown; i++) {
         if (strcmp(crt[i].nom, nom) == 0) {
            strcpy(crt[i].nom, crt[i + 1].nom);
            strcpy(crt[i].numero, crt[i + 1].numero);
            strcpy(crt[i].email, crt[i + 1].email);
            crt[i].id = crt[i + 1].id;
            countdown--;
            printf("\nContact Supprimeé avec success!\n");
         }
         if (i == countdown) {
             printf("\nVotre contact n'exist pas\n");
         }
    }
    break;
    case 4:
    printf("*************************************************************\n");
    printf("*************************************************************\n");
    printf("    ID        NAME          NUMBER           EMAIL\n");
    printf("*************************************************************\n");
    for (int i = 0; i < countdown; i++) {
        printf("    %-10d %-15s %-15s %-30s\n", i, crt[i].nom, crt[i].numero, crt[i].email);
    }
    break;
    case 5:
    printf("Entrer votre nom: ");
    scanf("%s",nom);
    for (int i = 0; i < countdown; i++) {
        if (strcmp(crt[i].nom, nom) == 0) {
            printf("*************************************************************\n");
            printf("*************************************************************\n");
            printf("    ID        NAME          NUMBER           EMAIL\n");
            printf("*************************************************************\n");
            printf("    %-10d %-15s %-15s %-30s\n", i, crt[i].nom, crt[i].numero, crt[i].email);
        break;
         }
         if (i == countdown) {
             printf("\nVotre contact n'exist pas\n");
             break;
         }
    }
    break;
}
}
    return 0;
}