#include "coeur.h"
#include "param.h"

float Frequence_Cardio_Milliseconde, i, a;

void setup(){
  // On définie tous les port digitale de la carte Arduino en sortie
  for(int i = 4; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  i = 0;
  a = 4;
}

void loop(){
  int Minute = 60;
  Frequence_Cardio_Milliseconde = (float)Battement_Frequence/Minute * 1000;
  // On fait appel à la fonction qui Allumera les LEDS selon les paramètres générer par le C.
  switch(TYPE_AFFICHAGE_LED){
    case 1:
    Affichage_LED_Battement(Frequence_Cardio_Milliseconde);
    break;
    case 2:
    i = Affichage_LED_Un_Sur_Deux(i, Frequence_Cardio_Milliseconde);
    break;
    case 3:
    Affichage_LED_Un_Sur_Trois(Frequence_Cardio_Milliseconde);
    break;
    case 4:
    a = Affichage_LED_Chenille(a, Frequence_Cardio_Milliseconde);
    break;
    case 5:
    yingyangled(Frequence_Cardio_Milliseconde);
    case 6:
    leftandrightled(Frequence_Cardio_Milliseconde);
    case 7:
    sidedled(Frequence_Cardio_Milliseconde);
    case 8:
    randomled(Frequence_Cardio_Milliseconde);
    default:
    Affichage_LED_Peronnaliser(TYPE_AFFICHAGE_LED - 50, Frequence_Cardio_Milliseconde);
    break;
  }
}
