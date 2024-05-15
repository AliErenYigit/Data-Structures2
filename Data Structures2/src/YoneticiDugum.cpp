/* 
* Dosya Adi:YoneticiDugum.cpp
* YonetciListeleri arasinda dugum kuran fonksiyonların kaynak dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 16/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#include "YoneticiDugum.hpp"


YoneticiDugum::YoneticiDugum(SatirListesi* veri, YoneticiDugum *sonraki , YoneticiDugum *onceki) 
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
    this->ort = ortHesapla();
}

YoneticiDugum::YoneticiDugum(SatirListesi* veri, YoneticiDugum *sonraki ) 
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
    this->ort = ortHesapla();
}

YoneticiDugum::YoneticiDugum(SatirListesi* veri) 
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
    this->ort = ortHesapla();
}
double YoneticiDugum::ortHesapla() 
{
    double toplam = 0;
    if (this->veri->bosmu())
    {
        return toplam;
    }
        

    int boyut = this->veri->boyutt();
    for (int i = 0; i < boyut; ++i) 
    {
        toplam += this->veri->elementAt(i);
    }
    return toplam / boyut;
}