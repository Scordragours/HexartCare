#include "param.h"

/*
==========================================
== Fonction qui afficher toutes les LED ==
==========================================
*/
void Affichage_LED_Battement(int Milliseconde){

  // On déclare toutes les LED sur allumée.
  for(int i = 4; i <= 13; i++){
    digitalWrite(i, HIGH);
  }

  // On laisse un delai qui est définie par le C.
  delay(Milliseconde);

  // On déclare toues les LED sur éteint. 
  for(int i = 4; i <= 13; i++){
    digitalWrite(i, LOW);
  }

  // On laisse un delai qui est définie par le C.
  delay(Milliseconde);

  // On refait appele à la fonction récursivement.
  // Affichage_LED_Battement();
}

/*
=====================================
== Fonction qui afficher 1 / 2 LED ==
=====================================
*/
int Affichage_LED_Un_Sur_Deux(int a, int Milliseconde){

  // Pour toutes les LED nous alumons 1 / 2 LED
  for(int i = 4; i <= 13; i++){
    digitalWrite(i, HIGH);
    // On teste boir si La LED n'est pas un multiple de 2.
    if((a == 1)&& !(i % 2)){
      digitalWrite(i, LOW);
    }else if((a == 0)&&(i % 2)){
      digitalWrite(i, LOW);
    }
  }

  // On laisse un delai qui est définie par le C.
  delay(Milliseconde);

  // Puis on appele l'inverse de ce que nous avons fait pour pouvoir alterne les 1 / 2 LED.
  if(a == 1){
    //Affichage_LED_Un_Sur_Deux(0);
    return 0;
  }else{
    //Affichage_LED_Un_Sur_Deux(1);
    return 1;
  }
}

/*
=====================================
== Fonction qui afficher 1 / 3 LED ==
=====================================
*/
void Affichage_LED_Un_Sur_Trois(int Milliseconde){
  int i;
  
  // Nous allumons un LED puis nous éteignons le deux autre, puis nous répétons cette action atant de fois que nous pouvons.
  while(i <= 13){
    digitalWrite(i, HIGH);
    digitalWrite(i+1, LOW);
    digitalWrite(i+2, LOW);
    i += 3;
  }

  // On laisse un delai qui est définie par le C.
  delay(Milliseconde);
  
  for(int i = 4; i < 14; i++){
      digitalWrite(i, LOW);
    }
  // On refait appele à la fonction.
  //Affichage_LED_Un_Sur_Trois();
}

/*
========================================================
== Fonction qui afficher en forme de chenille les LED ==
========================================================
*/
int Affichage_LED_Chenille(int i, int Milliseconde){
  // On allume la LED.
  digitalWrite(i, HIGH);

  // Si la LED est le numero 1 alors on éteins toutes les LED.
  if(i == 4){
    for(int i = 0; i < 14; i++){
      digitalWrite(i, LOW);
    }
    // On allume la LED 4.
    digitalWrite(i, HIGH);

    // On laisse un delai qui est définie par le C.
    delay(Milliseconde);

    return i+1;
    // On fait appele à la fonction avec i + 1
    //Affichage_LED_Chenille(i+1);
  }else if(i == 13){
    // On étteins la led de NOMBRES_LED_AFFICHER avant la LED que l'on a allumé.
    digitalWrite(i - NOMBRES_LED_AFFICHER, LOW);

    // On laisse un delai qui est définie par le C.
    delay(Milliseconde);

    return 4;
    // On réinitialiser le compteur.
    //Affichage_LED_Chenille(4);
  }else{
    // On étteins la led de NOMBRES_LED_AFFICHER avant la LED que l'on a allumé.
    digitalWrite(i - NOMBRES_LED_AFFICHER, LOW);

     // On laisse un delai qui est définie par le C.
    delay(Milliseconde);

    return i+1;
    // On fait appele à la fonction avec i + 1
    //Affichage_LED_Chenille(i+1);
  }
}

/*
==========================================
== Fonction qui affiche une LED précise ==
==========================================
*/
void Affichage_LED_Peronnaliser(int Led, int Milliseconde){
  // Affichage de la LED spécifique.
  digitalWrite(Led + 3, HIGH);
  delay(Milliseconde);
  digitalWrite(Led + 3, LOW);
  delay(Milliseconde);
}

// Fonction permettant d'illuminer le coeur de bas en haut comme s'il se remplissait
void remplissagecoeur(int Milliseconde){
  int i; //initialisation des variables locales
  int y;
  
  digitalWrite(4, HIGH); // allume la led branché au pin 4
  
  delay(Milliseconde); // attente
  
  for (i=5,y=13;i<9,y>9;i++,y--){   // allume les leds ligne par ligne en partant de la seconde ligne
    digitalWrite(i,HIGH); 
    digitalWrite(y, HIGH);
    delay(Milliseconde); // attente
  }
  
  digitalWrite(9, HIGH);  // allume la led branché au pin 9
  
  delay(Milliseconde); // attente
  
  for (i=4; i<14; i++){     // éteint toutes les leds 
    digitalWrite(i, LOW);
  }
  
  delay(Milliseconde); // attente 
  
}

