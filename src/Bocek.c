/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include "Bocek.h"

Bocek BocekOlustur(int value){          //Bocek olusturucu fonksiyonumuz
    Bocek this;
    this=(Bocek)malloc(sizeof(struct BOCEK));
    this->canli=CanliOlustur(value);    //Bocek canlidan kalitim aliyor.

    this->canli->gorunum=&BocekGorunum; //Canli gorunumunu bocek gorunume esitliyoruz.
    this->yoket=&BocekYoket;
    return this;
}

char* BocekGorunum(){   //Bocekin gorunumu
    return "C";
}

void BocekYoket(const Bocek this){  //Bocek yokedici fonksiyonumuz
    if(this==NULL) return;
    this->canli->delete(this->canli);   //Olusturdugumuz bocek canlisini siliyoruz.
    free(this);
}