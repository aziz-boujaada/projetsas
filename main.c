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

    int ID;
    char Nom[MAX_NOM_LENGTH];
    char Prenom[MAX_PRENOM_LENGTH];
    char Telephone[MAX_TELEPHONE_LENGTH];
    int Age;
    char Statu[MAX_STATU_LENGTH];
    char Date[MAX_DATE_LENGTH];
} Resirvation;




 Resirvation resirver[MAX_RESIRVATION] = {

    {1, "Ahmed", "El Mansouri", "0601234567", 30, "Valide", "2024-09-12"},
     {2, "Fatima", "Zahra", "0612345678", 25, "Valide", "2024-09-05"},
    {3, "Youssef", "Bouzid", "0623456789", 22, "Valide", "2024-09-14"},
     {4, "Amina", "El Fassi", "0634567890", 28, "reporte", "2024-09-19"},
    {5, "Omar", "Benali", "0645678901", 27, "Valide", "2024-09-08"},
     {6, "Leila", "Amari", "0656789012", 32, "Valide", "2024-09-02"},
     {7, "Samir", "Bouchareb", "0667890123", 21, "Valide", "2024-09-10"},
   {8, "Salma", "Ouardani", "0678901234", 26, "annule", "2024-09-11"},
    {9, "Khalid", "El Idrissi", "0689012345", 29, "traite", "2024-09-22"},
    {10, "Hana", "Jbari", "0690123456", 24, "Valide", "2024-09-17"}
 };

 

int nbr_resrvation = 10;

// AFFICHER
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
            printf("date : %s\n", resirver[i].Date);
            printf("\n__________________________________________________\n");
        }
    }
}

// AJOUTER
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

// MODIFER ET SUPPRIMER
void Modifer_Resirvation()
{
    // modifer
    int recherch;
    int found = 0;

    printf("Entrer ID pour MODIFIER:");
    scanf("%d", &recherch);
    int i;

    for (i = 0; i < nbr_resrvation; i++)
    {

        if (resirver[i].ID == recherch)
        {

            printf("\n========================\n");
            printf("%s\n", resirver[i].Nom);
            printf("%s\n", resirver[i].Prenom);
            printf("%d\n", resirver[i].Age);
            printf("%s\n", resirver[i].Telephone);
            printf("%s\n", resirver[i].Date);
            printf("%s\n", resirver[i].Statu);
            printf("\n========================\n");

            found = 1;
            break;
        }
    }

    if (found == 1)
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

        int choix3;
        printf("__Modifercation statu____\n");
        printf("1-Valide\n");
        printf("2-Anulle\n");
        printf("3-Reporte\n");
        printf("4-Traite\n");
        scanf("%d", &choix3);
        switch (choix3)
        {
        case 1:
        {
            strcpy(resirver[i].Statu, "valide");
            break;
        }
        case 2:
        {
            strcpy(resirver[i].Statu, "Anulle");
            break;
        }
        case 3:
        {
            strcpy(resirver[i].Statu, "Reporte");
            break;
        }
        case 4:
        {
            strcpy(resirver[i].Statu, "Traite");
            break;
        }
        default:
            printf("Choix invalaide!");
            break;
        }
    }

    Afficher_Resirvation();
}

