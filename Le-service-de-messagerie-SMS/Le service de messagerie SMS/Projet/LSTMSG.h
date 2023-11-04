#ifndef _LSTMSG_H
#define _LSTMSG_H
#include "ELTMSGPRIM.h"
typedef struct structNoeudMSG
{
ELEMENT_MSG info;
struct structNoeudMSG * suivant;
struct structNoeudMSG * precedent;
}
structNoeudMSG, * NOEUD_MSG;
typedef struct
{
NOEUD_MSG tete;
NOEUD_MSG queue;
int lg;
}
laStructMSG,*LISTE_MSG;
#endif


