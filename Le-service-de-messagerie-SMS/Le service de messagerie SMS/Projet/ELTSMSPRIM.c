#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include "ELTSMSPRIM.h"


ELEMENT_SMS elementCreersms(){
    ELEMENT_SMS e=(ELEMENT_SMS)malloc(sizeof(SMS));
    e->taille=0;
    strcpy(e->texte,"\0");
    return e;}

void elementLiresms(ELEMENT_SMS *e){
     printf("deposez votre SMS ici SVP : ");
     fgets((*e)->texte,1000,stdin);

          (*e)->taille=strlen((*e)->texte)-1;
          }

void elementAffichersms(ELEMENT_SMS e)
{   printf("   %s  | \n",e->texte);
     }

void elementDetruiresms(ELEMENT_SMS e){
 free(e);}

void elementAffectersms(ELEMENT_SMS*e1, ELEMENT_SMS e2){
     *e1=e2;}

void elementCopiersms(ELEMENT_SMS * e1, ELEMENT_SMS e2) {
*(*e1)=*e2;}
int elementComparersms(ELEMENT_SMS e1, ELEMENT_SMS e2){
    if (strcmp(e1->texte,e2->texte)==0)
    return 1;
    else
        return 0;}


