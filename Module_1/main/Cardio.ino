// Calcule la fréquence cardiaque en battement par minute.
int Battements(float Cardio, unsigned long int Temps, unsigned long Compteur_Coeur, unsigned long Compteur){
  if(Cardio > 2){
    Compteur++;
    if(Compteur == 10){
      Compteur_Coeur += 1;
      float Minute = 6000;
      Frequence_Cardio = (Compteur_Coeur/Temps)*Minute;
    }
  }else{
    Compteur = 0;
  }
}
