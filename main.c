#include "fajlkezeles/fajlkezeles.h"
#include "segedfuggvenyek/segedfuggvenyek.h"
#include "menu/menu.h"
#include "feladatok/letrehozas.h"
#include "feladatok/torles.h"
#include "feladatok/kereses.h"

//Spertli Krisztián
//IYX0EQ
//NHF

int main()
{
    Ugyfel *ugyfelek = fajbol_beolvasas(); //Ügyfelek beolvasása fájlból
    Auto *autok = fajbol_beolvasas_2(); //Autók beolvasása fájlból
    Javitas *javitasok = fajbol_beolvasas_3(); //Javtítások beolvasása fájlból

    int menupont;
    int szam;

    do
    {

        logo();
        fomenu();
        scanf("%d", &menupont);
        system("cls");

        switch (menupont)
        {
        case 1:
            // Új autó hozzáadása
            do
            {
                logo();
                almenu1();
                scanf("%d", &menupont);
                system("cls");

                switch(menupont)
                {
                case 1:
                    ugyfelek = uj_ugyfel(ugyfelek); //Új ügyfél bevitele az adatbázisba
                    break;
                case 2:
                    autok = uj_auto(autok, ugyfelek); //Meglévő ügyfélhez autó felvétele
                    break;
                case 0:
                    break;
                default:
                    printf("Ervenytelen valasztas. Probalja ujra.\n\n");
                    break;
                }
            }
            while(menupont != 0);
            menupont = -1;
            break;
        case 2:
            // Autó törlése
            almenu2();
            scanf("%d", &szam);
            autok = auto_torlese(autok, szam); //Autó törlése
            javitasok = javitas_torlese(javitasok, szam); //Ha tartozik az adott autóhoz javítás, akkor azok törlése
            break;
        case 3:
            // Keresés ügyfél és rendszám alapján
            do
            {
                logo();
                almenu3();
                scanf("%d", &menupont);
                system("cls");

                switch(menupont)
                {
                case 1:
                    ugyfel_autoi_kereses(ugyfelek, autok); //Ügyfél autóinak kilistázása név alapú kereséssel
                    visszalep();
                    break;
                case 2:
                    rendszam_kereses(autok); //Rendszám alapján keresés
                    visszalep();
                case 0:
                    break;
                default:
                    printf("Ervenytelen valasztas. Probalja ujra.\n\n");
                    break;
                }
            }
            while(menupont != 0);
            menupont = -1;
            break;
        case 4:
            // Javítás feljegyzése
            do
            {
                logo();
                almenu4();
                scanf("%d", &menupont);
                system("cls");

                switch(menupont)
                {
                case 1:
                    javitasok = uj_javitas(javitasok, autok); //Meglévő autóhoz javítás feljegyzése
                    menupont = -1;
                    break;
                case 0:
                    break;
                default:
                    printf("Ervenytelen valasztas. Probalja ujra.\n\n");
                    break;
                }
            }
            while(menupont != 0);
            menupont = -1;
            break;
        case 5:
            // Szerviztörténet megjelenítése
            szerviz_tortenet(javitasok); //Adott autó id alapján szervíztörténet kiírása
            visszalep();
            break;
        case 6:
            // Hamarosan lejáró vizsgák listázása
            lejaro_vizsga(ugyfelek, autok); //Hamarosan lejáró műszaki vizsgák kilistázása
            visszalep();
            break;
        case 0:
            // Kilépés a programból
            printf("Kilepes...\n");
            break;
        default:
            printf("Ervenytelen valasztas. Probalja ujra.\n\n");
            break;
        }
    }
    while (menupont != 0);

    ugyfelek_mentes(ugyfelek); //Ügyfelek mentése fájlba
    autok_mentes(autok); //Autók mentése fájlba
    javitasok_mentes(javitasok); //Javítások mentése fájlba

    free_ugyfelek(ugyfelek); //Ügyfél láncolt lista felszabadítása
    free_autok(autok); //Autók láncolt lista felszabadítása
    free_javitasok(javitasok); //Javítások láncolt lista felszabadítása

    return 0;
}
