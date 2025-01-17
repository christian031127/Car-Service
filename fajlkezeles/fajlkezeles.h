#ifndef FAJLKEZELES_H_INCLUDED
#define FAJLKEZELES_H_INCLUDED

#include "../segedfuggvenyek/segedfuggvenyek.h"

//Ügyfelek beolvasása fájból
#define UGYFELEK "ugyfelek.txt"
Ugyfel *fajbol_beolvasas();
//Autók beolvasása fálból;
#define AUTOK "autok.txt"
Auto *fajbol_beolvasas_2();
//Javítások beolvasása fájlból;
#define JAVITASOK "javitasok.txt"
Javitas *fajbol_beolvasas_3();

//Ügyfelek elmentése fájlba
void ugyfelek_mentes(Ugyfel *lista);
//AutÓk elmentése fáljba
void autok_mentes(Auto *lista);
//Javítások elmentése fájlba
void javitasok_mentes(Javitas *lista);

//Ügyfelek felszabadítása
void free_ugyfelek(Ugyfel *ugyfelek);
//Autók felszabadítása
void free_autok(Auto *autok);
//Javítások felszabadítása
void free_javitasok(Javitas *javitasok);

#endif // FAJLKEZELES_H_INCLUDED
