#ifndef _ELTSMSPRIM_H
#define _ELTSMSPRIM_H
#include "ELTSMSSDD.h"
ELEMENT_SMS elementCreersms(void) ;
void elementLiresms(ELEMENT_SMS*);
void elementDetruiresms(ELEMENT_SMS);
void elementAffichersms(ELEMENT_SMS);
void elementAffectersms(ELEMENT_SMS*, ELEMENT_SMS);
void elementCopiersms(ELEMENT_SMS *, ELEMENT_SMS) ;
int elementComparersms(ELEMENT_SMS, ELEMENT_SMS);
#endif


