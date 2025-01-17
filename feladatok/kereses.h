#ifndef KERESES_H_INCLUDED
#define KERESES_H_INCLUDED

#include "../segedfuggvenyek/segedfuggvenyek.h"

//Ügyfél autóinak kilistázása a neve szerint
void ugyfel_autoi_kereses(Ugyfel *lista, Auto *eleje);
//Ügyfél keresése rendszám alapján
void rendszam_kereses(Auto *lista);


//Szervíztörténet kilistázása
void szerviz_tortenet(Javitas *lista);

//Lejáró műszaki vizsga kilistázása
void lejaro_vizsga(Ugyfel *lista, Auto *eleje);

#endif // KERESES_H_INCLUDED
