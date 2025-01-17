#ifndef SEGEDFUGGVENYEK_H_INCLUDED
#define SEGEDFUGGVENYEK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "../debugmalloc.h"
#include "../adatszerkezet/adatszerkezet.h"

//Hosszú sor beolvasása dinamikus foglalással
char *hosszu_sort_olvas();
//Hosszú sor beolvasása fájlból dinamikus foglalással
char *hosszu_sort_olvas_fajbol(FILE *file);

//Ugyfel keresése azonosító alapján
Ugyfel *ugyfel_keresese(Ugyfel *lista, int const ugyfel_id);
//Auto keresése azonosító alapján
Auto *auto_keresese(Auto *lista, int const auto_id);

//Sztringre mutató pointert másol
char *masolas(char const *szoveg);

//Adott szövegben benne van-e a részlet
bool tartalmaz(const char *szoveg, const char *reszlet);

//Szöveget idõpont struktúrára konvertálja
Idopont szoveg_idopont_konvertalas(char const *szoveg);

//Év hányadik napja
int nap(Idopont t);
//Adott dátum hány napja telt el a rendszeridőtől
int nap_kulonbseg(Idopont t);

#endif // SEGEDFUGGVENYEK_H_INCLUDED
