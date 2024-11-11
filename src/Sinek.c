/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include "Sinek.h"

Sinek SinekOlustur(int value){      //Sinek olusturucu fonksiyonumuz
    Sinek this;
    this=(Sinek)malloc(sizeof(struct SINEK));
    this->bocek=BocekOlustur(value);    //Sinek bocekten kalitim aliyor.

    this->bocek->canli->gorunum=&SinekGorunum;  //Canli gorunumunu sinek gorunumune esitliyoruz.
    this->yoket=&SinekYoket;
    return this;
}

char* SinekGorunum(){       //Sinegin gorunumu
    return "S";
}

void SinekYoket(const Sinek this){      //Sinek yokedici fonksiyonumuz
    if(this==NULL) return;
    this->bocek->canli->delete(this->bocek->canli);
    free(this);
}