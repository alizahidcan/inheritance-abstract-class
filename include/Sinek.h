#ifndef SINEK_H
#define SINEK_H


#include "Bocek.h"

struct SINEK        //Sinek sinifini tanimliyoruz.
{
    Bocek bocek;    //Bocekten kalitim aliyoruz.
    void (*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int value);
char* SinekGorunum();
void SinekYoket(const Sinek);

#endif