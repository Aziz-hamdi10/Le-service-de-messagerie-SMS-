#ifndef _LSTSMS_H
#define _LSTSMS_H
#include "ELTSMSPRIM.h"
#define LongMax 8 /* longueur maximale d'une liste de SMS */
typedef struct
{
ELEMENT_SMS elements[LongMax]; /* tableau statique */
int lg; /* taille logique de la liste */
}
laStructSMS,*LISTE_SMS;
#endif

