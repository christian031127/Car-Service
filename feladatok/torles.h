#ifndef TORLES_H_INCLUDED
#define TORLES_H_INCLUDED

#include "../segedfuggvenyek/segedfuggvenyek.h"

//Autó törlése
Auto *auto_torlese(Auto *lista, int const auto_id);
//Autóhoz tartozó javítás(ok) törlése
Javitas *javitas_torlese(Javitas *lista, int const auto_id);

#endif // TORLES_H_INCLUDED
