/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include "Bitki.h"

Bitki BitkiOlustur(int value){      //Bitki olusturucu fonksiyonumuz
    Bitki this;
    this=(Bitki)malloc(sizeof(struct BITKI));
    this->canli=CanliOlustur(value);    //Bitki canlidan kalitim aliyor.

    this->canli->gorunum=&BitkiGorunum; //Canli gorunumunu bitki gorunume esitliyoruz.
    this->yoket=&BitkiYoket;
    return this;
}

char* BitkiGorunum(){   //Bitkinin gorunumu
    return "B";
}

void BitkiYoket(const Bitki this){  //Bitki yokedici fonksiyonumuz
    if(this==NULL) return;
    this->canli->delete(this->canli);   //Olusturdugumuz bitki canlisini siliyoruz.
    free(this);
}