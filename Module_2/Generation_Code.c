#include <stdio.h>

/*
===========================================
== Fonction que éxécute le choix du menu ==
===========================================
*/
void Choix(char Define_Arduino[20], int Nombres_Choix, int Milliseconde, int Nombres_LED_Affiche_Chenille){

    // Ouverture du fichier.
    FILE *Fichier = NULL;
    Fichier = fopen("C:\\Users\\lecra\\Desktop\\Projet_Module_2\\main\\Param.h", "w");
    if(Fichier == NULL){
        printf("Impossible");
    }

    // On écrit dans le fichier le choix de l'affichage des LED.
    if(Nombres_Choix == 0){
        fprintf(Fichier, "%s", Define_Arduino);
    }else{
        fprintf(Fichier, "%s%d \n", Define_Arduino, Nombres_Choix);
    }

    // On écrit dans le fichier le nombre de milliseconde voulue.
    fprintf(Fichier, "\n#define MILLISECONDE %d", Milliseconde);

    // On écrit dans le fichier le nombre de LED pour la chenille.
    if(Nombres_LED_Affiche_Chenille == 0){
        fprintf(Fichier, "\n#define NOMBRES_LED_AFFICHER 0");
    }else{
        fprintf(Fichier, "\n#define NOMBRES_LED_AFFICHER %d", Nombres_LED_Affiche_Chenille);
    }
}
