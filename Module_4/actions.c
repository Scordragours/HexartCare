#include "Struture.h"
#include "donnes.h"
#include <stdlib.h>
#include <stdio.h>

/*
=================================================
== Fonction qui permet d'afficher la structure ==
=================================================
*/
void Afficher_Ficher_CSV(Pouls_Information **Poux_Struct, long int Nombres){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On afficher toutes les valeurs de la structure.
    int i;
    for(i = 0; i < Nombres; i++){
        printf(" pouls %d \n", Temporaire[i].Pouls);
        Transforme_Seconde(Temporaire[i].Date);
    }

    // On attend que l'utilisateur confirme pour pouvoir passer a la suite.
    system("pause");
    printf("\n\n");
}


/*
====================================================
== Fonction qui permet de traiter selon les dates ==
====================================================
*/
int Partition_Order_Croissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On définit le compteur sur la première valeur.
    long int Compteur, Pivot, i;
    Compteur = Debut;

    // On définie le pivot sur la première valeur.
    Pivot = Temporaire[Debut].Date;

    // On teste les valeur tans que le pivot inféireur à la valeur tester elle n'est pas échanger et inversement.
    for(i = Debut + 1; i <= Fin - 1; i++){
        if(Temporaire[i].Date < Pivot){
            Compteur++;
            Echanger(&Temporaire, Compteur, i);
        }
    }
    Echanger(&Temporaire, Compteur, Debut);

    // On retourne la valeur de la borne une.
    return Compteur;
}
/*
=====================================
== Fonction qui divise les données ==
=====================================
*/
void Order_Croissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    if(Debut < Fin){
        // On défini le nouveau pivot.
        int Pivot = Partition_Order_Croissant_Time_Ficher_CSV(&Temporaire, Debut, Fin);

        // On divise le tableau de structure en deux.
        Order_Croissant_Time_Ficher_CSV(&Temporaire, Debut, Pivot);
        Order_Croissant_Time_Ficher_CSV(&Temporaire, Pivot + 1, Fin);
    }
}


/*
====================================================
== Fonction qui permet de traiter selon les dates ==
====================================================
*/
int Partition_Order_DeCroissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On définit le compteur sur la première valeur.
    int Compteur, Pivot, i;
    Compteur = Debut;

    // On définie le pivot sur la première valeur.
    Pivot = Temporaire[Debut].Date;

    // On teste les valeur tans que le pivot inféireur à la valeur tester elle n'est pas échanger et inversement.
    for(i = Debut + 1; i <= Fin - 1; i++){
        if(Temporaire[i].Date > Pivot){
            Compteur++;
            Echanger(&Temporaire, Compteur, i);
        }
    }
    Echanger(&Temporaire, Compteur, Debut);

    // On retourne la valeur de la borne une.
    return Compteur;
}
/*
=====================================
== Fonction qui divise les données ==
=====================================
*/
void Order_DeCroissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    if(Debut < Fin){
        // On défini le nouveau pivot.
        int Pivot = Partition_Order_DeCroissant_Time_Ficher_CSV(&Temporaire, Debut, Fin);

        // On divise le tableau de structure en deux.
        Order_DeCroissant_Time_Ficher_CSV(&Temporaire, Debut, Pivot);
        Order_DeCroissant_Time_Ficher_CSV(&Temporaire, Pivot + 1, Fin);
    }
}


/*
====================================================
== Fonction qui permet de traiter selon les pouls ==
====================================================
*/
int Partition_Order_Croissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On définit le compteur sur la première valeur.
    int Compteur, Pivot, i;
    Compteur = Debut;

    // On définie le pivot sur la première valeur.
    Pivot = Temporaire[Debut].Pouls;

    // On teste les valeur tans que le pivot inféireur à la valeur tester elle n'est pas échanger et inversement.
    for(i = Debut + 1; i <= Fin - 1; i++){
        if(Temporaire[i].Pouls < Pivot){
            Compteur++;
            Echanger(&Temporaire, Compteur, i);
        }
    }
    Echanger(&Temporaire, Compteur, Debut);

    // On retourne la valeur de la borne une.
    return Compteur;
}
/*
=====================================
== Fonction qui divise les données ==
=====================================
*/
void Order_Croissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    if(Debut < Fin){
        // On défini le nouveau pivot.
        int Pivot = Partition_Order_Croissant_Pouls_Ficher_CSV(&Temporaire, Debut, Fin);

        // On divise le tableau de structure en deux.
        Order_Croissant_Pouls_Ficher_CSV(&Temporaire, Debut, Pivot);
        Order_Croissant_Pouls_Ficher_CSV(&Temporaire, Pivot + 1, Fin);
    }
}


/*
====================================================
== Fonction qui permet de traiter selon les pouls ==
====================================================
*/
int Partition_Order_DeCroissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On définit le compteur sur la première valeur.
    int Compteur, Pivot, i;
    Compteur = Debut;

    // On définie le pivot sur la première valeur.
    Pivot = Temporaire[Debut].Pouls;

    // On teste les valeur tans que le pivot inféireur à la valeur tester elle n'est pas échanger et inversement.
    for(i = Debut + 1; i <= Fin - 1; i++){
        if(Temporaire[i].Pouls > Pivot){
            Compteur++;
            Echanger(&Temporaire, Compteur, i);
        }
    }
    Echanger(&Temporaire, Compteur, Debut);

    // On retourne la valeur de la borne une.
    return Compteur;
}
/*
=====================================
== Fonction qui divise les données ==
=====================================
*/
void Order_DeCroissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    if(Debut < Fin){
        // On défini le nouveau pivot.
        int Pivot = Partition_Order_DeCroissant_Pouls_Ficher_CSV(&Temporaire, Debut, Fin);

        // On divise le tableau de structure en deux.
        Order_DeCroissant_Pouls_Ficher_CSV(&Temporaire, Debut, Pivot);
        Order_DeCroissant_Pouls_Ficher_CSV(&Temporaire, Pivot + 1, Fin);
    }
}


