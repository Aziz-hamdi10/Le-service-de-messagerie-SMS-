#ifndef _LSTCON_H
#define _LSTCON_H
#include "ELTCONPRIM.h"
typedef struct structNoeudCONT
{
ELEMENT_CONT info;
struct structNoeudCONT * suivant;
}
structNoeudCONT, * NOEUD_CONT;
typedef struct
{
NOEUD_CONT tete;
int lg;
}
laStructCONT,*LISTE_CONT;
#endif


