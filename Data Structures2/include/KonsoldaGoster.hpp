/* 
* Dosya Adi:KonsoldaGoster.hpp
* Konsolda gösterme fonsiyonların baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 15/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef KonsoldaGoster_hpp
#define KonsoldaGoster_hpp

#include "YoneticiListesi.hpp"
#include "KonsolPozisyon.hpp"

#define GoruntulenenSayfa 8
#define Baslat 0

enum yon 
{
    yukari = 0,
    asagi = 1,
    yenile = 2,

};

enum sayfaYon 
{
    sayfaYukari = 0,
    sayfaAsagi = 1,
};

class KonsoldaGoster 
{

private:
    YoneticiListesi *yoneticiListe;
    
    int ifade;
    int baslat;
    int bitir;

    void denklestir();

public:

    void ifadeAyarla(yon yn);
    void sayfaAyarla(sayfaYon syn);
    KonsoldaGoster(YoneticiListesi* yonetici);
    void yazdirYoneticiListesi();
    void secilenSatirListesiYazdir(int x, int y);
    int rastgeleSecilenDugumGoster()throw (IndexOutOfBounds, NoSuchElement);
    void YoneticiDugumSil();
    void rastgeleSecilenDugumSil(int rastgeleIndex)throw (IndexOutOfBounds, NoSuchElement);
};

#endif