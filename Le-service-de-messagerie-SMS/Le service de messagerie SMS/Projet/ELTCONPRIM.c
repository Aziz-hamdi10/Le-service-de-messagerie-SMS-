
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "ELTCONPRIM.h"
int verif(char *ch)
{int i=0,s=1;
while(s && i<strlen(ch))
{ if((ch[0]!='9'&&ch[0]!='4'&&ch[0]!='2'&&ch[0]!='5')||ch[i]<'0'|| ch[i]>'9'|| strlen(ch)!=8)
s=0;
    else
    i++;
}
    return s;
}
int verifnom(char *ch)
{ int i=0,s=1;
   while(i<strlen(ch)&& s)
   {
       if(((ch[i])<'A'|| (ch[i])>'Z')&&((ch[i])>'z'||(ch[i])<'a'))
       {
           s=0;
       }
       i++;
   }
   return s;
}
void copier(char *ch ,char *ch1, int taillemax , int pos)
{
    int i=1,j=0;

    while(i<=taillemax && ch[pos]!='/0')
    {
        ch1[i-1]=ch[pos];
        i++;
        pos++;
    }
    ch1[i]='/0';
}
int position(char ch[100],char c)
{int i=0,s=-1;
while (i<strlen(ch)&&s==-1)
{
if(ch[i]==c ){s=i;}
else i++;
}
return s;
}
int verifemail(char *ch)
{int i=0,s=1;
char *ch1;
if(position(ch,'@')==-1 ||position(ch,'.')==-1 ||position(ch,'@')>position(ch,'.')||position(ch,'.')-position(ch,'@')<3)
   {s=0;}
else
   {
ch1=strstr(ch,"@");
       if((strcmp((ch1),"@hotmail.com")!=0) && (strcmp((ch1),"@gmail.com")!=0) && (strcmp((ch1),"@yahoo.fr")!=0)&& (strcmp((ch1),"@outlook.com")!=0)&&(strcmp((ch1),"@HOTMAIL.COM")!=0) && (strcmp((ch1),"@GMAIL.COM")!=0) && (strcmp((ch1),"@YAHOO.FR")!=0)&& (strcmp((ch1),"@OUTLOOK.COM")!=0))
  s=0; }
    return s;

}
ELEMENT_CONT elementCreerCon()
{
    ELEMENT_CONT e=(ELEMENT_CONT)malloc(sizeof(CONTACT));
    strcpy(e->nom,"");// Initialisation
    strcpy(e->numero,"");
    strcpy(e->email,"");
    return e;
}

void elementLireCon(ELEMENT_CONT *e)
{ char *ch; do {             fflush(stdin);

      printf("Donnez votre nom svp = ",138);
     gets(ch);strcpy((*e)->nom,ch);}while(!verifnom((*e)->nom));
     do
     {


     printf("Donnez votre numero svp = ",138);
     gets((*e)->numero);
     }while(!verif((*e)->numero));
     do
     {


     printf("Donnez votre EMAIL svp = ",138);
     gets((*e)->email);}while(!(verifemail((*e)->email)));

}
void elementAfficherCon(ELEMENT_CONT e)
{
     printf(" nom : %s \n email : %s \n numero : %s \n",e->nom,e->email,e->numero);
}

void elementDetruireCon(ELEMENT_CONT e)
{
     free(e);
}

void elementAffecterCon(ELEMENT_CONT* e1, ELEMENT_CONT e2)
{
     *e1=e2;
}

void elementCopierCon(ELEMENT_CONT * e1, ELEMENT_CONT e2)
{
*(*e1)=*e2;
}

int elementComparerCon(ELEMENT_CONT e1, ELEMENT_CONT e2) // On retourne 1 si les deux r els e1 et e2 sont identiques; 0 sinon
{
 return strcmp(e1->numero,e2->numero);
}

