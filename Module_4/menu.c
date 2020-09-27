#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "actions.h"
#include "Struture.h"

void Menu(Pouls_Information **Poux_Struct, int Nombres){
    /*
     =================================================================
     == On définie la structure pour qu'elle puisse être modifiable ==
     =================================================================
     */
    Pouls_Information *Temporaire = *Poux_Struct;

    /*
     ==========
     == Menu ==
     ==========
     */
    // On définie
    long int Valeur_Menu, Borne_Inferrieur_Temps_Saisie, Borne_Superrieur_Temps_Saisie;

    // On afficher notre menu.
    printf(""
           "1. Afficher les donn\202es dans l'ordre du fichier .CSV.\n"
           "2. Afficher les donn\202es dans un ordre personnalis\202.\n"
           "    21. croissant par rapport au temps.\n"
           "    22. d\202croissant par rapport au temps.\n"
           "    23. d\202croissant par rapport au pouls.\n"
           "    24. d\202croissant par rapport au pouls.\n"
           "3. Rechercher et afficher les donn\202es pour un temps particulier.\n"
           "4. Afficher la moyenne de pouls dans une plage de temps donn\202e.\n"
           "5. Afficher le nombre de lignes de donn\202es actuellement en m\202moire.\n"
           "6. Rechercher et afficher les max/min de pouls (avec le temps associ\202).\n"
           "7. Recher d\'un pouls.\n"
           "8. Quitter l'aplication.\n");
    printf("Quelle est votre choix :");

    // On récuperer notre options du menu.
    scanf("%d", &Valeur_Menu);

    // On traite la valeur récuperer du menu
    switch(Valeur_Menu){
        case 1:
            Afficher_Ficher_CSV(&Temporaire, Nombres);
            break;
        case 21:
            Order_Croissant_Time_Ficher_CSV(&Temporaire, 0, Nombres);
            Afficher_Ficher_CSV(&Temporaire, Nombres);
            break;
        case 22:
            Order_DeCroissant_Time_Ficher_CSV(&Temporaire, 0, Nombres);
            Afficher_Ficher_CSV(&Temporaire, Nombres);
            break;
        case 23:
            Order_Croissant_Pouls_Ficher_CSV(&Temporaire, 0, Nombres);
            Afficher_Ficher_CSV(&Temporaire, Nombres);
            break;
        case 24:
            Order_DeCroissant_Pouls_Ficher_CSV(&Temporaire, 0, Nombres);
            Afficher_Ficher_CSV(&Temporaire, Nombres);
            break;
        case 3:
            printf("Saisissez un temps en seconde :\n");
            scanf("%ld", &Borne_Inferrieur_Temps_Saisie);
            Afficher_Time_Fichier_CSV(&Temporaire, Nombres, Borne_Inferrieur_Temps_Saisie);
            break;
        case 4:
            printf("Saisissez un temps en seconde :\n");
            printf("Entre : ");
            scanf("%ld", &Borne_Inferrieur_Temps_Saisie);
            printf("et : ");
            scanf("%ld", &Borne_Superrieur_Temps_Saisie);
            printf("\n");
            Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV(&Temporaire, Nombres, Borne_Inferrieur_Temps_Saisie, Borne_Superrieur_Temps_Saisie);
            break;
        case 5:
            Afficher_Total_Resultat(Nombres);
            break;
        case 6:
            Afficher_Borne_Externe_Fichier_CSV(&Temporaire, Nombres);
            break;
        case 7:
            printf("Saisissez un pouls :\n");
            scanf("%ld", &Borne_Inferrieur_Temps_Saisie);
            Recher_Dicotomique(&Temporaire, Borne_Inferrieur_Temps_Saisie, 0, Nombres);
            break;
        default:
            system("exit");
            break;
    }
    Menu(Poux_Struct, Nombres);
}