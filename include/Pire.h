#ifndef PIRE_H
#define PIRE_H


#include "Bocek.h"

struct PIRE         //Pire sinifini tanimliyoruz.
{
    Bocek bocek;    //Bocekten kalitim aliyoruz.

    void (*yoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(int value);
char* PireGorunum();
void PireYoket(const Pire);


#endif