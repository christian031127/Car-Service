#include "letrehozas.h"

Ugyfel *uj_ugyfel(Ugyfel *lista)
{
    Ugyfel *uj =(Ugyfel*) malloc (sizeof(Ugyfel));
    Ugyfel *utolso = lista;

    while(lista != NULL && utolso->kov != NULL) //Megkeress�k az utols� elemet a list�ban
    {
        utolso = utolso->kov;
    }

    printf("UGYFEL REGISZTRALASA\n\n");
    if(lista == NULL)
        uj->id = 1; //Ha a lista �res, akkor az els� �gyf�l 1 id-t kap
    else
        uj->id = utolso->id + 1; //Am�gy az utols� �gyf�l id-j�hez hozz�adunk 1-et

    printf("Ugyfel neve: ");
    char *beolvasas = hosszu_sort_olvas(); //Beolvasunk egy karaktersorozatot
    while(tartalmaz(beolvasas, ";")) //Nem tartalmazhat pontosvessz�t, mivel a f�jlban az elemek is pontosvessz�vel vannak elv�lasztva
    {
        printf("Nem tartalmazhat pontosvesszot!\n");
        free(beolvasas);
        printf("Ugyfel neve: ");
        beolvasas = hosszu_sort_olvas();
    }
    uj->nev = masolas(beolvasas); //A beolvasott karaktersorozatot bet�ltj�k n�v hely�re
    free(beolvasas); //Felszabad�tjuk a lefoglalt mem�ri�t

    //Hasonl� m�veletek itt is
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
    uj->kov = NULL; //K�vetkez� elemet NULL-ra �ll�tjuk


    if(lista == NULL)
        lista = uj; //Ha �res a lista, akkor az els� helyre ker�l az elem
    else
        utolso->kov = uj; //K�l�nben a lista v�g�hez csatoljuk a felvett elemet
    system("cls");
    printf("Adatok sikeres bevitele, az uj ugyfel azonositoja: %d.\n\n", uj->id);
    return lista; //Visszadjuk a list�t
}

//Hasonl�an m�k�dik, mint az �gyf�l felv�tel
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
    uj->ugyfel_id = atoi(beolvasas); //A karaktersorozatot integerr� konvert�lja az atoi f�ggv�ny, mivel az id az int-k�nt lett l�trehozva az adatszerkezetben
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
    Idopont vizsga; //Felvesz�nk egy Idopont-beli strukt�ra elemet
    while(sscanf(beolvasas, "%d.%d.%d.", &vizsga.ev, &vizsga.honap, &vizsga.nap) != 3) //Csak akkor olvassuk be, ha megfelel� a form�tum
    {
        printf("Helyes datum formatumot adjon meg!\n");
        free(beolvasas);
        printf("Az auto muszaki vizsgajanak ervenyessegi ideje (eeee.hh.nn.): ");
        beolvasas = hosszu_sort_olvas();
    }
    free(beolvasas);
    uj->vizsga = vizsga; //Bet�ltj�k a strukt�ra elemet
    uj->kov = NULL;

    if(lista == NULL)
        lista = uj;
    else
        utolso->kov = uj;
    system("cls");
    printf("Adatok sikeres bevitele.\n\n");
    return lista;
}

//Hasonl�an m�k�dik az el�z� k�t f�ggv�nyhez k�pest
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
