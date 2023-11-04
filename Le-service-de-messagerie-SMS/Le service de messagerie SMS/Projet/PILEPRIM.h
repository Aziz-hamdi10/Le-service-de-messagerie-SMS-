#ifndef _PILEPRIM_H
#define _PILEPRIM_H
#include "PILESDD.h"
#include "ELTPILEPRIM.h"
PILE PileCreer();
void PileDetruire(PILE);
int estvidePile(PILE);
int EstSatureePile(PILE) ;

int PileTaille(PILE);
ELEMENT Sommet(PILE);
int empiler(PILE,ELEMENT);
ELEMENT Depiler(PILE);
void PileAfficher(PILE);
PILE PileCopier(PILE);
int PileComparer(PILE,PILE);
#endif // _PILEPRIM_H


