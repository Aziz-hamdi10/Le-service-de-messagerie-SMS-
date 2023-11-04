#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ELTMSGPRIM.h"
int taille (char ch[10000])
{ char *c1="@£$¥èéùÇØøÅåΔ_ΦΓΛΩΠΨΣΘΞ^{}[~]|€ÆæßÉ!#¤%&'()*+,./0123456789¡ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÑÜ§¿abcdefghijklmnopqrstuvwxyzäöñüà ";
    int s=0,i=0;
    while (i<strlen(ch))
    { if(position(c1,ch[i])==-1|| ch[i]=='"')
    s=s+2;
    else
        s=s+1;
        i++;
    }
    return s;
}
int simple(char *ch)
{ int i=0,t=1;

char c1[200]="@£$¥èéùÇØøÅåΔ_ΦΓΛΩΠΨΣΘΞ^{}[~]|€ÆæßÉ!#¤%&'()*+,./0123456789¡ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÑÜ§¿abcdefghijklmnopqrstuvwxyzäöñüà ";
while (t&&i<strlen(ch))
{ if(position(c1,ch[i])==-1)

t=-1;
 i++;
}
return t;
}
ELEMENT_MSG elementCreermsg() {
    ELEMENT_MSG m=(ELEMENT_MSG)malloc(sizeof(MESSAGE));
strcpy(m->recpeteur,"");
m->prix=0.0;
m->msg=listeCreerLsms();
m->date_envoi.annee=0;
m->date_envoi.mois=0;
m->date_envoi.jour=0;
m->heure_envoi.heure=0;
m->heure_envoi.minute=0;
m->heure_envoi.seconde=0;
return m;
}
void elementLiremsg(ELEMENT_MSG *e)
{printf("taper le receptuer svp");
gets((*e)->recpeteur);
}
void elementDetruiremsg (ELEMENT_MSG m)
{
listeDetruireLsms(m->msg);
free(m);
}
void elementAffichermsg(ELEMENT_MSG m)
{ printf("\t \t    |le recepteur : %s |",m->recpeteur);
    listeAfficherLsms(m->msg);
 printf("\n \t     |prix total = %f  \n \t |    date %i / %i / %i a %i : %i : %i \n",m->prix,m->date_envoi.jour,m->date_envoi.mois,m->date_envoi.annee,m->heure_envoi.heure,m->heure_envoi.minute,m->heure_envoi.seconde);

}
void elementAffectermsg(ELEMENT_MSG* m1, ELEMENT_MSG m2)
{ *m1=m2;}

void elementCopiermsg(ELEMENT_MSG *m1, ELEMENT_MSG m2)
{ *(*m1)=*m2;}

int elementComparermsg(ELEMENT_MSG m1, ELEMENT_MSG m2)
{
return strcmp(m1->recpeteur,m2->recpeteur);
}



