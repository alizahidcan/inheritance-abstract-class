/**
*
*@author Ali Zahid Can		zahid.can@ogr.sakarya.edu.tr
*@since 30.04.2024
* B211210044
* 2.Ogretim B Grubu
*/

#include <stdlib.h>
#include <stdio.h>
#include "Habitat.h"
#include "Bocek.h"
#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"

Habitat habitat(){  
    Habitat this;
    this=(Habitat)malloc(sizeof(struct HABITAT) );
    this->HabitatOlustur=&habitatOlustur;
    this->HabitatYaz=&HabitatYaz;
    this->SavasBaslat=&savasBaslat;
    this->HabitatSil=&HabitatSil;
    this->ekranSil=&clearScreen;    

    return this;
}

void habitatOlustur(const Habitat this){    //Habitati dosyadan okuyup olusturdugumuz fonksiyon
    FILE *dosya = fopen("Veri.txt","r");    //Dosyayi okuyoruz.
    char karakter;
    if (dosya==NULL)
    {
        fprintf(stderr,"Dosya acilmadi.\n");
        exit(EXIT_FAILURE);
    }

    this->sutun=0;
    this->satir=0;

    //Canli,satir ve sütun sayısı hesaplıyoruz.
    while (!feof(dosya)) {
        karakter = fgetc(dosya);
        if (karakter == ' ' || karakter == '\n') {
            this->sutun++;
        }
        if (karakter == '\n') {
            break; // Satır sonu olduğunda çık
        }
    }

    rewind(dosya); // Dosyayı başa alıyoruz.

    
    karakter = fgetc(dosya);
    if (karakter != EOF) {
        this->satir++;
    }

    // Diğer satırları okuyoruz
    while ((karakter = fgetc(dosya)) != EOF) {
        if (karakter == '\n') {
            this->satir++;
        }
    }

    this->CanliSayisi=this->satir*this->sutun;  //canli sayisini buluyoruz.
    
    rewind(dosya);
    
    this->canli=(Canli)malloc(this->CanliSayisi*sizeof(struct CANLI));  //Canli dizimizi olusturuyoruz.
    if(this->canli==NULL){
        fprintf(stderr,"Hatali\n");
        exit(EXIT_FAILURE);
    }
    int indeks=0;
    for (int i = 0; i < this->satir; i++) {     //Canli dizisine gorunum ve sayısal degerlerini veriyoruz.
        for (int j = 0; j < this->sutun ; j++) {
            int deger;
            fscanf(dosya, "%d", &deger);   
            if(deger > 0 && deger < 10){    //Bitki
                Bitki b;
                b=BitkiOlustur(deger);
                this->canli[indeks]=*b->canli;
                b->yoket(b);
            }
            if(deger >= 10 && deger <= 20){ //Bocek
                Bocek bo;
                bo=BocekOlustur(deger);
                this->canli[indeks]=*bo->canli;
                bo->yoket(bo);
            }
            if(deger > 20 && deger <= 50){  //Sinek
                Sinek s;
                s=SinekOlustur(deger);
                this->canli[indeks]=*s->bocek->canli;
                s->yoket(s);
            }
            if(deger > 50 && deger < 100){  //Pire
                Pire p;
                p=PireOlustur(deger);
                this->canli[indeks]=*p->bocek->canli;
                p->yoket(p);
            }
            indeks++;
        }
    }
    fclose(dosya);
}

void HabitatYaz(const Habitat this){    //Habitat yazdirma fonksiyonumuz.
    printf("\n\n");
    printf("\n\n");
    for(int i=0;i<this->CanliSayisi;i++){
        if(this->canli[i].value==111)
        {    printf("X ");}
        else{
            printf("%s ",this->canli[i].gorunum());
        }
        if((i+1)%this->sutun==0)
            printf("\n");
    }
}

