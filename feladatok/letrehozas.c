#include "letrehozas.h"

Ugyfel *uj_ugyfel(Ugyfel *lista)
{
    Ugyfel *uj =(Ugyfel*) malloc (sizeof(Ugyfel));
    Ugyfel *utolso = lista;

    while(lista != NULL && utolso->kov != NULL) //Megkeressük az utolsó elemet a listában
    {
        utolso = utolso->kov;
    }

    printf("UGYFEL REGISZTRALASA\n\n");
    if(lista == NULL)
        uj->id = 1; //Ha a lista üres, akkor az elsõ ügyfél 1 id-t kap
    else
        uj->id = utolso->id + 1; //Amúgy az utolsó ügyfél id-jéhez hozzáadunk 1-et

    printf("Ugyfel neve: ");
    char *beolvasas = hosszu_sort_olvas(); //Beolvasunk egy karaktersorozatot
    while(tartalmaz(beolvasas, ";")) //Nem tartalmazhat pontosvesszõt, mivel a fájlban az elemek is pontosvesszõvel vannak elválasztva
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Ugyfel neve: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->nev = masolas(beolvasas); //A beolvasott karaktersorozatot betöltjük név helyére
    free(beolvasas); //Felszabadítjuk a lefoglalt memóriát

    //Hasonló mûveletek itt is
    printf("Ugyfel elerhetosege: ");
    beolvasas = hosszu_sort_olvas();
    while(tartalmaz(beolvasas, ";"))
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Ugyfel elerhetosege: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->elerhetoseg = masolas(beolvasas);
    free(beolvasas);
    uj->kov = NULL; //Következõ elemet NULL-ra állítjuk


    if(lista == NULL)
        lista = uj; //Ha üres a lista, akkor az elsõ helyre kerül az elem
    else
        utolso->kov = uj; //Különben a lista végéhez csatoljuk a felvett elemet
    system("cls");
    printf("Adatok sikeres bevitele, az uj ugyfel azonositoja: %d.\n\n", uj->id);
    return lista; //Visszadjuk a listát
}

//Hasonlóan mûködik, mint az ügyfél felvétel
Auto *uj_auto(Auto *lista, Ugyfel *eleje)
{
    if(eleje == NULL)
    {
        system("cls");
        printf("Nincsen meg ugyfel felveve, elobb vegyen fol egyet!\n\n");
        return lista;
    }

    Auto *uj = (Auto*) malloc (sizeof(Auto));
    Auto *utolso = lista;

    while(lista != NULL && utolso->kov != NULL)
    {
        utolso = utolso->kov;
    }

    printf("AUTO REGISZTRALASA:\n\n");
    if(lista == NULL)
        uj->id = 1;
    else
        uj->id = utolso->id + 1;

    printf("Ugyfel azonositoja: ");
    char *beolvasas = hosszu_sort_olvas();
    while(ugyfel_keresese(eleje, atoi(beolvasas)) == NULL)
    {
        printf("Ervenyes azonositot adjon meg!\n");
        free(beolvasas);
        printf("Ugyfel azonositoja: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->ugyfel_id = atoi(beolvasas); //A karaktersorozatot integerré konvertálja az atoi függvény, mivel az id az int-ként lett létrehozva az adatszerkezetben
    free(beolvasas);

    printf("Auto rendszama: ");
    beolvasas = hosszu_sort_olvas();
    while(tartalmaz(beolvasas, ";"))
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Auto rendszama: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->rendszam = masolas(beolvasas);
    free(beolvasas);

    printf("Auto tipusa: ");
    beolvasas = hosszu_sort_olvas();
    while(tartalmaz(beolvasas, ";"))
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Auto tipusa: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->tipus = masolas(beolvasas);
    free(beolvasas);

    printf("Az auto muszaki vizsgajanak ervenyessegi ideje (eeee.hh.nn.): ");
    beolvasas = hosszu_sort_olvas();
    Idopont vizsga; //Felveszünk egy Idopont-beli struktúra elemet
    while(sscanf(beolvasas, "%d.%d.%d.", &vizsga.ev, &vizsga.honap, &vizsga.nap) != 3) //Csak akkor olvassuk be, ha megfelelõ a formátum
    {
        printf("Helyes datum formatumot adjon meg!\n");
        free(beolvasas);
        printf("Az auto muszaki vizsgajanak ervenyessegi ideje (eeee.hh.nn.): ");
        beolvasas = hosszu_sort_olvas();
    }
    free(beolvasas);
    uj->vizsga = vizsga; //Betöltjük a struktúra elemet
    uj->kov = NULL;

    if(lista == NULL)
        lista = uj;
    else
        utolso->kov = uj;
    system("cls");
    printf("Adatok sikeres bevitele.\n\n");
    return lista;
}

//Hasonlóan mûködik az elõzõ két függvényhez képest
Javitas *uj_javitas(Javitas *lista, Auto *eleje)
{
    if(eleje == NULL)
    {
        system("cls");
        printf("Nincsen adat az adatbazisban az autokrol, elobb vegyen fol egyet!\n\n");
        return lista;
    }

    Javitas *uj = (Javitas*) malloc (sizeof(Javitas));
    Javitas *utolso = lista;

    while(lista != NULL && utolso->kov != NULL)
    {
        utolso = utolso->kov;
    }

    printf("JAVITAS FELJEGYZESE:\n\n");
    if(lista == NULL)
        uj->id = 1;
    else
        uj->id = utolso->id + 1;

    printf("Auto azonositoja: ");
    char *beolvasas = hosszu_sort_olvas();
    while(auto_keresese(eleje, atoi(beolvasas)) == NULL)
    {
        printf("Ervenyes azonositot adjon meg!\n");
        free(beolvasas);
        printf("Auto azonositoja: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->auto_id = atoi(beolvasas);
    free(beolvasas);

    printf("Javitas leirasa: ");
    beolvasas = hosszu_sort_olvas();
    while(tartalmaz(beolvasas, ";"))
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Javitas leirasa: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->leiras = masolas(beolvasas);
    free(beolvasas);

    printf("Javitas koltsege: ");
    beolvasas = hosszu_sort_olvas();
    while(tartalmaz(beolvasas, ";"))
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Javitas koltsege: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->ar = masolas(beolvasas);
    free(beolvasas);

    printf("Javitas idopontja (eeee.hh.nn.): ");
    Idopont javitas;
    beolvasas = hosszu_sort_olvas();
    while(sscanf(beolvasas, "%d.%d.%d.", &javitas.ev, &javitas.honap, &javitas.nap) != 3)
    {
        printf("Helyes datum formatumot adjon meg!\n");
        free(beolvasas);
        printf("Javitas idopontja (eeee.hh.nn.): ");
        beolvasas = hosszu_sort_olvas();
    }
    free(beolvasas);
    uj->datum = javitas;
    uj->kov = NULL;

    if(lista == NULL)
        lista = uj;
    else
        utolso->kov = uj;
    system("cls");
    printf("Adatok sikeres bevitele.\n\n");
    return lista;
}
