
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "ELTCONPRIM.h"
#include <malloc.h>
#include "LSTCONPRIM.h"
LISTE_CONT listeCreerLcon(void)
{
    LISTE_CONT m=(LISTE_CONT)malloc(sizeof(laStructCONT));
    if(!m)
    {
    printf(" \n pas d'espace");
    }
    else
    { m->tete=NULL;
      m->lg=0;
    }
    return m;

}
void listeAfficherCon(LISTE_CONT lc)
{ int i=1;
    NOEUD_CONT n=noeudCreerLcon(elementCreerCon());
    if(estVideLcon(lc))
    {
printf("\t    |Liste du contact est vides !  |   :\n");
    }
    else
    { n=lc->tete;
        while(n!=NULL)
        { printf("\t  |----------------------------------------------------------------| \n");
          printf("\t \t|      | Contact numero : %i |    | \n",i);

            elementAfficherCon(n->info);
          printf("\t  |----------------------------------------------------------------| \n");
          n=n->suivant;
          i++;
    }
    }
}
LISTE_CONT listeCopierLcon(LISTE_CONT l) {
    LISTE_CONT l2=listeCreerLcon();
int i;
for (i=1;i<=listeTailleLcon(l);i++)
{
    elementCopierCon((recupererLcon(l2,i)),recupererLcon(l,i));
}
l2->lg=l->lg;
}
void listeDetruireLcon(LISTE_CONT m){
    NOEUD_CONT p,q=m->tete;
    while(q!=NULL)
    { p=q;
    q=q->suivant;
    noeudDetruireLcon(p);

    }
    free(m);
}

NOEUD_CONT noeudCreerLcon(ELEMENT_CONT e)
{
NOEUD_CONT n=(NOEUD_CONT)malloc(sizeof(structNoeudCONT));
if(!n){printf("pas de espace");}
else{

    elementAffecterCon(&(n->info),e);
    n->suivant=NULL;
}
return n;
}
void noeudDetruireLcon(NOEUD_CONT e){
elementDetruireCon(e->info);
free(e);
}
int insererLcon(LISTE_CONT m, ELEMENT_CONT e , int pos){ int i,s=1;
NOEUD_CONT n,p,q;
if(estSatureeLcon(m))
{
    printf(" Pas du memoire ! \n") ;
}
if(pos<1 || pos> m->lg+1 )
    {
        printf("position incorrect \n");
        s=0;
    }
    else
    { n=noeudCreerLcon(e);
        if(estVideLcon(m))
         {m->tete=n;
         }
         else
         {
             if(pos==1)
             {
             n->suivant=m->tete;
m->tete = n;
             }
             else
             {

                 q=m->tete;
                 for(i=1;i<pos;i++)
                 { p=q;
                     q=q->suivant;
                 }
                p->suivant=n;
n->suivant=q;

             }
         }
         m->lg++;
    }


    return s;
}
int supprimerLcon (LISTE_CONT m, int pos  ){ int i,s=1;
NOEUD_CONT p,q;
    if(estVideLcon(m))
    {s=0;
    printf("\t liste du contact est vide ! \n");

    }
    else
    { if(pos<1 || pos > m->lg)
    {s=0;
    printf("Position incorrect  ");
    }
    else
    { if(m->lg==1)
    { q=m->tete;
        m->tete=NULL;
    }
    else
    {


        if(pos==1)
        { q=m->tete;
        m->tete=q->suivant;
        }
        else
        { q=m->tete;
        for (i=1;i<pos;i++)
        { p=q;
        q=q->suivant;
        }
        p->suivant=q->suivant;
        }
        }
    }
    noeudDetruireLcon(q);
m->lg--;
    }

    return s;
}
int estSatureeLcon(LISTE_CONT lc){
    NOEUD_CONT n=(NOEUD_CONT)malloc(sizeof(structNoeudCONT));
int s;
if (!n){s=1;}
else
{ free(n);
    s=0;
}
return s;
}
int estVideLcon(LISTE_CONT m){
return m->tete==NULL;}
int listeTailleLcon(LISTE_CONT m){
return m->lg;}

ELEMENT_CONT recupererLcon(LISTE_CONT m, int pos){int i;
NOEUD_CONT q;
ELEMENT_CONT e=elementCreerCon();
if(estVideLcon(m))
{ printf("LISTE est vide ");
}
else {
if(pos<1 ||pos >m->lg)
{
    printf("position incorect ");
}
else
{ q=m->tete;
for(i=1;i<pos;i++)
{ q=q->suivant;
}
elementAffecterCon(&e,q->info);
}
}

return e;
}


