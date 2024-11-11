/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include "Canli.h"

Canli CanliOlustur(int value){          //Canli olusturucu fonksiyonumuz
    Canli this;
    this=(Canli)malloc(sizeof( struct CANLI) );         
    this->value=value;
    
    this->delete=&delete_Canli;
    return this;
}
void delete_Canli(const Canli this){    //Canli silme fonksiyonumuz
    if(this==NULL)  return;
    free(this);
}