#ifndef ADATSZERKEZET_H_INCLUDED
#define ADATSZERKEZET_H_INCLUDED

//Idopont strukt�ra
typedef struct Idopont
{
    int ev;
    int honap;
    int nap;
} Idopont;

//Jav�t�sokhoz tartoz� l�ncolt lista
typedef struct Javitas
{
    int id;
    int auto_id; //Kapcsolat az aut�k list�val
    char *leiras;
    char *ar;
    Idopont datum;
    struct Javitas *kov;
} Javitas;

//Aut�khoz tartoz� l�ncolt lista
typedef struct Auto
{
    int id;
    int ugyfel_id; //Kapcsolat az �gyf�l list�val
    char *rendszam;
    char *tipus;
    Idopont vizsga;
    struct Auto *kov;
} Auto;

//�gyfelekhez tartoz� l�ncolt lista
typedef struct Ugyfel
{
    int id;
    char *nev;
    char *elerhetoseg;
    struct Ugyfel *kov;
} Ugyfel;

#endif // ADATSZERKEZET_H_INCLUDED