void savasBaslat(const Habitat this){   //Dongu fonksiyonumuz
    Canli yasayan;  //Yasayanı kontrol etmek icin tuttuyoruz.
    int yasayanIndeks=0;
    yasayan=&(this->canli[0]);  //ilk elemana esitliyoruz.
    for (int i = 1; i < this->CanliSayisi; i++)     //Kontrol bloklarimiz donguyu odevde istenilen sekilde yapıyoruz.
    {
        if(yasayan->gorunum()==BitkiGorunum()){     //Yasayan bitkiyse olabilecek ihtimaller
            if (this->canli[i].gorunum()==PireGorunum())
            {
                this->canli[i].value=111;
            }
            if (this->canli[i].gorunum()==SinekGorunum())
            {
                this->canli[i].value=111;
            }
            if (this->canli[i].gorunum()==BocekGorunum()){
                this->canli[yasayanIndeks].value=111;
                yasayan=&(this->canli[i]);
                yasayanIndeks=i;
            }
            if(this->canli[i].gorunum()==BitkiGorunum()){
                if(this->canli[i].value>yasayan->value){
                    this->canli[yasayanIndeks].value=111;
                    yasayan=&(this->canli[i]);
                    yasayanIndeks=i;
                }
                if(yasayan->value>this->canli[i].value){
                    this->canli[i].value=111;
                }
                if(yasayan->value==this->canli[i].value){
                    if(i>yasayanIndeks){
                        this->canli[i].value=111;
                    }
                    if(yasayanIndeks>i){
                        this->canli[yasayanIndeks].value=111;
                        yasayan=&(this->canli[i]);
                        yasayanIndeks=i;
                    }
                }
            }
        }
        else if(yasayan->gorunum()==BocekGorunum())     //Yasayan bocekse olabilecek ihtimaller
        {
            if (this->canli[i].gorunum()==BitkiGorunum())
            {
                this->canli[i].value=111;
            }
            if (this->canli[i].gorunum()==PireGorunum()){
                this->canli[i].value=111;
            }
            if(this->canli[i].gorunum()==SinekGorunum()){
                this->canli[yasayanIndeks].value=111;
                yasayan=&(this->canli[i]);
                yasayanIndeks=i;
            }
            if(this->canli[i].gorunum()==BocekGorunum()){
                if(this->canli[i].value>yasayan->value){
                    this->canli[yasayanIndeks].value=111;
                    yasayan=&(this->canli[i]);
                    yasayanIndeks=i;
                }
                if(yasayan->value>this->canli[i].value){
                    this->canli[i].value=111;
                }
                if(yasayan->value==this->canli[i].value){
                    if(i>yasayanIndeks){
                        this->canli[i].value=111;
                    }
                    if(yasayanIndeks>i){
                        this->canli[yasayanIndeks].value=111;
                        yasayan=&(this->canli[i]);
                        yasayanIndeks=i;
                    }
                }
            }
        }
        else if(yasayan->gorunum()==SinekGorunum()) //Yasayan sinekse olabilecek ihtimaller
        {
            if (this->canli[i].gorunum()==BocekGorunum())
            {
                this->canli[i].value=111;
            }
            if (this->canli[i].gorunum()==PireGorunum()){
                this->canli[i].value=111;
            }
            if(this->canli[i].gorunum()==BitkiGorunum()){
                this->canli[yasayanIndeks].value=111;
                yasayan=&(this->canli[i]);
                yasayanIndeks=i;
            }
            if(this->canli[i].gorunum()==SinekGorunum()){
                if(this->canli[i].value>yasayan->value){
                    this->canli[yasayanIndeks].value=111;
                    yasayan=&(this->canli[i]);
                    yasayanIndeks=i;
                }
                if(yasayan->value>this->canli[i].value){
                    this->canli[i].value=111;
                }
                if(yasayan->value==this->canli[i].value){
                    if(i>yasayanIndeks){
                        this->canli[i].value=111;
                    }
                    if(yasayanIndeks>i){
                        this->canli[yasayanIndeks].value=111;
                        yasayan=&(this->canli[i]);
                        yasayanIndeks=i;
                    }
                }
            }
        }
        else if(yasayan->gorunum()==PireGorunum())  //Yasayan pireyse olabilecek ihtimaller
        {
            if (this->canli[i].gorunum()==BocekGorunum())
            {
                this->canli[yasayanIndeks].value=111;
                yasayan=&(this->canli[i]);
                yasayanIndeks=i;
            }
            if (this->canli[i].gorunum()==SinekGorunum())
            {
                this->canli[yasayanIndeks].value=111;
                yasayan=&(this->canli[i]);
                yasayanIndeks=i;
            }
            if (this->canli[i].gorunum()==BitkiGorunum())
            {
                this->canli[yasayanIndeks].value=111;
                yasayan=&(this->canli[i]);
                yasayanIndeks=i;
            }
            if(this->canli[i].gorunum()==PireGorunum()){
                if(this->canli[i].value>yasayan->value){
                    this->canli[yasayanIndeks].value=111;
                    yasayan=&(this->canli[i]);
                    yasayanIndeks=i;
                }
                if(yasayan->value>this->canli[i].value){
                    this->canli[i].value=111;
                }
                if(yasayan->value==this->canli[i].value){
                    if(i>yasayanIndeks){
                        this->canli[i].value=111;
                    }
                    if(yasayanIndeks>i){
                        this->canli[yasayanIndeks].value=111;
                        yasayan=&(this->canli[i]);
                        yasayanIndeks=i;
                    }
                }
            }
        }
        if(this->satir <= 25 && this->sutun <= 25){
            HabitatYaz(this);       
            clearScreen();
        }
    }
    if(this->satir>25 || this->sutun>25){
        HabitatYaz(this);
        clearScreen();
    }
    printf("Kazanan: %s : (%d,%d)",yasayan->gorunum(),(yasayanIndeks/this->sutun),(yasayanIndeks%this->sutun)); //Kazanani yaziyoruz.
}

void HabitatSil(const Habitat this){    //Habitat silme fonksiyonumuz
    this->canli->delete(this->canli);   //Canli dizimizi siliyoruz.
    this->CanliSayisi=0;
    free(this); //Habitatimizi siliyoruz.
}

void clearScreen(){     //Ekran sildirme fonksiyonumuz
   #ifdef _WIN32    //Windows icin
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord = {0, 0};
        DWORD count;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hStdOut, &csbi);
        FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    #else   //Linux ve unix icin
        system("clear");
    #endif
}