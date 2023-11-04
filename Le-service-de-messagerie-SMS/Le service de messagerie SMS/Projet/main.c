#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LSTMSGPRIM.h"
#include "LSTSMSPRIM.h"
#include <time.h>
#include "ELTCONPRIM.h"
#include "LSTCONPRIM.h"
#include "PILEPRIM.h"
#include "ELTMSGPRIM.h"
#include "ELTSMS.h"
#include <locale.h>
#include <conio.h>

////1111
CONTACT lePlusContacte(LISTE_MSG L1, LISTE_CONT L2)
{ ELEMENT_CONT e;
NOEUD_CONT nc=L2->tete;
NOEUD_MSG q;
int i,max=0;
while(nc!=NULL){ q=L1->tete; i=0;
    while(q!=NULL)
    { if(strcmp(nc->info->numero,q->info->recpeteur)==0)
    {
        i++;
    }
    q=q->suivant;
    }
    if(i>max){elementAffecterCon(&e,nc->info); max =i;}
    nc=nc->suivant;
}

return *e;
}

LISTE_MSG messages_D1_D2(LISTE_MSG l, DATE D1, DATE D2){
LISTE_MSG m=listeCreerLmsg();
NOEUD_MSG n;
if(estVideLmsg(l))
{
    printf("Liste est vide");
}
else
{n=l->tete;
while(n!=NULL)
{
    if(datecomparer(n->info->date_envoi,D1)>=0&& datecomparer(D2,n->info->date_envoi)<=0)
insererLmsg(m,n->info,m->lg+1);

n=n->suivant;
}}

return m;
}
ELEMENT_MSG messageLePlusLong(LISTE_MSG lm)
{ ELEMENT_MSG e= elementCreermsg();
NOEUD_MSG n=lm->tete;
int o,j,i,max=0;
char c1="@ £ $ ¥ è é ù ì ò Ç Ø ø Å å Δ _ Φ Γ Λ Ω Π Ψ Σ Θ Ξ ^ { } [ ~ ] | € Æ æ ß É !  # ¤ % & ' ( ) * + , . / 01 2 3 4 5 6 7 8 9 : ; < = > ? ¡ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Ä Ö Ñ Ü § ¿ a bc d e f g h i j k l m n o p q r s t u v w x y z ä ö ñ ü à";

if(estVideLmsg(lm)){printf("Liste est vide ");}
else
{ o=0;
    while(n!=NULL)
    { o=0;
    for(i=1;i<=n->info->msg->lg;i++)
        o=o+taille(n->info->msg->elements[i]->texte);

if(o>max){max=o;
elementCopiermsg(&e,n->info);}
    n=n->suivant;}

}
return e;
}
LISTE_CONT jamaisContactes(LISTE_MSG L1, LISTE_CONT L2)
{
LISTE_CONT c=listeCreerLcon();
NOEUD_MSG nm;
NOEUD_CONT nc;
int t=1;

{if(estVideLmsg(L1))
    { printf("\t    |Liste du messages est vides !  |   :\n");
        return L2;
    }
    else
    { nc=L2->tete;
    while(nc!=NULL)
    { nm=L1->tete;
    t=0;
    while(nm!=NULL&&!t)
    { if(strcmp(nm->info->recpeteur,nc->info->numero)==0){
    t=1;}
        nm=nm->suivant;
    }
    if(!t)
    {
    insererLcon(c,nc->info,c->lg+1);
    }
        nc=nc->suivant;
    }
    return c;

    }
}
}
int datecomparer(DATE d, DATE d1)
{int s;
if(d.annee>d1.annee){s=1;}
else if(d.annee<d1.annee){s=-1;}
else if(d.mois<d1.mois){s=-1;}
    else if(d.mois>d1.mois){s=1;}
    else if(d.jour>d1.jour){s=1;}
    else if(d.jour <d1.jour){s=-1;}
    else s=0;
return s;}
LISTE_SMS compteur(char * ch )
{ char std[200]="@£$¥èéùÇØøÅåΔ_ΦΓΛΩΠΨΣΘΞ^{}[~]|€ÆæßÉ!#¤%&'()*+,./0123456789¡ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÑÜ§¿abcdefghijklmnopqrstuvwxyzäöñüà ";
int j=0,i=0,n=0,max=taillemax(ch);
ELEMENT_SMS e=elementCreersms();
LISTE_SMS s=listeCreerLsms();
n=taille(ch)/taillemax(ch);
if(taille(ch)%taillemax(ch)>0)n++;
j=0;
for(i=0;i<n;i++)
{j=0;
 copier(ch,e->texte,taillemax(ch),j);
    j=j+taillemax(ch);
insererLsms(s,e,i+1);
}
return s;
}
void time1(DATE *d1 ,HEURE *h)
{  int hr, min, s, day, mois, an;
  time_t now;
    DATE d;
  // Renvoie l'heure actuelle
  time(&now);
  // Convertir au format heure locale
  struct tm *local = localtime(&now);
  hr = local->tm_hour;
  min = local->tm_min;
  s = local->tm_sec;
  day = local->tm_mday;
  mois = local->tm_mon + 1;
  an = local->tm_year + 1900;
  (*d1).jour=day;
  (*d1).mois=mois;
  (*d1).annee=an;
  (*h).minute=min;
    (*h).seconde=s;
      (*h).heure=hr;
}
void transform2(FILE *f,LISTE_CONT lc)
{int i=1;
int x; char ch[70],ch1[70],ch2[30],ch3[70];
ELEMENT_CONT e1,e2,e=elementCreerCon();
NOEUD_CONT q=lc->tete;
i=1;
while(fscanf(f,"%s %s %s ",&e->nom,&e->email,&e->numero)!=EOF)
{
insererLcon(lc,e,i);
i++;e=elementCreerCon();
        }
}
void transform(FILE *f,LISTE_MSG lm)
{int j,a,h,m,t=0,i=1;
float p;
NOEUD_MSG q=lm->tete;
char ch2[100],msg[100];
strcpy(msg,"");
ELEMENT_MSG e=elementCreermsg();
while(fscanf(f,"%s %i %i %i %i %i %i %f %s",&e->recpeteur,&e->date_envoi.jour,&e->date_envoi.mois,&e->date_envoi.annee,&e->heure_envoi.heure,&e->heure_envoi.minute,&e->heure_envoi.seconde,&e->prix,&ch2)!=EOF ){
for(j=0;j<strlen(ch2);j++)
{
if(ch2[j]==',')
        msg[j]=' ';
    else
        msg[j]=ch2[j];}
e->msg=compteur(msg);
   while(q!=NULL&&!t)
    {if(datecomparer(q->info->date_envoi,e->date_envoi)<=0)
    {t=1;}
        else {q=q->suivant;i++;}
    }
                insererLmsg(lm,e,i);
e=elementCreermsg();
}
}
void transform1(LISTE_MSG lm,FILE *f)
{
NOEUD_MSG n=lm->tete;
if(estVideLmsg(lm))
{
    printf("liste est vide \n");
}
while(n!=NULL)
{
fprintf(f,"%s %s %s %s %s %s",n->info->recpeteur,n->info->msg,n->info->prix,n->info->date_envoi.jour,n->info->date_envoi.mois,n->info->date_envoi.annee,n->info->heure_envoi);
n=n->suivant;
}
}

