#ifndef _LSTCONPRIM_H
#define _LSTCONPRIM_H
#include "LSTCONSDD.h"
void listeDetruireLcon(LISTE_CONT);
NOEUD_CONT noeudCreerLcon(ELEMENT_CONT );
LISTE_CONT listeCreerLcon(void);
void noeudDetruireLcon(NOEUD_CONT);
int insererLcon(LISTE_CONT , ELEMENT_CONT , int );
int supprimerLcon(LISTE_CONT, int  );
int estSatureeLcon(LISTE_CONT);
int estVideLcon(LISTE_CONT);
int listeTailleLcon(LISTE_CONT);
ELEMENT_CONT recupererLcon(LISTE_CONT, int );
void listeAfficherCon(LISTE_CONT);
LISTE_CONT listeCopierLcon(LISTE_CONT ) ;

#endif // LSTCONPRIM_H_INCLUDED


