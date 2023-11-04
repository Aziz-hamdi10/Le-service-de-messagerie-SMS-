

#include <stdlib.h>
#include <stdio.h>
#include "PILEPRIM.h"
#include "ELTPILEPRIM.h"
PILE PileCreer(void) {
PILE P ;
P = (PILE) malloc(sizeof(pilechaine));
if(!P) {
printf(" \nProblème de mémoire") ;}
else P->sommet = 0;
return(P) ; }

void PileDetruire(PILE P){
int i;
for(i = 1; i <= P->sommet; i++)

elementDetruireEpile(P->element[i]);
free(P);
}

void PileAfficher(PILE P){
int i;
if(estvidePile(P))
{        printf("\t    | Pile est vide ! |\n\n");


}
for(i = P->sommet; i >= 1; i--) { printf("\n");
elementAfficherEpile(P->element[i]);}}

int estvidePile(PILE P) {
return (P->sommet == 0) ; }

int EstSatureePile(PILE P) {
return (P->sommet == longMAX); }

int PileTaille(PILE P) {
return (P->sommet); }

int empiler (PILE P, ELEMENT e) {
int succes=1;
if (EstSatureePile(P)){
printf ("\n Pile saturée");
succes=0;}
else
{
(P->sommet)++;
elementAffecterEpile(&P->element[P->sommet],e);}
return(succes);}

ELEMENT Depiler (PILE P ) {
ELEMENT elt = elementCreerEpile();
if (estvidePile(P)) {
printf ("\n Pile vide"); }
else {
elementCopierEpile(&elt, (P->element)[P->sommet]);
elementDetruireEpile(P->element[P->sommet]);
(P->sommet)--;}
return (elt);}

ELEMENT Sommet (PILE P) {
ELEMENT elt= elementCreerEpile();
if (estvidePile(P))
printf (" \n Pile vide");
else
elt = (P->element[P->sommet]);
return(elt) ;}


PILE PileCopier (PILE P){
PILE PR = PileCreer();
int i;
ELEMENT elt;
for(i =1; i <= P->sommet; i++) {
elt=elementCreerEpile();
elementCopierEpile(&elt, P->element[i]);
empiler(PR, elt);
}
return PR;}

int PileComparer (PILE P1, PILE P2 )
{
int test= 1;
int i=P1->sommet;
if (PileTaille(P1)!= PileTaille(P2))
test= 0;
while ((i>=1) && (test)) {
if (elementComparerEpile(P1->element[i], P2->element[i])!=0)
test=0;
i--; }
return test;}

