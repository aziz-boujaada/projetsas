#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESIRVATION 200
#define MAX_NOM_LENGTH 20
#define MAX_PRENOM_LENGTH 20
#define MAX_TELEPHONE_LENGTH 20
#define MAX_AGE_LENGTH 3
#define MAX_STATU_LENGTH 20
#define MAX_ID_LENGTH 10
#define MAX_DATE_LENGTH 10

typedef struct
{

    char Nom[MAX_NOM_LENGTH];
    char Prenom[MAX_PRENOM_LENGTH];
    char Telephone[MAX_TELEPHONE_LENGTH];
    int Age;
    char Date[MAX_DATE_LENGTH];
    char Statu[MAX_STATU_LENGTH];
    int ID;
} Resirvation;

Resirvation resirver[MAX_RESIRVATION];
int nbr_resrvation = 0;

void Ajout_resirvation()
{
    int count_ID = nbr_resrvation;
    int ajout;
    printf("entrer nombre de Resrvation : ");
    scanf("%d", &ajout);
    for (int i = nbr_resrvation; i < nbr_resrvation + ajout; i++)
    {

        getchar();
        printf("Entrer Votre Nom: ");
        scanf(" %[^\n]", resirver[i].Nom);

        printf("Entrer Votre Prenom: ");
        scanf(" %[^\n]", resirver[i].Prenom);

        printf("Entrer Votre Age: ");
        scanf("%d", &resirver[i].Age);

        printf("Entrer Votre Telephone:");
        scanf(" %[^\n]", resirver[i].Telephone);

        printf("Entrer la Date :");
        scanf(" %[^\n]", resirver[i].Date);

        resirver[i].ID = ++count_ID;
        strcpy(resirver[i].Statu, "Valide");
        printf("______________________________________\n");
    }
    nbr_resrvation += ajout;
}

void Modifer_Resirvation()
{
    // modifer
    char recherch[MAX_NOM_LENGTH];
    int found = 0;

    printf("Entrer ID pour MODIFIER:");
    scanf("%s", recherch);

    for (int i = 0; i < nbr_resrvation; i++)
    {

        if (resirver[i].ID, recherch == 0)
        {

            printf("%[^\n]", resirver[i].Nom);
            printf("%[^\n]", resirver[i].Prenom);
            printf("%[^\n]", resirver[i].Age);
            printf("%[^\n]", resirver[i].Telephone);
            printf("%[^\n]", resirver[i].Date);
            printf("%[^\n]", resirver[i].Statu);
            found = 1;
        }
        

        int modifer;
        for (int i = 0; i < nbr_resrvation; i++)
        {

            getchar();
            printf("Entrer Votre Nom: ");
            scanf(" %[^\n]", resirver[i].Nom);

            printf("Entrer Votre Prenom: ");
            scanf(" %[^\n]", resirver[i].Prenom);

            printf("Entrer Votre Age: ");
            scanf("%d", &resirver[i].Age);

            printf("Entrer Votre Telephone:");
            scanf(" %[^\n]", resirver[i].Telephone);

            printf("Entrer la Date :");
            scanf(" %[^\n]", resirver[i].Date);

            for(int j=0 ; j<nbr_resrvation;j++){
                int choix3;
                
        do{
               printf("modifer votre statu\n");
               scanf("%d" , choix3);
                printf("1-reporte\n");
                printf("2-Annulel\n");
                printf("3-TRaite\n");
                printf("________________________\n");

        
        switch(choix3){
        
            case 1 :{
                strcpy(resirver[i].Statu ,"Reporter");
                break;
            }
            case 2 :{
                strcpy(resirver[i].Statu ,"Anulle");
                break;
            }
            case 3 :{
                strcpy(resirver[i].Statu ,"traite");
                break;
            }
        }
        }while(choix3<3);
            }
        }
    }
}

// suppremer
void Supprimer_Resirvation()
{

    char recherch[MAX_NOM_LENGTH];
    int found = 0;

    printf("Entrer ID pour SUPPRIMER:");
    scanf("%s", recherch);

    for (int i = 0; i < nbr_resrvation; i++)
    {

        if (resirver[i].ID, recherch == 0)
        {

            printf("%[^\n]", resirver[i].Nom);
            printf("%[^\n]", resirver[i].Prenom);
            printf("%[^\n]", resirver[i].Age);
            printf("%[^\n]", resirver[i].Telephone);
            printf("%[^\n]", resirver[i].Date);
            printf("%[^\n]", resirver[i].Statu);
            found = 1;
        }
         
           printf("------------Moudifer Et supprimer--------------\n");
         
        for (int j = 0; j < nbr_resrvation - 1; i++)
        {
            (resirver[j].ID, resirver[j + 1].ID);
            strcpy(resirver[j].Nom, resirver[j + 1].Nom);
            strcpy(resirver[j].Prenom, resirver[j + 1].Prenom);
            (resirver[j].Age, resirver[j + 1].Age);
            strcpy(resirver[j].Date, resirver[j + 1].Date);
            strcpy(resirver[j].Statu, resirver[j + 1].Statu);
        }
        nbr_resrvation--;
        printf("Resirvation est Supprimer!\n");
    }
}

