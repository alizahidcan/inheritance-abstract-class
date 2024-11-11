#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI        //Bitki sinifini tanimliyoruz.
{
    Canli canli;

    void (*yoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int value);
char* BitkiGorunum();
void BitkiYoket(const Bitki);


#endif