// suppremer
void Supprimer_Resirvation()
{

    int recherch;
    int found = 0;

    printf("Entrer ID pour SUPPRIMER:");
    scanf("%d", &recherch);

    // search to delet :
    for (int i = 0; i < nbr_resrvation; i++)
    {

        if (recherch == resirver[i].ID)
        {

            printf("\n========================\n");
            printf("%s\n", resirver[i].Nom);
            printf("%s\n", resirver[i].Prenom);
            printf("%d\n", resirver[i].Age);
            printf("%s\n", resirver[i].Telephone);
            printf("%s\n", resirver[i].Date);
            printf("%s\n", resirver[i].Statu);
            printf("\n========================\n");
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        for (int j = 0; j < nbr_resrvation - 1; j++)
        {
            resirver[j] = resirver[j + 1];
        }

        nbr_resrvation--;
        printf("Resirvation est Supprimer!\n");
    }
    if (found != 1)
    {
        printf("ID pas utiliser\n");
        return;
    }
}

// RECHZRCHER
void Rechercher_Resrvastion_ID()
{
    int chrcher;
    int found = 0;
    printf("Entrer votre id  ");
    scanf("%d", &chrcher);

    for (int i = 0; i < nbr_resrvation; i++)
    {
        if (chrcher == resirver[i].ID)
        {
            printf("----Resirvation trouver----\n");
            printf("\n========================\n");
            printf("%d\n", resirver[i].ID);
            printf("%s\n", resirver[i].Nom);
            printf("%s\n", resirver[i].Prenom);
            printf("%d\n", resirver[i].Age);
            printf("%s\n", resirver[i].Telephone);
            printf("%s\n", resirver[i].Date);
            printf("%s\n", resirver[i].Statu);
            printf("\n========================\n");
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        printf("No Resirvation Trouver");
    }
}

void Rechercher_Resrvastion_NOM()
{
    char chercher[MAX_NOM_LENGTH];
    int found = 0;
    printf("Entrer voter Nom :");
    scanf("%[^\n]", chercher);

    for (int i = 0; i < nbr_resrvation; i++)
    {
        if (strcmp(resirver[i].Nom, chercher) == 0)
        {
            printf("-----resirvation TRouver-----\n");
            printf("\n========================\n");
            printf("%d\n", &resirver[i].ID);
            printf("%s\n", resirver[i].Nom);
            printf("%s\n", resirver[i].Prenom);
            printf("%d\n", resirver[i].Age);
            printf("%s\n", resirver[i].Telephone);
            printf("%s\n", resirver[i].Date);
            printf("%s\n", resirver[i].Statu);
            printf("\n========================\n");
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        printf("No Reservation Trouver!!");
    }
}

// STATISTIC

void StatisticMoyenage()
{

    int somme = 0;
    for (int i = 0; i < nbr_resrvation; i++)
    {
        somme = somme + resirver[i].Age;
    }

    int moyen;

    moyen = somme / nbr_resrvation;

    printf("le moyen des age est :%d\n", moyen);
}

void StatisticGeniration()
{
    int Geniration1 = 0, Geniration2 = 0, Geniration3 = 0;

    for (int i = 0; i < nbr_resrvation; i++)
    {
        if (resirver[i].Age <= 18)
        {
            Geniration1++;
        }
        else if (resirver[i].Age > 18 && resirver[i].Age <= 35)
        {
            Geniration2++;
        }
        else if (resirver[i].Age > 35)
        {
            Geniration3++;
        }
    }

    printf("Geniration entre 1 ans et 18 ans :%d\n", Geniration1);
    printf("Geniration entre 19 ans et 35 ans :%d\n", Geniration2);
    printf("Geniration supiriuer de 36 ans  :%d\n", Geniration3);
}

void StatisticStatus()
{

    int Valide = 0, Anulle = 0, Reporte = 0, Traite = 0;

    for (int i = 0; i < nbr_resrvation; i++)
    {
        if (strcasecmp(resirver[i].Statu, "Valide") == 0)
        {
            Valide++;
        }
        else if (strcasecmp(resirver[i].Statu, "Anulle") == 0)
        {
            Anulle++;
        }
        else if (strcasecmp(resirver[i].Statu, "Reorte") == 0)
        {
            Reporte++;
        }
        else if (strcasecmp(resirver[i].Statu, "Traite") == 0)
        {
            Traite++;
        }
    }

    printf("nombre de resirvation  valide est : %d\n", Valide);
    printf("nombre de resirvation  Anulle est : %d\n", Anulle);
    printf("nombre de resirvation  Reporte est : %d\n", Reporte);
    printf("nombre de resirvation  Traite est : %d\n", Traite);
}

void StatisticResrvation()
{
    int choix_static;
    printf("=======++STATISTIC DE RESIRVATION++=======\n");
    printf("1-Moyen age des malade  \n");
    printf("2-les Geniratino \n ");
    printf("3- statu \n");
    printf("0-Ruteur a menu principal \n");

    printf("Entrer votre hcoix :  \n ", choix_static);
    scanf("%d", &choix_static);
    printf("_______________________________________\n");
    switch (choix_static)
    {
        case 1:
        {
            StatisticMoyenage();
            break;
        }
        case 2:
        {
            StatisticGeniration();
            break;
        }
        case 3:
        {
            StatisticStatus();
            break;
        }
    }
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
            system("cls");
            Ajout_resirvation();
            break;
        }
            /////////// MODIFER /  SUPREMER ///////////
        case 2:
        {
            int choix1;
            do
            {
                system("cls");
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
                    system("cls");
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
            system("cls");
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
                printf("3-Routeur a menu Principal \n");

                printf("entrer votre choix : \n");
                scanf("%d", &choix2);
                printf("_______________________\n");

                switch (choix2)
                {
                case 1:
                {
                    system("cls");
                    Rechercher_Resrvastion_NOM();
                    break;
                }
                case 2:
                {
                    system("cls");
                    Rechercher_Resrvastion_ID();
                    break;
                }
                case 3:
                {
                    goto menu;
                    break;
                }
                }

            } while (choix2 < 3);
            break;

            /////////////////// STATISTIC /////////////////////
        }
        case 6:
        {
            StatisticResrvation();
            break;
        }
        default:
            printf("choix ivalide");
        }

    } while (choix < 7);
    return 0;
}
