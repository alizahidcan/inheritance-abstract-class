#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"


struct CANLI        //Canli sinifini tanimliyoruz.
{
    int value;
    char* (*gorunum)();         //Kalitimla kullanacagimiz görünüm fonksiyon göstericisi.
    
    void (*delete)(struct CANLI*);
};
typedef struct CANLI* Canli;
Canli CanliOlustur(int value);
void delete_Canli(const Canli this);
#endif