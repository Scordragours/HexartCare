#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Struture.h"

/*
=====================================
== Comptage du nombre de résulstat ==
=====================================
*/
int Nombre_Ligne_Fichier(){
    int Caractere, Nombres;

    // Ouverture du fichier.
    FILE *Fichier = NULL;
    Fichier = fopen("C:\\Users\\lecra\\CLionProjects\\untitled1\\Telecharger.csv", "r");
    if(Fichier == NULL){
        printf("Impossible d'ouvrire le fichier");
        system("exit");
    }

    // Comptage du nombre d'instruction à produire pour stocker toutes les données dans la structure.
    Nombres = 1;
    do{
        if(Caractere == '\n'){
            Nombres++;
        }
    }while((Caractere = fgetc(Fichier)) != EOF);

    // On retourn le nombre de ligne.
    return Nombres;
}

/*
============================================================
== Lit le fichier et retiens le données dans la structure ==
============================================================
*/
void Read_Insertion_Information(Pouls_Information **Poux_Struct){
    int Caractere, i, Nombres;

    // Ouverture du fichier.
    FILE *Fichier = NULL;
    Fichier = fopen("C:\\Users\\lecra\\CLionProjects\\untitled1\\Telecharger.csv", "r");
    if(Fichier == NULL){
        printf("Impossible d'ouvrire le fichier");
        system("exit");
    }

    // Comptage du nombre d'instruction à produire pour stocker toutes les données dans la structure.
    Nombres = Nombre_Ligne_Fichier();

    // Allocation de sufisemant de mémoire pour stocker toutes les données.
    if((*Poux_Struct = (Pouls_Information*) malloc(Nombres * sizeof(Pouls_Information))) == NULL){
        printf("Impossible de lui ajouter de la m\202moire");
        system("exit");
    }

    // Modification de la structure pour qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct;

    // Retour à la position initiale.
    fseek(Fichier, 0, SEEK_SET);

    // Stockage des données dans la structure.
    for(i = 0; i < Nombres; i++){
        fscanf(Fichier, "%d, %ld;", &(Temporaire[i].Pouls), &(Temporaire[i].Date));
    }

    // Fermeture du fichier.
    fclose(Fichier);
}

/*
=======================================================================
== Fonction qui permet d'éhanger la position de deux case entre elle ==
=======================================================================
*/
void Echanger(Pouls_Information **Poux_Struct, int i, int j){
    // On définie la structure de t'elle sorte qu'elle puisse être modifier.
    Pouls_Information *Temporaire = *Poux_Struct, Memoire_Temp;

    // On stocke temporairement la première case.
    Memoire_Temp.Pouls = Temporaire[i].Pouls;
    Memoire_Temp.Date = Temporaire[i].Date;

    // On place la deuxième case dans la prmière.
    Temporaire[i].Pouls = Temporaire[j].Pouls;
    Temporaire[i].Date = Temporaire[j].Date;

    // Puis nous déplacons la case stocker temporairement dans le deuxième case.
    Temporaire[j].Pouls = Memoire_Temp.Pouls;
    Temporaire[j].Date = Memoire_Temp.Date;
}

/*
==========================================================
== Fonction qui transforme le nombre de seconde en date ==
==========================================================
*/
void Transforme_Seconde(long int Seconde){
    int Anne_Transforme, Mois_Transforme, Jours_Transforme, Heure_Transforme, Minute_Transforme, Seconde_Transforme, Bixestille, Minute_Seconde, Heure_Seconde, Journer_Seconde, Annee_Seconde, i;

    // On associe le nombre d'un moi à son noms.
    Mois Mois_Choisir[12] = {{"janvier", 31}, {"f\202vrier", 28}, {"mars", 31}, {"avril", 30}, {"mai", 31}, {"juin", 30}, {"juillet", 31}, {"ao\226t", 31}, {"septembre", 30}, {"octobre", 31}, {"novembre", 30}, {"d\202cembre", 31}};

    // Définition des diférentes base de temps en seconde.
    Minute_Seconde = 60;
    Heure_Seconde = 60*60;
    Journer_Seconde = 24*60*60;
    Annee_Seconde = 365*24*60*60;

    // On transforme les seconde en années et on garde en mémoire si elle est bixestille.
    Anne_Transforme = Seconde / Annee_Seconde;
    Bixestille = Anne_Transforme / 4;

    // On enlève la précédante à seconde.
    Seconde -= ((Anne_Transforme * Annee_Seconde) + (Bixestille * Journer_Seconde));

    // On calcule le nombres de jours sur les seconde restante.
    Jours_Transforme = Seconde / Journer_Seconde;

    // On enlève la précédante à seconde.
    Seconde -= (Jours_Transforme * Journer_Seconde);

    // On calcule le nombres de mois sur les jours restante.
    i = 0;
    while(Mois_Choisir[i].Nombres_Jours < Jours_Transforme){
        i++;
        Jours_Transforme -= Mois_Choisir[i].Nombres_Jours;
    }
    Mois_Transforme = i + 1;

    // On transforme le nombre d'heure dans les seconde restante.
    Heure_Transforme = Seconde / Heure_Seconde;

    // On enlève la précédante à seconde.
    Seconde -= (Heure_Transforme * Heure_Seconde);

    // On transforme le nombre de minutes dans les seconde restante.
    Minute_Transforme = Seconde / Minute_Seconde;

    // On enlève la précédante à seconde.
    Seconde -= (Minute_Transforme * Minute_Seconde);

    Seconde_Transforme = Seconde;

    // On affciher la date complète.
    printf("le %ld %s %ld \205 %ld:%ld:%ld", Jours_Transforme, Mois_Choisir[i].Noms_Mois, Anne_Transforme + 1970, Heure_Transforme + 1 , Minute_Transforme, Seconde_Transforme, Seconde);
}