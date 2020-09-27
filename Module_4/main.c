#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "donnes.h"
#include "actions.h"

/*
===================================================================
== Fonction diriger les données vers les fonctions de traitement ==
===================================================================
 */
void main(){
    int Nombres;
    Nombres = Nombre_Ligne_Fichier();
    Pouls_Information *Poux_Struct;
    Read_Insertion_Information(&Poux_Struct);
    Menu(&Poux_Struct, Nombres);
}