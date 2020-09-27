#include <stdio.h>
#include "Generation_Code.h"
/*
========================================
== Fonction qui fait éxécuter le menu ==
========================================
*/
void Menu(){
    int Selection, Nombre_LED_Choix, Nombres_Milliseconde, Nombres_LED_Affiche_Chenille;

    // On demande le nombre de milliseconde.
    printf("Veuillez saisir le nombre de miliseconde entre chaque affichage : ");

    // On récuperer notre options de temps.
    scanf("%d", &Nombres_Milliseconde);

    // On afficher notre menu.
    printf("Veuillez saisir le mode d'action :\n"
           "1. Battement.\n"
           "2. 1 LED sur 2.\n"
           "3. 1 LED sur 3.\n"
           "4. Chenille.\n"
           "5. Remplissage du coeur de bas en haut.\n"
           "6. Remplissage du coeur en allument progressivement les leds en partants des lat\202ral vers celle du milieu puis les \202teints dans le sens inverse.\n"
           "7. Allume progressivement un c\223t\202 du coeur, l'\202teint puis le fait de l'autre c\223t\202.\n"
           "8. Allume la led qui pr\202c\212de et celle qui suit une led prise al\202atoirement.\n"
           "9. 1 LED specifique (la sp\202cifi\202 a cote.");

    // On récuperer notre options du menu.
    scanf("%d", &Selection);
    switch(Selection){
        case 1:
            Choix("#define TYPE_AFFICHAGE_LED 1", 0, Nombres_Milliseconde, 0);
            break;
        case  2:
            Choix("#define TYPE_AFFICHAGE_LED 2", 0, Nombres_Milliseconde, 0);
            break;
        case  3:
            Choix("#define TYPE_AFFICHAGE_LED 3", 0, Nombres_Milliseconde, 0);
            break;
        case  4:
            printf("Saisir le nobre de LED a afficher :");
            scanf("%d", &Nombres_LED_Affiche_Chenille);
            Choix("#define TYPE_AFFICHAGE_LED 4", 0, Nombres_Milliseconde, Nombres_LED_Affiche_Chenille);
            break;
        case  5:
            Choix("#define TYPE_AFFICHAGE_LED 5", 0, Nombres_Milliseconde, 0);
            break;
        case  6:
            Choix("#define TYPE_AFFICHAGE_LED 6", 0, Nombres_Milliseconde, 0);
            break;
        case  7:
            Choix("#define TYPE_AFFICHAGE_LED 7", 0, Nombres_Milliseconde, 0);
            break;
        case  8:
            Choix("#define TYPE_AFFICHAGE_LED 8", 0, Nombres_Milliseconde, 0);
            break;
        default:
            printf("Quel LED à afficher :");
            scanf("%d", &Nombre_LED_Choix);
            Choix("#define TYPE_AFFICHAGE_LED ", Nombre_LED_Choix, Nombres_Milliseconde, 0);
            break;
    }
}