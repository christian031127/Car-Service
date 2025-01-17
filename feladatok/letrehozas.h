#ifndef LETREHOZAS_H_INCLUDED
#define LETREHOZAS_H_INCLUDED

#include "../segedfuggvenyek/segedfuggvenyek.h"

//Új ügyfél
Ugyfel *uj_ugyfel(Ugyfel *lista);
//Új autó
Auto *uj_auto(Auto *lista, Ugyfel *eleje);
//Új javítás
Javitas *uj_javitas(Javitas *lista, Auto *eleje);

#endif // LETREHOZAS_H_INCLUDED
