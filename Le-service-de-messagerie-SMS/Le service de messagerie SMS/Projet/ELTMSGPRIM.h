#ifndef _ELTMSGPRIM_H
#define _ELTMSGPRIM_H
#include "ELTMSGSDD.h"
ELEMENT_MSG elementCreermsg(void) ;
void elementLiremsg(ELEMENT_MSG*);
void elementDetruiremsg (ELEMENT_MSG);
void elementAffichermsg(ELEMENT_MSG);
void elementAffectermsg(ELEMENT_MSG*, ELEMENT_MSG);
void elementCopiermsg(ELEMENT_MSG *, ELEMENT_MSG) ;
int elementComparermsg(ELEMENT_MSG, ELEMENT_MSG);
#endif // ELTMSGPRIM_H_INCLUDED


