#ifndef UNTITLED1_ACTIONS_H
#define UNTITLED1_ACTIONS_H

#include "Struture.h"

void Afficher_Ficher_CSV(Pouls_Information **Poux_Struct, long int Nombres);
int Partition_Order_Croissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin);
void Order_Croissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin);
int Partition_Order_DeCroissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin);
void Order_DeCroissant_Time_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin);
int Partition_Order_Croissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin);
void Order_Croissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin);
int Partition_Order_DeCroissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, int Debut, int Fin);
void Order_DeCroissant_Pouls_Ficher_CSV(Pouls_Information **Poux_Struct, long int Debut, long int Fin);
void Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV_Traitement(Pouls_Information **Poux_Struct, int Debut, int Nombres, long int Borne_Inferrieur_Temps_Saisie, long int Borne_Superrieur_Temps_Saisie);
void Afficher_Time_Fichier_CSV(Pouls_Information **Poux_Struct, int Nombres, long int Temp_Afficher);
void Afficher_Moyen_Pouls_Plage_Time_Fichier_CSV(Pouls_Information **Poux_Struct, int  Nombres, long int Borne_Inferrieur_Temps_Saisie, long int Borne_Superrieur_Temps_Saisie);
void  Afficher_Total_Resultat(int Nombres);
void Recher_Dicotomique(Pouls_Information **Poux_Struct, int Pouls, int Debut, int Nombres);
void Afficher_Borne_Externe_Fichier_CSV(Pouls_Information **Poux_Struct, int Nombres);
#endif
