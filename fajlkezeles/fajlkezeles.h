#ifndef FAJLKEZELES_H_INCLUDED
#define FAJLKEZELES_H_INCLUDED

#include "../segedfuggvenyek/segedfuggvenyek.h"

//�gyfelek beolvas�sa f�jb�l
#define UGYFELEK "ugyfelek.txt"
Ugyfel *fajbol_beolvasas();
//Aut�k beolvas�sa f�lb�l;
#define AUTOK "autok.txt"
Auto *fajbol_beolvasas_2();
//Jav�t�sok beolvas�sa f�jlb�l;
#define JAVITASOK "javitasok.txt"
Javitas *fajbol_beolvasas_3();

//�gyfelek elment�se f�jlba
void ugyfelek_mentes(Ugyfel *lista);
//Aut�k elment�se f�ljba
void autok_mentes(Auto *lista);
//Jav�t�sok elment�se f�jlba
void javitasok_mentes(Javitas *lista);

//�gyfelek felszabad�t�sa
void free_ugyfelek(Ugyfel *ugyfelek);
//Aut�k felszabad�t�sa
void free_autok(Auto *autok);
//Jav�t�sok felszabad�t�sa
void free_javitasok(Javitas *javitasok);

#endif // FAJLKEZELES_H_INCLUDED