void transform3(LISTE_CONT lc,FILE *f)
{

NOEUD_CONT n=lc->tete;
if(estVideLcon(lc)){printf("liste est vide ");}
else
{
    n=lc->tete;

while(n!=NULL)
{
fprintf(f,"%s %s %s",n->info->nom,n->info->numero,n->info->email);
n=n->suivant;} printf("\n\t \t|      |       enregister !      |    | \n");

}
}
int taillemax(char ch[10000])
{ int taillemax;
 if(simple(ch)==-1){taillemax=70;}
else
 {taillemax=160 ;}
if(taille(ch)>taillemax)
{if(simple(ch)==1)
taillemax=153;
else
    taillemax=67;
}
return taillemax;
}


int validheure(char *ch)
{ int s =1,i;
char *ch1;
    if(strlen(ch)!=8)
    {
      s=0;
    }
    else
    { i=0;
        while(i<strlen(ch))
        { copier(ch,ch1,2,i);
            if(strcmp(ch1,"24")>0 || strcmp(ch1,"00")<0||ch[i+2]!=":")
            {
                s=0;
            }
            else i=i+3;
        }
    }
    return s;
}


int exist(ELEMENT_CONT e,LISTE_CONT lc)
{ int s=0;
NOEUD_CONT n=lc->tete;
while(!s&&n!=NULL)
{
    if(elementComparerCon(e,n->info)==0)
        s=1;
    else
        n=n->suivant;
}
return s;
}
int purger(LISTE_SMS l ,char m1[100][100], int k)
{ int i,s=k ;
int j=0;
char ch[100];
strcpy(ch,"");
for(i=1;i<=l->lg;i++){ strcat(ch,l->elements[i]->texte) ;
}
for(i=0;i<strlen(ch);i++){
 if(ch[i]!=' '){ m1[s][j]=ch[i];j++;}else{s++;
 j=0;}}
return s;
}

