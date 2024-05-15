/* 
* Dosya Adi:YoneticiDugum.hpp
* YonetciListeleri arasinda dugum kuran fonksiyonların baslik dosyasi
* 2.sinif 1-C Sinifi
* 1.Odev
* 16/11/2022(Düzenlemeler yapilmistir)
* Ali Eren Yigit ==> eren.yigit@ogr.sakarya.edu.tr
*/

#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp

#include "SatirListesi.hpp"

class YoneticiDugum 
{
public:
    SatirListesi* veri;
    double ort;
    YoneticiDugum *sonraki;
    YoneticiDugum *onceki;

    YoneticiDugum(SatirListesi* veri, YoneticiDugum *sonraki, YoneticiDugum *onceki);
    YoneticiDugum(SatirListesi* veri, YoneticiDugum *sonraki);
    YoneticiDugum(SatirListesi* veri);
    double ortHesapla();
};


#endif