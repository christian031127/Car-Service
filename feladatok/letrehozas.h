#ifndef LETREHOZAS_H_INCLUDED
#define LETREHOZAS_H_INCLUDED

#include "../segedfuggvenyek/segedfuggvenyek.h"

//�j �gyf�l
Ugyfel *uj_ugyfel(Ugyfel *lista);
//�j aut�
Auto *uj_auto(Auto *lista, Ugyfel *eleje);
//�j jav�t�s
Javitas *uj_javitas(Javitas *lista, Auto *eleje);

#endif // LETREHOZAS_H_INCLUDED
