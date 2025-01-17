#include "fajlkezeles.h"

Ugyfel *fajbol_beolvasas()
{
    Ugyfel *eleje = NULL;
    Ugyfel *mozgo = NULL;

    FILE *file = fopen(UGYFELEK, "r"); //F�jl megnyit�sa olvas�sra
    if(file == NULL) //Ha esetleg nem siker�l
    {
        printf("Az ugyfelek beolvasas sikertelen.\n\n");
        fclose(file);
        return NULL;
    }

    char *beolvasas = hosszu_sort_olvas_fajbol(file); //Beolvasunk egy sort a f�jlb�l
    while(beolvasas != NULL)
    {
        Ugyfel *uj = (Ugyfel*) malloc (sizeof(Ugyfel)); //Dinamikus ter�let l�trehoz�sa
        uj->id = atoi(strtok(beolvasas, ";")); //El�sz�r id beolvas�sa a pontosvessz�ig, majd integerr� konvert�lja a sz�veget
        uj->nev = masolas(strtok(NULL, ";")); //Pontosvessz�t�l beolvas�s k�vetkez� pontosvessz�ig, majd a m�sol�s f�ggv�nnyel mem�ri�t foglal, v�g�l �tadjuk a listaelemnek a karaktersorozatot
        uj->elerhetoseg = masolas(strtok(NULL, ";")); //Tov�bbiakban el�z�khoz hasonl�an ugyan�gy
        uj->kov = NULL;

        if(eleje == NULL)
        {
            mozgo = eleje = uj; //Ha �res a lista akkor az elej�re illesztj�k
        }
        else
        {
            mozgo = mozgo->kov = uj; //Am�gy meg a lista v�g�re illesztj�k
        }
        free(beolvasas); //Beolvas�s felszabad�t�sa
        beolvasas = hosszu_sort_olvas_fajbol(file); //K�vetkez� f�jlbeolvas�s
    }
    free(beolvasas);
    fclose(file); //F�jl becsuk�sa
    return eleje; //List�t visszadjuk
}

//Hasonl� el�z�h�z
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

//Hasonl� el�z�h�z
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
    FILE *file = fopen(UGYFELEK, "w"); //F�jl megnyit�sa �s �r�sa
    if(file == NULL) //Ha esetleg nem siker�l megnyitni
    {
        printf("Nem sikerult elmenteni az adatokat!\n\n");
        fclose(file);
        return;
    }

    for(; lista != NULL; lista = lista->kov) //V�gigmegy�nk a list�n
    {
        fprintf(file, "%d;%s;%s\n", lista->id, lista->nev, lista->elerhetoseg); //Pontosvessz�vel elv�lasztva behelyezz�k a l�ncolt lista elemit, v�g�n �j sort kezdve
    }

    fclose(file); //f�jl becsuk�sa
}

//Hasonl� el�z�h�z
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

//Hasonl� el�z�h�z
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
    while(mozgo != NULL) //V�gigmegy�nk a list�n
    {
        Ugyfel *kov = mozgo->kov; //k�vetkez� elem
        free(mozgo); //Felszabad�t�s
        mozgo = kov;
    }
}


//Hasonl� el�z�h�z
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

//Hasonl� el�z�h�z
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
