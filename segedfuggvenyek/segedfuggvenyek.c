#include "segedfuggvenyek.h"

char *hosszu_sort_olvas()
{
    char *s, *s2, nw;
    int i, n = 0;

    s = (char*) malloc((n+1+1)*sizeof(char)); //Létrehozunk dinamikus egy karaktertömböt

    s[0]='\0';
    scanf("\n");
    while (scanf("%c", &nw) == 1 && nw != '\n') //Addig csináljuk, míg sikeres a beolvasás és nem kapunk entert
    {
        s2 = (char*) malloc ((n + 1 + 1)*sizeof(char)); //Új karaktertömb
        for (i = 0; i < n; i++)
            s2[i] = s[i]; //Adatok bemásoljuk az újba
        free(s); //Régit felszabadítjuk

        s = s2; //Mutatót átrakjuk
        s2[n] = nw; //Új karakter elhelyezése
        s2[n + 1] = '\0'; //Lezáró nulla
        n += 1; //Tömb méretének növelése
    }
    return s; //Visszaadjuk a mutatót
}

char *hosszu_sort_olvas_fajbol(FILE *file)
{
    char tmp;
    if (fscanf(file, "\n%c", &tmp) == EOF) //Ha nem sikerült beolvasni a fájlból akkor NULL-t ad vissza
    {
        return NULL;
    }

    int size = 1;
    //Hasonlóan működik, mint az előző függvény csak malloc helyett realloc van a kódban
    char *line =(char*) malloc (sizeof(char));

    while (tmp != '\n')
    {
        line = realloc(line, ++size * sizeof(char));
        line[size - 2] = tmp;
        if (fscanf(file, "%c", &tmp) == EOF)
        {
            break; //Ha a fájl végéhez értünk, akkor lépjen ki
        }
    }

    line[size - 1] = '\0';
    return line;
}

Ugyfel *ugyfel_keresese(Ugyfel *lista, int const ugyfel_id)
{
    for(Ugyfel *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov) //Ügyfél listán végig megy a mutató
    {
        if(mozgo->id == ugyfel_id) //Ha egyezik az ügyfél azonosítóval
            return mozgo; //Visszadja a helyét
    }
    return NULL; //Különben NULL
}

Auto *auto_keresese(Auto *lista, int const auto_id)
{
    //Hasonlóan az előzőhöz
    for(Auto *mozgo = lista; mozgo != NULL; mozgo = mozgo->kov)
    {
        if(mozgo->id == auto_id)
            return mozgo;
    }
    return NULL;
}

char *masolas(const char *szoveg)
{
    // Ellenõrizzük, hogy a bemeneti szöveg ne legyen NULL
    if (szoveg == NULL)
    {
        return NULL;
    }

    //Az strdup függvény magában foglalja a memóriát és másolja a szöveget
    char *tmp = strdup(szoveg);

    // Ellenõrizzük, hogy a memória foglalás sikeres volt-e
    if (tmp == NULL)
    {
        fprintf(stderr, "Hiba: Nem sikerult eleg memoria foglalasa.\n");
        exit(EXIT_FAILURE);
    }

    return tmp;
}

bool tartalmaz(const char *szoveg, const char *reszlet)
{
    // Ellenõrizzük, hogy a bemeneti szövegek ne legyenek NULL
    if (szoveg == NULL || reszlet == NULL)
    {
        return false;
    }

    for (int i = 0; i < strlen(szoveg); i++)
    {
        int tmp = 0;
        for (int j = i; j < strlen(szoveg); j++) //Ciklusokkal végig megyünk az adott szó karakterein
        {
            if (tolower(szoveg[j]) == tolower(reszlet[tmp])) //Ha a nagybetűsített változatuk megegyezik a részlet karakterrel
            {
                tmp++;
                if (tmp == strlen(reszlet)) //Ha egyenlő a részlet karaktereinek száma a szövegben talált karakterek számával
                {
                    return true; //Akkor igaz
                }
            }
        }
    }
    return false; //Amúgy hamis
}

Idopont szoveg_idopont_konvertalas(char const *szoveg)
{
    Idopont tmp;
    sscanf(szoveg, "%d.%d.%d", &tmp.ev, &tmp.honap, &tmp.nap); //Szöveget időpont struktúrára alakítja
    return tmp;
}

int nap(Idopont t)
{
    int honap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(t.honap == 1)
        return t.nap;

    bool szokoev = (((t.ev % 4 == 0) && (t.ev % 100 != 0)) || (t.ev % 400 == 0)); //Megvizsgálja, hogy az adott év szökőév-e
    int osszeg = 0;

    for(int i = 0; i < t.honap - 1; i++) //Hónap napjait összeadja a megfelelő időpontig
    {
        osszeg += honap[i];
    }

    if(szokoev) //Ha szökőév, akkor hozzáad egy napot
    {
        osszeg += 1;
    }

    osszeg += t.nap; //A megadott napot hozzáadja az összeghez

    return osszeg; //Visszadjuk a napok számát
}

//C fórumon talált kódrészlet, amely segít lekérni a rendszeridőt (time.h függvényeinek használata)
int nap_kulonbseg(Idopont ido)
{
    time_t t = time(NULL); //Aktuális idõ lekérdezése

    struct tm currentTime = *localtime(&t); //Idõ struktúrába való konverzió

    Idopont jelenido;
    jelenido.ev = currentTime.tm_year + 1900;
    jelenido.honap = currentTime.tm_mon + 1;
    jelenido.nap = currentTime.tm_mday;

    int kulonbseg = (jelenido.ev * 365 + nap(jelenido)) - (ido.ev * 365 + nap(ido)); //Jelenidőt átszámítja napba, majd kivonja a megadott idő átszámított napjait

    return kulonbseg; //Visszadjuk a különbséget a két dátum között
}
