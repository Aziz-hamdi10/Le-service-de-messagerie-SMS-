#ifndef _ELTCONPRIM_H
#define _ELTCONPRIM_H
#include "ELTCONSDD.h"
int verifemail(char *);
int verifnom(char *);
int position(char *,char );
void copier(char *,char *, int, int);
ELEMENT_CONT elementCreerCon(void) ;
void elementLireCon(ELEMENT_CONT*);
void elementDetruireCon (ELEMENT_CONT);
void elementAfficherCon(ELEMENT_CONT);
void elementAffecterCon(ELEMENT_CONT*, ELEMENT_CONT);
void elementCopierCon(ELEMENT_CONT *, ELEMENT_CONT) ;
int elementComparerCon(ELEMENT_CONT, ELEMENT_CONT);
#endif // ELTCONPRIM_H_INCLUDED


