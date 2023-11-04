
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LSTSMSPRIM.h"
LISTE_SMS listeCreerLsms()
{ LISTE_SMS l=(LISTE_SMS)malloc(sizeof(laStructSMS));
 l->lg=0;
return l;
}
void listeDetruireLsms(LISTE_SMS l){
int i;
for (i=1;i<=l->lg;i++)
    elementDetruiresms(l->elements[i]);
    free(l);
}
int estVideLsms(LISTE_SMS l)
{
return l->lg==0;
}
int listeTailleLsms(LISTE_SMS l){
return l->lg;}
int estsature(LISTE_SMS l)
{
    return l->lg==LongMax;
}
int insererLsms(LISTE_SMS l, ELEMENT_SMS e, int pos)
{ int i;
    if(pos <0 || pos>l->lg+1 ||estsature(l))
    {
        printf("\t  |position incorrect");
        return 0;
    }
    else
    { (l->lg)++;

        for (i=l->lg-1;i>=pos;i--)
    elementAffectersms(&(l->elements[i+1]),l->elements[i]);
    }
elementAffectersms(&(l->elements[pos]),e);
return 1;
    }

ELEMENT_SMS recupererLsms(LISTE_SMS l, int pos){
    return l->elements[pos]; }

int supprimerLsms(LISTE_SMS l,int pos)
    { int i;
if(estVideLsms(l)){
    printf("LISTE vide") ; return 0;}
else if(pos < 1 ||pos >l->lg) {
    printf("\t \t |position incorrect ");
    return 0; }
else { for (i=pos;i<listeTailleLsms(l);i++)
   elementAffectersms(&l->elements[i],l->elements[i+1]);
(l->lg)--;
return 1;
}
    }
void listeAfficherLsms(LISTE_SMS l) {
int i;
if(estVideLsms(l))
{
    printf(" \n \t \t|liste est vide \n");
}
else
{
printf("\n \t  |");

for(i=1;i<=listeTailleLsms(l);i++)
{
    elementAffichersms(l->elements[i]);
}
}
}
LISTE_SMS listeCopierLsms(LISTE_SMS l) {
    LISTE_SMS l2=listeCreerLsms();
int i;
for (i=1;i<=listeTailleLsms(l);i++)
{
    elementCopiersms(&l2->elements[i],l2->elements[i]);
}
l2->lg=l->lg;
return l2;
}
int  listeComparerLsms(LISTE_SMS l, LISTE_SMS l2){ int i=1,t=1;
    if(l->lg != l2->lg)
    {
        return 0;
    }
    else
    { while (i<=listeTailleLsms(l)&& t)
    {
        if (elementComparersms(l->elements[i],l2->elements[i])==0)
            i++;
        else
            t=0;
    }
return t;
    }

}