/*
==================================================
== Fonction qui afficher le pouls selon un temp ==
==================================================
*/
void Afficher_Time_Fichier_CSV(Pouls_Information **Poux_Struct, int Nombres,  long int Temp_Afficher){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On afficher tous les données du tableaux de structure qui sont égaux aux temps données.
    for(int j = 0; j < Nombres; ++j){
        if(Temporaire[j].Date == Temp_Afficher){
            printf("pouls %d ", Temporaire[j].Pouls);
            // On change le nombres de seconde en date.
            Transforme_Seconde(Temporaire[j].Date);
            printf("\n\n");
        }
    }
}


/*
=========================================================
== Fonction qui calcule la moyene de la plage de temps ==
=========================================================
*/
void Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV_Traitement(Pouls_Information **Poux_Struct, int Debut, int Nombres, long int Borne_Inferrieur_Temps_Saisie, long int Borne_Superrieur_Temps_Saisie){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;
    Nombres--;
    long int i, Calcule;
    float Moyenne;

    // On réduit le tableau de
    if(Temporaire[Debut].Date < Borne_Inferrieur_Temps_Saisie){
        Debut++;
    }
    if(Temporaire[Nombres].Date > Borne_Superrieur_Temps_Saisie){
        Nombres--;
    }

    Calcule = 0;

    // On teste si les valeurs si elle sont égale au bornes.
    if((Temporaire[Debut].Date == Borne_Inferrieur_Temps_Saisie)&&(Temporaire[Nombres].Date == Borne_Superrieur_Temps_Saisie)){
        // On additionne toutes les valeurs entre les bornes temporelle.
        for(i = Debut; i <= Nombres; i++){
            Calcule += Temporaire[i].Pouls;
        }

        // On divise toutes les vaaleurs entre les bornes temporrelle par le nombre de valeurs.
        Moyenne = Calcule/(Nombres-Debut+1);

        // Offiche la moyenne entre les bornes;
        printf("La moyen du poux entre ");
        // On change le nombres de seconde en date.
        Transforme_Seconde(Borne_Inferrieur_Temps_Saisie);
        printf(" et ");
        // On change le nombres de seconde en date.
        Transforme_Seconde(Borne_Superrieur_Temps_Saisie);
        printf(" est %f \n\n", Moyenne);

    }else{

        // On appelle la fonction ou nous nous situons de façons récursive pour pouvoir diminuer la plage de données et don ce raprocher des bornes temporelle.
        Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV_Traitement(&Temporaire, Debut, Nombres, Borne_Inferrieur_Temps_Saisie, Borne_Superrieur_Temps_Saisie);
    }
}
/*
=========================================================================
== Fonction qui prépare le tableau de structure pour calculer la moyen ==
=========================================================================
*/
void Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV(Pouls_Information **Poux_Struct, int Nombres, long int Borne_Inferrieur_Temps_Saisie, long int Borne_Superrieur_Temps_Saisie){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On met dans l'ordre les valeurs du tableau de structure.
    Order_Croissant_Time_Ficher_CSV(&Temporaire, 0, Nombres);

    // On appelle la fonction qui vas calculer la moyen des pouls entre les bornes temporelle..
    Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV_Traitement(&Temporaire, 0, Nombres, Borne_Inferrieur_Temps_Saisie, Borne_Superrieur_Temps_Saisie);
}


/*
=====================================================================================
== Fonction qui afficher le nombre de données stocker dans le tableau de structure ==
=====================================================================================
*/
void  Afficher_Total_Resultat(int Nombres){
    // On afficher le nombres de données contenus dans le tableau de structre.
    printf("il y a un totale de %d informations sauvegarder \n\n", Nombres);
}

/*
===================================
== Fonction qui cherche un pouls ==
===================================
*/
void Recher_Dicotomique(Pouls_Information **Poux_Struct, int Pouls, int Debut, int Nombres){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On met dans l'ordre les valeurs du tableau de structure.
    Order_Croissant_Pouls_Ficher_CSV(&Temporaire, 0, Nombres);

    // On divise la borner externe.
    int Nombres_Borne_Dicotomique;
    Nombres_Borne_Dicotomique = Nombres / 2;

    // On teste voir si le pouls au millieux est inféieur pour savoir si nous devons recommence ou s'arreter a la borne du millieu.
    if(Temporaire[Nombres_Borne_Dicotomique].Pouls < Pouls){
        Recher_Dicotomique(&Temporaire, Pouls, Nombres_Borne_Dicotomique, Nombres);
    }else if(Temporaire[Nombres_Borne_Dicotomique].Pouls == Pouls){
        Afficher_Ficher_CSV(&Temporaire, 1);
    }else{
        Recher_Dicotomique(&Temporaire, Pouls, Nombres, Nombres_Borne_Dicotomique);
    }
}

/*
================================================================
== Fonction qui afficher le plus grand et le plus petit pouls ==
================================================================
*/
void Afficher_Borne_Externe_Fichier_CSV(Pouls_Information **Poux_Struct, int Nombres){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // On met dans l'ordre les valeurs du tableau de structure.
    Order_Croissant_Pouls_Ficher_CSV(&Temporaire, 0, Nombres);

    // On afficher la première et la dernière valeur de pouls de notre tableau de structure.
    printf("le minimume est %d et le minimum est %d \n\n", Temporaire[0].Pouls, Temporaire[Nombres-1].Pouls);
}