// Fonction qui allume les leds deux par deux de manière symmétrique par rapport au centre du coeur
void yingyangled(int Milliseconde){  
  int i; //initialisation des variables locales
  
  for (i=4; i<9; i++){ // allume la led i et la 5eme led qui la suit
    digitalWrite(i, HIGH);
    digitalWrite(i+5, HIGH);
    delay(Milliseconde);
  }
  
  for (i=4; i<9; i++){ // eteint la led i et la 5eme led qui la suit
    digitalWrite(i, LOW);
    digitalWrite(i+5, LOW);
    delay(Milliseconde);
    }
    
}

// Fonction qui allume progressivement les leds en partants de celles latéral vers celle du milieu puis les éteints dans le sens inverse
void leftandrightled(int Milliseconde){
  int i; //initialisation des variables locales
  int y;
  
  for (i=6,y=11; i<8,y<13; i++,y++){ // allume les leds 6, 7, 11 et 12
    digitalWrite(i, HIGH);
    digitalWrite(y, HIGH);
  }  
  
  delay(Milliseconde); // attente 
  
  for (i=5,y=13; i<6,y<14; i++,y++){ // allume les leds 5, 8, 10 et 13
    digitalWrite(i, HIGH);
    digitalWrite(i+3, HIGH);
    digitalWrite(y, HIGH);
    digitalWrite(y-3, HIGH);
  }
  
  delay(Milliseconde); // attente 
  
  for (i=4; i<5; i++){  // allume les leds 4 et 9
    digitalWrite(i, HIGH);
    digitalWrite(i+5, HIGH);
  }
  
  delay(Milliseconde); // attente 
  
  for (i=4; i<5; i++){ // éteint les leds 4 et 9
    digitalWrite(i, LOW);
    digitalWrite(i+5, LOW);
  }
  
  delay(Milliseconde); // attente 
  
  for (i=5,y=13; i<6,y<14; i++,y++){ // éteint les leds 5,8,10 et 13
    digitalWrite(i, LOW);
    digitalWrite(i+3, LOW);
    digitalWrite(y, LOW);
    digitalWrite(y-3, LOW);
  }
  
  delay(Milliseconde);
  
  for (i=6,y=11; i<8,y<13; i++,y++){ // éteint les leds 6,7,11 et 12
    digitalWrite(i, LOW);
    digitalWrite(y, LOW);
  }  
  
  delay(Milliseconde); // attente 
  
}

// allume progressivement un côté du coeur, l'éteint puis le fait de l'autre côté
void sidedled(int Milliseconde){
  int i; //initialisation des variables locales
  int y;
  
  for (i=4; i<10; i++){   // allume les leds 4 à 9
    digitalWrite(i, HIGH);
    delay(Milliseconde);
  }
  
  for (i=4; i<10; i++){ // éteint les leds 4 à 9
    digitalWrite(i, LOW);
  }
  
  delay(Milliseconde); // attente d'une demi-seconde
  
  digitalWrite(4, HIGH); // allume la led 4
  
  for (i=14; i>8; i--){ //allume les leds 13 à 9 
    digitalWrite(i, HIGH);
    delay(Milliseconde);
  }
  
  delay(Milliseconde); // attente 
  
  for (i=9; i<14; i++){ // éteint les leds 13 à 9
    digitalWrite(i, LOW);
  }
  
  digitalWrite(4, LOW); // éteint la led 4

  delay(Milliseconde); // attente 
}

// Fonction qui allume la led qui précède et celle qui suit une led prise aléatoirement
void randomled(int Milliseconde){
  int i; //initialisation des variables locales
  
  i = random(4,14); // i prends une valeur aléatoire dans l'intervalle [4;14[
  
  int y = i; // y prends la valeur de i
  
  if (i==4){ // si i est égal à 4, on lui donne la valeur 14
    i=14;
  }
  
  digitalWrite(i-1, HIGH); // on allume la led précedant la led i

  if (i==13){ // si i est égal à 13, on lui donne la valeur 3
    y=3;
  }
  
  digitalWrite(y+1, HIGH); // on allume la led suivant la led y  
  
  delay(Milliseconde); // attente 
  
  if (i==4){ // si i est égal à 4, on lui donne la valeur 14
    i=14;
  }
  
  digitalWrite(i-1, LOW); // on éteint la led précedant la led i
  
  if(i==13){ // si i est égal à 13, on lui donne la valeur 3
    y=3;
  }
  
  digitalWrite(y+1, LOW); // on éteint la led suivant la led y  
}
