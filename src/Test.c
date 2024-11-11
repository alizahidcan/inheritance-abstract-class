/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include "Habitat.h"

int main(){
    Habitat habitat;
    habitatOlustur(habitat);    //Habitatimizi olusturuyoruz.
    HabitatYaz(habitat);        //Ilk durumumuzu yazdiriyoruz.
    printf("\n\nDonguyu baslatmak istiyorsaniz herhangi bir tusa basiniz!");    //Kullanicidan donut istiyoruz.
    if(getchar() != '\n'){
        clearScreen();
        savasBaslat(habitat);   //Ekran temizletip dongumuzu baslatiyoruz.
    }
    HabitatSil(habitat);        //Habitatimizi siliyoruz.
    return 0;
}