void supprimermat(char m[100][100],char ch[100] ,int k,int o)
{
 int i,j=0,l;
 while(o>0&&j<k)
 { if(strcmp(m[j],ch)==0)
 { for(i=j;i<k;i++)
    strcpy(m[i],m[i+1]);
    k--;o--;
 }
 j++;
}
}
PILE bigrammes(LISTE_MSG L, int M)
 {   NOEUD_MSG n,q;
    PILE p=PileCreer() ;
    ;
    char m[100][100],m1[100][100];
    ELEMENT e;
    int pos,o,i,j,max, k=0,l;
    if(estVideLmsg(L))printf("liste est vide");
        else
    { n=L->tete;
    while(n!=NULL)
        {k=purger(n->info->msg,m,k);
         n=n->suivant;k++;
        }
   for(i=0,j=0;i<k-1;j++,i+=2)
   {strcpy(m1[j],strcat(strcat(m[i]," "),m[i+1]));} k=k/2+k%2;l=0;
       while(l<M&&l<k)
        {
          for(i=0;i<k;i++)
        { o=1;
            for(j=0;j<k;j++)
                if(strcmp(m1[i],m1[j])==0)
            {
o++;
            }

            if(max<o){max=o;pos=i;}
        }
        printf("%i",pos);
        e=elementCreerEpile();
        strcpy(e->nom,m1[pos]);
        empiler(p,e);
   supprimermat(m1,e->nom,k,max);
    k-=o;
    l++;
    max=0;
    }
   }
return p ;
}
PILE unigrammes(LISTE_MSG L, int M){
    NOEUD_MSG n=noeudCreerLmsg(elementCreermsg());
    PILE p=PileCreer() ;
    ;
    char m[100][100];
    ELEMENT e;
    int o,i,j,max=0,pos,l,k=0;
    if(estVideLmsg(L))printf("liste est vide");
        else
    {
        n=L->tete;
    while(n!=NULL)
        {

            k=purger(n->info->msg,m,k);
         n=n->suivant;k++;
         } l=0;
         while(l<M&&l<k)
        {
          for(i=0;i<k;i++)
        { o=1;
            for(j=0;j<k;j++)
                if(strcmp(m[i],m[j])==0)
            {o++;}
            if(max<o){max=o;pos=i;}
        }
        e=elementCreerEpile();
        strcpy(e->nom,m[pos]);
        empiler(p,e);
   supprimermat(m,e->nom,k,max);
    k-=o;
    l++;
    max=0;
    }
    return p;
}}
int menu(LISTE_CONT lc,LISTE_MSG lm,LISTE_MSG lb)//liste msg liste cont
{ DATE d,d1,d2;
HEURE h;

time1(&d,&h);
ELEMENT_CONT ecc=elementCreerCon();
ELEMENT_MSG e1,e=elementCreermsg();
int x,j,a,m; ELEMENT_MSG em=elementCreermsg();
    char recepteur[9],*ch;
    char msg[10000];
LISTE_SMS ls;
ELEMENT_CONT ec;
  int i,n;
  system("COLOR 0");
printf("\t \t|      |      Bienvenue !      |    | \n");
printf("\t    | 1- pour %ccrire un message \t        |\n",130);
printf("\t    | 2- pour acc%cder à la liste du contact   |\n ",130);
printf("\t    | 3- pour acc%cder à la liste du messages  |\n",130);
printf("\t    | 4- pour acc%cder a la liste du brouillon  | \n ",130);
printf("\t    | 5- pour afficher le message le plus long  |\n",130);

printf("\t    | 6- pour quitter !  | \n ");

do {
printf("\t    |Quel est votre choix? taper 1, 2,3 ,4 ou 5  \n\n");
  scanf("%d", &i);} while(i <1 || i >6);

  printf("\n");
  switch (i)
  {
    case 1: system("COLOR 2");
do {
printf(" \n \n \n \t|      | num%cro selection : | \n",130);
printf("\t    |taper 1 : si vous selection un num%cro du contact|   :\n",130);
printf("\t    |taper 2 : si vous taper un num%cro:\t\t   |\n",130);
printf("\t    |taper 3 pour revenir au menu                   |\n ");
printf("\t    |taper 4 pour quitter             |\n ");
scanf("%i",&i);}while (i<1 || i> 4) ;
switch(i)
{
    case 1 : listeAfficherCon(lc); do {printf("\t \t|      | taper votre choix svp : | \n");scanf("%i",&i);}
    while (i<1  || i> lc->lg); strcpy(recepteur,(recupererLcon(lc,i))->numero);
break;
case 2 :
    do {
            fflush(stdin);
printf("\t    |taper le num%cro svp : | \n ",130);
fgets(recepteur,9,stdin);
}while (!verif(recepteur));
case 3: menu(lc,lm,lb);
default:printf("\t    | A BIENTOT ! |\n\n");exit(1);
}

  do {do{ printf("\t    | recepteur : %s|\n   ",recepteur);

printf("\t    | 1- Taper votre msg svp \t        |\n");
            fflush(stdin);

fgets(msg,10000,stdin);
msg[strlen(msg)-1]='\0';
ls=compteur(msg);
n=taille(msg)/taillemax(msg);
if(taille(msg)%taillemax(msg)>0)n++;}while(n>8);
printf("\t    | message :  %s |   ",msg);
printf("\t `\t \t\t   |(%i)| \n",n);
printf("\t \t \t \t \t \t \t  ~~~~~~~~\n");
printf("\t \t \t \t \t \t \t ||%i/%i| \n",taillemax(msg)-taille(msg)%taillemax(msg),taillemax(msg)*ls->lg);
printf("\t \t \t \t \t \t \t  ~~~~~~~~\n");
printf("\t    | taper 1 pour envoyer        |\n");
printf("\t    | taper 2 pour r%ccrire le msg  |\n ",130);
printf("\t    | taper 3 pour revenir au menu |\n");
printf("\t    | taper 4 pour quitter         |\n");
do { printf("\t    | Quelle est votre choix? taper 1, 2, 3 ou 4 : |\n\n");
        scanf("%i", &i);}while (i<1 || i >4);
  } while(i==2);


       switch(i){

        case 1:
          {
                strcpy(e->recpeteur,recepteur);
               e->msg=ls;
                e->date_envoi=d;
                e->heure_envoi=h;
                e->prix=n*0.5;
                insererLmsg(lm,e,lm->lg+1);
                printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||                Votre message a %ct%c envoy%c !                         ||\n",130,130,130);
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n");
                menu(lc,lm,lb);
            }
        case 3:
        strcpy(e->recpeteur,recepteur);
               e->msg=ls;
                e->date_envoi=d;
                e->heure_envoi=h;
                e->prix=n*0.5;
                insererLmsg(lb,e,lb->lg+1);
                printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||              enregistrer dans la brouillon !                   ||\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n");
                menu(lc,lm,lb);
            break;        default:printf("\t    | A BIENTOT ! |\n\n");exit(1);
       }
       break;
    case 2:   system("COLOR 1");
 listeAfficherCon(lc);
        do {
        printf("\t    |taper 1 pour envoyer un msg pour un contact         | \n");
        printf("\t    |taper 2 pour Ajouter un contact                     |\n");
        printf("\t    |taper 3 pour supprimer un contact                   |\n ");
        printf("\t    |taper 4 pour afficher les contacts jamais contacter |\n");
        printf("\t    |taper 5 pour afficher le contact plus contacter |  \n");
        printf("\t    |taper 6 pour revenir au menu                   |\n ");
        printf("\t    |taper 7 pour quitter                                |\n");
        printf("\t    |Quel est votre choix? taper 1, 2, 3, 4 , 5 ou 6         |\n\n");
        scanf("%d", &i);}while(i<1 || i>7);
       switch(i){
        case 1: listeAfficherCon(lc);
            do {
            printf("\t    |Contact num%cro ° : | \n",130);
            scanf("%d", &i);} while(i<1 ||  i>lc->lg);// i> lc->lg
             strcpy(recepteur,recupererLcon(lc,i)->numero) ;

  do {do{ printf("\t    | recepteur : %s|\n   ",recepteur);

printf("\t    |  Taper votre msg svp \t        |\n");
            fflush(stdin);

fgets(msg,10000,stdin);
msg[strlen(msg)-1]='\0';
ls=compteur(msg);
n=taille(msg)/taillemax(msg);
if(taille(msg)%taillemax(msg)>0)n++;}while(n>8);
printf("\t    | message :  %s |   ",msg);
printf("\t `\t \t\t   |(%i)| \n",n);
printf("\t \t \t \t \t \t \t  ~~~~~~~~\n");
printf("\t \t \t \t \t \t \t ||%i/%i| \n",taillemax(msg)-taille(msg)%taillemax(msg),taillemax(msg)*ls->lg);
printf("\t \t \t \t \t \t \t  ~~~~~~~~\n");
printf("\t    | taper 1 pour envoyer        |\n");
printf("\t    | taper 2 pour r%ccrire le msg  |\n ",130);
printf("\t    | taper 3 pour revenir au menu |\n");
printf("\t    | taper 4 pour quitter         |\n");
do { printf("\t    | Quelle est votre choix? taper 1, 2, 3 ou 4 : |\n\n");
        scanf("%i", &i);}while (i<1 || i >4);
  } while(i==2);
       switch(i){
        case 1:
            strcpy(e->recpeteur,recepteur);
               e->msg=ls;
                e->date_envoi=d;
                e->heure_envoi=h;
                e->prix=n*0.5;
                insererLmsg(lm,e,lm->lg+1);
                printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||                Votre message envoyer !                         ||\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n");
                              menu(lc,lm,lb);break;
        case 3:
        strcpy(e->recpeteur,recepteur);
               e->msg=ls;
                e->date_envoi=d;
                e->heure_envoi=h;
                e->prix=ls->lg*0.5;
                insererLmsg(lb,e,lb->lg+1);
                printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||          ce message enregistrer dans le broillon               ||\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n");
                menu(lc,lm,lb);;
        menu(lc,lm,lb);
            break;
        default :        printf("\t    |  A bientot ! |\n\n");
           exit(1);
            break;
       }
            break;
        case 2:
        ec=elementCreerCon();
        do {elementLireCon(&ec);}while (exist(ec,lc)==1);
        insererLcon(lc,ec,lc->lg);
         printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||           l'ajout a %ct%c effectu%c avec succe<%c              ||\n",130,130,130,130);
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n");
        do{
        printf("\t    |taper 1 pour revenir au menu |  \n");
        printf("\t    |taper 2 pour quitter         |  \n ");
        scanf("%i",&i);}while(i<1||i>2);
        switch(i)
        { case 1: menu(lc,lm,lb);
         default :        printf("\t    | Au revoir ! |\n\n"); exit(1);
        }
            break;
        case 3:{
            if(estVideLcon(lc)){printf("\t  Liste du contact est vide ! \n");}
            else {        do { listeAfficherCon(lc);
            printf("\t    |Contact numero° : | \n");
            scanf("%d", &i);} while(i<1|| i>lc->lg);//
            x=supprimerLcon(lc,i);
            printf("\t  suppresion éffectu%c  \n",130);
            do {
                        printf("\t    |taper 1 pour revenir au menu : | \n");
                        printf("\t    |taper 2 pour quitter :         | \n"); scanf("%i",&i);}while(i<1 || i>2);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
                default :        printf("\t    | A BIENTOT ! |\n\n");  exit(1);
            }}
            break;}
            case 4:listeAfficherCon(jamaisContactes(lm,lc));
            do {
                        printf("\t    |taper 1 pour revenir au menu : | \n");
                        printf("\t    |taper 2 pour quitter :         | \n"); scanf("%i",&i);}while(i<1 || i>2);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
                default :        printf("\t    | A BIENTOT ! |\n\n");  exit(1);
            }

case 5: *ecc=lePlusContacte(lm,lc);
elementAfficherCon(ecc);
            do {
                        printf("\t    |taper 1 pour revenir au menu : | \n");
                        printf("\t    |taper 2 pour quitter :         | \n"); scanf("%i",&i);}while(i<1 || i>2);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
                default :        printf("\t    | GOOD BYE ! |\n\n");  exit(1);
            }
