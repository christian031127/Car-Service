#include "kereses.h"

void ugyfel_autoi_kereses(Ugyfel *lista, Auto *eleje)
{
    if(eleje == NULL) //Ha üres az autók lista
    {
        system("cls");
        printf("Nincsen bejegyzett auto az adatbazisban!\n\n");
        return;
    }

    printf("UGYFEL AUTOINAK KILISTAZASA:\n\n");

    printf("Az ugyfel neve: ");
    char *beolvasas = hosszu_sort_olvas(); //Beolvasunk egy karaktersorozatot

    system("cls");

    int db = 0;
    while(lista != NULL) //Végigmegyünk az ügyfél listán
    {
        if(tartalmaz(lista->nev, beolvasas)) //Ha egyezik a beolvasás valamelyik listaelemmel
        {
            Auto *mozgo = eleje;
            while(mozgo != NULL) //Végigmegyünk az autó listán
            {
                if(mozgo->ugyfel_id == lista->id) //Ha egyezik az két id, akkor folytatjuk
                {
                    db += 1;
                    if(db == 1)
                    {
                        //Adatok kiírása
                        printf("+---------+--------------------+-----------+------------+---------------+-------------------+\n");
                        printf("| AUTO ID |     UGYFEL NEV     | UGYFEL ID |  RENDSZAM  |     TIPUS     |  MUSZAKI VIZSGA   |\n");
                        printf("|---------+--------------------+-----------+------------+---------------+-------------------|\n");
                    }
                    printf("| %7d | %18s | %9d | %10s | %13s | %10d.%02d.%02d. |\n", mozgo->id, lista->nev, mozgo->ugyfel_id, mozgo->rendszam, mozgo->tipus, mozgo->vizsga.ev, mozgo->vizsga.honap, mozgo->vizsga.nap);
                }
                mozgo = mozgo->kov;
            }
        }
        lista = lista->kov;
    }

    if(db != 0)
    {
        printf("+---------+--------------------+-----------+------------+---------------+-------------------+\n");
        printf("%d db talalat.\n\n", db);
    }
    else
        printf("Nincsen talalat.\n\n");
    free(beolvasas);
}

void rendszam_kereses(Auto *lista)
{
    if(lista == NULL) //Ha üres a lista
    {
        system("cls");
        printf("Nincsen bejegyzett auto az adatbazisban!\n\n");
        return;
    }

    printf("RENDSZAMHOZ TARTOZO ADATOK KILISTAZASA:\n\n");

    printf("Az auto rendszama: ");
    char *beolvasas = hosszu_sort_olvas();

    system("cls");

    int db = 0;
    while(lista != NULL)
    {
        if(tartalmaz(lista->rendszam, beolvasas)) //Ha egyezik a beolvasasás valamely rendszám karaktertömbjével, akkor kiírjuk azokat
        {
            db += 1;
            if(db == 1)
            {
                printf("+---------+-----------+------------+---------------+-------------------+\n");
                printf("| AUTO ID | UGYFEL ID |  RENDSZAM  |     TIPUS     |  MUSZAKI VIZSGA   |\n");
                printf("|---------+-----------+------------+---------------+-------------------|\n");
            }
            printf("| %7d | %9d | %10s | %13s | %10d.%02d.%02d. |\n", lista->id, lista->ugyfel_id, lista->rendszam, lista->tipus, lista->vizsga.ev, lista->vizsga.honap, lista->vizsga.nap);

        }
        lista = lista->kov;
    }

    if(db != 0)
    {
        printf("+---------+-----------+------------+---------------+-------------------+\n");
        printf("%d db talalat.\n\n", db);
    }
    else
        printf("Nincsen talalat.\n\n");
    free(beolvasas);
}

//Hasonlóan működik az előző függvényhez képest
void szerviz_tortenet(Javitas *lista)
{
    if(lista == NULL) //Ha üres a lista
    {
        system("cls");
        printf("Nincsen adat az adatbazisban a javitasokrol, elobb vegyen fol egyet!\n\n");
        return;
    }

    printf("SZERVIZTORTENET:\n\n");

    int szam;
    printf("Az auto azonositoja: "); //Bekérünk egy azonosítót
    scanf("%d", &szam);
    system("cls");

    int db = 0;
    Javitas *mozgo = lista;
    while(mozgo != NULL)
    {
        if(mozgo->auto_id == szam)
        {
            db += 1;
            if(db == 1)
            {
                printf("A KOVETKEZO AZONOSITOJU JARMU SZERVIZTORTENETE: %d\n\n", szam);
                printf("+------------+------------------+--------------+---------------------+\n");
                printf("| JAVITAS ID |      LEIRAS      |      AR      |  JAVITAS IDOPONTJA  |\n");
                printf("|------------+------------------+--------------+---------------------|\n");
            }
            printf("| %10d | %16s | %12s | %12d.%02d.%02d. |\n", mozgo->id, mozgo->leiras, mozgo->ar, mozgo->datum.ev, mozgo->datum.honap, mozgo->datum.nap);
        }
        mozgo = mozgo->kov;
    }

    if(db != 0)
    {
        printf("+------------+------------------+--------------+---------------------+\n");
        printf("%d db talalat\n\n", db);
    }
    else
        printf("Nincsen talalat.\n\n");
}

void lejaro_vizsga(Ugyfel *lista, Auto *eleje)
{
    if(eleje == NULL) //Ha üres a lista
    {
        system("cls");
        printf("Nincsen adat az adatbazisban az autokrol, elobb vegyen fol egyet!\n\n");
        return;
    }

    printf("LEJARO MUSZAKI VIZSGAK:\n\n");

    int db = 0;
    while(lista != 0)
    {
        Auto *mozgo = eleje;
        while(mozgo != NULL)
        {
            //Ha a megfelelő azonosítók megegyeznek, illetve ha a vizsgadátum a rendszeridőtől számított napok számát meghaladja
            if(mozgo->ugyfel_id == lista->id && nap_kulonbseg(mozgo->vizsga) >  (2 * 365)) //2 évig érvényes a mûszaki vizsga
            {
                db += 1;
                if(db == 1)
                {
                    printf("+-----------+------------------+---------+------------+-----------------+-------------------------+\n");
                    printf("| UGYFEL ID |    UGYFEL NEV    | AUTO ID |  RENDSZAM  |  UTOLSO VIZSGA  | VIZSGA OTA ELTELT NAPOK |\n");
                    printf("|-----------+------------------+---------+------------+-----------------+-------------------------|\n");
                }
                printf("| %9d | %16s | %7d | %10s | %8d.%02d.%02d. | %23d |\n", mozgo->ugyfel_id, lista->nev, mozgo->id, mozgo->rendszam, mozgo->vizsga.ev, mozgo->vizsga.honap, mozgo->vizsga.nap, nap_kulonbseg(mozgo->vizsga));
            }
            mozgo = mozgo->kov;
        }
        lista = lista->kov;
    }

    if(db != 0)
    {
        printf("+-----------+------------------+---------+------------+-----------------+-------------------------+\n");
        printf("%d db talalat.\n\n", db);
    }
    else
    {
        printf("Nincsen talalat.\n\n");
    }
}
