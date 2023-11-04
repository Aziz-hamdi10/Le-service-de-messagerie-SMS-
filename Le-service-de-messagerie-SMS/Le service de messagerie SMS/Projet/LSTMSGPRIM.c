
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LSTMSGPRIM.h"
LISTE_MSG listeCreerLmsg()
{
        LISTE_MSG m=(LISTE_MSG)malloc(sizeof(laStructMSG));
    if(!m)
    {
    printf(" \n pas d'espace");
    }
    else
    { m->tete=NULL;
      m->queue=NULL;
      m->lg=0;
    }
    return m;

}
void listeDetruireLmsg(LISTE_MSG m){
    int i;
    NOEUD_MSG p,q=m->tete;
    while(q!=NULL)
    { p=q;
    q=q->suivant;
    noeudDetruireLmsg(p);

    }
    free(m);
}
NOEUD_MSG noeudCreerLmsg(ELEMENT_MSG e)
{
NOEUD_MSG n=(NOEUD_MSG)malloc(sizeof(structNoeudMSG));
if(!n){printf("pas de espace");}
else{
    elementAffectermsg(&(n->info),e);
    n->suivant=NULL;
    n->precedent=NULL;

return n;}
}
void noeudDetruireLmsg(NOEUD_MSG e){
elementDetruiremsg(e->info);
free(e);
}
int insererLmsg(LISTE_MSG m, ELEMENT_MSG e , int pos){ int i,s=1;
NOEUD_MSG n,p,q;

    { if(pos<1 || pos> m->lg+1 )
    {
        printf("position incorrect");
        s=0;
    }
    else
    { n=noeudCreerLmsg(e);
        if(m->lg==0)
         {m->tete=n;
          m->queue=n;
         }
         else
         {
             if(pos==1)
             { m->tete->precedent=n;
             n->suivant=m->tete;
             m->tete=n;

             }
             else
             { if(pos==m->lg+1)
             { m->queue->suivant=n;
             n->precedent=m->queue;
             m->queue=n;

             }
             else
             {
                 q=m->tete;
                 for(i=1;i<pos;i++)
                 { p=q;
                     q=q->suivant;
                 }
                 p->suivant=n;
                 q->precedent=n;
                 n->precedent=p;
                 n->suivant=q;
             }

             }
         }
         m->lg++;
    }

    }
    return s;
}
int supprimerLmsg (LISTE_MSG m, int pos  ){ int i,s=1;
NOEUD_MSG p,q;
    if(estVideLmsg(m))
    {s=0;
    printf("liste d%cja vide ",130);

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
        m->queue=NULL;
    }
    else
    {


        if(pos==1)
        { q=m->tete;
        m->tete=q->suivant;
        m->tete->precedent=NULL;
        }
        else
        { if(pos=m->lg)
        {q=m->queue;
m->queue=m->queue->precedent;
m->queue->suivant=NULL;
        }
        else
        { q=m->tete;
        for (i=1;i<pos;i++)
        { p=q;
        q=q->suivant;
        }
        p->suivant=q->suivant;
        q->suivant->precedent=p;
        }
        }
    }
    noeudDetruireLmsg(q);
m->lg--;
    }
    }
    return s;
}
int estSatureeLmsg(LISTE_MSG m){
    ELEMENT_MSG e=elementCreermsg();
NOEUD_MSG n=noeudCreerLmsg(e);
if (!n){return 1;}
else
{ noeudDetruireLmsg(n);
    return 1;
}
}
int estVideLmsg(LISTE_MSG m){
return m->tete==NULL;}
int listeTailleLmsg(LISTE_MSG m){
return m->lg;}
ELEMENT_MSG recupererLmsg(LISTE_MSG m, int pos){int i;
NOEUD_MSG q;
ELEMENT_MSG e=elementCreermsg();
if(estVideLmsg(m))
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
elementAffectermsg(&e,q->info);
}
}

return e;
}
void listeAfficherLmsg(LISTE_MSG lm){ int i=0;
NOEUD_MSG m=noeudCreerLmsg(elementCreermsg());
if(estVideLmsg(lm))
{
    printf(" \t Aucun message ! \n");
}
else
{ m=lm->tete; i++;
while(m!=NULL)
{
{   printf("\t \t  |      n: %i    | \t \n",i);

    printf("\t   |-------------------------------------|  \n");
    elementAffichermsg(m->info);
    m=m->suivant;
    i++;
    }
}
}}