case 6: menu(lc,lm,lb);

        default :        printf("\t    | A BIENTOT ! |\n\n");     exit(1);  }

       break;
    case 3:   system("COLOR 7");
 {listeAfficherLmsg(lm);

       do {
                        printf("\t    |taper 1 pour revenir au menu : | \n");
                        printf("\t    |taper 2 pour effacer un message : | \n");
                        printf("\t    |taper 3 pour revenir les message entre deux date : | \n");
                        printf("\t    |taper 4 pour quitter :         | \n");
                        scanf("%i",&i);}while(i<1 || i>4);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
            case 2 : listeAfficherLmsg(lm);
            do { printf("\t    |taper le numéro du message : | \n",130);scanf("%i",&i);;
            }while (i<1|| i>lm->lg) ;
            supprimerLmsg(lm,i);

                 printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||               La suppresion a %ct%c  effectué                  ||\n",130,130,130);
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n");

            case 3:do {printf("||               taper le jour svp                  ||\n",130,130,130);
            scanf("%i",&j);} while (j<0||j>31);
            do{printf("||               taper le mois svp                  ||\n",130,130,130);
            scanf("%i",&m);} while (m<0||m>12);
            do{printf("||               taper l'ann%ce svp                  ||\n",130);
            scanf("%i",&a);} while (a<0||a>d.annee);
d1.annee=a;d1.jour=j;d1.mois=m;
do {printf("||               taper le jour svp                  ||\n",130,130,130);
            scanf("%i",&j);} while (j<0||j>31);
           do {printf("||               taper le mois svp                  ||\n",130,130,130);
            scanf("%i",&m);} while (m<0||m>12);
           do {printf("||               taper l'ann%ce svp                  ||\n",130);
            scanf("%i",&a);} while (a<0||a>d.annee);
d2.annee=a;d2.jour=j;d2.mois=m;
               listeAfficherLmsg(messages_D1_D2(lm,d1,d2));
do {
                        printf("\t    |taper 1 pour revenir au menu : | \n");
                        printf("\t    |taper 2 pour quitter :         | \n"); scanf("%i",&i);}while(i<1 || i>2);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
                default :        printf("\t    | GOOD BYE ! |\n\n");  exit(1);}
            default :        printf("\t    | A BIENTOT ! |\n\n");

    exit(1);
            }
