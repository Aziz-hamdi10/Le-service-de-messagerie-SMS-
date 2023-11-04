#ifndef _LSTMSGPRIM_H
#define _LSTMSGPRIM_H
#include "LSTMSGSDD.h"
LISTE_MSG listeCreerLmsg(void);
void listeDetruireLmsg(LISTE_MSG);
NOEUD_MSG noeudCreerLmsg(ELEMENT_MSG );
void noeudDetruireLmsg(NOEUD_MSG);
int insererLmsg(LISTE_MSG , ELEMENT_MSG , int );
int supprimerLmsg(LISTE_MSG, int  );
int estSatureeLmsg(LISTE_MSG);
int estVideLmsg(LISTE_MSG);
int listeTailleLmsg(LISTE_MSG);
ELEMENT_MSG recupererLmsg(LISTE_MSG, int );
void listeAfficherLmsg(LISTE_MSG);
#endif // LSTMSGPRIM_H_INCLUDED