void Afficher_Resirvation()
{
    if (nbr_resrvation == 0)
    {
        printf("Pas de Resirvation!!!\n");
    }
    else
    {
        printf("=================RESIRVATION DETAILE ===================\n");
        for (int i = 0; i < nbr_resrvation; i++)
        {
            printf("Reference: %d\n", resirver[i].ID);
            printf("Nom : %s\n", resirver[i].Nom);
            printf("Prenom : %s\n", resirver[i].Prenom);
            printf("Age : %d\n", resirver[i].Age);
            printf("Telephone : %s\n", resirver[i].Telephone);
            printf("statu : %s\n", resirver[i].Statu);
            printf("__________________________________________________\n");
        }
    }
}

void Rechercher_Resrvastion_ID()
{
    int chrcher;
    int found = 0;
    printf("Entrer votre id  ");
    scanf("%d", &chrcher);

    for (int i = 0; i < nbr_resrvation; i++)
    {
        if (resirver[i].ID, chrcher == 0)
        {
            printf("%d" ,resirver[i].ID);
            printf("%[^\n]", resirver[i].Nom);
            printf("%[^\n]", resirver[i].Prenom);
            printf("%d\n", resirver[i].Age);
            printf("%[^\n]", resirver[i].Telephone);
            printf("%[^\n]", resirver[i].Date);
            printf("%[^\n]", resirver[i].Statu);
            found = 1;
        }
    }
}
void Rechercher_Resrvastion_NOM()
{
    char chercher[MAX_NOM_LENGTH];
    int found = 0;
    printf("Entrer voter Nom :");
    scanf("%s", chercher);

    for (int i = 0; i < nbr_resrvation; i++)
    {
        if (strcmp(resirver[i].Nom, chercher) == 0){
        printf("%d", &resirver[i].ID);
        printf("%[^\n]", resirver[i].Nom);
        printf("%[^\n]", resirver[i].Prenom);
        printf("%d\n", resirver[i].Age);
        printf("%[^\n]", resirver[i].Telephone);
        printf("%[^\n]", resirver[i].Date);
        printf("%[^\n]", resirver[i].Statu);
        }
        
        found = 1;
        break;
            

    }
    if(!found)printf("No Reservation Trouver!!");
}

int main()
{

    int choix;
    do
    {
    menu:
        printf("//==============RESIRVATION DENTAIRES//=============\n");
        printf("1-Ajouter Un Resirvation\n");
        printf("2-Modifer ou Supprimer Une Resirvation\n");
        printf("3-Tri des resrvastion");
        printf("4-Afficher votre resirvation Details\n");
        printf("5-Rechercher pour une  Resirvation\n");
        printf("6-Afficher les Statistic dentaires\n");
        printf("7-Quitter!\n");
        printf("Entrer votre Choix :");
        scanf("%d", &choix);
        printf("_________________________________________\n");

        switch (choix)
        {

            //////////////// AJOUTRE RESERVATION ////////////
        case 1:
        {
            Ajout_resirvation();
            break;
        }
            /////////// MODIFER /  SUPREMER ///////////
        case 2:
        {
            int choix1;
            do
            {
                printf("------------Moudifer Et supprimer--------------\n");
                printf("1- Modifer votre detail par ID\n");
                printf("2-Suppremer Resirvation par ID\n");
                printf("3-Routeur a Menu principal\n");
                printf("________________________\n");

                scanf("%d", &choix1);

                switch (choix1)
                {
                case 1:
                {
                    Modifer_Resirvation();
                    
                    break;
                }
                case 2:
                {
                    Supprimer_Resirvation();
                    break;
                }
                case 3:
                {
                    goto menu;
                    break;
                }
                }
                break;
            } while (choix1 < 3);
        }
        //////////////   AFFICHER  /////////////
        case 3:
        {
            Afficher_Resirvation();
            break;
        }
        //////////////  TRI DE RESIRVATION //////////
        case 4:
        {

            break;
        }
        ////////////////// RECHERCHER PAR NOM OU ID //////////////
        case 5:
        {
            int choix2;
            do
            {
                printf("=========RECHERCHER PAR NOM / ID==============\n");
                printf("1-Rechercher par Nom \n");
                printf("2-Rechercher par ID \n");
                printf("1-Routeur a menu Principal \n");

                printf("entrer votre choix : \n");
                scanf("%d", &choix2);
                printf("_______________________\n");

                switch (choix2)
                {
                case 1:
                {
                    Rechercher_Resrvastion_NOM();
                    break;
                }
                case 2:
                {

                    Rechercher_Resrvastion_ID();
                    break;
                }
                }

            } while (choix2 < 3);
            break;

            /////////////////// STATISTIC /////////////////////
        }
        case 6:
        {

            break;
        }
        default:
            printf("choix ivalide");
        }

    } while (choix < 7);
    return 0;
}
