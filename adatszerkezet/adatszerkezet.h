#ifndef ADATSZERKEZET_H_INCLUDED
#define ADATSZERKEZET_H_INCLUDED

//Idopont struktúra
typedef struct Idopont
{
    int ev;
    int honap;
    int nap;
} Idopont;

//Javításokhoz tartozó láncolt lista
typedef struct Javitas
{
    int id;
    int auto_id; //Kapcsolat az autók listával
    char *leiras;
    char *ar;
    Idopont datum;
    struct Javitas *kov;
} Javitas;

//Autókhoz tartozó láncolt lista
typedef struct Auto
{
    int id;
    int ugyfel_id; //Kapcsolat az ügyfél listával
    char *rendszam;
    char *tipus;
    Idopont vizsga;
    struct Auto *kov;
} Auto;

//Ügyfelekhez tartozó láncolt lista
typedef struct Ugyfel
{
    int id;
    char *nev;
    char *elerhetoseg;
    struct Ugyfel *kov;
} Ugyfel;

#endif // ADATSZERKEZET_H_INCLUDED
