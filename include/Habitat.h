#ifndef HABITAT_H
#define HABITAT_H

#include "windows.h"
#include "Canli.h"
#include "Bocek.h"
#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"

struct HABITAT  //Habitat sinifimizi tanimliyoruz.
{
    int CanliSayisi;
    int satir;
    int sutun;
    Canli canli;

    void (*HabitatOlustur)(struct HABITAT*);        //Kullanacagimiz fonksiyonlar
    void (*HabitatYaz)(struct HABITAT*);
    void (*SavasBaslat)(struct HABITAT*);
    void (*HabitatSil)(struct HABITAT*);
    void (*ekranSil)();
};
typedef struct HABITAT* Habitat;

Habitat habitat();
void habitatOlustur(const Habitat);
void HabitatYaz(const Habitat);
void savasBaslat(const Habitat);
void HabitatSil(const Habitat);
void clearScreen();
#endif