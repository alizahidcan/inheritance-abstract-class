/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include "Pire.h"

Pire PireOlustur(int value){        //Pire olusturucu fonksiyonumuz
    Pire this;
    this=(Pire)malloc(sizeof(struct PIRE));
    this->bocek=BocekOlustur(value);        //Pire bocekten kalitim aliyor.

    this->bocek->canli->gorunum=&PireGorunum;   //Canli gorunumunu pire gorunumune esitliyoruz
    this->yoket=&PireYoket;
    return this;
}

char* PireGorunum(){         //Pirenin gorunumu
    return "P";
}

void PireYoket(const Pire this){        //Pire yokedici fonksiyonumuz
    if(this==NULL) return;
    this->bocek->canli->delete(this->bocek->canli);
    free(this);
}