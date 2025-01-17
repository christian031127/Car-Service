#include "fajlkezeles.h"

Ugyfel *fajbol_beolvasas()
{
    Ugyfel *eleje = NULL;
    Ugyfel *mozgo = NULL;

    FILE *file = fopen(UGYFELEK, "r"); //Féjl megnyitása olvasásra
    if(file == NULL) //Ha esetleg nem sikerül
    {
        printf("Az ugyfelek beolvasas sikertelen.\n\n");
        fclose(file);
        return NULL;
    }

    char *beolvasas = hosszu_sort_olvas_fajbol(file); //Beolvasunk egy sort a fájlból
    while(beolvasas != NULL)
    {
        Ugyfel *uj = (Ugyfel*) malloc (sizeof(Ugyfel)); //Dinamikus terület létrehozása
        uj->id = atoi(strtok(beolvasas, ";")); //Elõször id beolvasása a pontosvesszõig, majd integerré konvertálja a szöveget
        uj->nev = masolas(strtok(NULL, ";")); //Pontosvesszõtõl beolvasás következõ pontosvesszõig, majd a másolás függvénnyel memóriát foglal, végül átadjuk a listaelemnek a karaktersorozatot
        uj->elerhetoseg = masolas(strtok(NULL, ";")); //Továbbiakban elõzõkhoz hasonlóan ugyanígy
        uj->kov = NULL;

        if(eleje == NULL)
        {
            mozgo = eleje = uj; //Ha üres a lista akkor az elejére illesztjük
        }
        else
        {
            mozgo = mozgo->kov = uj; //Amúgy meg a lista végére illesztjük
        }
        free(beolvasas); //Beolvasás felszabadítása
        beolvasas = hosszu_sort_olvas_fajbol(file); //Következõ fájlbeolvasás
    }
    free(beolvasas);
    fclose(file); //Fájl becsukása
    return eleje; //Listát visszadjuk
}

//Hasonló elõzõhöz
Auto *fajbol_beolvasas_2()
{
    Auto *eleje = NULL;
    Auto *mozgo = NULL;

    FILE *file = fopen(AUTOK, "r");
    if(file == NULL)
    {
        printf("Az autok beolvasas sikertelen.\n\n");
        fclose(file);
        return NULL;
    }

    char *beolvasas = hosszu_sort_olvas_fajbol(file);
    while(beolvasas != NULL)
    {
        Auto *uj = (Auto*) malloc (sizeof(Auto));
        uj->id = atoi(strtok(beolvasas, ";"));
        uj->ugyfel_id = atoi(strtok(NULL, ";"));
        uj->rendszam = masolas(strtok(NULL, ";"));
        uj->tipus = masolas(strtok(NULL, ";"));
        uj->vizsga = szoveg_idopont_konvertalas(strtok(NULL, ";"));
        uj->kov = NULL;

        if(eleje == NULL)
        {
            mozgo = eleje = uj;
        }
        else
        {
            mozgo = mozgo->kov = uj;
        }
        free(beolvasas);
        beolvasas = hosszu_sort_olvas_fajbol(file);
    }
    free(beolvasas);
    fclose(file);
    return eleje;
}

//Hasonló elõzõhöz
Javitas *fajbol_beolvasas_3()
{
    Javitas *eleje = NULL;
    Javitas *mozgo = NULL;

    FILE *file = fopen(JAVITASOK, "r");
    if(file == NULL)
    {
        printf("Az javitasok beolvasas sikertelen.\n\n");
        fclose(file);
        return NULL;
    }

    char *beolvasas = hosszu_sort_olvas_fajbol(file);
    while(beolvasas != NULL)
    {
        Javitas *uj = (Javitas*) malloc (sizeof(Javitas));
        uj->id = atoi(strtok(beolvasas, ";"));
        uj->auto_id = atoi(strtok(NULL, ";"));
        uj->leiras = masolas(strtok(NULL, ";"));
        uj->ar = masolas(strtok(NULL, ";"));
        uj->datum = szoveg_idopont_konvertalas(strtok(NULL, ";"));
        uj->kov = NULL;

        if(eleje == NULL)
        {
            mozgo = eleje = uj;
        }
        else
        {
            mozgo = mozgo->kov = uj;
        }
        free(beolvasas);
        beolvasas = hosszu_sort_olvas_fajbol(file);
    }
    free(beolvasas);
    fclose(file);
    return eleje;
}

void ugyfelek_mentes(Ugyfel *lista)
{
    FILE *file = fopen(UGYFELEK, "w"); //Fájl megnyitása és írása
    if(file == NULL) //Ha esetleg nem sikerül megnyitni
    {
        printf("Nem sikerult elmenteni az adatokat!\n\n");
        fclose(file);
        return;
    }

    for(; lista != NULL; lista = lista->kov) //Végigmegyünk a listán
    {
        fprintf(file, "%d;%s;%s\n", lista->id, lista->nev, lista->elerhetoseg); //Pontosvesszõvel elválasztva behelyezzük a láncolt lista elemit, végén új sort kezdve
    }

    fclose(file); //fájl becsukása
}

//Hasonló elõzõhöz
void autok_mentes(Auto *lista)
{
    FILE *file = fopen(AUTOK, "w");
    if(file == NULL)
    {
        printf("Nem sikerult elmenteni az adatokat!\n\n");
        fclose(file);
        return;
    }

    for(; lista != NULL; lista = lista->kov)
    {
        fprintf(file, "%d;%d;%s;%s;%04d.%02d.%02d.\n", lista->id, lista->ugyfel_id, lista->rendszam, lista->tipus, lista->vizsga.ev, lista->vizsga.honap, lista->vizsga.nap);
    }

    fclose(file);
}

//Hasonló elõzõhöz
void javitasok_mentes(Javitas *lista)
{
    FILE *file = fopen(JAVITASOK, "w");
    if(file == NULL)
    {
        printf("Nem sikerult elmenteni az adatokat!\n\n");
        fclose(file);
        return;
    }

    for(; lista != NULL; lista = lista->kov)
    {
        fprintf(file, "%d;%d;%s;%s;%04d.%02d.%02d.\n", lista->id, lista->auto_id, lista->leiras, lista->ar, lista->datum.ev, lista->datum.honap, lista->datum.nap);
    }

    fclose(file);
}

void free_ugyfelek(Ugyfel *ugyfelek)
{
    Ugyfel *mozgo = ugyfelek;
    while(mozgo != NULL) //Végigmegyünk a listán
    {
        Ugyfel *kov = mozgo->kov; //következõ elem
        free(mozgo); //Felszabadítás
        mozgo = kov;
    }
}


//Hasonló elõzõhöz
void free_autok(Auto *autok)
{
    Auto *mozgo = autok;
    while(mozgo != NULL)
    {
        Auto *kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

//Hasonló elõzõhöz
void free_javitasok(Javitas *javitasok)
{
    Javitas *mozgo = javitasok;
    while(mozgo != NULL)
    {
        Javitas *kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}