break;}
    case 4:       system("COLOR 4");
  printf("\t \t    |  Brouillon : | \n");
        listeAfficherLmsg(lb);
         do {
                        printf("\t  |taper 1 pour revenir au menu : | \n");
                        printf("\t  |taper 2 pour effacer un brouillant : | \n");
                        printf("\t  |taper 3 pour quitter :         | \n");
                        scanf("%i",&i);}while(i<1 || i>3);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
            case 2 : listeAfficherLmsg(lb);
            do { printf("\t    |taper le numero du message : | \n");scanf("%i",&i);;
            }while (i<1|| i>lb->lg) ;
            supprimerLmsg(lb,i);                        printf("___________________________________________________________________\n");
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("||                     Suppresion effectué                        ||\n",130);
                printf("||                                                                ||\n");
                printf("||                                                                ||\n");
                printf("___________________________________________________________________\n\n\n"); menu(lc,lm,lb);

            default :        printf("\t    | A BIENTOT ! |\n\n");

    exit(1);
            }
            case 5 : elementAffichermsg(messageLePlusLong(lm));
             do {
                        printf("\t    |taper 1 pour revenir au menu : | \n");
                        printf("\t    |taper 2 pour quitter :         | \n"); scanf("%i",&i);}while(i<1 || i>2);
            switch(i)
            {case 1:menu(lc,lm,lb); break ;
                default :        printf("\t    | GOOD BYE ! |\n\n");  exit(1);}
    default:
       printf("\t    | A BIENTOT ! |\n\n");
       exit(1);
}
  printf("\n\n");

  return 0;
}

int main()
{ ELEMENT e=elementCreerEpile();
    PILE p=PileCreer();
FILE *fc;
FILE *fb;
FILE *fm;
fc= fopen("contact.txt","r+");
fb= fopen("brouillan.txt","r+");
fm= fopen("messages.txt","r+");
LISTE_MSG lm=listeCreerLmsg();
LISTE_MSG lb=listeCreerLmsg();
LISTE_CONT lc=listeCreerLcon();
PILE P=PileCreer();
transform2(fc,lc);
transform(fm,lm);
transform(fb,lb);
menu(lc,lm,lb);
fclose(fc);
fclose(fb);
fclose(fm);


}
