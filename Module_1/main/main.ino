#include "coeur.h"
#include "param.h"
#include "Cardio.h"

float Temps = 0, Compteur_Coeur = 0, Compteur = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  float Cardio = analogRead(A0);
  Temps = millis();

  int Battement_Frequence = Battements(Cardio,Temps, Compteur_Coeur, Compteur);
  Serial.print(Battement_Frequence);
  Serial.println(", ");
}
