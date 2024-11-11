#ifndef BOCEK_H
#define BOCEK_H


#include "Canli.h"

struct BOCEK        //Bocek sinifini tanimliyoruz.
{
    Canli canli;

    void (*yoket)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;


Bocek BocekOlustur(int value);
char* BocekGorunum();
void BocekYoket(const Bocek);


#endif