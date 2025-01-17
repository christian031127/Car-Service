#include "torles.h"

Auto *auto_torlese(Auto *lista, int const auto_id)
{
    if(lista == NULL) //Ha a lista üres
    {
        system("cls");
        printf("Nincsen adat az adatbazisban az autokrol, elobb vegyen fol egyet!\n\n");
        return lista;
    }

    int db = 0;

    Auto *izgo = lista;
    while(izgo != NULL) //Megkeressük, hogy az autó listában megtalálható-e az adott autó azonosító
    {
        if(izgo->id == auto_id)
        {
            db++;
        }
        izgo = izgo->kov;
    }

    if(db < 1) //Ha nincs meg az id
    {
        printf("Nincsen talalat.\n\n");
    }
    else
    {
        Auto *mozgo = lista;
        Auto *lemarado = NULL;
        while(mozgo != NULL && mozgo->id != auto_id) //Megkeressük a listában a keresett id alapján a listaelemet és a két pointert megfelelő helyre állítjuk
        {
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }

        if(mozgo == NULL)
        {
            //nincs teendõ
        }
        else if(lemarado == NULL) //Ha az első elemet kell törölni
        {
            Auto *ujeleje = mozgo->kov;
            free(mozgo);
            lista = ujeleje;
        }
        else //Ha a közepéről/végéről akarunk törölni
        {
            lemarado->kov = mozgo->kov;
            free(mozgo);
        }

        system("cls");

        printf("Auto sikeres torlese.\n");
    }

    return lista; //Visszaadjuk a listát
}

//Hasonlóan működik, mint az előző függvény, csak itt a javítások listájáról van szó és abban keressük, hogy melyik javítás tartozik az adott autó id-hez
Javitas *javitas_torlese(Javitas *lista, int const auto_id)
{
    if(lista == NULL)
    {
        system("cls");
        printf("Nincsen adat az adatatbazisban a javitasokrol, elobb vegyen fol egyet!\n\n");
        return NULL;
    }

    int db = 0;
    Javitas *izgo = lista;
    while(izgo != NULL)
    {
        if(izgo->auto_id == auto_id)
        {
            db++;
        }
        izgo = izgo->kov;
    }

    if(db < 1)
    {
        printf("Autohoz nem tartozik javitas.\n\n");
    }
    else
    {
        for(int i = 0; i < db; i++)
        {
            Javitas *mozgo = lista;
            Javitas *lemarado = NULL;
            while(mozgo != NULL && mozgo->auto_id != auto_id)
            {
                lemarado = mozgo;
                mozgo = mozgo->kov;
            }

            if(mozgo == NULL)
            {
                //nincs teendõ
            }
            else if(lemarado == NULL)
            {
                Javitas *ujeleje = mozgo->kov;
                free(mozgo);
                lista = ujeleje;
            }
            else
            {
                lemarado->kov = mozgo->kov;
                free(mozgo);
            }
        }
        printf("Hozzatartozo javitasok sikeresen torolve.\n\n");
    }
    return lista;
}
