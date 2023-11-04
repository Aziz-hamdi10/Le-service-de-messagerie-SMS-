#ifndef _ELTPILEPRIM_H
#define _ELTPILEPRIM_H
#include "ELTPILESDD.h"
ELEMENT elementCreerEpile(void) ;
void elementLireEpile(ELEMENT*);
void elementDetruireEpile (ELEMENT);
void elementAfficherEpile(ELEMENT);
void elementAffecterEpile(ELEMENT*, ELEMENT);
void elementCopierEpile(ELEMENT *, ELEMENT) ;
int elementComparerEpile(ELEMENT, ELEMENT);
#endif // _ELTPILEPRIM_H

