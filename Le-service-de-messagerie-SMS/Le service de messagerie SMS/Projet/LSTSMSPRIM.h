#ifndef _LSTSMSPRIM_H
#define _LSTSMSPRIM_H
#include "LSTSMSSDD.H"
#include "ELTSMSPRIM.h"
LISTE_SMS listeCreerLsms(void);

void listeDetruireLsms(LISTE_SMS);
int estVideLsms(LISTE_SMS);

int estSatureeLsms(LISTE_SMS);

int listeTailleLsms(LISTE_SMS);

ELEMENT_SMS recupererLsms(LISTE_SMS, int);

int insererLsms(LISTE_SMS, ELEMENT_SMS,int);

int supprimerLsms(LISTE_SMS, int);

void listeAfficherLsms(LISTE_SMS);

LISTE_SMS listeCopierLsms(LISTE_SMS);

int  listeComparerLsms(LISTE_SMS, LISTE_SMS);


#endif // LSTSMSPRIM_H_INCLUDED


