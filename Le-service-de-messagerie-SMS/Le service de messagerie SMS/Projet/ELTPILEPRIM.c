
#include <stdlib.H>
#include <stdio.h>
#include <string.h>
#include "ELTPILEPRIM.h"

#include <malloc.h>
ELEMENT elementCreerEpile()
{ ELEMENT e=(ELEMENT)malloc(sizeof(chaine));
strcpy(e->nom,"");
return e;
}
void elementLireEpile(ELEMENT* e)
{ printf("taper le chaine svp");
gets((*e)->nom);
}
void elementDetruireEpile (ELEMENT e)
{free(e);

}
void elementAfficherEpile(ELEMENT e)
{
    printf("%s",e->nom);
}
void elementAffecterEpile(ELEMENT* e, ELEMENT e2){ *e=e2;
}

void elementCopierEpile(ELEMENT *e, ELEMENT e2)
{
*(*e)=*e2;
}
int elementComparerEpile(ELEMENT e1 , ELEMENT e2)
{
    return strcmp(e1->nom,e2->nom);

}
